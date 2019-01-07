//Eric Madden
//Lab 2, Making Exact Change
//Editor used: Xcode
//Compiler used: Xcode

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;

void printid(string assignment);

int main()
{
  
  printid("Lab 2");
  
  string buf;
  double purchaseAmount, amountTendered, changeReturned;
  int hundred = 0, fifty = 0, twenty = 0, ten = 0, five = 0, one = 0, fiftyCent = 0, twentyFiveCent = 0, tenCent = 0, fiveCent = 0, oneCent = 0;
  
  cout << "Please enter the amount of your purchase $";
  cin >> buf; purchaseAmount = atof(buf.c_str());
  
  cout << "Please enter the amount tendered $";
  cin >> buf; amountTendered = atof(buf.c_str());
  
  changeReturned = amountTendered - purchaseAmount;
  
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "$" << changeReturned << endl;
  
  while (changeReturned > 99.999){
    changeReturned = changeReturned - 100;
    hundred++;
  }
  
  while (changeReturned > 49.999){
    changeReturned = changeReturned - 50;
    fifty++;
  }
  
  while (changeReturned > 19.999){
    changeReturned = changeReturned - 20;
    twenty++;
  }
  
  while (changeReturned > 9.999){
    changeReturned = changeReturned - 10;
    ten++;
  }
  
  while (changeReturned > 4.999){
    changeReturned = changeReturned - 5;
    five++;
  }
  
  while (changeReturned > 0.999){
    changeReturned = changeReturned - 1;
    one++;
  }
  
  while (changeReturned > 0.499){
    changeReturned = changeReturned - 0.50;
    fiftyCent++;
  }
  
  while (changeReturned > 0.244){
    changeReturned = changeReturned - 0.25;
    twentyFiveCent++;
  }
  
  while (changeReturned > 0.099){
    changeReturned = changeReturned - 0.1;
    tenCent++;
  }
  
  while (changeReturned > 0.049){
    changeReturned = changeReturned - 0.05;
    fiveCent++;
  }
  
  while (changeReturned > 0.009){
    changeReturned = changeReturned - 0.01;
    oneCent++;
  }
  
  if (hundred == 1)
    cout << hundred << " $100 bill" << endl;
  if (hundred > 1)
    cout << hundred << " $100 bills" << endl;
  
  if (fifty == 1)
    cout << fifty << " $50 bill" << endl;
  if (fifty > 1)
    cout << fifty << " $50 bills" << endl;
  
  if (twenty == 1)
    cout << twenty << " $20 bill" << endl;
  if (twenty > 1)
    cout << twenty << " $20 bills" << endl;
  
  if (ten == 1)
    cout << ten << " $10 bill" << endl;
  if (ten > 1)
    cout << ten << " $10 bills" << endl;
  
  if (five == 1)
    cout << five << " $5 bill" << endl;
  if (five > 1)
    cout << five << " $5 bills" << endl;
  
  if (one == 1)
    cout << one << " $1 bill" << endl;
  if (one > 1)
    cout << one << " $1 bills" << endl;
  
  if (fiftyCent == 1)
    cout << fiftyCent << " 50-cent coin" << endl;
  if (fiftyCent > 1)
    cout << fiftyCent << " 50-cent coins" << endl;
  
  if (twentyFiveCent == 1)
    cout << twentyFiveCent << " 25-cent coin" << endl;
  if (twentyFiveCent > 1)
    cout << twentyFiveCent << " 25-cent coins" << endl;
  
  if (tenCent == 1)
    cout << tenCent << " 10-cent coin" << endl;
  if (tenCent > 1)
    cout << tenCent << " 10-cent coins" << endl;
  
  if (fiveCent == 1)
    cout << fiveCent << " 5-cent coin" << endl;
  if (fiveCent > 1)
    cout << fiveCent << " 5-cent coins" << endl;
  
  if (oneCent == 1)
    cout << oneCent << " 1-cent coin" << endl;
  if (oneCent > 1)
    cout << oneCent << " 1-cent coins" << endl;
  
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
