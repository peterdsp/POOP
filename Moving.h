#ifndef MOVING_H
#define MOVING_H

#include <iostream>
using namespace std;

#include <vector>
#include <string>

class Moving{
    protected:
        int x;
        int y;
    public:
        int gX();
        void sX(int lx);
        int gY();
        void sY(int ly);
        void monsterMoving(int **lmoveM);
};

#endif