#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan,rateyear,canpay;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rateyear;
	cout << "Enter amount you can pay per year: ";
	cin >> canpay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	int year=0;
	double prevb = loan;
	cout << fixed << setprecision(2); 
	while (prevb > 0) {
		year++;
		double interest = prevb * (rateyear/100);
		double total = prevb + interest;
		double payment = (total > canpay) ? canpay : total;
		double newb = total - payment;

		
		cout << setw(13) << left << year; 
		cout << setw(13) << left << prevb;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << payment;
		cout << setw(13) << left << newb;
		cout << "\n";

		
		prevb = newb;
	}

	return 0;
}
