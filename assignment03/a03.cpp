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
  double lgBeanLength = 0;
  double lgBeanHeight = 0;

  int volumeOfJar = 0;
  int lgVolumeJar = 0;

  int beansInJar = 0;
  int entries = 0;
  int totalBeans = 0;
  int mostBeans = 0;
  float avgBeans = 0.0;

  // Welcome message
  cout << "Welcome to my Jelly Bean estimate program!!" << endl;
  cout << endl;
  cout << "Enter jelly bean length (cm), jelly bean height, and jar size separated by space: "
        << endl;

  // Recieve input
  cin >> beanLength >> beanHeight >> volumeOfJar;
  
  do {
    // Formula for volume of single jelly bean, set value to volumeOfSingleBean
    volumeOfSingleBean = 5 * PI * beanLength * (beanHeight * beanHeight) / 24;
    
    // Formula for total beans in jar, set value equal to beansInJar
    beansInJar = (volumeOfJar * LOADFACTOR) / volumeOfSingleBean;
  
    // Output the number of beans that will fit in jar
    cout << "Estimate of jelly beans in the jar: " << beansInJar << endl;
	cout << endl;
	
	entries = entries + 1;
	totalBeans = totalBeans + beansInJar;
	
	if (beansInJar > mostBeans) {
		mostBeans = beansInJar;
		lgBeanHeight = beanHeight;
		lgBeanLength = beanLength;
	}
	if (volumeOfJar > lgVolumeJar) {
		lgVolumeJar = volumeOfJar;
	}

	// Prompt user to input jelly bean length, height, jar size
    cout << "Enter jelly bean length (cm), jelly bean height, and jar size separated by space: ";      
    cin >> beanLength >> beanHeight >> volumeOfJar;

  } while (beanLength != 0 && beanHeight != 0 && volumeOfJar !=0);

  avgBeans = totalBeans / entries;

  cout << endl;

  cout << "Total number of entries: " << entries << endl;
  cout << "Average number of beans: " << avgBeans << endl;
  cout << "Bean size for the largest jelly bean estimate: " << lgBeanLength << " cm" << " and " << lgBeanHeight << " cm" << endl;
  cout << "Jar size for the largest jelly bean estimate: " << lgVolumeJar << " ml" << endl;
  cout << "Thank you for using my program." << endl;
  
  //Exit
  return 0;
}