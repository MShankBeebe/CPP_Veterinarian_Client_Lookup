#include "PetFamily.h"
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

string PetFamily::getFname()
{
	return firstname;
}


void PetFamily::setFName(string name)
{
	firstname = name;
}

string PetFamily::getLname()
{
	return lastname;
}


void PetFamily::setlName(string name)
{
	lastname = name;
}

string PetFamily::getPhone()
{
	return phonenumber;
}

void PetFamily::setPhone(string phone)
{
	phonenumber = phone;
}


int PetFamily::getId()
{
	return idnumber;
}

void PetFamily::print()
{
	cout << "ID Number: " << idnumber << endl;
	cout << "Phone Number: " << phonenumber << endl;
	cout << "Owner Name: " << firstname << " " << lastname << endl;
}

PetFamily::PetFamily()
{
	idnumber = 0;
	phonenumber = "";
	firstname = "";
	lastname = "";
}

PetFamily::PetFamily(int &masterIdNumber, string fname, string lname, string phone)
{
	idnumber = masterIdNumber;
	masterIdNumber++;
	firstname = fname;
	lastname = lname;
	phonenumber = phone;
}