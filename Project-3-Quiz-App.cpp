#include <bits/stdc++.h>
using namespace std;
class Question {
public:
	string qs_title;
	char correct_answer;
	vector<string>choices;
	Question(string qs_title,  vector<string>choices, char correct_answer) {
		this->qs_title = qs_title;
		this->correct_answer = correct_answer;
		this->choices = choices;
	}

};
class Quiz {
private:
	char answer;
	int score=0;

public:
	vector<Question>questions;

	void greeting() {
		cout<< " === Quiz App ===\n";
	}
	void standardize(char &choice) {
		if(choice>='A'&&choice<='Z') choice=choice+32;
	}
	void display_qs() {
		int i=0;
		int choices_count=questions[i].choices.size();
		while(i<questions.size()) {
			cout<<"Question "<<i+1<<": ";
			cout<<questions[i].qs_title<<endl;
			for(int j=0; j<choices_count; j++) {
				char c='a'+j;
				cout<<" "<<c<<")";
				cout<<questions[i].choices[j]<<endl;
			}
			cout<<"Your answer: ";
			cin>>answer;
			standardize(answer);
			while(isInvalid(answer, choices_count)) {
				cout<<"Invalid choice!!please try again..\n";
				cout<<"Your answer: "<<choices_count<<") : ";
				cin>>answer;
				isInvalid(answer, choices_count);
			}
			cin.ignore();
			isCorrect(answer, i);
			i++;
		}

	}
	bool isInvalid(char answer, int choices_count) {
		if(answer<'a'||answer>'z'||answer>'a'+choices_count) {
			return true;
		}
		return false;
	}
	void isCorrect(char answer, int i) {
		if(answer==questions[i].correct_answer) {
			cout<<"Correct!\n";
			score++;
		} else {
			cout<<"Wrong! Correct answer: "<<questions[i].correct_answer<<endl;
		}
	}
	void get_score() {
		cout<<"\n === Quiz Complete ===\n";
		cout<<" Score: "<<score<<" / "<<questions.size()<<endl;
	}
	//This is function for displaying correct answers, but I have commeneted it since it wasn't required in the project

	/**void displayCorrectAnswers(){
	    cout<<"_____________________\n";
	    cout<<"Correct answers are: "<<endl;
	    for(int i=0;i<questions.size();i++){
	        cout<<"Question "<<i+1<<": "<<questions[i].correct_answer<<endl;
	    }
	}**/
};
void RunApp() {
	Quiz quiz1;
	quiz1.greeting();
	quiz1.questions= {Question("What is the capital of Japan?", {"Tokyo", "Kyoto", "Hiroshima", "Osaka"}, 'a'),
	                  Question("Which planet is known as the Red Planet?", {"Jupiter", "Mars", "Mercury", "Venus"}, 'b')
	                 };
	Question q("What is the atomic number of Nitrogen?", {"7", "8", "9", "10"}, 'a');
	quiz1.questions.push_back(q);
	quiz1.display_qs();
	quiz1.get_score();
	//displaying correct answers
	//quiz1.displayCorrectAnswers();
}
int main() {
	RunApp();
	return 0;
}
