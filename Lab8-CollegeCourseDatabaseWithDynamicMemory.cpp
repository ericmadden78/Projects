//Eric Madden
//Lab 8, College Course Database With Dynamic Memory
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

#include <algorithm>
using std::swap;

#include <fstream>
using std::fstream;

#include <cstring>
#include <cctype>
#include <cstdlib>

struct CourseType //struct of course information to be entered by the user
{
  char course[12];
  int year;
  int units;
  char grade[2];
};

void printid(string assignment);
char menu(int size, int capacity);
void addCourse(CourseType *&coursesArray, int &size, int &capacity);
void printHeader();
void listCourses(CourseType *coursesArray, int size, int capacity);
void doubleArrayCapacity(CourseType *&coursesArray, int &capacity);
void arrangeByCourse(CourseType *&courseArray, int size);
void arrangeByYear(CourseType *&courseArray, int size);
void arrangeByUnits(CourseType *&courseArray, int size);
void arrangeByGrade(CourseType *&courseArray, int size);
void serializeDown(CourseType *&coursesArray, int &size, fstream &outFile);
void serializeUp(CourseType *&coursesArray, int &size, int &capacity, fstream &inFile);

int main()
{
  int size = 0;
  int capacity = 2;
  char choice = NULL;
  CourseType *coursesPtr = new CourseType[capacity]; //dynamic array of struct CourseType
  fstream fin;
  fstream fout;
  
  printid("Lab 8");
  
  serializeUp(coursesPtr, size, capacity, fin); //serialize up function
  
  while (choice != 'Q') //loop prints menu options for user until user presses 'q' or 'Q'
  {
    choice = menu(size, capacity);
    choice = toupper(choice);
    
    switch (choice) //switch calls appropriate function based on user input
    {
      case 'A':
      {
        addCourse(coursesPtr, size, capacity);
        break;
      }
      case 'L':
      {
        listCourses(coursesPtr, size, capacity);
        break;
      }
      case 'Q':
        break;
        
      case 'C':
      {
        arrangeByCourse(coursesPtr, size);
        break;
      }
        
      case 'Y':
      {
        arrangeByYear(coursesPtr, size);
        break;
      }
        
      case 'U':
      {
        arrangeByUnits(coursesPtr, size);
        break;
      }
        
      case 'G':
      {
        arrangeByGrade(coursesPtr, size);
        break;
      }
        
      default:
      {
        cout << "Invalid input. Please enter a valid choice. " << endl;
        break;
      }
    }
  }
  
  serializeDown(coursesPtr, size, fout); //serialize down function
  
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

/*********************************************************************************
 * Purpose: prints a menu of choices to the user via the output device.
 *
 * Parameters:
 * size (int) - current size of the array of struct
 * capacity (int) - current capacity of the array of struct
 *
 * Return: value called choice that the user chooses from the menu options
 ********************************************************************************/
char menu(int size, int capacity)
{
  char choice;
  cout << "Array size: " << size << ", capacity: " << capacity << endl;
  cout << "MENU" << endl;
  cout << "A Add a course" << endl;
  cout << "L List all courses" << endl;
  cout << "C Arrange by course" << endl;
  cout << "Y arrange by year" << endl;
  cout << "U arrange by units" << endl;
  cout << "G arrange by grade" << endl;
  cout << "Q quit" << endl;
  cout << "... your choice: ";
  cin >> choice;
  cout << endl;
  
  return choice;
}

/*********************************************************************************
 * Purpose: adds course information, designated by the user, to the array of struct
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value in the dynamic array of struct
 * size (int) - current size of the array of struct
 * capacity (int) - current capacity of the array of struct
 *
 * Return: stores course information in the array of struct as designated by the user
 * updates the size and capacity of the dynamic array of struct as objects are added
 * to the struct
 ********************************************************************************/
void addCourse(CourseType *&coursesArray, int &size, int &capacity)
{
  string buf;
  
  if(size == capacity)
    doubleArrayCapacity(coursesArray, capacity);
  
  cin.ignore(1000, 10);
  cout << "Enter a courses name: ";
  cin.getline(coursesArray[size].course, 20);
  cout << endl;
  for (int i = 0; coursesArray[size].course[i] != 0; i++)
    coursesArray[size].course[i] = toupper(coursesArray[size].course[i]);
  cout << "Enter the year for " << coursesArray[size].course << "[like 2016]: " << endl;
  cin >> buf; coursesArray[size].year = atoi(buf.c_str());
  cout << endl;
  cout << "Enter the units for " << coursesArray[size].course << "[0, 1, 2...]: ";
  cin >> buf; coursesArray[size].units = atoi(buf.c_str());
  cout << endl;
  cout << "Enter the grade for " << coursesArray[size].course << "[A, B... X if still in progress or planned]: ";
  cin >> coursesArray[size].grade;
  for (int i = 0; i < 2; i++)
    coursesArray[size].grade[i] = toupper(coursesArray[size].grade[i]);
  cout << endl;
  
  size++;
}

/*********************************************************************************
 * Purpose: prints the header information related to the information stored in the
 * array of struct
 *
 * Parameters:
 * none
 *
 * Return: prints header information
 ********************************************************************************/
void printHeader()
{
  cout << "      Course " << " Year " << "Units " << "Grade" << endl;
  cout << "------------ " << "----- " << "----- " << "-----" << endl;
}

/*********************************************************************************
 * Purpose: lists all of the course information stored in the array of struct
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 * capacity (int) - the current capacity of the array of struct
 *
 * Return: prints header information and prints course information stored in the
 * array of struct in nicely formatted columns
 ********************************************************************************/
void listCourses(CourseType *coursesArray, int size, int capacity)
{
  printHeader();
  
  for(int i = 0; i < size; i++)
  {
    cout.width(12);
    cout << coursesArray[i].course << " ";
    cout.width(5);
    cout << coursesArray[i].year << " ";
    cout.width(5);
    cout << coursesArray[i].units << " ";
    cout.width(5);
    cout << coursesArray[i].grade << " ";
    cout << endl;
  }
  cout << endl;
}

/*********************************************************************************
 * Purpose: doubles the capacity of the array when the size = capacity
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * capacity (int) - the current capacity of the array of struct
 *
 * Return: doubles the capacity of a dynamic array
 ********************************************************************************/
void doubleArrayCapacity(CourseType *&coursesArray, int &capacity)
{
  CourseType *temp = new CourseType[2 * capacity];
  for (int i = 0; i < capacity; i++)
    temp[i] = coursesArray[i];
  
  delete [] coursesArray;
  coursesArray = temp;
  capacity *= 2;
}

/*********************************************************************************
 * Purpose: arranges the array of struct in alphabetical order by course
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 *
 * Return: arranges the array of struct in alphabetical order by course
 ********************************************************************************/
void arrangeByCourse(CourseType *&courseArray, int size)
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
    {
      int comparison = strcmp(courseArray[i].course, courseArray[j].course);
      if (comparison > 0)
        swap(courseArray[i], courseArray[j]);
    }
}

/*********************************************************************************
 * Purpose: arranges the array of struct in order by year
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 *
 * Return: arranges the array of struct in order by year from oldest to newest
 ********************************************************************************/
void arrangeByYear(CourseType *&courseArray, int size)
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (courseArray[i].year > courseArray[j].year)
        swap(courseArray[i], courseArray[j]);
}

/*********************************************************************************
 * Purpose: arranges the array of struct in order by units
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 *
 * Return: arranges the array of struct in order by units from least to greatest
 ********************************************************************************/
void arrangeByUnits(CourseType *&courseArray, int size)
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (courseArray[i].units > courseArray[j].units)
        swap(courseArray[i], courseArray[j]);
}

/*********************************************************************************
 * Purpose: arranges the array of struct in order by grade
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 *
 * Return: arranges the array of struct in order by grade alphabetically
 ********************************************************************************/
void arrangeByGrade(CourseType *&courseArray, int size)
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
    {
      int comparison = strcmp(courseArray[i].grade, courseArray[j].grade);
      if (comparison > 0)
        swap(courseArray[i], courseArray[j]);
    }
}

/*********************************************************************************
 * Purpose: outputs dynamic array of struct in a binary file
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 * outFile (fstream) - variable used to output information to a binary file
 *
 * Return: outputs array of struct in a binary file
 ********************************************************************************/
void serializeDown(CourseType *&coursesArray, int &size, fstream &outFile)
{
  outFile.open("courses.dat", ios::binary|ios::out);
  outFile.write(reinterpret_cast<char*>(&size), sizeof(int));
  outFile.write(reinterpret_cast<char*>(coursesArray), size * sizeof(CourseType));
  outFile.close();
}

/*********************************************************************************
 * Purpose: inputs information from a binary file into an array of struct
 *
 * Parameters:
 * coursesArray (CourseType pointer) - points to the initial value stored in the
 * array of struct
 * size (int) - the current size of the array of struct
 * capacity (int) - the current capacity of the dynamic array of struct
 * inFile (fstream) - variable used to input information from a binary file
 *
 * Return: inputs information from a binary file into an array of struct
 ********************************************************************************/
void serializeUp(CourseType *&coursesArray, int &size, int &capacity, fstream &inFile)
{
  inFile.open("courses.dat", ios::binary|ios::in);
  if (inFile.good())
  {
    inFile.read(reinterpret_cast<char*>(&size), sizeof(int));
    capacity = size;
    delete [ ] coursesArray;
    coursesArray = new CourseType[capacity];
    inFile.read(reinterpret_cast<char*>(coursesArray), capacity * sizeof(CourseType));
  }
  inFile.close();
}
