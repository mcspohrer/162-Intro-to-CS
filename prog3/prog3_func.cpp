//Matthew Spohrer
//ID#958566579
//CS162

//this .cpp holds the functions for program 3

#include "prog3.h"

//gets the info for one structure from the structure
void get_info(item manager[], int & num)
{
	char ans;
	do{
		ans='\0';
		cout << "Which category would you like to add an item to? (Gear, Consumable, or Extra)\n";
		cin >> manager[num].category; 
		cin.ignore(100, '\n');
		manager[num].category[0] = toupper(manager[num].category[0]);
		if (strcmp(manager[num].category, "Consumable") != 0 && (strcmp(manager[num].category, "Gear")) != 0 && (strcmp(manager[num].category, "Extra")) !=0)
			 cout << "Invalid Entry\n\n\n";//checks the validit of the user's entry, say no if no good
		else{
			get_guts(manager, num);//gets the members of the structs from the user
			cout << "You entered:\n" << manager[num].category << endl  << manager[num].quant << endl << manager[num].name 
			     << endl << manager[num].note <<endl << "Is this correct? Yes or No\n";
			cin >> ans;
			cin.ignore(100, '\n');
			if (toupper(ans)!= 'Y' && toupper(ans) != 'N')
			{
				cout << "Invalid entry\n\n";
				ans = '\0';
			}
			cout << "\n\n\n\n";
		}
	}while (toupper(ans) != 'Y');	 
	++num; //increments the number of structs in the array
}

//gets the guts of the structs from the user
void get_guts(item manager[], int num)
{
	//I was having trouble with my cin.gets. If I just hit enter it would loop infinitely with garbage as the variables. I went to the homework recitation
	//for help and told me this should work for homework. If after you've looked at my program you can see how I was getting garbage, I would really 
	//appreciate a comment or two about it, it is driving me crazy. Thanks!
	cout << "What item would you like to add? Enter the item you'd like to add THEN press enter!\n";
	cin.get(manager[num].name, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "How many do you need?(enter a whole number, please)\n";
	cin >> manager[num].quant;
	cin.ignore(100,'\n');
	cout << "Now enter any notes you may have for your " << manager[num].name << ". If you have no notes to enter please enter \"no notes\"" <<endl;
	cin.get(manager[num].note, SIZE, '\n');
	cin.ignore(100,'\n');
}

	
//reads in all the data stored in "eclipse.txt"
void read(item manager[], int & num)
{
	ifstream file_in;
	file_in.open("eclipse.txt");
	if (!file_in)
	{
		cout << "Error in opening eclipse.txt\n";
		return;
	}
	file_in.get(manager[num].category, SIZE, '#');//priming the pump
	file_in.ignore(100, '#');
	while (file_in && !file_in.eof())
	{
		file_in >>  manager[num].quant;
		file_in.ignore(100, '#');
		file_in.get(manager[num].name, SIZE, '#');
		file_in.ignore(100, '#');
		file_in.get(manager[num].note, SIZE, '\n');
		file_in.ignore(100, '\n');
		++num;//keeps a tally on the size of manager
		file_in.get(manager[num].category, SIZE, '#');
		file_in.ignore(100, '#');
	}
	file_in.close();
	file_in.clear();
	
}
					
//displays all the items of all the categories
void display_all(item manager[])
{
	char cat[SIZE];
	
	strcpy(cat, "Gear");
	display_one(manager, cat);
	strcpy(cat, "Consumable");
	display_one(manager, cat);
	strcpy(cat,"Extra");
	display_one(manager, cat);
}

//displays one category frm the array of structs
void display_one (item manager[], char which_cat[])
{
	cout << "\nHere is a list of all the " << which_cat << " you have entered:\n\n";
	for (int i = 0; i <= SIZE; ++i)
	{
		if (strcmp(manager[i].category, which_cat)==0)
		    cout << "Quantity: "<< manager[i].quant << "\nThe item: " <<  manager[i].name << "\nNotes: " << manager[i].note << endl << endl;
	}

}

//writes over all the info in eclipse.txt with the current version as changed by the user
void write(item manager[SIZE],int num)
{
	ofstream file_out;

	file_out.open("eclipse.txt");
	if (file_out)
	{
		for (int i=0; i <=  num; ++i)
			//I was having trouble with file_out outputting "#0##" so I added this to solve it.
			if (strcmp(manager[i].category, "Consumable") == 0 || (strcmp(manager[i].category, "Gear")) == 0 || (strcmp(manager[i].category, "Extra")) ==0)
			{
				file_out << manager[i].category << "#" << manager[i].quant << "#" << manager[i].name 
					 << "#" << manager[i].note << endl;
			}	
		file_out.close();
		file_out.clear();
	}
}

//this function prompt the user if they want to add an item, display one category, display all categories, or quit the program
void user_choice(char choice[MAN_SIZE], char which_cat[])
{
	char resp;
	do
	{
		resp = '\0';
		choice[0] = '\0';
		cout << "Please enter one of the following choices:\nAdd (to add an item)\nOne (to display"
	             << " the items in one category)\nAll (to display all the items of all the categories)\n"
		     << "Quit (to quit the program):\n";
		cin >> choice;
		cin.ignore(100,'\n');
		choice[0] = toupper(choice[0]);
		if (strcmp(choice, "Add") != 0 &&  strcmp(choice, "One") != 0 && strcmp(choice, "All") !=0 && strcmp(choice,"Quit") != 0)
			cout << "You have made an invalid entry, please try again.\n\n";
		else 
		{
			cout << "You have entered " << choice << ", is that correct? Yes or No: ";
			cin >> resp;
			cin.ignore(100, '\n');
		}
	} while (toupper(resp) != 'Y');
	if (strcmp(choice, "One")==0) get_which(which_cat);
}

//gets the category to display
void get_which(char which_cat[])
{
	which_cat[0] = '\n';
	while (strcmp(which_cat, "Consumable") != 0 && (strcmp(which_cat, "Gear")) != 0 && (strcmp(which_cat, "Extra")) !=0)
	{
		cout << "Which category would you like to see? (Consumable, gear, or extra)\n";
		cin >> which_cat;
		cin.ignore(100, '\n');
		which_cat[0] = toupper(which_cat[0]);
		if (strcmp(which_cat, "Consumable") != 0 && (strcmp(which_cat, "Gear")) != 0 && (strcmp(which_cat, "Extra")) !=0)
		{
			cout << "Invalid entry\n\n";
			which_cat[0]= '\0';
		}
	}
} 

//welcomes the user and provides a little info about the program
void welcome()
{
	cout << "Welcome to the eclipse-a-tron 3000!\n\n"
	     << "I will allow you to create a list of all the stuff you will need for the "
             << "solar eclipse on August 21, 2017. I am assuming you are going camping \n"
             << "to avoid the crowds. You will be able to make lists for three different "
	     << "categories (camping gear, consumables, or extra stuff) and include \n"
	     << "notes for each item you would like to take. I will then store this "
	     << "information for future use which you can access at any time.\n\n\n";
}
