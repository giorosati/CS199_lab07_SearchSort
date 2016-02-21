/*********************************************************************
** Program Filename: lab7.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-20
** Description: File with main() for CS199_400 Lab 7
*********************************************************************/

//libraries
#include <iostream>
#include <cstdlib>
#include <time.h>	//added so srand could be used with time

//header files

//usings
using std::cout;
using std::endl;
using std::cin;

//function prototypes
void binarySearch(int arr[], int size, int value);
void linearSearch(int arr[], int size, int value);
void mySort(int arr[], int size);

//main
int main()
{
	srand(time(0));	//seed random number generator
	//create two identical arrays with 1,000 ints, each position 0-999
	int arrayOne[1000];
	int arrayTwo[1000];
	for (int i = 0; i < 1000; i++)
	{
		int value = rand() % 1000;  //generates 0 to 999
		arrayOne[i] = value;
		arrayTwo[i] = value;
	}

	//compute time to perform
	//	100,000,000 linear searches using random numner 0-999
	//	Sorting and 100,000,000 binary searches using random numner 0-999
	//Display the two times to the console with clear descriptions

	int searchValue = rand() % 1000;  //generates 0 to 999
	cout << "Search value is: " << searchValue << endl;
	cin.get();

	//However the double difftime(time_t t1, time_t t0) function returns the difference t1 - t0 expressed in seconds as a double

	//linear search time trial
	void linearSearch(int arr[], int size, int value);

	//binary search time trial
	void binarySearch(int arr[], int size, int value);

	return 0;
}