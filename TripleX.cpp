// TripleX.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <list>

#include "MessageClass.cpp";

using namespace std;



bool PlayGame(Bomb bomba)
{   
    Messages msg;
    
    if (bomba.getDifficulty() == 1) {
        msg.PrintLogo();
        msg.PrintIntroMessage(bomba);
    }
    else {
        msg.PrintNextLevelMessage(bomba.getDifficulty());
    }

    msg.PrintDescription(bomba);
    vector<int> UserGuess = msg.AskForCodes(bomba.getCodes().size());

    bool CheckCode = bomba.CheckCode(UserGuess);
    if (CheckCode) {
        msg.SlowPrint("That was brilliant...");
        msg.NewLine();
    }
    else {
        msg.SlowPrint("You son of a... *BOOM*");
        msg.NewLine();
        msg.SlowPrint("*The communication was lost*");
    }
    return CheckCode;    
}

int main()
{   
    Bomb bomba = Bomb();
    
    int const MaxDifficulty = 5;

    while (bomba.getDifficulty() <= MaxDifficulty) {

        bool bLevelComplete = PlayGame(bomba);
        cin.ignore();

        if (bLevelComplete) {
            bomba.increaseDifficulty();
            if (bomba.getDifficulty() % 2 == 0) { bomba.increaseWires(); }
            bomba.calculateCodes();
        }
        else {
            return 0;
        }
    }

    cout << "Thanks for everything, soldier, we are still alive thanks to you";

    return 0;
}