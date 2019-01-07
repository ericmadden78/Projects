//Eric Madden
//September 22, 2018
//Lab 2A, Making Exact Change Using Functions
//Editor used: Xcode
//Compiler used: Xcode

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;

#include <cstdlib>

void printid(string assignment);
void changeToReturn(double change, double denomination, string billOrCoin);
double updateChangeReturned (double change, double denomination);

int main()
{
  
  printid("Lab 2A");
  
  string buf;
  double purchaseAmount, amountTendered, changeReturned;
  
  cout << "Please enter the amount of your purchase $";
  cin >> buf; purchaseAmount = atof(buf.c_str()); //inputs the purchase cost and converts it to a float
  
  cout << "Please enter the amount tendered $";
  cin >> buf; amountTendered = atof(buf.c_str()); /*inputs the amount received from the customer and converts it to a float */
  
  changeReturned = amountTendered - purchaseAmount; /*calculates the amount of change to be returned to the customer */
  
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "$" << changeReturned << endl;
  
  changeToReturn(changeReturned, 100.00, "100");
  changeReturned = updateChangeReturned(changeReturned, 100.00);
  
  changeToReturn(changeReturned, 50.00, "50");
  changeReturned = updateChangeReturned(changeReturned, 50.00);
  
  changeToReturn(changeReturned, 20.00, "20");
  changeReturned = updateChangeReturned(changeReturned, 20.00);
  
  changeToReturn(changeReturned, 10.00, "10");
  changeReturned = updateChangeReturned(changeReturned, 10.00);
  
  changeToReturn(changeReturned, 5.00, "5");
  changeReturned = updateChangeReturned(changeReturned, 5.00);
  
  changeToReturn(changeReturned, 1.00, "1");
  changeReturned = updateChangeReturned(changeReturned, 1.00);
  
  changeToReturn(changeReturned, 0.50, "50-cent");
  changeReturned = updateChangeReturned(changeReturned, 0.50);
  
  changeToReturn(changeReturned, 0.25, "25-cent");
  changeReturned = updateChangeReturned(changeReturned, 0.25);
  
  changeToReturn(changeReturned, 0.10, "10-cent");
  changeReturned = updateChangeReturned(changeReturned, 0.10);
  
  changeToReturn(changeReturned, 0.05, "5-cent");
  changeReturned = updateChangeReturned(changeReturned, 0.05);
  
  changeToReturn(changeReturned, 0.01, "1-cent");
  changeReturned = updateChangeReturned(changeReturned, 0.01);
  
  cout << "Press ENTER or RETURN to continue...";
  cin.get();
  
  return 0;
}

void printid(string assignment)
{
  cout << "Eric Madden\n";
  cout << assignment << endl;
  cout << "Editor used: Xcode\n";
  cout << "Compiler used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}

/* This function counts the number of bills or coins that need to be returned to the customer. Once these figures have been counted the fuction will cout the number of bills or coins to be returned to the customer including the denomination of the bill
 */
void changeToReturn(double change, double denomination, string billOrCoin)
{
  int numOfBillsOrCoins = 0;
  while (change > denomination - 0.001){
    change = change - denomination;
    numOfBillsOrCoins++;
  }
  
  if (denomination >= 1.00)
  {
    if (numOfBillsOrCoins == 1)
      cout << numOfBillsOrCoins << " $" << billOrCoin << " bill" << endl;
    if (numOfBillsOrCoins > 1)
      cout << numOfBillsOrCoins << " $" << billOrCoin << " bills" << endl;
  }
  else
  {
    if (numOfBillsOrCoins == 1)
      cout << numOfBillsOrCoins << " " << billOrCoin << " coin" << endl;
    if (numOfBillsOrCoins > 1)
      cout << numOfBillsOrCoins << " " << billOrCoin << " coins" << endl;
  }
}

/* updates the value of change to be returned to the customer to account for change already returned to the customer */
double updateChangeReturned (double change, double denomination)
{
  while (change > denomination - 0.001){
    change = change - denomination;
  }
  return change;
}