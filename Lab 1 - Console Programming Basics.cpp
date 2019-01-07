//Eric Madden
//Lab 1, Console Programming Basics
//Editor used: Xcode
//Compiler used: Xcode

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

void printid(string assignment);

int main()
{
    
  printid("Lab 1");
    
  int age, ageInTwoYrs;
  string name, city, buf;
  double tempF, tempCel;
    
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf.c_str());
  cin.ignore(1000, 10);
    
  cout << "Enter your name: ";
  getline(cin, name);
    
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; tempF = atof(buf.c_str());
  cin.ignore(1000, 10);
    
  cout << "What city are you in right now? ";
  getline(cin, city);
    
  tempCel = (tempF - 32) * (5.0/9.0);
  ageInTwoYrs = age + 2;
    
  cout << name << " is " << age << " years old now, and will be " << ageInTwoYrs << " two years from now." << endl;
  cout << "It's " << tempF << " degrees F in " << city << " -- that's ";
  cout.setf(ios::fixed);
  cout.precision(1);
  cout << tempCel << " degrees C." << endl;
    
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