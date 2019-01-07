//Eric Madden
//October 2, 2018
//Lab 7, Track Expenses Using Array
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
#include <cctype>

struct ExpenseType
{
  double amount;
  string description;
};

void printid(string);
int menu();
void showAll(ExpenseType array[], int size);
void spend(ExpenseType array[], int &size);
void searchString(ExpenseType array[], int size);
void searchAmount(ExpenseType array[], int size);
string toLowerCase(string aCppString);

int main()
{
  printid ("Lab 7");
  int num = NULL;
  const int CAPACITY = 100;
  int size = 0;
  ExpenseType expenses[CAPACITY];
  string search = "";
  
  while (num != 5) /* Loop that continues to output the menu function and then calls an additional function based on user input. Loop continues until the user presses menu item 5 to exit */
  {
    num = menu();
    
    if (num == 5)
      break;
    
    if (num == 1)
      showAll(expenses, size);
    
    if (num == 2)
      spend (expenses, size);
    
    if (num == 3)
      searchString(expenses, size);
    
    if (num == 4)
      searchAmount(expenses, size);
  }
  
  cin.ignore(1000, 10);
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

/****************************************************************
 * Purpose: Prints a menu to the users screen allowing them to choose from 5 different options.
 *
 * Parameters: none
 *
 * Return: Returns an integer value for the menu item that the user selected.
 ****************************************************************/
int menu()
{
  int num;
  string buf;
  do {
    cout << "Welcome to my expense tracker. " << endl;
    cout << "   1. show all " << endl;
    cout << "   2. spend " << endl;
    cout << "   3. search expenses containing this string " << endl;
    cout << "   4. search expenses with greater than or equal to this amount " << endl;
    cout << "   5. exit " << endl;
    cout << "Enter your option: ";
    cin >> buf; num = atoi(buf.c_str());
    cout << endl;
    if (num < 1 || num > 5)
    {
      cout << "Please enter a valid option." << endl;
      cout << endl;
    }
  } while (num > 5 || num < 1);
  
  return num;
}

/****************************************************************
 * Purpose: Prints all expenses that have been entered include the amount of the expense and the
 * description
 *
 * Parameters:
 * array (ExpenseType) - array that stores expenses and their amount
 * size (int) - the size of the array
 *
 * Return: Void function does not return. Outputs the expense description and associated amount.
 ****************************************************************/
void showAll(ExpenseType array[], int size)
{
  if (size == 0)
  {
    cout << "There is no expense entry available." << endl;
    cout << endl;
  }
  else
  {
    cout << "Expenses: " << endl;
    for (int i = 0; i < size; i++){
      cout << "AMOUNT(" << array[i].amount << ") DESC(" << array[i].description << ")" << endl;
    }
    cout << endl;
  }
}

/****************************************************************
 * Purpose: Allows the user to input expenses and associated amounts into an array.
 *
 * Parameters:
 * array (ExpenseType) - Array that stores expense descriptions and associated amounts.
 * size (int) - size of the array.
 *
 * Return: Void function does not return value. Stores expense description and associated amount
 * in an array.
 ****************************************************************/
void spend(ExpenseType array[], int &size)
{
  string buf;
  
  cin.ignore(1000, 10);
  cout << "Please enter the description for the expense: ";
  getline(cin, array[size].description);
  while (array[size].description == "")
  {
    cout << "Invalid entry. Description must contain characters." << endl;
    cout << "Please enter the description: ";
    getline(cin,array[size].description);
  }
  
  cout << "Please enter the amount of the expense: ";
  cin >> buf; array[size].amount = atof(buf.c_str());
  while (array[size].amount <= 0)
  {
    if (array[size].amount <= 0)
    {
      cout << "Invalid amount. Amount cannot be negative or string. Please try it again. " << endl;
      cout << "Please enter the amount: ";
      cin >> buf; array[size].amount = atof(buf.c_str());
    }
  }
  
  cout << "AMOUNT(" << array[size].amount << ") DESC(" << array[size].description << ")" << endl;
  cout << endl;
  size++;
}

/****************************************************************
 * Purpose: Allows the user to search through inputted expense descriptions for any expense that
 * contains the array entered by the user. The search is not case sensitive.
 *
 * Parameters:
 * array (ExpenseType) - Array that stores expense descriptions and associated amounts.
 * size (int) - size of the array.
 *
 * Return: Outputs any expense description and amount for any expense description that contains the
 * string entered by the user.
 ****************************************************************/
void searchString(ExpenseType array[], int size)
{
  string holder;
  int length = 0;
  int position = 0;
  string word = "";
  
  cout << "Please enter the search string: ";
  cin >> word;
  cout << endl;
  
  for (int i = 0; i < size; i++)
  {
    length = word.length();
    holder = toLowerCase(array[i].description);
    word = toLowerCase(word);
    position = holder.find(word);
    if (position != string::npos)
      cout << "AMOUNT(" << array[i].amount << ") " << "DESC(" << array[i].description << ")" << endl;
  }
  cout << endl;
}

/****************************************************************
 * Purpose: Allows the user to search for expenses that are equal to or greater than a value entered
 * by the user.
 *
 * Parameters:
 * array (ExpenseType) - Array that stores the description and amount of an expense.
 * size (int) - The size of the array.
 *
 * Return: Outputs any expense description and assoicated amount that has an amount value equal to
 * or greater than the value entered by the user.
 ****************************************************************/
void searchAmount(ExpenseType array[], int size)
{
  double amount = 0;
  string buf;
  
  cout << "Please enter the amount: ";
  cin >> buf; amount = atof(buf.c_str());
  
  for (int i = 0; i < size; i++)
  {
    if (array[i].amount > amount - 0.001)
    {
      cout << "AMOUNT(" << array[i].amount << ") DESC(" << array[i].description << ")" << endl;
    }
  }
  cout << endl;
}

/****************************************************************
 * Purpose: Converts all of the characters in a string to lowercase letters.
 *
 * Parameters:
 * aCppString (string) - String variable or text entered by the user.
 *
 * Return: Returns a string value with every character lowercase.
 ****************************************************************/
string toLowerCase(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; i++)
    aCppString[i] = tolower(aCppString[i]);
  
  return aCppString;
}
