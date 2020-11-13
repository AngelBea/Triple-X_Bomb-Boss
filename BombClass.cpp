#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Bomb {
	public:
		Bomb() {
			Wires = 2;
			Difficulty = 1;
			calculateCodes();
		}

		void increaseWires() { Wires++; };
		void increaseDifficulty() { Difficulty++; };

		int getWires() { return Wires; };
		vector<int> getCodes() { return Codes; };
		vector<int> getResultCodes() { return ResultCodes; };
		int getDifficulty() { return Difficulty; };

		void calculateCodes() {
			Codes.clear();
			ResultCodes.clear();

			for (int i = 0; i < Wires; i++) {
				time_t RawTime;
				time(&RawTime);
				srand(RawTime+i);
				int RandomNumber = rand() % (Difficulty * 10) + 1;

				Codes.push_back(RandomNumber);
				ResultCodes.push_back(RandomNumber * RandomNumber);				
			}
		}

		bool CheckCode(vector<int> UserGuess) {
			for (int i = 0; i < UserGuess.size(); i++) {
				if (UserGuess[i] != Codes[i]) {
					return false;
				}
			}

			return true;
		}


	private:
		int Difficulty;
		int Wires;
		vector<int> Codes;
		vector<int> ResultCodes;
};





