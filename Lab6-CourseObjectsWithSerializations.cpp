//Eric Madden
//September 22, 2018
//Lab 5, Student Objects With Serializing Down
//Editor used: Xcode
//Compiler used: Xcode

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

struct Course //struct called course made up of 4 member variables
{
  string course;
  int year;
  int units;
  char grade;
};

void printid(string assignment);
Course cinOneCourse(int num);
void printHeader();
void coutAllCourses(Course array[], int num);

int main()
{
  
  printid("Lab 6");
  
  const int CAPACITY = 100;
  int size = 0;
  string buf;
  Course courseArray[CAPACITY];
  ifstream fin;
  ofstream fout;
  
  fin.open("courses.txt"); // serializes up any course objects previously entered by the user last time the program was run
  while (fin.good())
  {
    getline(fin, buf);
    if (buf == "EOF")
      break;
    courseArray[size].course = buf;
    fin >> courseArray[size].year;
    fin >> courseArray[size].units;
    fin >> courseArray[size].grade;
    fin.ignore(1000, 10);
    size++;
  }
  
  fin.close();
  
  for (int i = size; size < CAPACITY; i++) // loop allowing the user to update course information
  {
    coutAllCourses(courseArray, size); //outputs all course objects entered by the user
    cout << endl;
    
    courseArray[i] = cinOneCourse(i); //updates new course objects one course object at a time
    if (courseArray[i].course == "Q" || courseArray[i].course == "q") //quits the loop if the user no longer has course info to enter
      break;
    size++;
  }
  
  fout.open("courses.txt"); // serialize down all course objects to a file called courses.txt
  for (int i = 0; i < size; i++)
  {
    fout << courseArray[i].course << endl;
    fout << courseArray[i].year << endl;
    fout << courseArray[i].units << endl;
    fout << courseArray[i].grade << endl;
  }
  fout << "EOF" << endl;
  
  fout.close();
  
  cout << "Please press ENTER or RETURN to continue ...";
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

/*************************************************************************************
 * purpose: prompts the user to input various data for the members of a course object
 *
 * parameters:
 * num (int) the sequence number of the course object being entered
 *
 * returns: a course object at the sequence number designated by num
 *
 ****************************************************************************/
Course cinOneCourse(int num)
{
  Course holder;
  string buf;
  
  cout << "Enter the name of the course (press \'Q\' or \'q\' to quit): ";
  getline(cin, holder.course);
  if (holder.course == "Q" || holder.course == "q")
    return holder;
  cout << "Enter the year the course was taken ";
  cin >> buf; holder.year = atoi(buf.c_str());
  cout << "Enter the number of units for the course: ";
  cin >> buf; holder.units = atoi(buf.c_str());
  cout << "Enter the grade that your received for the course, (if the course is in progress please enter a \"?\"): ";
  cin >> holder.grade;
  cin.ignore(1000, 10);
  
  return holder;
}

/*************************************************************************************
 * purpose: outputs the headings for course objects to be outputted to the users screen
 *
 * parameters: none
 **************************************************************/
void printHeader()
{
  cout << "         Course Year Units Grade" << endl;
  cout << "--------------- ---- ----- -----" << endl;
}

/*************************************************************************************
 * Purpose: Prints all of the course objects that have been entered by the user
 * Parameters:
 * array (course) where the course objects have been stored
 * num (int) the size of the course array
 *
 * outputs all course object information to the users screen
 ******************************************************************/
void coutAllCourses(Course array[], int num)
{
  printHeader();
  
  for(int i = 0; i < num; i++)
  {
    cout.width(15);
    cout << array[i].course << " ";
    cout.width(4);
    cout << array[i].year << " ";
    cout.width(5);
    cout << array[i].units << " ";
    cout.width(5);
    cout << array[i].grade << " ";
    cout << endl;
  }
}