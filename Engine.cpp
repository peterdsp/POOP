#include "Engine.h"

Engine:: Engine(string lmap, string lhScores){
	int curX, curY, player, choice;
	int flag= 0;
	int highlight= 0;
	initscr();
	curs_set(FALSE);
	clear();
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax) ;
	WINDOW *menuwin= newwin(6, xMax- 12, yMax- 8, 5);
	box(menuwin, 0, 0);
	refresh() ;
	wrefresh(menuwin) ;
	keypad(menuwin, true) ;
	string choices[3]= {"New Game", "Show High Scores", "Exit"};
	while (1){
		for (int i= 0; i< 3; i++){
			if (i== highlight)
				wattron (menuwin, A_REVERSE) ;
			mvwprintw(menuwin, i+ 1, 1, choices[i].c_str());
			wattroff (menuwin, A_REVERSE) ;
		}
		choice = wgetch(menuwin);
		switch (choice){
			case KEY_UP:
				highlight--;
				if (highlight== -1)
					highlight= 0;
			break;
			case KEY_DOWN:
				highlight++;
				if(highlight== 3)
					highlight= 2;
			break;
			default:
				endwin();
			break;
		}
		if (choice == 10)
			break;
	}
	if (choices[highlight]== "New Game"){
				sMap(lmap);
				score= 0;
				sGemPos();
				Potter ptr;
				Gnome gnm;
				Traal trl;
				pMap(ptr, gnm, trl);
				HiScore hse(lhScores);
				hse<< "Αλεξάνδρα"<< score;
	}else if (choices[highlight]== "Show High Scores") {
				HiScore hse(lhScores);
				cout<< hse.rFromFile()<< endl;
	}
};

void Engine:: sMap(string lmap){
    try{
        ifstream mfile(lmap);
        string line;
        if(mfile.is_open()){
            while(getline(mfile, line))
                map.push_back(line);
            mfile.close();
        }
    }catch(int exc){
        cout<<"Σφάλμα κατα την πρόσβαση στον χάρτη!";
    }
};

void Engine:: pMap(Potter lptr, Gnome lgnm, Traal ltrl){
    int player, curX, curY,i, curgX, curgY, curtX, curtY;
	int flag= 0;
	initscr();
	curs_set(FALSE);
	clear();
	lptr.pPos(map);
	lgnm.gPos(map);
	ltrl.tPos(map);
	for (int i= 0; i< map.size(); i++)
	    mvprintw(i, 0, "%s", map[i].c_str());
	curX= lgnm.gX();
	curY= lgnm.gY();
	keypad(stdscr, TRUE);
	move(curY, curX);
	addch('G');
	map[curY][curX]= 'G';
	curX= ltrl.gX();
	curY= ltrl.gY();
	keypad(stdscr, TRUE);
	move(curY, curX);
	addch('T');
	map[curY][curX]= 'T';
	curX= lptr.gX();
	curY= lptr.gY();
	keypad(stdscr, TRUE);
	move(curY, curX);
	addch('P');
	map[curY][curX]= 'P';
	do{	
		player= getch ();
		move(curY, curX);
		addch (' ');
		map[curY][curX]= ' ';
		switch (player){
			case KEY_UP:
			if(map[curY-1][curX]!= '*'&& map[curY-1][curX]!= 'G'&& map[curY-1][curX]!= 'T')
			    curY--;
				break;
			case KEY_DOWN:
			if(map[curY+1][curX]!= '*'&& map[curY+1][curX]!= 'G'&& map[curY+1][curX]!= 'T')
			    curY++; 
				break;
			case KEY_LEFT:
			if(map[curY][curX-1]!= '*'&& map[curY][curX-1]!= 'G'&& map[curY][curX-1]!= 'T')
			    curX--; 
				break;
			case KEY_RIGHT:
			if(map[curY][curX+1]!= '*'&& map[curY][curX+1]!= 'G'&& map[curY][curX+1]!= 'T')
			    curX++; 
				break;
		}
		if(map[curY][curX]== '^'){
			flag++;
			score+= 10;
			if(flag== 10)
				sParchPos();
		}
		if(map[curY][curX]== '~')
			score+=100;
		move(curY, curX);
		addch('P');
		map[curY][curX]= 'P';
		sMoveActions();
		curgX= lgnm.gX();
		curgY= lgnm.gY();
		move(curgY, curgX);
		addch(' ');
		map[curgY][curgX]= ' ';	
		lgnm.monsterMoving(moveM);
		curgX= lgnm.gX();
		curgY= lgnm.gY();
		if (moveM[curgY][curgX]== 0){
			clear();
			printw("GAME OVER!");
			refresh();
			getch();
			break;
		}
		move(curgY, curgX);
		addch('G');
		map[curgY][curgX]= 'G';
		curtX= ltrl.gX();
		curtY= ltrl.gY();
		move(curtY, curtX);
		addch (' ');
		map[curtY][curtX]= ' ';
		ltrl.monsterMoving(moveM);
		curtX= ltrl.gX();
		curtY= ltrl.gY();
		if (moveM[curtY][curtX]== 0){
			clear();
			printw("GAME OVER!");
			refresh();
			getch();
			break;
		}
		move(curtY, curtX);
		addch('T');
		map[curtY][curtX]= 'T';
		refresh();
	}while (player!= 27);
	endwin();
};

void Engine::sMoveActions(){ 
    int c= map[0].length();   
    int r= map.size();
    moveM= new int* [r];
    int e= 0;
    for(int i= 0; i< r; ++i)
        moveM[i] = new int[c];
    for(int i= 0; i< r; i++)
        for(int j= 0; j< c; j++)
			if(map[i][j]== '*')
                moveM[i][j]= -8;
			else if(map[i][j]== '^')
                moveM[i][j]= -6;
			else if(map[i][j]== 'P')
                moveM[i][j]= 0;
            else {
                moveM[i][j]= -2;
                e++;
            }
    for(int s= 0; s< e; s++) 
		for(int l= 0; l< c; l++)    
        	for(int w= 0; w< r; w++)       
                for(int z= 0; z< e; z++)
                    if(moveM[w][l]== z){   
						if(l> 1&& (moveM[w][l- 1]== -2 || moveM[w+ 1][l]== -6))
                            moveM[w][l- 1]= z+ 1;
						else if(w< (r- 1)&& (moveM[w+ 1][l]== -2|| moveM[w+ 1][l]== -6))
                            moveM[w+ 1][l]= z+ 1;
						else if(w> 1&& (moveM[w- 1][l]== -2|| moveM[w+ 1][l]== -6))
                            moveM[w-1][l]= z+ 1; 
						else if(l< (c- 1)&& (moveM[w][l+ 1]== -2 || moveM[w+ 1][l]== -6))
                            moveM[w][l+ 1]= z+ 1;
                     }
}

void Engine:: sGemPos(){
	int r= map.size()-2;
	int c= map[1].length()-2;
    int x, y, i= 0;
    while(i< 10){	
        x= (rand()% r- 1)+ 1;
        y= (rand()% c- 1)+ 1;
        if(map[x][y]!= '*'&& map[x][y]!= 'P'&& map[x][y]!='G'&& map[x][y]!= 'T'){
            map[x][y]= '^';
            i++;       
        }
	}   
};

void Engine:: sParchPos(){
		int r= map.size()-2;
		int c= map[1].length()-2;
		int x, y, i= 0;
		while(i< 1){	
			x= (rand()% r- 1)+ 1;
			y= (rand()% c- 1)+ 1;
			if(map[x][y]!= '*'&& map[x][y]!= 'P'&& map[x][y]!= 'G'&& map[x][y]!= 'T'){
				map[x][y]= '~';
				move(x, y);
				addch ('~');
				i++;       
			}
		}  
};

