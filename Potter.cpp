#include "Potter.h"

void Potter:: pPos(vector <string> &lmap){
	int r= lmap.size()- 2;
	int c= lmap[1].length()- 2;
    int i= 0;
	while(i< 1){
        sY((rand()% r- 1)+ 1);
        sX((rand()% c- 1)+ 1);
        if(lmap[gY()][gX()]!= '*'&& lmap[gY()][gX()]!= '^'&& lmap[gY()][gX()]!= 'G'&& lmap[gY()][gX()]!= 'T'){
            lmap[gY()][gX()]= 'P';
            i++;       
        }
	} 
};