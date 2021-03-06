/*****************************************************************************************************************
  DESCRIPTION:   Laboratory in Object Oriented Programming - Final Project
  AUTHOR:        Petros Dhespollari (AM= 18390189)
  CLASS:         Τμήμα 03 (Δευτέρα 15:00 - 16:00), ICE-2004, ice.uniwa.gr 
  DATE:          15/ 06/ 2021 
  EXERCISE:      ΕΡΓΑΣΙΑ - Ο ΜΠΑΜΠΗΣ ΠΟΤΕΡΙΔΗΣ ΚΑΙ Η ΤΕΛΙΚΗ ΔΟΚΙΜΑΣΙΑ
  TOOLS:         Visual Studio Code - Version: 1.57 & Windows Subsystem for Linux (WSL2) - Ubuntu Distro
******************************************************************************************************************/
#include "Engine.h"

int main(int argc, char *argv[]){
    srand (time(0));
    Engine obj(argv[1], argv[2]);
}
/*
root@My-PC:/mnt/c/Users/PetrosDhespollari/OneDrive - University of West Attica/Courses/Spring 6th Semester/2. Object Oriented Programming/Lab/Project# g++ -o FinalProject_18390189 FinalProject_18390189.cpp HiScore.cpp Moving.cpp Engine.cpp Potter.cpp Traal.cpp Gnome.cpp -lncurses && ./FinalProject_18390189 map.txt LeaderBoard.bin


     ┌────────────────────────────────────────────────┐
     │New Game                                        │
     │Show High Scores                                │
     │Exit                                            │
     │                                                │
     └────────────────────────────────────────────────┘

1.Η επιλογή Νew Game ξεκινάει νέο παιχνίδι με τις απαιτούμενες προδιαγραφές
2.Η επιλογή Show High Scores εμφανίζει στον χρήστη το LeaderBoard
3.H επιλογή Exit κάνει έξοδο από το παιχνίδι

1.
************************************************************
*******            *****************    ^          ^    ****
***      ****************************************    ^  ****
***               ***************                  *********
***     G*******************     ********      *************
****              ***********             ******************
******            ****************    **********************
********    ***************** ^        *********************
********    **********************            **************
********    **********************      ^        ***********
********         ***************         T   ***************
**************   ************         **********************
**************    *******        ***************************
***************                *****************************
***************        *****  ^   ^**********  P   *********
****************     **********           ***      *********
****************     **********                 ************
*****************  ^^**************         ^   ************
****************                             ***************
************************************************************

2. Ο πίνακας αρχικοποιείται με " " και 0 για το όνομα χρήστη και την βαθμολογία αντίστοιχα
Αλεξάνδρα 50
  0
  0
  0
  0

3. H επιλογή Exit κάνει έξοδο από το παιχνίδι ή πατάμε το πλήκτρο Esc μετά την είσοδο στο New Game

*/