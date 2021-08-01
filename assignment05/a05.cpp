#include <iostream>
#include <iomanip>

using namespace std;

const double MONTHLY_FEE = 20;
const double PERS_TRAIN_FEE = 10;
const double MEMBERSHIP_PRE_PAY_DISCOUNT = .10;
const double PERSONAL_TRAIN_DISCOUNT = .20;
const double SENIOR_DISCOUNT = .30;

double membershipCost = 0.0;
double personalTrainCost = 0.0;
double totalMembershipCost = 0.0;
double totalCost = 0;
char yesNoAnswer;
char optionsChar;
bool senior = false;
int months = 0;
int personal = 0;

void welcome();
void getInfo(bool &senior, int &months, int &personal);
void calcCost(bool senior, int months, int personal);
void printQuote();

int main()
{
  do
  {
    welcome();
    cout << "Please pick one of the following options: " << endl
         << endl;
    cout << "a. Calculate membership cost" << endl;
    cout << "b. quit this program" << endl
         << endl;
    cin >> optionsChar;
    if (optionsChar == 'b')
    {
      return 0;
    }
    getInfo(senior, months, personal);
    calcCost(senior, months, personal);
    printQuote();
  } while (optionsChar == 'a');
};

void welcome()
{
  cout << fixed << setprecision(2);
  cout << "Welcome to my fitClub program!!" << endl;
  cout << "The cost to become a member of the fitClub center is as follows:" << endl
       << endl;

  cout << "The membership fee per month is $" << MONTHLY_FEE << endl;

  cout << "The personal training session fee per session is $" << PERS_TRAIN_FEE << endl;

  cout << "If the membership is bought and paid for 12 or more months, the discount is " << MEMBERSHIP_PRE_PAY_DISCOUNT * 100 << "% off membership cost" << endl;

  cout << "If more than five personal training sessions are bought and paid for, the discount on each session is " << PERSONAL_TRAIN_DISCOUNT * 100 << "%." << endl;

  cout << "The senior citizens discount is " << SENIOR_DISCOUNT * 100 << "% off the total amount." << endl
       << endl;
};

void getInfo(bool &senior, int &months, int &personal)
{
  cout << endl;
  cout << "Are you a Senior Citizen (y|Y/n|N): ";
  cin >> yesNoAnswer;
  cout << endl;

  while (tolower(yesNoAnswer) != 'y' && tolower(yesNoAnswer) != 'n')
  {
    cout << "Invalid answer, please type 'y' for Yes or 'n' for No" << endl;
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
  // calculate membership fee
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
  // calculate personal training fee
  if (personal < 5)
  {
    totalCost += PERS_TRAIN_FEE * personal;
    personalTrainCost = PERS_TRAIN_FEE * personal;
  }
  else if (personal >= 5)
  {
    totalCost += (PERS_TRAIN_FEE * (1 - PERSONAL_TRAIN_DISCOUNT)) * personal;
    personalTrainCost = (PERS_TRAIN_FEE * (1 - PERSONAL_TRAIN_DISCOUNT)) * personal;
  }
  // Senior discount
  if (senior)
  {
    totalCost *= (1 - SENIOR_DISCOUNT);
  }
}

void printQuote()
{
  cout << "Your membership cost after the " << MEMBERSHIP_PRE_PAY_DISCOUNT * 100 << "% off is $" << membershipCost << endl
       << endl;

  cout << "Your personal training cost for " << personal << " sessions is $" << personalTrainCost << endl
       << endl;

  cout << "Your total membership cost is $" << membershipCost + personalTrainCost << "." << endl
       << endl;

  if (senior)
  {
    cout << "After your Senior discount, your membership cost is $" << totalCost << endl
         << endl;
  }

  cout << "Thank you for checking out my fitclub center!! Come back and be fit!" << endl
       << endl;
};