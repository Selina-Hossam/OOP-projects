#include <bits/stdc++.h>
using namespace std;
class Account {
private:
	string account_owner;
	double balance=0.0;
public:
	Account(string account_owner) {
		this->account_owner=account_owner;
		cout<<"An account has been created successfully!\n";
		cout<<"\n";
	}
	static void printOptions();
	void Deposit(double amount) {
		if(amount<=0) {
			cout<<"Error: Invalid amount! please enter a valid amount(more than 0.0 EGP)\n";
			cout<<"\n";
			return;
		}
		balance+=amount;
		cout<<"Deposited "<<amount<<" EGP. New balance: "<<balance<<" EGP\n"<<endl;
		cout<<"\n";
	}
	void Withdraw(double amount) {
		if(amount>balance) {
			cout<<"Error: insufficient funds. Current balance: "<<balance<<" EGP \n";
			cout<<"\n";
			return;
		}
		balance-=amount;
		cout<<"Withdraw successful!\n";
		cout<<"Your current balance now: "<<balance<<endl;
		cout<<"\n";


	}
	double Balance_Inquiry() {
		return balance;
	}

};
void Account::printOptions() {
	cout<<"1. Deposit\n";
	cout<<"2. Withdraw\n";
	cout<<"3. Check Balance\n";
	cout<<"4. Exit\n";
}
void RunSystem() {
	string name;
	double initial_balance;
	cout<<"=== Bank System ===\n";
	cout<<"Enter your name: \n";
	cin.ignore();
	getline(cin, name);
	Account acc1(name);
	Account::printOptions();
	while(true) {
		int option;
		double amount;
		cout<<"Choose an option: ";
		cin>>option;
		switch(option) {
		case 1:
			cout<<"Enter amount to deposit: ";
			cin>>amount;
			acc1.Deposit(amount);
			break;
		case 2:
			cout<<"Enter amount to withdraw: ";
			cin>>amount;
			acc1.Withdraw(amount);
			break;
		case 3:
			cout<<"Current balance: "<<acc1.Balance_Inquiry()<<" EGP\n";
			cout<<"\n"<<"\n";
			break;
		case 4:
			cout<<"Goodbye!\n";
			return;
		default:
			cout<<"Invalid input!\n";
		}
	}

}

int main() {
	RunSystem();


	return 0;
}
