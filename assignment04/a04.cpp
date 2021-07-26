//**********************************************************************
// Author:		    Nathan Schrader
// Assignment:	  #04 - Jelly Bean / User Defined Functions
// Date:		      July 25th, 2021
// Description:	  Refactor Assignment03 and break logic out into separate functions
// Input:		      Jelly bean length, height, jar volume
// Output:		  //Number of jelly beans that will fit in jar
                //Total entries
                //Avg number of beans
                //Bean size for the largest jelly bean estimate
                //Jar size for the largest jelly bean estimate
// Sources:		    None
//**********************************************************************

#include <iostream>
using namespace std;

  const double PI = 3.14159265358979323846;
  const double LOADFACTOR = 0.745;
  
  int entries = 0;
  int totalBeans = 0;
  int volumeOfJar = 0;

  double beanLength = 0.0;
  double beanHeight = 0.0;
  double volumeOfSingleBean = 0.0;

  void greeting();
  void doLoop(double volumeOfSingleBean);
  double calcJBVolume(double beanLength, double beanHeight);
  int numBeansInJar(int volumeOfJar, double volumeOfSingleBean);

int main() {
  greeting();
  doLoop(volumeOfSingleBean);

  return 0;
}

void greeting() {
	cout << "Welcome to my Jelly Bean estimate program!!" << endl;
	cout << endl;
};

double calcJBVolume(double beanLength, double beanHeight) {
	volumeOfSingleBean = 5 * PI * beanLength * (beanHeight * beanHeight) / 24;

	return volumeOfSingleBean;
}

int numBeansInJar(int volumeOfJar, double volumeOfSingleBean) {
	int beansInJar = 0;
	
	beansInJar = (volumeOfJar * LOADFACTOR) / volumeOfSingleBean;

	return beansInJar;
}

void doLoop(double volumeOfSingleBean) {
  double lgBeanLength = 0;
  double lgBeanHeight = 0;
	int lgVolumeJar = 0;
	int mostBeans = 0;
	float avgBeans = 0.0;

	cout << "Enter jelly bean length (cm), jelly bean height, and jar size separated by space: " 
       << endl;

  cin >> beanLength >> beanHeight >> volumeOfJar;
  volumeOfSingleBean = calcJBVolume(beanLength, beanHeight);

  do {
  cout << "Estimate of jelly beans in the jar: " 
       << numBeansInJar(volumeOfJar,volumeOfSingleBean) 
       << endl
       << endl;

	entries += 1;
	totalBeans += numBeansInJar(volumeOfJar, volumeOfSingleBean);
	
	if (numBeansInJar(volumeOfJar, volumeOfSingleBean) > mostBeans) {
		mostBeans = numBeansInJar(volumeOfJar, volumeOfSingleBean);
		lgBeanHeight = beanHeight;
		lgBeanLength = beanLength;
	}
	if (volumeOfJar > lgVolumeJar) {
		lgVolumeJar = volumeOfJar;
	}
    cout << "Enter jelly bean length (cm), jelly bean height, and jar size separated by space: ";
    cin >> beanLength >> beanHeight >> volumeOfJar;
	  volumeOfSingleBean = calcJBVolume(beanLength, beanHeight);
  } while (beanLength != 0 && beanHeight != 0 && volumeOfJar !=0);

  avgBeans = totalBeans / entries;

  cout << endl;
  cout << "Total number of entries: " << entries << endl;
  cout << "Average number of beans: " << avgBeans << endl;
  cout << "Bean size for the largest jelly bean estimate: "
       << lgBeanLength << " cm" << " and " << lgBeanHeight
       << " cm" << endl;
  cout << "Jar size for the largest jelly bean estimate: "
       << lgVolumeJar << " ml" << endl;
  cout << "Thank you for using my program." << endl;
}