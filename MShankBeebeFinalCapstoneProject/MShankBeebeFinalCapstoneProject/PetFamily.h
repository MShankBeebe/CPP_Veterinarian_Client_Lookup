#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


class PetFamily
{
public:
	string getFname();
	//returns the last name

	void setFName(string name);
	//sets the last name

	string getLname();
	//returns the last name

	void setlName(string name);
	//sets the last name

	string getPhone();
	//returns the phone number

	void setPhone(string phone);
	//sets the phone number

	int getId();
	//returns Id

	void print();
	//prints the last name, phone number, and customer id

	//default constructor
	PetFamily();

	//constructor
	PetFamily(int &masterIdNumber, string fname, string lname, string phone);


protected:
	string firstname;
	string lastname;
	string phonenumber;
	int idnumber;




};

