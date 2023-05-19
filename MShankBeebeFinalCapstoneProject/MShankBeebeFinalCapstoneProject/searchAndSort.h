#pragma once
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pet.h"

using namespace std;

class searchAndSort
{
	int getClientID(string phone);
	//after the main validates that the phone number is correct, 
	//this function  converts it to a number and uses the quicksort
	//function to sort it and then a  to find the number
	//once it has found the number, it will return the id number

	void quickSortPhone(Pet &petArray);
	//quick sort function for the list by phone number

	int binarySort(int num, Pet &petArray);
	//to find phone number, returns the client id number

	//overloading []
	int& operator[](int index);


};

