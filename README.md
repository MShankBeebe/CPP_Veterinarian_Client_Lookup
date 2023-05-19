# CPP_Veterinarian_Schedular
# Created by Megan Shank Beebe, 12/2023, final project for Computer Science 2

     A program designed to store, search, and retreive pet and owner information.  Eventually, I would like to expand it into a schedular to make appointments.  
     
     The program itself is a text based program with a looping menu.  
     ![mainMenu](https://github.com/MShankBeebe/CPP_Veterinarian_Client_Lookup/assets/63660114/f2715b93-6394-45e9-81e7-dfdc8c6ee664)

     
     To test the sorting feature, first print the list unsorted (selection 4 in the main menu, then selection 1 in the submenu. The search feature will also sort the list, so make sure to run this before anything else).  You will see the client Steve Harrington has an id number of 49 and is at the top of the list.    
 ![printUnsortedList](https://github.com/MShankBeebe/CPP_Veterinarian_Client_Lookup/assets/63660114/863b4c7e-2f70-40db-b9b5-0bd864ed1dc0)

     If you print the list sorted (selection 4 in the main menu, selection 2 in the sub menu) you will see that the client Steve Harrington moves to the bottom of the list, and Max Mayfield is now at the top of the list.
![printSortedList](https://github.com/MShankBeebe/CPP_Veterinarian_Client_Lookup/assets/63660114/c03290de-0cb9-4bc2-97d1-cb969ed90749)
    
     The program sorts the clients with a quick sort.  This quick sort function is also called within the binary search function (which is used to find clients by ID number).
![SearchAndSortToFindCreatedClient](https://github.com/MShankBeebe/CPP_Veterinarian_Client_Lookup/assets/63660114/c267db6c-8f4e-45b2-aed8-6a3f357acb1b)

    If a pet dies, the receptionist can change the status of the patient to "not current":
![ChangeOfPetStatus](https://github.com/MShankBeebe/CPP_Veterinarian_Client_Lookup/assets/63660114/31610028-2e58-48e2-bcad-fd1bd72f3071)

