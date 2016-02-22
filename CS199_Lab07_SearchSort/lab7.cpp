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
#include <sstream>
#include <time.h>	//added so srand could be used with time

//header files

//usings
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::string;
//using std::to_string;

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

	cout << "Enter number of searches to perform in the time trial and press enter to start. " << endl;
	cin >> searches;

	//format searches number with commas
	/*string searchesCommas = to_string(searches);
	int insertPosition = searchesCommas.length() - 3;
	while (insertPosition > 0)
	{
		searchesCommas.insert(insertPosition, ",");
		insertPosition -= 3;
	}*/

	cout << endl;
	cout << "Program now running:" << endl;
	//cout << searchesCommas << " linear searches and " << endl;
	//cout << searchesCommas << " binary searches." << endl;
	cout << searches << " linear searches and " << endl;
	cout << searches << " binary searches." << endl;
	cout << endl;
	cout << "When the searches have completed, the time required for each will be shown." << endl;
	cout << "Be patient if you entered more than 2,000,000 searches..." << endl;
	cout << endl;

	//linear searches
	double linearTimeStart = time(0);
	for (int i = 1; i < searches; i++)
	{
		int searchValue = rand() % size;  //generates 0 to 999
		linearSearch(arrayOne, size, searchValue);
	}
	double linearTimeEnd = time(0);
	double timeElapsed = linearTimeEnd - linearTimeStart;
	cout << searches << " linear searches took " << timeElapsed << " seconds." << endl;
	cout << endl;
	cin.ignore();

	//binary searches
	double binaryTimeStart = time(0);
	//step one is to sort the array
	mySort(arrayOne, size);

	//step two, binary searches
	for (int i = 1; i < searches; i++)
	{
		int searchValue = rand() % size;  //generates 0 to 999
		binarySearch(arrayOne, size, searchValue);
	}
	double binaryTimeEnd = time(0);
	double timeElapsed2 = binaryTimeEnd - binaryTimeStart;
	cout << searches << " binary searches took " << timeElapsed2 << " seconds." << endl;
	//cin.ignore();
	cin.get();

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

bool binarySearch(int arr[], int size, int searchValue)
{
	int first = 0;
	int last = size - 1;
	int middle;
	int position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (arr[middle] == searchValue)
		{
			found = true;
			position = middle;
			return found;
		}
		else if (arr[middle] > searchValue)
			last = middle - 1;
		else
		{
			first = middle + 1;
		}
	}
	return found;
}

void mySort(int arr[], int size)
{
	int temp;			//bubble sort adapted from textbook page 618
	bool swap;
	do
	{
		swap = false;
		for (unsigned count = 0; count < size - 1; count++)
		{
			if (arr[count] > arr[count + 1])
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}