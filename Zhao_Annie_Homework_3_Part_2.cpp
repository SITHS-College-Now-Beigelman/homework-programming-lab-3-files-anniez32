// Annie Zhao
// October 20, 2024
// Homework 3, Part 2

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main () {
  // Variables
  char transaction; // type of transaction 
  double transAmt; // amount of money in transaction
  double transD=0; // total times deposited
  double transW=0; // total times withdrawn
  double transDAmt=0;  // total amount despoisted
  double transWAmt=0; // total amount withdrawn
  double total; // money in bank account
  ifstream inData; // declare an ifstream variable
  ofstream outData; // declare an ofstream variable

  inData.open("transaction.txt"); // open the file
  outData.open("outData.txt");

  // Output the total money in the bank account 
  inData >> total;
  outData << "Your total balance at the beginning of the day was: $" << total << endl;

  outData << "Transaction history: " << endl;
  outData << setfill('.');  // fill empty spaces with '.'
  outData << "Transaction" << setw(30) << "Amount" << setw(30) << "Balance" << endl;
  
  // Loop
  while (!inData.eof()) {
    inData >> transaction >> transAmt;
    if (transaction == 'D') {
      total += transAmt;
      transD++;
      transDAmt += transAmt;
      outData << "Despoit" << setw(33) << transAmt << setw(30) << total << endl;
    }
    else if (transaction == 'W') {
      total -= transAmt;
      transW ++;
      transWAmt += transAmt;
      outData << "Withdrawal" << setw(30) << transAmt << setw(30) << total << endl;
    }
  }

  // Output transaction history 
  outData << "Your total balance at the end of the day is: $" << total << endl;
  outData << "Money was desposited " << transD << " times for a total amount of $" << transDAmt << endl;
  outData << "Money was withdrawn " << transW << " times for a total amount of $" << transWAmt << endl;
  
  // Close the files
  inData.close();
  outData.close();

  return 0;
}
//Output message
/*
Your total balance at the beginning of the day was: $5000
Transaction history: 
Transaction........................Amount.......................Balance
Withdrawal...........................200..........................4800
Withdrawal...........................800..........................4000
Withdrawal............................40..........................3960
Despoit...............................90..........................4050
Despoit..............................100..........................4150
Despoit.............................1000..........................5150
Withdrawal............................20..........................5130
Despoit..............................200..........................5330
Despoit.............................5170.........................10500
Withdrawal...........................200.........................10300
Your total balance at the end of the day is: $10300
Money was desposited 5 times for a total amount of $6560
Money was withdrawn 5 times for a total amount of $1260
*/