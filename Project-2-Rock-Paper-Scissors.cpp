#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Rock_Paper_Scissors {
public:
	int player_score=0, computer_score=0,r=1;
	char choice(char arr[]) {
		char ch;
		srand(time(NULL));
		int i = (rand() % 3);
		ch = arr[i];
		return ch;
	}
	bool Check_valid(char user_ch) {
		if (user_ch == 'r' || user_ch == 'p' || user_ch == 's') return true;
		return false;
	}
	void check_win(char ch, char user_ch) {
		char arr[2] = { ch, user_ch };
		char winner;
		for (int i = 0; i < 2; i++) {
			if (arr[i] == 'r' && (arr[i + 1] == 's' || arr[i - 1] == 's')) {
				winner = arr[i];
				break;
			}
			else if (arr[i] == 's' && (arr[i + 1] == 'p' || arr[i - 1] == 'p')) {
				winner = arr[i];
				break;
			}
			else if (arr[i] == 'p' && (arr[i + 1] == 'r' || arr[i - 1] == 'r')) {
				winner = arr[i];
				break;
			}
			else {
				if (i >= 2) {
					winner = 'd';
					break;
				}
			}
		}
		if (winner == ch) {
			computer_score++;
			cout<<"Computer wins this round!\n";
		}
		else if (winner == user_ch) {
			player_score++;
			cout<<"You win this round!\n";
		} else {
			cout << "It's a tie!\n";
		}
		cout<<"Score -> You: "<<player_score<<" Computer: "<<computer_score<<endl;
	}
	void start_game() {
		int rounds;
		cout<<"=== Rock, Paper, Scissors ===\n";
		cout<<"How many rounds? ";
		cin>>rounds;
		cout<<"\n";
		char choices[3] = { 'r', 'p', 's' };
		int status;
		bool is_valid;
		while (rounds--) {
			char ch = choice(choices), user_ch;
			do {
				cout<<"Round "<<r<<endl;
				r++;
				cout<<"Enter your choice (r/p/s): ";
				cin>>user_ch;
				is_valid=Check_valid(user_ch);
				if(is_valid) {
					switch(user_ch) {
					case 'r':
						cout<<"You chose Rock. ";
						break;
					case 's':
						cout<<"You chose Scissors. ";
						break;
					case 'p':
						cout<<"You chose Paper. ";
						break;
					}
					switch(ch) {
					case 'r':
						cout<<"Computer chose Rock. ";
						break;
					case 's':
						cout<<"Computer chose Scissors. ";
						break;
					case 'p':
						cout<<"Computer chose Paper. ";
						break;
					}
					cout<<"\n";
					check_win(ch, user_ch);
				}
				else {
					cout << "Invalid input!! Please try again...\n";
				}
				cout<<"\n";
			}
			while (!is_valid);
		}
		cout<<"=== Final Result ===\n";
		cout<<"You: "<<player_score<<" | Computer: "<<computer_score<<endl;
		if(player_score>computer_score) {
			cout<<"You win overall!\n";
		} else if(computer_score>player_score) {
			cout<<"Computer wins overall!\n";
		} else {
			cout<<"It's a tie overall!\n";
		}
	}
};
int main() {
	Rock_Paper_Scissors game;
	game.start_game();
	return 0;
}
