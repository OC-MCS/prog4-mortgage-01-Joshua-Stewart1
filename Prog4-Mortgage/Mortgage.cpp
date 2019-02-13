// implementation file for Mortgage class

#include <cmath>
using namespace std;
#include "Mortgage.h"

//Default Constructor
Mortgage::Mortgage()
{
	loan = 0.0;
	rate = 0.0;
	years = 0;
}

//======================================================
// setLoan: sets the value of loan to loanAmount
// parameters: 
//  loanAmount: the amount of the loan
// return type: void
//======================================================
void Mortgage::setLoan(float loanAmount)
{
	loan = loanAmount;
}

//======================================================
// setRate: sets the value of rate to interestRate
// parameters: 
//  interestRate: the annual interest rate
// return type: void
//======================================================
void Mortgage::setRate(float interestRate)
{
	rate = interestRate;
}

//======================================================
// setYears: sets the value of years to yearsOnLoan
// parameters: 
//  yearsOnLoan: the number of years of the loan
// return type: void
//======================================================
void Mortgage::setYears(int yearsOnLoan)
{
	years = yearsOnLoan;
}

//======================================================
// getTerm: finds the value of the term for payment calculations
// parameters: none
// return type: float
//======================================================
float Mortgage::getTerm()
{
	return pow(1 + (rate / 12), 12 * years);
}

//======================================================
// getMonthlyPayment: calculates the total payed each month
// parameters: none
// return type: float
//======================================================
float Mortgage::getMonthlyPayment()
{
	return (loan * (rate / 12) * getTerm()) / (getTerm() - 1);
}

//======================================================
// getTotalPayment: calculates the total payed on the loan
// parameters: none
// return type: float
//======================================================
float Mortgage::getTotalPayment()
{
	return getMonthlyPayment() * 12 * years;
}