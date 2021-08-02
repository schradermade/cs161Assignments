#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

void welcome();
void getInfo(bool &senior, int &months, int &personal);
void calcCost(bool senior, int months, int personal);

int main()
{

  bool senior = false;
  int months = 0;
  int personal = 0;

  char optionsChar = 'y';

  do
  {
    welcome();
    cout << "Please pick one of the following options: " << endl
         << endl;
    cout << "        a. Calculate membership cost" << endl;
    cout << "        b. quit this program" << endl
         << endl;
    cin >> optionsChar;
    if (optionsChar == 'b')
    {
      cout << "Thank you for checking out my fitClub center!!  Come back and be fit!" << endl;
      return 0;
    }
    getInfo(senior, months, personal);
    calcCost(senior, months, personal);
  } while (optionsChar == 'a');
};

void welcome()
{
  cout << fixed << setprecision(2);
  cout << "Welcome to my fitClub program!!" << endl;
  cout << "The cost to become a member of the fitClub center is as follows:" << endl
       << endl;

  cout << "\u2022 The membership fee per month is $20.00" << endl;

  cout << "\u2022 The personal training session fee per session is $10.00" << endl;

  cout << "\u2022 If the membership is bought and paid for 12 or more months, the discount is 10% off membership cost" << endl;

  cout << "\u2022 If more than five personal training sessions are bought and paid for, the discount on each session is 20%" << endl;

  cout << "\u2022 The senior citizens discount is 30% off the total amount." << endl
       << endl;
};

void getInfo(bool &senior, int &months, int &personal)
{
  char yesNoAnswer;

  cout << endl;

  cout << "Are you a Senior Citizen (y|Y/n|N): ";
  cin >> yesNoAnswer;

  cout << endl;

  while (tolower(yesNoAnswer) != 'y' && tolower(yesNoAnswer) != 'n')
  {
    cout << "Invalid input: '" << yesNoAnswer << "'" << endl;
    cout << "Please respond with one these options -> (y|Y/n|N): ";
    cin >> yesNoAnswer;
  }

  switch (yesNoAnswer)
  {
  case 'y':
    senior = true;
    break;
  case 'n':
    senior = false;
    break;
  default:
    break;
  };

  cout << "How many months of membership would you like? ";
  cin >> months;
  cout << endl;

  cout << "How many personal training sessions would you like? ";
  cin >> personal;
  cout << endl;
};

void calcCost(bool senior, int months, int personal)
{
  const double MEMBERSHIP_PRE_PAY_DISCOUNT = .10;
  const double MONTHLY_FEE = 20;
  const double PERSONAL_TRAIN_FEE = 10;
  const double PERSONAL_TRAIN_DISCOUNT = .20;
  const double SENIOR_DISCOUNT = .30;

  double membershipCost = 0.0;
  double persTrainTotal = 0.0;
  double totalMembershipCost = 0.0;
  double totalCost = 0;

  // calculate membership total
  if (months < 12)
  {
    totalCost += MONTHLY_FEE * months;
    membershipCost = MONTHLY_FEE * months;
  }
  else if (months >= 12)
  {
    totalCost += (MONTHLY_FEE * (1 - MEMBERSHIP_PRE_PAY_DISCOUNT)) * months;
    membershipCost = (MONTHLY_FEE * (1 - MEMBERSHIP_PRE_PAY_DISCOUNT)) * months;
  }
  // calculate personal training total
  if (personal < 5)
  {
    totalCost += PERSONAL_TRAIN_FEE * personal;
    persTrainTotal = PERSONAL_TRAIN_FEE * personal;
  }
  else if (personal >= 5)
  {
    totalCost += (PERSONAL_TRAIN_FEE * (1 - PERSONAL_TRAIN_DISCOUNT)) * personal;
    persTrainTotal = (PERSONAL_TRAIN_FEE * (1 - PERSONAL_TRAIN_DISCOUNT)) * personal;
  }
  // Senior discount bool
  if (senior)
  {
    totalCost *= (1 - SENIOR_DISCOUNT);
  }

  cout << "\e[1m"
       << "Your membership cost after the 10% off is $" << membershipCost 
       << "\e[0m" 
       << endl << endl;

  cout << "\e[1m"
       << "Your personal training cost for " << personal << " sessions is $" << persTrainTotal 
       << "\e[0m" 
       << endl << endl;

  cout << "\e[1m"
       << "Your total membership cost is $" << totalCost << "."
       << "\e[0m" 
       << endl << endl;

  if (senior)
  {
    cout << "\e[1m"
         << "After your Senior discount, your membership cost is $" << totalCost 
         << "\e[0m" 
         << endl << endl;
  }

  cout << "\e[1m"
       << "Thank you for checking out my fitclub center!! Come back and be fit!"
       << "\e[0m" 
       << endl << endl;
};