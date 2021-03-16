//Matthew Spohrer
//ID#958566579
//CS162

//this is the header file for program three, the inventory for the eclipse

#include <fstream>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE=101, MAN_SIZE=5;

struct item
{
	char category[SIZE], name[SIZE], note[SIZE];
	int quant;
};

void user_choice(char choice[], char which_cat[]);
void welcome();
void display_all(item manager[]);
void display_one(item manager[], char which_cat[]);
void get_info(item manager[], int & num);
void write(item manager[], int num);
void read(item manager[], int & num);
void get_guts(item manager[], int num);
void get_which(char which_cat[]);
