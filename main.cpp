//Program finds the total rainfall, average monthly rainfall,
//highest temp and the lowest temp then finds the average monthly temp
//In a 12 month period

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

//Structure declaration
struct Information
{
    int rainfall;
    int highTemp;
    int lowTemp;
};

// Prototypes
void getInfo(Information info[]);
void sortHighTemp(Information info[]);
void sortLowTemp(Information info[]);
int findHighestHighTemp(Information info[]);
int findLowestLowTemp(Information info[]);
int highBinarySearch (Information info2[], int LENGTH, int value);
int lowBinarySearch (Information info2[], int LENGTH, int value);

int main()
{
  cout << "Enter the following information.\n";

  const int LENGTH = 4;
  Information info[LENGTH];
  Information info2[LENGTH];



  //Copy of the hightemp and lowtemp to use for the month latter in the code.


  getInfo(info);                                        //getInfo call

  for (int index = 0; index < LENGTH; index++)
  info2[index] = info[index];


  sortHighTemp(info);                                    //sort highTemp Call
  sortLowTemp(info);                                     //sort lowTemp Call
  int highHighest = findHighestHighTemp(info);          //stores highest temp value into highest variable
  int lowLowest = findLowestLowTemp(info);              // stores lowest temp value into lowest variable


  // get the sum of total rainfall
  double total = 0;
  for (int count = 0; count < LENGTH; count++)
    total += info[count].rainfall;

  cout << "\n";
  cout << "Total Rainfall: " << total << endl;

  //gets the average rainfall
  double rainAverage;
  rainAverage = total / LENGTH;

  cout << fixed << showpoint << setprecision(2);

  cout << "Average Monthly Rain: " << rainAverage << endl;

  //finds the highest temperature
  int highest;

     highest = highHighest;


  int monthHigh = highBinarySearch (info2, LENGTH, highest);
  monthHigh = monthHigh + 1;


  cout << "The Highest Temperature: " << highest;
  cout << "     (Month " << monthHigh << ")\n";

  //finds the lowest temperature
  int lowest;

    lowest = lowLowest;

  int monthLow = lowBinarySearch (info2, LENGTH, lowest);
  monthLow = monthLow + 1;


  cout << "The Lowest Temperature: "  << lowest;
  cout << "     (Month " << monthLow << ")\n";

  cout << fixed << showpoint << setprecision(2);

  // finds the average temperature
  double tempAverage = (highest + lowest)/ 2;


  cout << "Average Monthly Average Temperature: ";
  cout << tempAverage;
  cout << "\n";





  return 0;

}

//Obtains the weather information
void getInfo(Information info[])
{
     for (int i = 0; i < 12; i++)
    {
        cout << "\n";
        cout << "Month " << (i + 1) << ":\n";
        cout << "Total Rainfall: ";
        cin >> info[i].rainfall;

        cout << "Highest Temperature: ";
        cin >> info[i].highTemp;


        if (info[i].highTemp >= -100 && info[i].highTemp <= 140)
        {
         cout << "Lowest Temperature: ";
         cin >> info[i].lowTemp;

            if (info[i].lowTemp >= -100 && info[i].lowTemp <= 140)
            {

            }
            else
            {

            do
            {
            cout << "Invalid Entry: Temperature must ";
            cout << "be between -100 and +140 degrees ";
            cout << "Fahrenheit.\n";
            cout << "Please reenter: ";
            cin >> info[i].lowTemp;
            }
            while(info[i].lowTemp < -100 || info[i].lowTemp > 140);
            }

        }
        else
        {
            do
            {
            cout << "Invalid Entry: Temperature must ";
            cout << "be between -100 and +140 degrees ";
            cout << "Fahrenheit.\n";
            cout << "Please reenter: ";
            cin >> info[i].highTemp;
            }
            while(info[i].highTemp < -100 || info[i].highTemp > 140);

            cout << "Lowest Temperature: ";
            cin >> info[i].lowTemp;

            if (info[i].lowTemp >= -100 && info[i].lowTemp <= 140)
            {

            }
            else
            {

            do
            {
            cout << "Invalid Entry: Temperature must ";
            cout << "be between -100 and +140 degrees ";
            cout << "Fahrenheit.\n";
            cout << "Please reenter: ";
            cin >> info[i].lowTemp;
            }
            while(info[i].lowTemp < -100 || info[i].lowTemp > 140);

            }



        }
    }
}

//stores the highest temp values
void sortHighTemp(Information info[])
{
int minIndex, minValue;
int const LENGTH = 12;

    for (int start = 0; start < (LENGTH - 1); start++)
    {
	minIndex = start;
    minValue = info[start].highTemp;
    for (int index = start + 1; index < LENGTH; index++)
    {
        if (info[index].highTemp < minValue)
        {
		minValue = info[index].highTemp;
		minIndex = index;
        }
    }
    swap (info[minIndex].highTemp, info[start].highTemp);
    }

}

//sorts the lowest temp values
void sortLowTemp(Information info[])
{
int minIndex, minValue;
int const LENGTH = 12;

    for (int start = 0; start < (LENGTH - 1); start++)
    {
	minIndex = start;
    minValue = info[start].lowTemp;
    for (int index = start + 1; index < LENGTH; index++)
    {
        if (info[index].lowTemp < minValue)
        {
		minValue = info[index].lowTemp;
		minIndex = index;
        }
    }
    swap (info[minIndex].lowTemp, info[start].lowTemp);
    }
}

//finds the histest temp value
int findHighestHighTemp(Information info[])
{
const int SIZE = 12;

int i;
int highest;

highest = info[0].highTemp;
for (i = 1; i < SIZE; i++)
{
    if (info[i].highTemp > highest)
    highest = info[i].highTemp;
}
return highest;
}

//finds the lowest temp value
int findLowestLowTemp(Information info[])
{
const int SIZE = 12;

int i;
int lowest;

lowest = info[0].lowTemp;
for (i = 1; i < SIZE; i++)
{
    if (info[i].lowTemp < lowest)
    lowest = info[i].lowTemp;
}
return lowest;
}

//Binary search to find the high temp value
int highBinarySearch (Information info2[], int LENGTH, int value)
{
  int first = 0,			//first array element
      last = LENGTH  - 1, 	//last array element
      middle,			//midpoint of search
      position = - 1;		//position of search value
    bool found = false;		//flag

        while (!found && first <= last)
        {
            middle = (first + last) / 2;		//calculate midpoint
        if   (info2[middle].highTemp == value)		//if value is found at mid
        {
		found = true;
		position = middle;
        }
        else if (info2[middle].highTemp > value)		//if value is in lower half
            last = middle - 1;
        else
            first = middle + 1;		//if value is in upper half
}
return position;
}

//binary search to find the low temp value
int lowBinarySearch (Information info2[], int LENGTH, int value)
{
  int first = 0,			//first array element
      last = LENGTH  - 1, 	//last array element
      middle,			//midpoint of search
      position = - 1;		//position of search value
    bool found = false;		//flag

        while (!found && first <= last)
        {
            middle = (first + last) / 2;		//calculate midpoint
        if   (info2[middle].lowTemp == value)		//if value is found at mid
        {
		found = true;
		position = middle;
        }
        else if (info2[middle].lowTemp > value)		//if value is in lower half
            last = middle - 1;
        else
            first = middle + 1;		//if value is in upper half
}
return position;
}


