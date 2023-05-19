// MShankBeebeFinalCapstoneProject.cpp 
// Final Project for Megan Shank Beebe, Computer Science 2
//A veterinary scheduling program.
//12/10/2022

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cstdlib>
#include "PetFamily.h"
#include "Pet.h"


using namespace std;

//global variables
int masterIdNumber = 1;
int testNum = 49;
int petListIndex = 28;
const int petListIndexMax = 50;

//menu function declarations
int mainMenuSelection(Pet petList[]);


//checking phone number
bool checkPhoneNumber(string phone);


//try catch class declarations
class mainMenuInvalidSelection {};

//hard-coded pets for testing, creating them with constructors and then copying them into our master list
Pet pet0 = Pet(testNum, "Steve", "Harrington", "5555555555", "Fluffy", 'c', "Domestic Shorthair", 2, true);
Pet pet1 = Pet(masterIdNumber, "Max", "Mayfield", "4444444444", "Sparky", 'd', "Greyhound", 5, true);
Pet pet2 = Pet(masterIdNumber, "Billy", "Hargrove", "8888888888", "Bert", 'r', "Python", 1, true);
Pet pet3 = Pet(masterIdNumber, "Robin", "Buckley", "1111111111", "Pickles", 'h', "Mustang", 7, true);
Pet pet4 = Pet(masterIdNumber, "Nancy", "Wheeler", "4444444444", "Tweety", 'b', "Domestic Shorthair", 2, false);
Pet pet5 = Pet(masterIdNumber, "Lucas", "Sinclair", "9999999999", "Cookie", 's', "Hamster", 5, false);
Pet pet6 = Pet(masterIdNumber, "Eddie", "Munson", "9999999999", "Max", 'd', "Labradore", 7, true);
Pet pet7 = Pet(masterIdNumber, "Mike", "Wheeler", "9999999999", "Sprinkles", 'c', "Tabby", 5, false);
Pet pet8 = Pet(masterIdNumber, "Dustin", "Henderson", "9999999999", "Rover", 'd', "Labradoodle", 3, true);
Pet pet9 = Pet(masterIdNumber, "Will", "Byers", "9999999999", "Champion", 'h', "Mustang", 24, true);
Pet pet10 = Pet(masterIdNumber, "Jim", "Hopper", "9999999999", "Ralph", 'r', "snake", 2, true);
Pet pet11 = Pet(masterIdNumber, "Erica", "Sinclair", "9999999999", "Archibald", 'b', "Parrot", 5, true);
Pet pet12 = Pet(masterIdNumber, "Jonathan", "Byers", "9999999999", "Sam", 'o', "Tarantula", 1, true);
Pet pet13 = Pet(masterIdNumber, "Joyce", "Byers", "9999999999", "Mittens", 'c', "Calico", 9, true);
Pet pet14 = Pet(masterIdNumber, "Martin", "Brenner", "9999999999", "Spot", 'd', "Dalmation", 6, true);
Pet pet15 = Pet(masterIdNumber, "Heather", "Holloway", "9999999999", "Mr. Whiskers", 'c', "Domestic Longhair", 5, true);
Pet pet16 = Pet(masterIdNumber, "Victor", "Creel", "9999999999", "Count", 'o', "Bat", 1, true);
Pet pet17 = Pet(masterIdNumber, "Kali", "Prasad", "9999999999", "Cheddar", 's', "Mouse", 2, true);
Pet pet18 = Pet(masterIdNumber, "Sam", "Owens", "9999999999", "Fluffy", 's', "Hamster", 1, true);
Pet pet19 = Pet(masterIdNumber, "Fred", "Benson", "9999999999", "Hammy", 's', "Hamster", 1, true);
Pet pet20 = Pet(masterIdNumber, "Becky", "Ives", "9999999999", "Hamtaro", 's', "Hamster", 5, false);
Pet pet21 = Pet(masterIdNumber, "Tom", "Holloway", "9999999999", "Nell", 'h', "Appaloosa", 10, true);
Pet pet22 = Pet(masterIdNumber, "Ted", "Wheeler", "9999999999", "Crackers", 's', "Hamster", 7, false);
Pet pet23 = Pet(masterIdNumber, "Terry", "Ives", "9999999999", "Sammy", 'd', "Golden Retreiver", 2, true);
Pet pet24 = Pet(masterIdNumber, "Ell", "Wheeler", "9999999999", "Patches", 'c', "Calico", 5, true);
Pet pet25 = Pet(masterIdNumber, "Larry", "Kline", "9999999999", "Bart", 's', "Ferret", 2, true);
Pet pet26 = Pet(masterIdNumber, "Bob", "Newby", "9999999999", "Billy", 'o', "Goat", 2, true);
Pet pet27 = Pet(masterIdNumber, "Barb", "Holland", "9999999999", "Tinkerbell", 's', "Ferret", 2, true);

//main program
int main()
{
	//global variables
	int mainSelection = 0;

	//our master list of clients
	Pet petList[petListIndexMax];
	Pet* pointerList = petList;

	//adding hard coded pets for testing
	petList[0] = pet0;
	petList[1] = pet1;
	petList[2] = pet2;
	petList[3] = pet3;
	petList[4] = pet4;
	petList[5] = pet5;
	petList[6] = pet6;
	petList[7] = pet7;
	petList[8] = pet8;
	petList[9] = pet9;
	petList[10] = pet10;
	petList[11] = pet11;
	petList[12] = pet12;
	petList[13] = pet13;
	petList[14] = pet14;
	petList[15] = pet15;
	petList[16] = pet16;
	petList[17] = pet17;
	petList[18] = pet18;
	petList[19] = pet19;
	petList[20] = pet20;
	petList[21] = pet21;
	petList[22] = pet22;
	petList[23] = pet23;
	petList[24] = pet24;
	petList[25] = pet25;
	petList[26] = pet26;
	petList[27] = pet27;
	
	//to print the list
	//pList->printList(pList);




	//main menu loop
	while (mainSelection != 6)
	{
		bool mainDone = false;
		do {
			try {
				mainSelection = mainMenuSelection(pointerList);

				if (mainSelection == 0)
					throw mainMenuInvalidSelection();
				mainDone = true;
			}

			catch (mainMenuInvalidSelection)
			{
				cout << "Invalid menu selection, please try again." << endl;
			}
			catch (...)
			{
				cout << "Invalid menu selection, please try again.";
			}
		} while (!mainDone);
	}
	return 0;
}

//menu function definitions

//displays main menu text and returns a selection
int mainMenuSelection(Pet pList[])
{
	string userInput;
	int selection;

	cout << endl << "------------- Furry Friends Veterinary Hospital Scheduler -------------" << endl;
	cout << endl;
	cout << "Please make a selection from the following options (enter the number that corresponds with your choice):                        " << endl;
	cout << endl;
	cout << endl;
	cout << "1. Create Client" << endl;
	cout << "2. Update Pet Status (Current Or Not)" << endl;
	cout << "3. Find Client By ID Number" << endl;
	cout << "4. Print Client List" << endl;
	cout << "6. Exit Program" << endl;

	//cin >> selection;
	cin >> userInput;



	bool test;
	test = isalpha(userInput[0]);

	if (userInput.length() != 1)
	{
		return 0;
	}
	else if (test == true)
	{
		return 0;
	}
	else if (userInput.empty() == true)
	{
		return 0;
	}
	else
	{
		selection = stoi(userInput);
	}
	

	if (selection == 1)
	{
		if (petListIndex == petListIndexMax) {
			cout << "List full, unable to add client.  Please delete a client.";
			return selection;
		}
		string first;
		string last;
		string phone;
		string petName;
		char species;
		string breed;
		int age;
		char yesOrNo;
		bool isAlive;
		bool correctSpecies = false;
		string ageAttempt;
		bool correctAge = false;
		bool correctAnswer = false;
		bool done = false;
		char saveAnswer;
		
		cout << endl << "------Create Client------" << endl;
		cout << "Owner's First Name: " << endl;
		cin >> first;
		cout << "Owner's Last Name: " << endl;
		cin >> last;
		cout << "Phone Number: " << endl;
		cin >> phone;
		cout << "Pet Name: " << endl;
		cin >> petName;
		cout << "Pet species: " << endl;
		while(!correctSpecies)
		{
			cout << "Enter pet species letter, options are: d (dog), c (cat), b (bird), r (reptile), s (small mammal), h (horse), o (other) " << endl << "Animal letter choice: ";
			cin >> species;
			if (species == 'D' || species == 'd' || species == 'C' || species == 'c' || species == 'B' || species == 'b' || species == 'R' || species == 'r' || species == 'S' || species == 's' || species == 'H' || species == 'h' || species == 'O' || species == 'o')
			{
				correctSpecies = true;
			}
			else
			{
				cout << "invalid entry, please try again";
			}
		}
		cout << "Breed: " << endl;
		cin >> breed;
		cout << "Age: " << endl;
		while (!correctAge)
		{
			cin >> ageAttempt;
			if (isdigit(ageAttempt[0]))
			{
				age = stoi(ageAttempt);
				correctAge = true;
			}
			else
			{
				cout << "Incorrect data format, please try again." << endl;
			}
		}
		cout << "Is pet alive?(y/n): " << endl;
		while (!correctAnswer)
		{
			cin >> yesOrNo;

			if (yesOrNo == 'y' || yesOrNo == 'Y')
			{
				isAlive = true;
				correctAnswer = true;
			}
			else if (yesOrNo == 'n' || yesOrNo == 'N')
			{
				isAlive = false;
				correctAnswer = true;
			}
			else
			{
				cout << "Invalid answer, please try again." << endl;
			}
		}
		cout << "Save? (y/n)";
		while (!done)
		{
			cin >> saveAnswer;
			if (saveAnswer == 'y' || saveAnswer == 'Y')
			{
				pList[petListIndex]= Pet(masterIdNumber, first, last, phone, petName, species, breed, age, isAlive);
				petListIndex++;
				done = true;
			}
			else if (saveAnswer == 'n' || saveAnswer == 'N')
			{
				done = true;
			}
		}
		return selection;
	}
	else if (selection == 2)
	{
		bool correctInput = false;
		string idCheck;
		int id;

		while (!correctInput)
		{
			cout << "Enter Client ID Number: ";
			cin >> idCheck;
			cout << endl;
			if (isdigit(idCheck[0]))
			{
				id = stoi(idCheck);
				correctInput = true;
			}
			else
			{
				cout << "Incorrect input.  Please Try again." << endl;
			}
		}

		int searchID = pList->binarySearch(pList, id);
		if (searchID == -1)
		{
			cout << "Client not found";
		}
		else
		{
			if (pList[searchID].isAlive == true)
				{
					pList[searchID].isAlive = false;
				}
			else
				{
					pList[searchID].isAlive = true;
				}
				cout << "Pet status changed." << endl;
				pList[searchID].print();
		}
	}
	else if (selection == 3)
	{
		bool correctInput = false;
		string idCheck;
		int id;

		while (!correctInput)
		{
			cout << "Enter Client ID Number: ";
			cin >> idCheck;
			cout << endl;
			if (isdigit(idCheck[0]))
			{
				id= stoi(idCheck);
				correctInput = true;
			}
			else
			{
				cout << "Incorrect input.  Please Try again." << endl;
			}
		}

		int searchID = pList->binarySearch(pList, id);
		if(searchID == -1)
		{
			cout << "Client not found";
		}
		else 
		{
			pList[searchID].print();
		}

		return selection;
	}
	else if (selection == 4)
	{
		bool done = false;

		while (!done)
		{
			int selection;
			cout << "Enter 1 for unsorted, 2 for sorted." << endl << "Please enter a selection:" << endl;
			cin >> selection;

			if (selection == 2)
			{
				cout << endl;
				cout << "Sorted List:" << endl;
				pList->quickSortID(pList, 50);
				pList->printList(pList);
				done = true;
			}
			else if (selection == 1)
			{
				cout << endl;
				cout << "Unsorted List:" << endl;
				pList->printList(pList);
				done = true;
			}
			else
			{
				cout << endl;
				cout << "Incorrect entry, please try again." << endl;
			}
		}
		return selection;
	}
	else if (selection == 6)
	{
		cout << "Goodbye!" << endl;
		return selection;
	}
	else
	{
		return 0;
	}
}

bool checkPhoneNumber(string phone)
{
	bool isValid = true;
	if (phone.length() != 10)
	{
		return false;
	}

	for (int i = 0; i < 10; i++)
	{
			if (isdigit(phone[i]))
			{
				i++;
			}
			else
			{
				return false;
			}
	}
	return true;
}