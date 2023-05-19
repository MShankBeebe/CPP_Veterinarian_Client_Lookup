#include<iostream>
#include<cstdlib>
#include<string>
#include "PetFamily.h"
#include "Pet.h"

Pet::Pet(int &masterIdNumber, string fName, string lName, string phone, string pName, char species, string breed, int age, bool tOrF): PetFamily(masterIdNumber, fName, lName, phone)
{
	petName = pName;
	petSpecies = species;
	petBreed = breed;
	petAge = age;
	isAlive = tOrF;
}

Pet::Pet() : PetFamily()
{
	petName = "";
	petSpecies = 'o';
	petBreed = "";
	petAge = 0;
	isAlive = false;
}

Pet::~Pet() 
{

}

void Pet::setPetInfo(int &masterIdNumber, string fName, string lName, string phone, string petName, char species, string breed, int age, bool tOrF)
{
	petName = petName;
	petSpecies = species;
	petBreed = breed;
	petAge = age;
	isAlive = tOrF;
}

void Pet::print()
{
	PetFamily::print();
	cout << "Pet Name: " << petName << endl;

	if (petSpecies == 'd')
	{
		cout << "Species: Dog" << endl;
	}
	else if (petSpecies == 'c')
	{
		cout << "Species: Cat" << endl;
	}
	else if (petSpecies == 'b')
	{
		cout << "Species: Bird" << endl;
	}
	else if (petSpecies == 'r')
	{
		cout << "Species: Reptile" << endl;
	}
	else if (petSpecies == 's')
	{
		cout << "Species: Small Mammal" << endl;
	}
	else if (petSpecies == 'h')
	{
		cout << "Species: Horse" << endl;
	}
	else
	{
		cout << "Species: Other" << endl;
	}

	cout << "Breed: " << petBreed << endl;
	cout << "Pet age: " << petAge << " years" << endl;

	if (isAlive == true)
	{
		cout << "Current Patient" << endl;
	}
	else
		cout << "Former Patient" << endl;
}

const Pet& Pet::operator=(const Pet& petToCopy)
{
	idnumber = petToCopy.idnumber;
	firstname = petToCopy.firstname;
	lastname = petToCopy.lastname;
	phonenumber = petToCopy.phonenumber;
	petName = petToCopy.petName;
	petSpecies = petToCopy.petSpecies;
	petBreed = petToCopy.petBreed;
	petAge = petToCopy.petAge;
	isAlive = petToCopy.isAlive;

	return *this;
}

void Pet::printList(Pet petArray[])
{
	for (int i = 0; i < 50; i++)
	{
		if (petArray[i].getId() != 0)
		{
			petArray[i].print();
			cout << endl << endl;
		}
	}
}

void Pet::swap(Pet list[], int first, int second)
{
	Pet temp;

	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

int Pet::partition(Pet list[], int first, int  last)
{
	Pet pivot;
	int smallindex;

	swap(list, first, (first + last) / 2);

	pivot = list[first];
	smallindex = first;

	for (int index = first + 1; index <= last; index++)
		if (list[index].idnumber < pivot.idnumber)
		{
			smallindex++;
			swap(list, smallindex, index);
		}
	swap(list, first, smallindex);

	return smallindex;
}

void Pet::recQuickSortID(Pet list[], int first, int last)
{
	int pivotLocation;
	if (first < last)
	{
		pivotLocation = partition(list, first, last);
		recQuickSortID(list, first, pivotLocation - 1);
		recQuickSortID(list, pivotLocation + 1, last);
	}
}

void Pet::quickSortID(Pet list[], int length)
{
	recQuickSortID(list, 0, length - 1);
}


int Pet::binarySearch(Pet list[], int idNum)
{
	quickSortID(list, 50);
	int start = 0;
	int finish = 49;
	int mid;

	bool found = false;

	while (start <= finish && !found)
	{
		mid = (start + finish) / 2;
		if (list[mid].idnumber == idNum)
		{
			found = true;
		}
		else if (list[mid].idnumber > idNum)
		{
			finish = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	if (found)
		return mid;
	else
		return -1;
}

//overloading []
//int& Pet::operator[](int index)
//{
//
//}

//make a constructor for an array?