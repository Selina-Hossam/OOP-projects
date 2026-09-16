#include <bits/stdc++.h>
using namespace std;
class Student {
private:
	string name;
	vector<string>courses;
public:
	Student() {
		string student_name;
		cout<<"Enter student name: ";
		getline(cin, student_name);
		name=student_name;
		cout<<"Student \""<<student_name<<"\" added.\n";
	}
	void setCourse() {
		string c;
		cout<<"Enter course name: ";
		getline(cin, c);
		courses.push_back(c);
		cout<<"Course \""<<c<<"\" added to "<<name<<"."<<endl;
	}
	void deleteCourse() {
		string c;
		cout<<"Enter the course that you want to delete: ";
		getline(cin, c);
		int i=0;
		for(string course : courses) {
			if(course==c) {
				courses.erase(courses.begin()+i);
				break;
			}
			i++;
		}
		cout<<"The course has been deleted successfully!\n";

	}
	string getName() {
		return name;
	}
	void getCourses() {
		cout<<"Courses: ";
		for(int i=0; i<courses.size(); i++) {
			cout<<courses[i];
			if(i!=courses.size()-1) cout<<", ";
		}
		cout<<endl;
	}
	static void menu();
};
void Student::menu() {
	cout<<"1. Add Student\n";
	cout<<"2. Delete Student\n";
	cout<<"3. Add Course to Student\n";
	cout<<"4. Delete Course from Student\n";
	cout<<"5. Display All Stuedents\n";
	cout<<"6. Exit\n";
}
void RunSystem() {
	cout<<"=== Student Management System ===\n";
	vector<Student>students;
	Student::menu();
	while(true) {
		int choice;
		cout<<"Choose an option: ";
		cin>>choice;
		cin.ignore();
		if(choice==1) {
			Student s;
			students.push_back(s);
		}
		else if(choice>=2&&choice<=4) {
			string name;
			int idx;
			cout<<"Enter Student name: ";
			getline(cin, name);
			for(int i=0; i<students.size(); i++) {
				string temp=students[i].getName();
				if(temp==name) {
					idx=i;
					break;
				}
			}
			if(choice==2) {
				students.erase(students.begin()+idx);
			}
			else if(choice==3) {
				students[idx].setCourse();
			} else {
				students[idx].deleteCourse();
			}
		} else if(choice ==5) {
			for(Student s : students) {
				cout<<"Student: "<<s.getName()<<endl;
				s.getCourses();
			}
		} else if(choice ==6) {
			cout<<"Goodbye!\n";
			return;
		} else {
			cout<<"Invalid choice!\n";
		}
		cout<<"\n";
	}
}

int main() {

	RunSystem();

	return 0;
}
