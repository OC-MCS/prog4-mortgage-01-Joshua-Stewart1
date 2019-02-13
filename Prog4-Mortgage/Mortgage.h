#pragma once
// header file for Mortgage class

class Mortgage
{
private:
	float loan; //The dollar amount of the loan
	float rate; //The annual interest rate
	int years; //The number of years of the loan
	float getTerm();
public:
	Mortgage();
	void setLoan(float loanAmount);
	void setRate(float interestRate);
	void setYears(int yearsOnLoan);
	float getMonthlyPayment();
	float getTotalPayment();
};