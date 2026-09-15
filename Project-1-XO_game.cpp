#include <iostream>
using namespace std;
class XO_game {
public:
	char arr[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
		char check_win(char arr[3][3], char player) {
		char result = ' ';
		for (int i = 0; i < 3; i++) {
			if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player) {
				result = player;
				return result;
			}
			else if (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player) {
				result = player;
				return result;
			}
			else if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) {
				result = player;
				return result;
			}
			else if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player) {
				result = player;
				return result;
			}
			else {
				result = 'D';
			}
			return result;
		}
	}
	void displayGrid(char array[3][3]) {
		int temp=0;
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
			    cout<<" ";
				temp++;
				cout<<array[i][j];
				if(j==0||j==1) {
					cout<<" |";
				}
				if(temp==3) {
				    cout<<"\n";
					temp=0;
					if(i<2) cout<<"---+---+---\n";
				}
			}
		}
	}
	void start_game() {
	    cout<<"=== XO Game ===\n";
		char player = 'X';
		int status;
		for (int i = 1; i <= 9; i++) {
			if(i==1) displayGrid(arr);
			int m,r,c;
			int invalid = 0;
			do {
				cout << "Player " << player << " ,enter your move(1-9): ";
				cin >> m;
				if(m>=1&&m<=3) {
					r=0;
					c=m-1;
				} else if(m>=4&&m<=6) {
					r=1;
					c=m-4;
				} else if(m>=7&&m<=9) {
					r=2;
					c=m-7;
				}
				if ((m>=1&&m<=9) && (arr[r][c] !='X'&&arr[r][c]!='O')) {
					arr[r][c] = player;
					invalid-=invalid;
				}
				else {
					cout << "Invalid input! Please try again...\n";
					invalid++;
				}
			} while (invalid > 0);
			displayGrid(arr);
			char result = check_win(arr, player);
			if (result == player) {
				cout << "Player " << player << " wins!\n";
				return;
			}
			else if (result == 'D'&&i==9) {
				cout << "Draw\n";
			}
			if (player == 'X') player = 'O';
			else player = 'X';
		}
		return;
	}
};


int main() {
	XO_game g;
	g.start_game();
	return 0;
}
