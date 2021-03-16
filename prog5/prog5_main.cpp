//Matthew Spohrer
//CS164 Program 5
//ID# 958566579

#include "prog5.h"

int main()
{
	char ans = 'y';
	char choice = '\0';	
	node * head = NULL;
	node * current = NULL;
	welcome();
	while (ans == 'y')
	{
		choice = action();	
		if (toupper(choice) == 'A') 
		{
			current = new node;
			current->data.add();		
			add_node(head, current);	
		}
		else display_all(head);
		ans = more();
	}
	end();
	destructor(head);
	return 0;
}
