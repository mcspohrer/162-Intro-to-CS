//Matthew Spohrer
//Program 4 CS162

//This is where the program functions will be implemented
#include "prog4.h"

//gives thanks to the usera returning nothing
void end()
{
	cout << "Thank you for using the program. Enjoy the apocalypse that results from the eclipse!\n\n\n\n\n";
}

//asks the user if they want to continue returning the users response as a single char (y for yes and n for no)
char more()
{
	char ans = '\0';
	while (ans != 'y' && ans != 'n')
	{
		cout << "Would you like to continue with the program? Yes or No\n";
		cin >> ans;
		cin.ignore(100,'\n');
		ans = tolower(ans);
		if (ans != 'y' && ans != 'n') 
			cout<< "Invalid entry, please try again.";
	}
	return ans;
}
	
//welcomes the user returning nothing
void welcome()
{
	cout << "Hello! This program will ask you to add things to prep to three different lists\n"
	     << "(Gear, Consumables, and Extras) and add any notes other users may need for the preperations\n"
	     << "for the clouded over total solar eclipse.\n\n\n\n\n";
}

//asks the user their choice of action returning a single char (a for add or d for display) to be used by main
char action()
{
	char choice = ' ';
	while (toupper(choice) != 'A' && toupper(choice) != 'D')
	{
		cout << "Please choose to add an item or display all: Add or Display\n";
		cin >> choice;
		cin.ignore(100, '\n'); 
		if (toupper(choice) != 'A' && toupper(choice) != 'D')
			cout << "Invalid entry, please try again.\n\n";
	}
	return choice;
}

//displays all the data members of all the indices of manager and uses length as a stopping point, returns nothing
void display_all(Eclipse_Category manager[], int length)
{
	for (int i=0; i<length; ++i)
		manager[i].display();
}
	
//this functions displays the data for the particular index of the managing array and returns nothing
void Eclipse_Category::display()
{
	cout << "Category: " << category << "\nPrep: " << prep << "\nNotes: " << notes << "\n\n\n";
}

//this function adds the info into the data members of a new Eclipse_Category object and increments length, returns nothing
void Eclipse_Category::add()
{
	char ans = '\0';
	char temp[SIZE];
	while (toupper(ans) != 'Y')
	{	
		ans = '\0';
		do
		{
			category = NULL;
			cout << "Which category would you like to add to? Gear, Consumables, or Extras\n";
			cin.get(temp, SIZE, '\n');
			cin.ignore(100, '\n');
			if (category) delete [] category;
			category = new char[strlen(temp)+1];
			strcpy(category, temp);
			category[0] = toupper(category[0]);
			if (strcmp(category, "Gear") != 0 && strcmp(category, "Consumables") != 0 && strcmp(category, "Extras") != 0)
				cout << "Invalid entry, please try again.";
		} while (strcmp(category, "Gear") != 0 && strcmp(category, "Consumables") != 0 && strcmp(category, "Extras") != 0);

		cout << "What needs to be prepared? Something needs to be entered or it enters an infinite lood for some reason.\n";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		if (prep) delete [] prep;
		prep = new char[strlen(temp) +1];
		strcpy(prep, temp);

		cout << "Would you like to add any notes for other people? If no, please enter \"no notes\" otherwise, infinite loop.\n";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		if (notes) delete [] notes;
		notes = new char[strlen(temp)+1];
		strcpy(notes, temp);

		while (ans != 'y' && ans != 'n')
		{
			cout << "\n\nYou entered:\n" << category << endl <<prep << endl << notes
			     << "\nIs this correct? Yes or No\n";
			cin >> ans;
			cin.ignore(100, '\n');
			ans = tolower(ans);
			if (ans != 'y' && ans != 'n') 
				cout << "Invalid entry, please try again.";
		}
	}
	
}

//this functon takes the populated manager array and reallocates by incrementing length then copying the old array to the new array and returning nothing
void reallocate_man(Eclipse_Category *& manager, int & length)
{
	Eclipse_Category * temp = NULL;
	temp = manager;
	++length;
	manager = new Eclipse_Category[length];
	if (temp)
	{
		for (int i = 0; i < length-1; ++i){
			manager[i].copy(temp[i]);
		}
	}
	delete [] temp;
}

//this is the constructor to initialize all the data members in the class to their zero equivalents
Eclipse_Category::Eclipse_Category()
{
	category = NULL;
	prep = NULL;
	notes = NULL;
}

//copies the data from the object passed into the new object in the new managing array
void Eclipse_Category::copy(const Eclipse_Category & tocopy)
{
	if (category) delete [] category;
	category = new char[strlen(tocopy.category)+1];
	strcpy(category, tocopy.category);

	if (prep) delete [] prep;
	prep = new char[strlen(tocopy.prep)+1];
	strcpy(prep, tocopy.prep);

	if (notes) delete [] notes;
	notes = new char[strlen(tocopy.notes)+1];
	strcpy(notes, tocopy.notes);
}
