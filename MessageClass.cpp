#include "BombClass.cpp";
#include <iomanip>
#include <vector>
#include <random>
#include <string>
#include <chrono>
#include <Windows.h>
#include <Lmcons.h>

using namespace std;

class Messages {

public:
    /*
    * @Description Goes fullscreen and prints logo, waits until the user press enter.
    */
    void PrintLogo() {
        ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

        cout << R"(                                                                                                   `                            `yNh/                                                                   
                                                                                              `        /                            oMMMM/                                                                  
                                                        .-       -`                           `        o     `                      `dmmh`                                                                  
                                               -m+      sh      om:                     /      `       y     -                                                                                              
                                -ohhys/.        `oy-    /s    .y+                              `       d    -.                                                                                              
                              `yMNhhhmMMdo.        //`  `+   :/`                           `/  `  `.` -m    o                                                                                               
                              dMs     `/yNMh+.       -`  .  .`                            `./+.-.-/+sysN ``+hyo:-.`                                                                                         
              /+:.`          .MM-`       `/sNMh+`             .-:/+o.    `yNmh/`        ./-        .dNNMdhsN`    `..:.    .`                                                             .-::-`             
             `NMMMMNdy/`  :dNMMMMNNo        `/yMMdo:.`-ohs               `dMMMMm      `.-        .ohhs/dNMoo         :.`:od.                                                          .sNMMMMMNy`           
             sMMMMMMMMMN: /MMMMMMMMy           `:sdNMMMNh:   `.-`         `yNMMy   .-`.s       /NmdNm/.osNNs`    ``   h-                                                  :sdNNNmy/  `NMMMMNMMMMd           
            `MMMMM+oMMMMd+hMMMMMMMMMds/`            ```-   .    -/+:.        .:-     /hd  ..`  /dmos.d:s+yhN``  .d-  +m ..                                   `/oyhyo:    hMMMMMMMMMs -MMMMh yMMMM:          
            sMMMMd /MMMMMMMMMMMMMMMNMMMMhyNmhyo/.     .o   .+      -oy`   :y-        yNNodMMdsNMhy`:.`:d+-.- -/.-./:oNys-- `                                +NMMMMMMMm- -MMMMd:dMMMM.`MMMMN`-hys+-          
           `MMMMM:`mMMMMMMMMMMMMMm:.-omMMMMMMMMM- /mhym+-`  o/            -y+        :+/-`/shddydhh+``++y...`/dyy+shmMM:hN+o/.        `     ./oshdmNMNh/   :MMMMmsMMMMN..MMMMd :MNmd/ sMMMMNs:`             
           sMMMMMmNMMMMMMMMMMMMMMN/....oMMMMMMMN .NMMMMMM: ohN/:.             `   `+h+:--.mMmho/odhNMNMh .`smMMNo-oyyNh/o+   .::     `m.    .MMMMMMMMMMMy  +MMMMy yMMMMy hMMMMh:`     `hMMMMMMMdo.          
          .MMMMMMMMMMMMMMMMMMMMMMMMd/...:NMMMMMy dMMMMMMh .MMMMMMMmy:         y  `ossdo::sMMMN/``mmMMMh/`` `.hNo.:ohmNN/.-     `:     `      hMMMMd:dMMMM: -MMMMM`-MMMMM.-NMMMMMNdo.    +dMMMMMMMMs         
          sMMMMd`hMMMMMMMMMMMMMMMMMMM+...oMMMMM/sMMMMMMM- yMMMMMMMMMM+        `   `/mmmNdNNNMNNmmdMMMMs/     ` -ohMMMMMMy`      -            :MMMMN`.MMMMh  mMMMM+ dMMMMo .hMMMMMMMMd:    `/yNMMMMMs        
         .MMMMM: mMMMMMMMMMMMMMMMMMMMN...-MMMMM/MMNMMMMh -MMMMM-:MMMMh             ddy/: o/oomddMMMMMmNm-o  y/ syNMMMMMMMd.     `             mMMMM+ mMMMd  oMMMMm /MMMMN   `/yNMMMMMM/ ./+oy`:NMMMM-       
         yMMMMd /MMMMMMMMMMMMMMMMMMMMN-../MMMMmNMMhMMMM- yMMMMh +MMMMo           `.yoyyNMMMmyhmMMMMms..sshMMMNsymMMMMMMMMNo    `-`            oMMMMNmMMMh-  `MMMMM:`NMMMM/   `-::yMMMMN`+MMMMo +MMMMs       
        .MMMMMs+NMMMMMMMMMMMMMMMMMMMMMNddMMMMMMMMoNMMMh -MMMMM:-NMMMN`             -shNmmMMMMMMmh://` .``.sdMMMMMMMMMMMMddd:/.:y              .MMMMMMMMMMMh` yMMMMy sMMMMh oMMMM/ yMMMMo`NMMMN./MMMMd       
        yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMhoMMMM- hMMMMMMMMMMm:             -dmdmNNMMMMMMMNNy .-/   :hmMMMMMmMMNMNhdy`sdd/     --        hMMMMh.yMMMMh -MMMMM`-MMMMM`.MMMMd -MMMMh :MMMMMMMMMM/       
        .:/oydmMMMMhyMMMMMMMMMMMMMMMMMMMMMmMMMMN.NMMMh -MMMMMmMMMNo              `oomddmMMMMMMMMMMd./``:sshmMMMMMm/mMMMsdNddy:  `              :MMMMN`.MMMMM. dMMMMo dMMMM/ sMMMMdmMMMMs  -yNMMMMds.        
                `.`  :dMMMMMMMMMMMMMMMMMM/+MMMM:oMMMM- hMMMMy yMMMM/           ``.hsohhhmMMMMMMMyymhsohNNMMMMMMmymNNMMMmyo/oyh/..+o             mMMMM+ hMMMMs :MMMMNomMMMM.  oNMMMMMMm+      `.`            
                       .+ymMMMMMMMMMMMMMy hMMMo`NMMMy -MMMMM.`NMMMM:        `-----hsohdmdd-oMdMy`+/-dMm+o+NMMMMo-/yMMMNy..``.+N  ```            oMMMMm:dMMMMd  /NMMMMMMMN/     -/++:.                       
                           `-:////:/ydNN.`MMMd sMMMM. hMMMMy oMMMMm        -MMMMNd+y.     `sNmNd:sso:o/  -+MMMmyohMMNN-       y..`              `MMMMMMMMMMMy   `/syhys/`                                   
                                       ` `+sy.`NMMMy -MMMMMhyMMMMM/         mMMMMM: .`.-++osMMhs.`. .hd..ymmNMm:yMMs-``    `-.-  ```             yMMMMNmdyo:                                                
                                               `-:+. yMMMMMMMMMMMh          /mMMMMo   +h/.shs.` `   .:./..hdNmmNNNs+/       s/                   ./:.`                                                      
                                                      `.:+sydmNmo             ./yh` .s/` /yo        `.-:+  .oysso+/ooh/-``+so:`                                                                             
                                                                                  `/:`  s/o-        /: `` /.+.` `o+so``/:::.  --`                                                                           
                                                                                 -:   `o.  /:      .h.     +o. ``..mM-          ``                                                                          
                                                                               `-` ./:/      :--:/++.      s+      `dd                                                                                      
                                                                                   -:.      `o         `   .y        y+                                                                                     
                                                                                            -          /.   o         o.                                                                                    
                                                                                                            -          .                                                                                    
                                                                                  ---------PRESS ENTER TO START-----------)"
            << endl << endl;
        cin.ignore();
    }

    /*
    * @Description Prints the intro message 
    * @Params:
    *       bomb - The bomb to work with
    */
    static void PrintIntroMessage(Bomb bomb) {
        SlowPrint("Hi, "+ GetUser() + " this is Lt. Lisa Smith. We have a level " + to_string(bomb.getDifficulty()) + " situation...");
        NewLine();

        SlowPrint("This Bomb has " + to_string(bomb.getWires()) + " wires");
        NewLine();

        SlowPrint("We believe that the codes are inside the serial numbers of the wires... I will try to get all of them for you to guess the code.");
        NewLine();
    }

    /*
    * @Description Prints new random phrase
    * @Params:
    *       difficulty - The difficulty of the new level
    */
    void PrintNextLevelMessage(int Difficulty) {
        string NewPhraseLevel = ReturnNewNextLevelPhrase();       

        SlowPrint(NewPhraseLevel.replace(NewPhraseLevel.find("{0}"), sizeof("{0}") - 1, to_string(Difficulty)));
        NewLine();
        SlowPrint("I will try the give you the new serial numbers...");
        NewLine();        
    }

    /*
    * @Description Prints new random descriptions
    * @Params:
    *       bomb - The bomb to work with
    */
    void PrintDescription(Bomb bomb) {
        vector<int> BombCodes = bomb.getResultCodes();

        int Counter = 0;
        vector<string> StringDescriptions;

        for (int BombCode : BombCodes) {
            string WireCode = to_string(Counter+1) + to_string(BombCode);            
            StringDescriptions.push_back(WireCode);
            Counter++;
        }

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(StringDescriptions.begin(), StringDescriptions.end(), std::default_random_engine(seed));

        Counter = 0;
        
        for (string Description : StringDescriptions) {   
            int place = Counter + 1;
            string NewDescriptionPhrase = ReturnNewDescriptionPhrase();

            switch (Counter) {
                case 0: 
                    SlowPrint(NewDescriptionPhrase.replace(NewDescriptionPhrase.find("{0}"), sizeof("{0}") - 1, to_string(place) + "st") + Description);
                    NewLine();
                    break;
                case 1: 
                    SlowPrint(NewDescriptionPhrase.replace(NewDescriptionPhrase.find("{0}"), sizeof("{0}") - 1, to_string(place) + "nd") + Description);
                    NewLine();
                    break;
                case 2: 
                    SlowPrint(NewDescriptionPhrase.replace(NewDescriptionPhrase.find("{0}"), sizeof("{0}") - 1, to_string(place) + "rd") + Description);
                    NewLine();
                    break;
                default: SlowPrint(NewDescriptionPhrase.replace(NewDescriptionPhrase.find("{0}"), sizeof("{0}") - 1, to_string(place) + "th") + Description);
                    NewLine();
            }
            
            Counter++;
        }
    }

    /*
    * @Description Ask for codes, with randomized phrases 
    * @Params:
    *       numberOfCodesToAsk - The number of codes to ask for
    * @Return 
    *       UserGuesses - The user guesses of the codes to compare
    */
    vector<int> AskForCodes(int numberOfCodesToAsk) {
       string TryingPhrase;
       vector<int> UsersGuesses;
       int UserGuess;
       try {
            for (int i = 1; i <= numberOfCodesToAsk; i++) {
                switch (i) {
                case 1:
                    TryingPhrase = ReturnNewTryingPhrase();
                    SlowPrint(TryingPhrase.replace(TryingPhrase.find("{0}"), sizeof(to_string(i) + "st") - 1, to_string(i) + "st")); 
                    cout << ": ";
                    cin >> UserGuess;
                    UsersGuesses.push_back(UserGuess);                                
                    break;
                case 2:
                    TryingPhrase = ReturnNewTryingPhrase();
                    SlowPrint(TryingPhrase.replace(TryingPhrase.find("{0}"), sizeof(to_string(i) + "nd") - 1, to_string(i) + "nd"));                    
                    cout << ": ";
                    cin >> UserGuess;
                    UsersGuesses.push_back(UserGuess);
                    break;
                case 3:
                    TryingPhrase = ReturnNewTryingPhrase();
                    SlowPrint(TryingPhrase.replace(TryingPhrase.find("{0}"), sizeof(to_string(i) + "") - 1, to_string(i) + "rd"));                    
                    cout << ": ";
                    cin >> UserGuess;
                    UsersGuesses.push_back(UserGuess);
                    break;
                default: 
                    TryingPhrase = ReturnNewTryingPhrase();
                    SlowPrint(TryingPhrase.replace(TryingPhrase.find("{0}"), sizeof(to_string(i) + "th") - 1, to_string(i) + "th"));                    
                    cout << ": ";
                    cin >> UserGuess;
                    UsersGuesses.push_back(UserGuess);
                }        
            }
       }
       catch (exception exc) {
           cout << exc.what() << " ";
       }
        return UsersGuesses;       
    }
    /*
    * @Description Slow print function
    * @Params:
    *       StringToPrint - The string that will be printed
    */
    static void SlowPrint(string StringToPrint) {
        cout << setw(30);
        for (char ch : StringToPrint) {
            cout << ch;
            Sleep(SlowSleep);
        }
    }
    /*
    * @Description Inserts new line
    */
    static void NewLine() {
        cout << endl;
    }


private:
    static const int SlowSleep = 50;

    vector<string> TryingMessages {
        "Nice what would be the {0} one: ",
        "The {0} one, please: ",
        "I need to know now what number do you think is the {0} one: ",
        "This is insane, what number could be the {0} one: ",
        "Now I need to know the {0} one: ",
        "Keep thinking, we are so close, the {0} one please: "
    };

    vector<string> NextLevelIntroMsgs = {
        "Believe or not this isn't over yet, we have now a {0} level situation... ",
        "This Bomb is a fucking Matrioska, now we have a {0} level situation ",
        "Oh fuck, now this is a good damn {0} level situation",
        "Well, now we are more screwed than before... we have a {0} level situation "
    };

    vector<string> DescriptionMsgs = {
        "Now the {0} one is... ",
        "Let me check the {0} one... K. This is... ",
        "The {0} one is a little bit curlied... Yeah I got it, is... ",
        "Is a little bit blurry the {0} one. But I think I can read it... is... ",
        "The {0} was hiding, but nothing can escape of my sight. Ths is... "
    };
    /*
    * @Description Randomize the Trying Phrases
    * @Return:
    *       The phrase in the first index.
    */
    string ReturnNewTryingPhrase() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle(TryingMessages.begin(), TryingMessages.end(), std::default_random_engine(seed));
        return TryingMessages[0];
    }
    /*
    * @Description Randomize the Next Level phrases
    * @Return:
    *       The phrase in the first index.
    */
    string ReturnNewNextLevelPhrase() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle(NextLevelIntroMsgs.begin(), NextLevelIntroMsgs.end(), std::default_random_engine(seed));
        return NextLevelIntroMsgs[0];
    }

    /*
    * @Description Randomize the description phrases
    * @Return:
    *       The phrase in the first index.
    */
    string ReturnNewDescriptionPhrase() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle(DescriptionMsgs.begin(), DescriptionMsgs.end(), std::default_random_engine(seed));
        return DescriptionMsgs[0];
    }

    
    /*
    * @Description Gets the windows user
    * @Return:
    *       usenS - The username stringified.
    */
    static string GetUser() {
        TCHAR username[UNLEN + 1];
        DWORD username_len = UNLEN + 1;
        GetUserName(username, &username_len);

        wstring usern = username;
        string usernS = std::string(usern.begin(), usern.end());

        return usernS;
    }
};