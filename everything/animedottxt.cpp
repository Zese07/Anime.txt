#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

class gameTxt{
	char start;
	int score = 0;
	string clue, text, name;
	
	public:			
		void txtMenu(){
			cout << R"(- - - - - - - - - - - - - - - - - - - -
    			[S] To Start
	Anime.txt				 	 
    			[E] To Exit 
- - - - - - - - - - - - - - - - - - - -
)";

			cin >> start;
			cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	
			switch(start){
			    case 's':
			    case 'S':
			    	cout << "Starting..." << endl;
			    	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;	    	
			    	txtStart();
	    	
			    	break;
			    default:
			    	cout << "Exiting..." << endl;
	   		 	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	    	
	   		 	break;
			}
		}
		void txtStart(){					
			srand(time(0));
    
  		  int column, row;
 	   	column = txtColumn();  
		    row = txtRow();    			
			
			switch(column){
	  		  case 0:
	 		   	txt0(row);
	   	 	break;
	   	 	
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
		void txtWho(){ 
			cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
			cout << "Who is this? ";
			
		}		
		int txtCorrect(){ 
			++score;
			cout << "Correct" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
			cout << "Current Score: " << score << endl;
			cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
			txtStart();
			
		}		
		void txtWrong(){ 
			cout << "Wrong" << endl;
	    	cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	    	cout << "Final Score: " << score << endl;
	    	score = 0;
	    	txtMenu();
	    	
		}			
		void txt0(int row){ 
			string txt = to_string(++row) + ".txt";			
			 			
			switch(row){
				case 1: case 2: case 3: case 4: case 6: clue = 'L'; break;
				case 5: clue = 'Z'; break;
				case 7: clue = 'R'; break;
				case 8: clue = 'K'; break;
				case 9: clue = 'E'; break;
				case 10: clue = 'N'; break;
				default: cout << "Error."; break;					
			}
			cout << "Character: " << clue << endl;
			ifstream character(txt);			
																																						while(character >> text){
				cout << text << endl;
			}				
			txtWho();
										
			cin >> name;							 																			
			if(((name == "Lelouch") || (name == "Zero") || (name == "Lulu")) && row == 1){
	    		txtCorrect();
			}else if((name == "Levi") && row == 2){
	    		txtCorrect();
			}else if(((name == "Luffy") || (name == "Mugiwara") || (name == "Lucy")) && row == 3){
	    		txtCorrect();
	    	}else if(((name == "L") || (name == "Hideki") || (name == "Ryuzaki") || (name == "Coil") || (name == "Deneuve")) && row == 4){
	    		txtCorrect();
	    	}else if(((name == "Zoro") || (name == "Marimo") || (name == "Zorojuro")) && row == 5){
	    		txtCorrect();
	    	}else if(((name == "Light") || (name == "Kira")) && row == 6){
	    		txtCorrect();
	    	}else if(((name == "Rintarou") || (name == "Kyouma") || (name == "Okarin")) && row == 7){
	    		txtCorrect();
	    	}else if((name == "Killua") && row == 8){
	    		txtCorrect();
	    	}else if(((name == "Edward") || (name == "Ed")) && row == 9){
	    		txtCorrect();
	    	}else if((name == "Naruto") && row == 10){
	    		txtCorrect();	        			    	
	    	}else{ txtWrong(); }										
		}
		void txt1(int row){
		
		}	
};

int main(){
	gameTxt txtObject;
	txtObject.txtMenu();
		    	    	    	    
	return 0;
}
