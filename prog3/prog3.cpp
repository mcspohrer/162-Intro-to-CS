//Matthew Spohrer
//ID#958566579
//CS162

//the purpose of this program is to create a checklist of everything 
//needed for a successful viewing of the total solar eclipse using an
//external file to store the information the user entered in secondary storage.

#include "prog3.h"

int main()
{
	char choice[MAN_SIZE], which_cat[SIZE];
	item manager[SIZE];
	int num = 0;
	choice[0]='\0';
	which_cat[0] = '\0';

	welcome();
	read(manager, num);
	while (strcmp(choice, "Quit")!=0) 
	{
		choice[0] = '\0';
		user_choice(choice, which_cat);
		if (strcmp(choice, "All")==0) display_all(manager);		
		else if (strcmp(choice, "One")==0) display_one(manager, which_cat);
		else if (strcmp(choice, "Add")==0) get_info(manager, num);
	}
	write(manager, num);

	return 0;
}
