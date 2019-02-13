//=====================================================
// Joshua Stewart
// 2/13/19
// Programming Assignment #4
// Description: Mortgage Payment
//=====================================================

// main goes here. Code that *uses* the Mortgage class
// goes in this file

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Mortgage.h"

bool parseInt(string inputString, int& inputInt);
bool parseFloat(string inputString, float& inputFloat);

int main()
{
	Mortgage myMortgage; //The mortgage for showing functionality
	string loan; //The amount of the loan
	string rate; //The annual interest rate
	string years; //The number of years of the loan
	float loanTemp; //Temporary value for holding loan
	float rateTemp; //Temporary value for holding rate
	int yearsTemp; //Temporary value for holding years

	cout << "Enter loan amount: ";
	getline(cin, loan);
	while (!parseFloat(loan, loanTemp) || loanTemp < 0)
	{
		cout << "Invalid input. Enter a positive float value." << endl;
		cout << "Enter loan amount: ";
		getline(cin, loan);
	}
	myMortgage.setLoan(loanTemp);

	cout << "Enter interest rate: ";
	getline(cin, rate);
	while (!parseFloat(rate, rateTemp) || loanTemp < 0)
	{
		cout << "Invalid input. Enter a positive float value." << endl;
		cout << "Enter interest rate: ";
		getline(cin, rate);
	}
	myMortgage.setRate(rateTemp);

	cout << "Enter years of payment: ";
	getline(cin, years);
	while (!parseInt(years, yearsTemp) || loanTemp < 0)
	{
		cout << "Invalid input. Enter a positive int value." << endl;
		cout << "Enter years of payment: ";
		getline(cin, years);
	}
	myMortgage.setYears(yearsTemp);

	cout << fixed << showpoint << setprecision(2);
	cout << "Monthly Payment: $" << setw(2) << myMortgage.getMonthlyPayment() << endl;
	cout << "Total Payment:   $" << setw(2) << myMortgage.getTotalPayment() << endl;

	return 0;
}

//======================================================
// parseInt: determine if the given input is an int value
// parameters: 
//  inputString: The provided input
//  inputInt: The location to put the input if valid
// return type: bool
//======================================================
bool parseInt(string inputString, int& inputInt)
{
	int temp; //Temporarily holds the value of the input
	bool success = true; //Whether or not the conversion worked

	try
	{
		temp = stoi(inputString);
		inputInt = temp;
	}
	catch (const std::exception&)
	{
		success = false;
	}

	return success;
}

//======================================================
// parseFloat: determine if the given input is a float value
// parameters: 
//  inputString: The provided input
//  inputFloat: The location to put the input if valid
// return type: bool
//======================================================
bool parseFloat(string inputString, float& inputFloat)
{
	float temp; //Temporarily holds the value of the input
	bool success = true; //Whether or not the conversion worked

	try
	{
		temp = stof(inputString);
		inputFloat = temp;
	}
	catch (const std::exception&)
	{
		success = false;
	}

	return success;
}