//**********************************************************************
// Author:		    Nathan Schrader
// Assignment:	  #1 - bean_count
// Date:		      June 25th, 2021
// Description:	  Calculate number of jelly beans that will fit in a jar
// Input:		      Jelly bean length, height, jar volume
// Output:		    Number of jelly beans that will fit in jar
// Sources:		    None
//**********************************************************************

#include <iostream>
using namespace std;

  const double PI = 3.14159265358979323846;  
  const double LOADFACTOR = 0.745;

int main() {
  // Initialize variables
  double volumeOfSingleBean = 0.0;
  double beanLength = 0.0;
  double beanHeight = 0.0;
  int volumeOfJar = 0;
  int beansInJar = 0;

  // Welcome message
  cout << "Welcome to my bean count program!!" 
  	   << endl;
  
  // Prompt user to input jelly bean length, height, jar size
  cout << "Enter jelly bean length (cm), jelly bean height, and jar size separated by space: "
       << endl;

  // Recieve input
  cin >> beanLength >> beanHeight >> volumeOfJar;

  // Formula for volume of single jelly bean, set value to volumeOfSingleBean
  volumeOfSingleBean = 5 * PI * beanLength * (beanHeight * beanHeight) / 24;
  
  // Formula for total beans in jar, set value equal to beansInJar
  beansInJar = (volumeOfJar * LOADFACTOR) / volumeOfSingleBean;
 
  // Output the number of beans that will fit in jar
  cout << endl << "Estimate of jelly beans in the jar: " << beansInJar 
       << endl; 
  
  //Exit
  return 0;
}