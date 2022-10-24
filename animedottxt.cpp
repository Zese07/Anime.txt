#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class gameTxt{
	char start;
	int line = 1;
	int score = 0;
	string clue, txt, name;
	string space = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

	public:
		void txtMenu(){
			cout << R"(
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    						[S] To Start
		Anime.txt
    						[E] To Exit
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
)";

			cin >> start;
			cout << space << endl;

			switch(start){
			    case 's':
			    case 'S':
			    	cout << "                           Starting..." << endl;
			    	cout << space << endl;
			    	txtStart();

			    	break;
			    default:
			    	cout << "                           Exiting..." << endl;
                   	 	cout << space << endl;

	   		 	break;

			}
		}
		void txtStart(){
			srand(time(0));

            int column = 0;
            int row = rand()%10;
            int rowadd = rand()%5 * 2;

            txtCore(column, row, rowadd);

        }
		void txtClue(int column, int row){
		    switch(column){
                case 0:
                    switch(row){
                        case 1: case 2: case 3: case 4: case 6: clue = 'L'; break;
                        case 5: clue = 'Z'; break;
                        case 7: clue = 'R'; break;
                        case 8: case 13: case 18: clue = 'K'; break;
                        case 9: case 14: clue = 'E'; break;
                        case 10: clue = 'N'; break;
                        case 11: case 12: case 19: clue = 'G'; break;
                        case 15: clue = 'I'; break;
                        case 16: clue = 'M'; break;
                        case 17: clue = 'H'; break;
                        case 20: clue = 'S'; break;
                        default:
                            cout << "Error Row: " << row << endl;
                            txtWrong();
                            break;
                        }
                    break;
                default:
                    cout << "Error Column: " << column << endl;
                    txtWrong();
                    break;
            }
            cout << "Character: " << clue << endl;
		}
		void txtRead(string cTxt, string rTxt){
		    int line = 1;

            ifstream character(cTxt);
			while(character >> txt){
				if(txt == rTxt){
					while(character >> txt && line <= 35){
						cout << txt << endl;
						++line;

					}
				}
			}
		}
		void txtName(int column, int row){
		    cout << space << endl;
			cout << "Who is this? ";

		    cin >> name;

		    switch(column){
                case 0:
                    if(((name == "Lelouch") || (name == "Zero") || (name == "Lulu")) && row == 1){ txtCorrect();
                    }else if((name == "Levi") && row == 2){ txtCorrect();
                    }else if(((name == "Luffy") || (name == "Mugiwara") || (name == "Lucy")) && row == 3){ txtCorrect();
                    }else if(((name == "L") || (name == "Hideki") || (name == "Ryuzaki") || (name == "Coil") || (name == "Deneuve")) && row == 4){ txtCorrect();
                    }else if(((name == "Zoro") || (name == "Marimo") || (name == "Zorojuro")) && row == 5){ txtCorrect();
                    }else if(((name == "Light") || (name == "Kira")) && row == 6){ txtCorrect();
                    }else if(((name == "Rintarou") || (name == "Kyouma") || (name == "Okarin")) && row == 7){ txtCorrect();
                    }else if((name == "Killua") && row == 8){ txtCorrect();
                    }else if(((name == "Edward") || (name == "Ed")) && row == 9){ txtCorrect();
                    }else if((name == "Naruto") && row == 10){ txtCorrect();
                    }else if((name == "Guts") && row == 11){ txtCorrect();
                    }else if(((name == "Gintoki") || (name == "Gin-san") || (name == "Gin-chan")) && row == 12){ txtCorrect();
                    }else if(((name == "Kurisu") || (name == "Christina")) && row == 13){ txtCorrect();
                    }else if((name == "Eren") && row == 14){ txtCorrect();
                    }else if((name == "Itachi") && row == 15){ txtCorrect();
                    }else if((name == "Mikasa") && row == 16){ txtCorrect();
                    }else if(((name == "Hachiman") || (name == "Hikki") || (name == "Hikitani") || (name == "Hikio") || (name == "Hikigaeru") || (name == "Hikigerma") || (name == "Fishigaya")) && row == 17){ txtCorrect();
                    }else if(((name == "Ken") || (name == "Centipede") || (name == "Dragon") || (name == "Eyepatch")) && row == 18){ txtCorrect();
                    }else if((name == "Satoru") && row == 19){ txtCorrect();
                    }else if((name == "Saitama") && row == 20){ txtCorrect();
                    }else{ txtWrong(); }
                    break;
                default:
                    cout << "Error Column: " << column << endl;
                    txtWrong();
                    break;
            }
		}
		void txtCorrect(){
			++score;
			cout << "Correct" << endl;
			cout << space << endl;
			cout << "                           Current Score: " << score << endl;
			cout << space << endl;
			txtStart();

		}
		void txtWrong(){
			cout << "Wrong" << endl;
	    		cout << space << endl;
	    		cout << "                           Final Score: " << score << endl;
	    		score = 0;
	    		txtMenu();

		}
		void txtCore(int column, int row, int rowadd){
		    string cTxt = "txt/" + to_string(column) + ".txt";

			row = row + rowadd;
			string rTxt = to_string(++row) + ".txt";

			txtClue(column, row);

			txtRead(cTxt, rTxt);

			txtName(column, row);

		}
};
int main(){
	gameTxt txtObject;
	txtObject.txtMenu();

	return 0;
}
