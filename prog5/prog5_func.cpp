//Matthew Spohrer
//Program 5 CS162

//This is where the program functions will be implemented
#include "prog5.h"

//destructor, removes all data nodes at the end of the program
void destructor(node *& head)
{
	if (!head) return;
	else if (!head->next) 
	{
		delete head;
		head = NULL;
		return;
	}
	destructor(head->next);
	return;
}
	
	
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
	cout << "\n\n\n\nHello! This program will ask you to add any items needed to prep for your eclipse trip in\n"
	     << "as many categories as you need with any notes for preperation included. Your items will\n"
	     << "stored alphabetically by category.\n\n\n"; 
}

//asks the user their choice of action returning a single char (a for add or d for display) to be used by main to 
//determine which course of action the program will take.
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

//displays all the data members of all the data members of all the nodes of the LLL, returns nothing
void display_all(node * head)
{
	//current = new node;
	if (!head) return;
	node * current = head;
	while (current)
	{
		current->data.display();
		current=current->next;
	}	
}
	
//this function displays the data for a node and returns nothing
void Eclipse_Category::display()
{
	cout << "Category: " << category << "\nPrep: " << prep << "\nNotes: " << notes << "\n\n\n";
}

//adds a new data node with the entered data from the user in the class Eclipse_Category
roid add_node(node *& head, node *& current)
{
	node * ptr = NULL;
	char comp = ' ';
	if (!head) 
	{
		head = current;
		return;
	}
	comp = head->data.compare(current->data);
	if (comp >= 0)
	{
		current->next = head;
		head = current;
		return;
	}
	add_node(head->next, current);
	return;
}
			
//this function adds the info into the data members of a new Eclipse_Category object, returns nothing
void Eclipse_Category::add()
{
	char ans = '\0';
	char temp[SIZE];
	while (toupper(ans) != 'Y')
	{	
		ans = ' ';
		category = NULL;
		cout << "Which category would you like to add to? \n";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		if (category) delete [] category;
		category = new char[strlen(temp)+1];
		strcpy(category, temp);
		category[0] = toupper(category[0]);

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
			     << "\nIs this correct? Yes or No\n\n\n";
			cin >> ans;
			cin.ignore(100, '\n');
			ans = tolower(ans);
			if (ans != 'y' && ans != 'n') 
				cout << "Invalid entry, please try again.\n";
		}
	}
	
}

//this is the constructor to initialize all the data members in the class to their zero equivalents
Eclipse_Category::Eclipse_Category()
{
	category = NULL;
	prep = NULL;
	notes = NULL;
}

//copies the data from the temp object into the node being added
int Eclipse_Category::compare(const Eclipse_Category & to_comp)
{
	int comp = 0;
	comp = strcmp(category, to_comp.category);
	return comp;
}
