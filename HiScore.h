#ifndef HISCORE_H
#define HISCORE_H

#include <iostream>
using namespace std;

#include <exception>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <curses.h>
#include <algorithm>

class HiScore{
    private:
        string X;
        string N;
        int S;
        string hScores[5][2];
    public:
        HiScore(string lX);
        void sName(string lN);
        void sScore(int lS);
        string rFromFile();
        void wInFile();
        HiScore& operator<< (const string &XN);
        void operator<< (const int &lS);
};

#endif

