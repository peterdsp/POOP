#ifndef ENGINE_H
#define ENGINE_H

#include "Potter.h"
#include "Gnome.h"
#include "Traal.h"
#include "HiScore.h"

class Engine{
    private:
        vector <string> map;
        int **moveM;
	    int score;
    public:
        Engine(string lmap, string lhScores);
        void sMap(string lmap);
        void pMap(Potter lptr, Gnome lgnm, Traal ltrl);
        void sMoveActions();
        void sGemPos();
        void sParchPos();
};

#endif