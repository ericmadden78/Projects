//Eric Madden
//Lab 10, Queue Data Structure
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
using std::ifstream;
using std::ofstream;

#include <cstring>
#include <cctype>
#include <cstdlib>

struct MovieType{ //MovieType struct that stores movie objects
  string name;
  int year;
  int rating;
  MovieType *next;
};

void printid(string assignment);
char menu();
void addMovie(MovieType *&firstMovie, MovieType *&lastMovie);
void printHeader();
void listMovies(MovieType *firstMovie);
void updateMovie(MovieType *&firstMovie);
void removeMovie(MovieType *&firstMovie, MovieType *&lastMovie);
string uppercase(string word);
void arrangeTitle(MovieType *&firstMovie);
void arrangeYear(MovieType *&firstMovie);
void arrangeRating(MovieType *&firstMovie);
void serializeDown(MovieType *firstMovie, ofstream &fout);
void serializeUp(MovieType *&firstMovie, MovieType *&lastMovie, ifstream &fin);

int main()
{
  printid("Lab 10");
  
  MovieType *firstMovie = 0; //points to the first MovieType object
  MovieType *lastMovie = 0; //points to the last MovieType object
  char choice = 0;
  ifstream fin;
  ofstream fout;
  
  serializeUp(firstMovie, lastMovie, fin);
  
  while (choice != 'Q') //while loop that allows the user to perform various commands based on their input. The loop exits once the user chooses 'Q' or 'q'
  {
    choice = menu();
    choice = toupper(choice);
    
    switch (choice) //switch statement that calls the appropriate function based on the users input from the menu function
    {
      case 'A':
      {
        addMovie(firstMovie, lastMovie);
        break;
      }
      case 'U':
      {
        updateMovie(firstMovie);
        break;
      }
      case 'E':
      {
        removeMovie(firstMovie, lastMovie);
        break;
      }
      case 'L':
      {
        listMovies(firstMovie);
        break;
      }
      case 'T':
      {
        arrangeTitle(firstMovie);
        break;
      }
      case 'V':
      {
        arrangeYear(firstMovie);
        break;
      }
      case 'R':
      {
        arrangeRating(firstMovie);
        break;
      }
      case 'Q':
        break;
      default:
      {
        cout << "Please enter a valid choice." << endl; //outputs message if the user chooses an option not listed on the menu
        cout << endl;
        break;
      }
    }
  }
  
  serializeDown(firstMovie, fout);
  
  while (firstMovie) //deletes all nodes before the program exits to avoid memory leaks
  {
    MovieType *p = firstMovie;
    firstMovie = firstMovie->next;
    delete p;
  }
  
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

/**************************************************************************
 * Purpose: Outputs the menu of options on the users screen
 *
 * Parameters:
 * None
 *
 * Return: char value that the user choses from the menu of options
 *************************************************************************/
char menu()
{
  char choice;
  
  cout << "MENU" << endl;
  cout << "A Add a movie" << endl;
  cout << "U Update a movie" << endl;
  cout << "E rEmove a movie" << endl;
  cout << "L List all movies" << endl;
  cout << "T arrange by Title" << endl;
  cout << "V arrange by year Viewed" << endl;
  cout << "R arrange by Rating" << endl;
  cout << "Q Quit" << endl;
  cout << "...your choice: ";
  cin >> choice;
  cout << endl;
  
  return choice;
}

/**************************************************************************
 * Purpose: Allows the user to add movies to their list
 *
 * Parameters:
 * firstMovie pointer (MovieType) - the first object in our linked list
 * lastMovie pointer (MovieType) - the last object in our linked list
 *
 * Return: void function that adds a MovieType object to the users linked list
 * of movies
 *************************************************************************/
void addMovie(MovieType *&firstMovie, MovieType *&lastMovie)
{
  string buf;
  
  cin.ignore(1000, 10);
  cout << "Enter a movie's title: ";
  getline(cin, buf);
  
  MovieType *temp = new MovieType;
  temp->name = buf;
  
  cout << "Enter the year you saw " << temp->name << " [like 2016]: ";
  cin >> buf; temp->year = atoi(buf.c_str());
  
  cout << "Enter your rating for " << temp->name << " [1, 2, 3, 4, 5]: ";
  cin >> buf; temp->rating = atoi(buf.c_str());
  
  cin.ignore(1000, 10);
  
  temp->next = 0;
  if (lastMovie) lastMovie->next = temp;
  else firstMovie = temp;
  lastMovie = temp;
}

/**************************************************************************
 * Purpose: prints the header for all of the attributes stored in the linked
 * list
 *
 * Parameters:
 * None
 *
 * Return: void function that outputs header to the users screen
 *************************************************************************/
void printHeader()
{
  cout << " # Title                                              Viewed Rating " << endl;
  cout << "__ __________________________________________________ ______ ______ " << endl;
}

/**************************************************************************
 * Purpose: outputs the MovieType objects to the users screen in a format
 * designated by the header function.
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the users
 * linked list
 *
 * Return: outputs all MovieType objects in a specific format to the users screen
 *************************************************************************/
void listMovies(MovieType *firstMovie)
{
  printHeader();
  int index(0);
  MovieType *p;
  
  for (p = firstMovie, index = 1; p; p = p->next, index++)
  {
    cout.width(2);
    cout << index << " ";
    cout.width(50);
    cout.setf(ios::left);
    cout << p->name << " ";
    cout.unsetf(ios::left);
    cout.width(6);
    cout << p->year << " ";
    cout.width(6);
    cout << p->rating << " " << endl;
  }
  cout << endl;
}

/**************************************************************************
 * Purpose: Allows the user to update movie attributes designated by an index
 * number
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 *
 * Return: void function that stores the udated MovieType attributes, in the
 * linked list, at the index designated by the user
 *************************************************************************/
void updateMovie(MovieType *&firstMovie)
{
  MovieType *p;
  int index = 0;
  int numberOfNodes = 0;
  int initialIndex = 0;
  int i = 1;
  string buf;
  if (firstMovie != 0)
    initialIndex = 1;
  for (p = firstMovie; p; p = p->next, numberOfNodes++);
  
  if (!initialIndex)
  {
    cout << "No movies to update. Please add a movie to your list. " << endl;
    cout << endl;
  }
  
  if (initialIndex)
  {
    if (initialIndex == numberOfNodes)
    {
      cout << "...which movie to update (" << initialIndex << ")? ";
      cin >> buf; index = atoi(buf.c_str());
      cin.ignore(1000, 10);
      cout << endl;
    }
    
    else
    {
      cout << "...which movie to update (" << initialIndex << "-" << numberOfNodes << ")? ";
      cin >> buf; index = atoi(buf.c_str());
      cin.ignore(1000, 10);
      cout << endl;
    }
    
    for (p = firstMovie; p; p = p->next, i++)
      if (i == index)
        break;
    
    cout << "Please update the name of this movie: ";
    getline(cin, p->name);
    
    cout << "Please update the year you saw " << p->name << ": ";
    cin >> buf; p->year = atoi(buf.c_str());
    
    cout << "Please update the rating for " << p->name << ": ";
    cin >> buf; p->rating = atoi(buf.c_str());
    cout << endl;
  }
}

/**************************************************************************
 * Purpose: Allows the user to remove MovieType objects, from the list,
 * designated by the index number the user enters
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 * lastMovie pointer (MovieType) - the last object in our linked list
 *
 * Return: void function that removes the user designated MovieType object
 * from the linked list
 *************************************************************************/
void removeMovie(MovieType *&firstMovie, MovieType *&lastMovie)
{
  MovieType *p;
  MovieType *prev;
  int index = 0;
  int numberOfNodes = 0;
  int initialIndex = 0;
  int i = 1;
  string buf;
  if (firstMovie != 0)
    initialIndex = 1;
  for (p = firstMovie; p; p = p->next, numberOfNodes++);
  
  if (!initialIndex)
  {
    cout << "No movies to remove. Please add a movie to your list. " << endl;
    cout << endl;
  }
  
  if (initialIndex)
  {
    if (initialIndex == numberOfNodes)
    {
      cout << "...which movie to remove (" << initialIndex << ")? ";
      cin >> buf; index = atoi(buf.c_str());
      cin.ignore(1000, 10);
      cout << endl;
    }
    
    else
    {
      cout << "...which movie to remove (" << initialIndex << "-" << numberOfNodes << ")? ";
      cin >> buf; index = atoi(buf.c_str());
      cin.ignore(1000, 10);
      cout << endl;
    }
    
    for (p = firstMovie, prev = 0; p; prev = p, p = p->next, i++)
      if (i == index)
        break;
    
    if (p)
    {
      if (prev)
        prev->next = p->next;
      else
        firstMovie = p->next;
      delete p;
      if (p == lastMovie) lastMovie = prev;
    }
    else
      cout << "Movie not found. " << endl;
  }
}

/**************************************************************************
 * Purpose: to return a c++ string variable with every letter uppercase
 *
 * Parameters:
 * word (string) - the word that is going to be returned in an uppercase format
 *
 * Return: string variable that is entered as the parameter in an uppercase
 * format
 *************************************************************************/
string uppercase(string word)
{
  int length = word.length();
  
  for (int i = 0; i < length; i++)
    word[i] = toupper(word[i]);
  return word;
}

/**************************************************************************
 * Purpose: Arranges the users list of movies in alphabetical order
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 *
 * Return: void function that sorts the users list of movies in alphabetical
 * order by name
 *************************************************************************/
void arrangeTitle(MovieType *&firstMovie)
{
  for (MovieType *p = firstMovie; p; p = p->next)
    for (MovieType *q = p->next; q; q = q->next)
      if (uppercase(p->name) > uppercase(q->name))
      {
        swap(*p, *q);
        swap(p->next, q->next);
      }
}

/**************************************************************************
 * Purpose: Sorts the users list of movies by the year the movie was seen
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 *
 * Return: void function that sorts the linked list by year the movie was
 * viewed from most recent to oldest
 *************************************************************************/
void arrangeYear(MovieType *&firstMovie)
{
  for (MovieType *p = firstMovie; p; p = p->next)
    for (MovieType *q = p->next; q; q = q->next)
      if (p->year < q->year)
      {
        swap(*p, *q);
        swap(p->next, q->next);
      }
}

/**************************************************************************
 * Purpose: Sorts the users list of movies by how the user rated the movie
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 *
 * Return: void function that sorts the linked list by rating from high to low.
 * The highest rated movies are rated 5 and the lowest rated are 1.
 *************************************************************************/
void arrangeRating(MovieType *&firstMovie)
{
  for (MovieType *p = firstMovie; p; p = p->next)
    for (MovieType *q = p->next; q; q = q->next)
      if (p->rating < q->rating)
      {
        swap(*p, *q);
        swap(p->next, q->next);
      }
}

/**************************************************************************
 * Purpose: Stores the users list of movies in a text file
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 * fout (ofstream) - output variable used to write information to the text file
 *
 * Return: void function that outputs MovieType objects to a text file, attribute
 * by attribute
 *************************************************************************/
void serializeDown(MovieType *firstMovie, ofstream &fout)
{
  fout.open("movies.txt");
  for (MovieType *p = firstMovie; p; p = p->next)
  {
    fout << p->name << endl;
    fout << p->year << endl;
    fout << p->rating << endl;
  }
  fout << "EOF" << endl;
  fout.close();
}

/**************************************************************************
 * Purpose: Reads the users movie list from a text file and stores it in a
 * linked list
 *
 * Parameters:
 * firstMovie pointer (MovieType) - points to the first object in the linked list
 * lastMovie pointer (MovieType) - the last object in our linked list
 * fin (ifstream) - input variable used to read information from a text file
 *
 * Return: void function that inputs MovieType objects from a text file, attribute
 * by attribute, into a linked list
 *************************************************************************/
void serializeUp(MovieType *&firstMovie, MovieType *&lastMovie, ifstream &fin)
{
  fin.open("movies.txt");
  while (fin.good())
  {
    string buf;
    getline(fin, buf);
    if (buf == "EOF")
      break;
    
    MovieType *temp = new MovieType;
    temp->name = buf;
    fin >> temp->year; fin.ignore(1000, 10);
    fin >> temp->rating; fin.ignore(1000, 10);
    
    temp->next = 0;
    if (lastMovie)
      lastMovie->next = temp;
    else
      firstMovie = temp;
    lastMovie = temp;
  }
  fin.close();
}
