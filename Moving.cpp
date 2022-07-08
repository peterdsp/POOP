#include "Moving.h"

int Moving:: gX(){return x; };

void Moving:: sX(int lx){x= lx; };

int Moving:: gY(){return y; };

void Moving:: sY(int ly){y= ly; };

void Moving:: monsterMoving(int **lmoveM){
    if(lmoveM[y][x+ 1]!= -8&& lmoveM[y][x+ 1]< lmoveM[y][x])
        x++;
    else if(lmoveM[y][x- 1]!= -8&& lmoveM[y][x- 1]< lmoveM[y][x])
        x--;
    else if(lmoveM[y+ 1][x]!= -8&& lmoveM[y+ 1][x]< lmoveM[y][x])
        y++;  
    else if(lmoveM[y-1][x]!= -8&& lmoveM[y-1][x]< lmoveM[y][x])
        y--;              
}
