//Matthew Spohrer
//CS164 Program 4
//ID# 958566579

#include "prog4.h"

int main()
{
	int length = 0;
	Eclipse_Category * manager = NULL; 
	char ans = 'y';
	char choice = '\0';	
	welcome();
	while (ans == 'y')
	{
		choice = action();	
		if (toupper(choice) == 'A') 
		{
			reallocate_man(manager, length);
			manager[length-1].add();
		}
		else display_all(manager, length);
		ans = more();
	}
	end();
	delete [] manager;
	return 0;
}
