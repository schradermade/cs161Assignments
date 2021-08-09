#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
   ifstream inFS; // Input file stream
   string dayOfWeek;
   string city = "Los Angeles";
   int count = 0;

   int highTemp = 0;
   int lowTemp = 0;

   int totalHighTemps = 0;
   int totalLowTemps = 0;

   double avgHighTemp = 0;
   double avgLowTemp = 0;

   int hottestTemp = 0;
   int coolestTemp;
   string hottestDay;
   string coolestDay;

   double totalRain = 0;
   double avgPercChanceRain = 0.0;
   double percChanceRain = 0.0;

   // Open file
   cout << "Opening file laweather.txt." << endl;
   inFS.open("laweather.txt");

   if (!inFS.is_open())
   {
      cout << "Could not open file laweather.txt." << endl;
      return 1;
   }

   cout << "Weather report for " << city << endl
        << endl;

   while (!inFS.eof())
   {
      inFS >> dayOfWeek >> highTemp >> lowTemp >> percChanceRain;
      if (!inFS.fail())
      {
         count += 1;
         if (count == 1)
         {
            cout << "Here is your 7 day Forecast: " << endl;
            coolestTemp = lowTemp;
            coolestDay = dayOfWeek;
         }
         totalLowTemps += lowTemp;
         totalHighTemps += highTemp;
         totalRain += percChanceRain;

         if (highTemp >= hottestTemp)
         {
            hottestTemp = highTemp;
            hottestDay = dayOfWeek;
         }
         if (lowTemp < coolestTemp)
         {
            coolestTemp = lowTemp;
            coolestDay = dayOfWeek;
         }

         cout << dayOfWeek << " "
              << highTemp << " "
              << lowTemp << " "
              << percChanceRain
              << endl;
      }
   }

   if (inFS.eof())
   {
      cout << endl;
      avgHighTemp = totalHighTemps / count;
      cout << "The average High temperature for the week is "
           << avgHighTemp << " degrees."
           << endl;

      cout << endl;

      avgLowTemp = totalLowTemps / count;
      cout << "The average Low temperature for the week is "
           << avgLowTemp << " degrees."
           << endl;

      cout << endl;

      avgPercChanceRain = totalRain / count;
      cout << "The average rain fall per day, in inches will be "
           << fixed << setprecision(2)
           << avgPercChanceRain << "\"."
           << endl;

      cout << endl;

      cout << "The hottest day of the week will be "
           << hottestDay << " with a high of " << hottestTemp
           << " degrees."
           << endl;

      cout << endl;

      cout << "The coolest day of the week will be "
           << coolestDay << " with a low of " << coolestTemp
           << " degrees."
           << endl;

      cout << endl;

      cout << "Have fun in the sun!" << endl;
   }

   // Done with file, so close it
   inFS.close();

   return 0;
}