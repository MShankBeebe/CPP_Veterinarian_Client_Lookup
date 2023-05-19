#pragma once
#include "PetFamily.h"
#include<iostream>
#include<cstdlib>
#include<string>

class Pet : public PetFamily
{
    public:
        Pet(int &masterIdNumber, string fName, string lName, string phone, string petName, char species, string breed, int age, bool tOrF);
        Pet();
        ~Pet();
        void setPetInfo(int &masterIdNumber, string fName, string lName, string phone, string petName, char species, string breed, int age, bool tOrF);
        void print();
        void printList(Pet petArray[]);

        //for sorting
        //int getClientID(int id, Pet list[]);
        int partition(Pet list[], int start, int  finish);
        void swap(Pet list[], int first, int second);
        void recQuickSortID(Pet petArray[], int first, int last);
        void quickSortID(Pet list[], int length);
        int binarySearch(Pet list[], int idNum);
        
        ////overloading asssignment operator
        //int& operator[](int index);

        //overloading the = operator to easily copy one pet to another
        const Pet& operator = (const Pet&);
        bool isAlive;

    protected:
        string petName;
        char petSpecies;
        string petBreed;
        int petAge;


    private:
        //Pet* listPointer;

};

