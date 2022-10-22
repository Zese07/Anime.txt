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
	string clue, text, name;
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

            int column = txtColumn();
		    int row = txtRow();
		    int rowadd = txtRowAdd();

			switch(column){
                case 0: txt0(row, rowadd); break;
                case 1: txt1(row, rowadd); break;
                default: cout << "Error."; break;

			}
		}
		int txtColumn(){
			int column = 0;
			return column;

		}
		int txtRow(){
			int row = rand()%10;
			return row;

		}
		int txtRowAdd(){
			int rowadd = rand()%5;
			rowadd = rowadd * 0;
			return rowadd;

		}
		void txtWho(){
			cout << space << endl;
			cout << "Who is this? ";

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
		void txt0(int row, int rowadd){
			row = row + rowadd;
			string txt = to_string(++row) + ".txt";

			int line = 1;

			switch(row){
				case 1: case 2: case 3: case 4: case 6: clue = 'L'; break;
				case 5: clue = 'Z'; break;
				case 7: clue = 'R'; break;
				case 8: clue = 'K'; break;
				case 9: clue = 'E'; break;
				case 10: clue = 'N'; break;
				default:
                    cout << "Error: " << row << endl;
                    txtWrong();
                    break;

			}
			cout << "Character: " << clue << endl;

			ifstream character("txt/0.txt");
			while(character >> text){
				if(text == txt){
					while(character >> text && line <= 35){
						cout << text << endl;
						++line;

					}
				}
			}
			txtWho();

			cin >> name;
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
	    	}else{ txtWrong(); }

		}
		void txt1(int row, int rowadd){

		}
};

int main(){
	gameTxt txtObject;
	txtObject.txtMenu();

	return 0;
}
