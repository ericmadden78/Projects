//Eric Madden
//Print Reverse
//Editor used: Xcode
//Compiler used: Xcode

#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <cstring>

#include <string>
using std::string;

void printid(string assignment);
void printReverse(char array[]);

int main()
{
  char msg [] = "olleH";
  
  printid("Print Reverse");
  
  printReverse(msg);
  
  cout << "Press ENTER or RETURN to continue...";
  cin.ignore();
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

/********************************************************************************
 * Purpose: outputs the characters of a c string in reverse.
 *
 * Parameters:
 * array[] (char) cstring to be printed in reverse.
 *
 * Return: void function that outputs the string in reverse.
 *******************************************************************************/
void printReverse(char array[])
{
  int length = 0;
  
  for (int i = 0; *(array + i) != 0; i++)
    length++;
  
  for (length = length - 1; length >= 0; length--)
  {
    cout << *(array + length);
  }
  cout << endl;
}
