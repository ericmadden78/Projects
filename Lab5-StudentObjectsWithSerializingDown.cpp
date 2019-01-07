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

#include <cstdlib>

#include <fstream>
using std::ifstream;
using std::ofstream;

struct studentType
{
  string name;
  int age;
  double gpa;
  string major;
  int studentID;
};

void printid(string assignment);
studentType assignStudent (studentType anyStudent);
void printHeader();
void printStudent(studentType anyStudent);
void serializeDown(studentType anyStudent, ofstream& outFile);

int main()
{
  printid("Lab 5");
  
  studentType student1 = {};
  studentType student2 = {};
  studentType student3 = {};
  ofstream fout;
  
  //asking the user to provide the information for 3 different studentType variables
  student1 = assignStudent(student1);
  cout << endl;
  student2 = assignStudent(student2);
  cout << endl;
  student3 = assignStudent(student3);
  cout << endl;
  
  printHeader(); //prints the header
  printStudent(student1); //next 3 lines print the contents of 3 studentType variables
  printStudent(student2);
  printStudent(student3);
  
  fout.open("students.txt"); //opens file for serializing down
  serializeDown(student1, fout); //stores the contents of 3 studentType variables in specified file
  serializeDown(student2, fout);
  serializeDown(student3, fout);
  fout.close();
  
  cout << "Please press ENTER or RETURN to continue...";
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

//prompts the user to provide input to fill in the contents of a studentType variable/
//these contents are stored in a specific studentType variable.
studentType assignStudent (studentType anyStudent)
{
  string buf;
  
  cout << "Enter the name of the student: ";
  getline(cin, anyStudent.name);
  
  cout << "Enter " << anyStudent.name << "'s age: ";
  cin >> buf; anyStudent.age = atoi(buf.c_str());
  cin.ignore(1000, 10);
  
  cout << "Enter " << anyStudent.name << "'s GPA: ";
  cin >> buf; anyStudent.gpa = atof(buf.c_str());
  cin.ignore(1000, 10);
  
  cout << "Enter " << anyStudent.name << "'s current major: ";
  getline(cin, anyStudent.major);
  
  cout << "Enter " << anyStudent.name << "'s student ID: ";
  cin >> buf; anyStudent.studentID = atoi(buf.c_str());
  cin.ignore(1000, 10);
  
  return anyStudent;
}

//prints the header for a studentType variable
void printHeader()
{
  cout << "                Name  Age   GPA                Major   Student ID" << endl;
  cout << "-------------------- ---- ----- -------------------- ------------" << endl;
}

//prints the contents of a studentType variable;
void printStudent(studentType anyStudent)
{
  cout.width(20);
  cout << anyStudent.name << " ";
  cout.width(4);
  cout << anyStudent.age << " ";
  cout.setf(ios::fixed);
  cout.precision(2);
  cout.width(5);
  cout << anyStudent.gpa << " ";
  cout.unsetf(ios::fixed);
  cout.width(20);
  cout << anyStudent.major << " ";
  cout.width(12);
  cout << anyStudent.studentID << " " << endl;
}

//stores a variable of type studentType into a specified outFile
void serializeDown(studentType anyStudent, ofstream& outFile)
{
  outFile << anyStudent.name << endl;
  outFile << anyStudent.age << endl;
  outFile << anyStudent.gpa << endl;
  outFile << anyStudent.major << endl;
  outFile << anyStudent.studentID << endl;
}