#include "HiScore.h"

HiScore:: HiScore(string lX):X(lX){
    for (int i= 0; i< 5; i++){
        hScores[i][0]= " ";
        hScores[i][1]= "0";
    }
};

void HiScore:: sName(string lN){N= lN; };

void HiScore:: sScore(int lS){S= lS; };

string HiScore:: rFromFile(){
    char ghs[100];
    string score;
    try{
        ifstream gameHiScore(X, ios:: in| ios:: binary);
        for (int i= 0; i< 5; i++)
            gameHiScore.read(ghs, sizeof(ghs));
        gameHiScore.close();
        score= ghs;
        return score;
    }catch(int exc){
        cout<< "Σφάλμα! Αδύνατη η πρόσβαση στο αρχείο!"<< endl;
    }
    return score;
};

void HiScore:: wInFile(){ 
    for (int k= 0; k< 5- 1; k++)
        for (int j= 0; j< 5- k- 1; j++)
            if (stoi(hScores[j][1])< stoi(hScores[j+ 1][1])){
                swap(hScores[j+ 1][1], hScores[j][1]);
                swap(hScores[j+ 1][0], hScores[j][0]);   
            } 
    hScores[4][0]= N; 
    hScores[4][1]= to_string(S);
    for (int k= 0; k< 5- 1; k++)
        for (int j= 0; j< 5- k- 1; j++)
            if (stoi(hScores[j][1])< stoi(hScores[j+ 1][1])){
                swap(hScores[j+ 1][1], hScores[j][1]);
                swap(hScores[j+ 1][0], hScores[j][0]);   
            } 
    try{
        ofstream gameHiScore(X, ios::out| ios::binary);
        for (int i= 0; i< 5; i++)
            gameHiScore << hScores[i][0]<< " "<< hScores[i][1]<< endl;
        gameHiScore.close();
    }catch(int exc){
        cout<< "Σφάλμα! Αδύνατη η πρόσβαση στο αρχείο!"<< endl;
    }
};

HiScore& HiScore::operator<<(const string &XN){
    N= XN;
    return *this;
}

void HiScore:: operator<<(const int &lS){
    S= lS;
    wInFile();
}
