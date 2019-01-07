//Eric Madden
//Lab 11, Artificial Intelligence With Innate Knowledge
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

#include <fstream>
using std::ifstream;
using std::ofstream;

struct NFLteam{
  string saythis;
  NFLteam *yes;
  NFLteam *no;
};

void printid(string assignment);
void serializeDown (ofstream &fout, NFLteam *p);

int main()
{
  printid("Lab 11");
  
  ofstream fout;
  ifstream fin;
  
  NFLteam a = {"The team is the San Francisco 49ers."};
  NFLteam b = {"The team is the Seattle Seahawks."};
  NFLteam c = {"The team is the Green Bay Packers."};
  NFLteam d = {"The team is the Chicago Bears."};
  NFLteam e = {"The team is the Oakland Raiders."};
  NFLteam f = {"The team is the Los Angeles Chargers"};
  NFLteam g = {"The team is the Pittsburg Steelers."};
  NFLteam h = {"The team is the Baltimore Ravens."};
  
  NFLteam i = {"Are the teams colors red and gold?", &a, &b};
  NFLteam j = {"Does the team play at Soldier Field?", &d, &c};
  NFLteam k = {"Is the team planning to move to Las Vegas?", &e, &f};
  NFLteam l = {"Is the team mascot the same as the title of a poem by Edgar Allen Poe?", &h, &g};
  NFLteam m = {"Is the team in the NFC West?", &i, &j};
  NFLteam n = {"Is the team in the AFC North?", &l, &k};
  NFLteam o = {"Is the team in the NFC?", &m, &n};
  
  NFLteam *top = &o;
  
  NFLteam *p = top;
  
  while (true)
  {
    cout << p->saythis;
    if (p->yes == 0 && p->no == 0) break;
    cout << " [yes/no] ";
    
    string buf;
    getline(cin, buf);
    
    if (buf[0] == 'y' || buf[0] == 'Y') p = p->yes;
    else if (buf[0] == 'N' || buf[0] == 'n') p = p->no;
    else
      cout << "Invalid answer. Please enter an appropriate response. " << endl;
  }
  cout << endl << endl;
  
  fout.open("ai.txt");
  serializeDown(fout, top);
  fout.close();
  
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

void serializeDown (ofstream &fout, NFLteam *p)
{
  if (p == 0)
    fout << "EOF" << endl;
  else
  {
    fout << p->saythis << endl;
    serializeDown(fout, p->yes);
    serializeDown(fout, p->no);
  }
}
