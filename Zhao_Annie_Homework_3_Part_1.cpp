// Annie Zhao
// October 19, 2024
// Homework 3, Part 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  // Variables
  char transaction; // type of transaction 
  double transAmt; // amount of money in transaction
  double total; // money in bank account 
  ifstream inData; // declare an ifstream variable
  ofstream outData; // declare an ofstream variable

  inData.open("transaction.txt"); // open the file
  outData.open("outData.txt");

  // Output the total money in the bank account 
  inData >> total;
  outData << "Your total is: $" << total << endl;

  while (!inData.eof()) {
    inData >> transaction >> transAmt;
    if (transaction == 'D') {
      outData << "Despoit of: $" << transAmt << endl;
      total += transAmt;
      outData << "Total left in account: $" << total << endl;
    }
    else if (transaction == 'W') {
      outData << "Withdrawal of: $" << transAmt << endl;
      total -= transAmt;
      outData << "Total left in account: $" << total << endl;
    }
  }

  // Total money in account at the end of transactions
  outData << "Your total balance at the end of the day is: $" << total << endl;

  // Close the files
  inData.close();
  outData.close();

  return 0;
}

//Output message
/*
Your total is: $5000
Withdrawal of: $200
Total left in account: $4800
Withdrawal of: $800
Total left in account: $4000
Withdrawal of: $40
Total left in account: $3960
Despoit of: $90
Total left in account: $4050
Despoit of: $100
Total left in account: $4150
Despoit of: $1000
Total left in account: $5150
Withdrawal of: $20
Total left in account: $5130
Your total balance at the end of the day is: $5130
*/