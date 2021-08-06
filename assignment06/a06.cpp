/*This is the starter file for assignment 06.  It creates 2 parallel arrays for names and scores of students.
It populates data into the Parallel Arrays using a function.
It prints the data from the Parallel Arrays using a function.
You need to add a function that will insert a new name and score into the arrays at a given position. */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//constants
const int CAP = 20;

//function prototypes
void readData(string names[], double scores[], int &size);
void printData(string names[], double scores[], int size);
void insertData(string names[], double scores[], int &size);

//your function prototype goes here.

//main
int main()
{
  string names[CAP];
  double scores[CAP] = {0};
  int size = 0;

  //call the readData function
  readData(names, scores, size);
  //print the data
  printData(names, scores, size);
  //Your function call to insert goes here.
  //insert data
  insertData(names, scores, size);
  //Then call the print function again to print the list.
  printData(names, scores, size);
  return 0;
}

//description:	just populates the array.
//params:		string array, double array, int size
//return:		none
//output:		none
void readData(string names[], double scores[], int &size)
{
  names[0] = "Amy Goyal";
  scores[0] = 95.4;
  names[1] = "Priya Sekar";
  scores[1] = 95.5;
  names[2] = "Rama Noel";
  scores[2] = 78.6;
  size = 3;
}

void insertData(string names[], double scores[], int &size)
{
  string name = "";
  double score = 0;
  int position = 0;

  cout << "Name: ";
  cin >> name;

  cout << "Score: ";
  cin >> score;

  cout << "Position: ";
  cin >> position;

  cout << endl;
  //insert name into names[]
  for (int i = size; i >= position; i--)
  {
    names[i + 1] = names[i];
  }
  names[position] = name;
  //insert score into scores[]
  for (int i = size; i >= position; i--)
  {
    scores[i + 1] = scores[i];
  }
  scores[position] = score;
  //increment size count
  size += 1;
}

//description:	prints data to the user.
//params:		string array, double array, int size
//return:		none
//output:		array contents
void printData(string names[], double scores[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << setw(20) << left << names[i] << setw(10) << scores[i] << endl;
  }
  cout << endl;
}
