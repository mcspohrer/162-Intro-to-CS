//Matthew Spohrer
//Program 5 CS162
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
		int compare(const Eclipse_Category & to_comp);
	private:
		char * category;
		char * prep;
		char * notes;
};

//struct decleration for a data node for a linear linked list
struct node
{
	Eclipse_Category data;
	node * next;
};

void add_node(node *&  head, node *& current);//adds a new data in the alphabetically by category
void welcome();//welcomes user
char action();//asks whether the user would like to add an item or display all
void end();//thanks the user
char more();//asks if the user would like to continue using the program
void display_all(node * head);// displays all the data members on each of the nodes of the LLL
void destructor(node *& head);
