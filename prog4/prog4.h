//Matthew Spohrer
//Program 4 CS162
//ID# 958566579

//This is the header file for program 4. It contains the class interface, all the includes for libraries and
//what not.

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

const int SIZE = 101; //constant size for inputs from user

//the class interface which will manage the data
class Eclipse_Category
{
	public:
		Eclipse_Category(); //constructor
		void display();//displays the data members
		void add();//adds data from user
		void copy(const Eclipse_Category & to_copy);
	private:
		char * category;
		char * prep;
		char * notes;
};

void reallocate_man(Eclipse_Category *& manager, int & length);//dynamically allocates the existing manager array
void welcome();//welcomes user
char action();//asks whether the user would like to add an item or display all
void end();//thanks the user
char more();//asks if the user would like to continue using the program
void display_all(Eclipse_Category manager[], int length);// displays all the data members in all the indices of the managing array
