/*********************************************************************
** Program Filename: lab7.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-20
** Description: File with main() for CS199_400 Lab 7
*********************************************************************/

//libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <time.h>	//added so srand could be used with time

//header files

//usings
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::string;
using std::to_string;

//function prototypes
bool binarySearch(int arr[], int size, int searchValue);
bool linearSearch(int arr[], int size, int searchValue);
void mySort(int arr[], int size);
const int size = 1000;

//main
int main()
{
	srand(time(0));	//seed random number generator
	int searches = 0;
	//create two identical arrays with 1,000 ints, each position has random value of 0-999
	int arrayOne[size];
	int arrayTwo[size];
	for (int i = 0; i < size; i++)
	{
		int value = rand() % size;  //generates 0 to 999
		arrayOne[i] = value;
		arrayTwo[i] = value;
	}

	//compute time to perform
	//	100,000,000 linear searches using random numner 0-999
	//	Sorting and 100,000,000 binary searches using random numner 0-999
	//Display the two times to the console with clear descriptions

	//int searchValue = rand() % 1000;  //generates 0 to 999
	//cout << "Search value is: " << searchValue << endl;
	//cin.get();

	//However the double difftime(time_t t1, time_t t0) function returns the difference t1 - t0 expressed in seconds as a double

	//linear search time trial
	cout << "Beginning linear search time trial." << endl;
	cout << "enter number of searches to perform in the time trial and press enter to start. " << endl;
	cin >> searches;

	double linearTimeStart = time(0);
	for (int i = 1; i < searches; i++)
	{
		int searchValue = rand() % 1000;  //generates 0 to 999
		linearSearch(arrayOne, size, searchValue);
	}
	double linearTimeEnd = time(0);
	double timeElapsed = linearTimeEnd - linearTimeStart;
	cout << "Completed linear search time trial." << endl;

	string searchesCommas = to_string(searches);
	int insertPosition = searchesCommas.length() - 3;
	while (insertPosition > 0)
	{
		searchesCommas.insert(insertPosition, ",");
		insertPosition -= 3;
	}

	cout << "Seconds to complete " <<  searchesCommas << " linear searches was: " << timeElapsed << endl;
	cin.ignore();
	cin.get();

	//binary search time trial





	//void binarySearch(int arr[], int size, int value);

	return 0;
}

bool linearSearch(int arr[], int size, int searchValue)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == searchValue)
		{
			return true;
		}
	}
	return false;
}

bool linearSearch(int arr[], int size, int searchValue) 
{
	//step one is to sort the array
	mySort(arr, size);
	//step two, binary search


}

void mySort(int arr[], int size);
{


}