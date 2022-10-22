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
			rowadd = rowadd * 2;
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
				case 8: case 13: case 18: clue = 'K'; break;
				case 9: case 14: clue = 'E'; break;
				case 10: clue = 'N'; break;
				case 11: case 12: case 19: clue = 'G'; break;
				case 15: clue = 'I'; break;
				case 16: clue = 'M'; break;
				case 17: clue = 'H'; break;
				case 20: clue = 'S'; break;
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

		}
};

int main(){
	gameTxt txtObject;
	txtObject.txtMenu();

	return 0;
}
