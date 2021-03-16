//Matthew Spohrer
//CS162
//ID# 958566579

//This program is a counter for three different nutritional values.

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void welcome();



int main()
{
	int Na_Goal, Sat_Goal, Prot_Goal, weight=0;
	int Na_Tot, Sat_Tot, Prot_Tot = 0;
	int Na_Amt, Sat_Amt, Prot_Amt=0;
	char answer;
	welcome(); //informs the user how to use the program

	//this part below gets the goal for sodium
	do
	{
		
		cout << "Please enter the amount of sodium you would like your goal to be set at for today (in milligrams and a whole number, please).\n"
		     << "Keep in mind the recommended dietary allowance is 2300 mg/day.\n";
		cin >> Na_Goal;
		cout << "\nYou entered " << Na_Goal << " mg as your goal for the day. Is this correct? Y or N \n";
		cin >> answer;
		if (toupper(answer) != 'Y') cout << "Let's try this again, shall we?\n\n\n";
	} while (toupper(answer) != 'Y' );
	
	//this part gets the daily goal for saturated fat
	do
	{
		cout << "Please enter the amount of saturated fat you would like your goal to be set for today (in grams and whole numbers please).\n"
		     << "Keep in mind the recommended dietary allowance for saturated fat is about 13 g/day.\n";
		cin >> Sat_Goal;
		cout << "\nYou entered " << Sat_Goal << " g for your goal for the day. Is this correct? Y or N \n";
		cin >> answer;
		if (toupper(answer) != 'Y') cout << "Let's try that again, shall we?\n\n\n";
	} while (toupper(answer) != 'Y');
	
	//this part gets the goal for protein
	do
	{
		//asks the user for their weight so the rda for protein can be determined.	
		do
		{
			cout << "How much, in pounds and whole numbers, do you weigh?\n";
			cin >> weight;
			cout << "You entered " << weight << " pounds as your weight, is this correct? Y or N\n";
			cin >> answer;
			if (toupper(answer)!= 'Y') cout << "Let's try this again!\n\n\n";
		} while (toupper(answer) != 'Y');

		weight *= 0.45359237 * 0.8;
		cout << "Please enter the amount of protein you would like your goal to be set to for today (in grams and whole numbers, please).\n"
		     << "With your weight, the recommended dietary allowance for protein is " << weight << " grams.\n";
		cin >> Prot_Goal;
		cout << "You entered " << Prot_Goal << " grams as your goal for the day. Is this correct? Y or N. \n";
		cin >> answer;
		if (toupper(answer) != 'Y') cout << "Let's try this again, then.\n\n\n";
	} while (toupper(answer) != 'Y');

	//this next block totals the amount of each nutrient consumed for the day
	char Day_Ans,ans_type;
	do
	{
		//below asks how much sodium was consumed by the user per meal
		do
		{
			cout << "Please enter, in whole numbers, the amount of sodium you consumed.\n";
			cin >> Na_Amt;
			if (Na_Amt > 0)
			{
				do
				{
					cout << "Is that in grams or milligrams? please enter g for grams and m for milligrams.\n";
					cin >> ans_type;
					cout << "You entered " << ans_type << " as the type of your sodium entry, is this correct? Y or N\n";
					cin >> answer;
					if (toupper(answer) != 'Y') cout << "Let's try this again!\n\n\n";
					if ('g' == tolower(ans_type)) Na_Amt *= 1000;
				}while (toupper(answer) != 'Y');
			} 
			cout << "You entered " << Na_Amt << " milligrams as what you have just eaten, is this correct? Y or N\n";
			cin >> answer;
			if (toupper(answer) == 'Y') Na_Tot += Na_Amt;
			else cout << "Let's try this again!\n\n\n";
		}while (toupper(answer) != 'Y'); 
		
		//the block below gets the saturated fats consumed and tallys them
		do
		{
			cout << "Please enter, in whole numbers, the amount of saturated fat you consumed.\n";
			cin >> Sat_Amt;
			if (Sat_Amt> 0)
			{
				do
				{
					cout << "Is that in grams or milligrams? Please enter g for grams and m for milligrams. \n";
					cin >> ans_type;
					cout << "You entered " << ans_type << " as the type of your saturated fat entry, is this correct? Y or N \n";
					cin >> answer;
					if (toupper(answer) != 'Y') cout << "Let's try this again!\n\n\n";
					if (tolower(ans_type) == 'n') Sat_Amt /= 1000;
				} while (toupper(answer) != 'Y');
			}
			cout << "You entered " << Sat_Amt << " grams as what you have just eaten, is this correct? Y or N\n";
			cin >> answer;
			if (toupper(answer) == 'Y') Sat_Tot += Sat_Amt;
			else cout << "Let's try this again! \n\n\n";
		} while (toupper(answer) != 'Y');

		//this block below gets the amount of protein just consumed by the user and adds it to the total
		do
		{
			cout << "Please enter, in whole numbers, the amount of protein you consumed.\n";
			cin >> Prot_Amt;
			if (Prot_Amt > 0)
			{
				do
				{
					cout << "Is that in grams or milligrams? Please enter g for grams or m for milligrams. \n";
					cin >> ans_type;
					cout << "You entered " << ans_type << " as the type of your proteing entry, is this correct? Y or N \n";
					cin >> answer;
					if (toupper(answer) != 'Y') cout << "Let's try this again! \n\n\n";
					if (tolower(ans_type) == 'n') Prot_Amt /=1000;
				} while (toupper(answer) != 'Y');
			}
			cout << "You entered " << Prot_Amt << " grams as what you have just eaten, is this correct? Y or N \n";
			cin >> answer;
			if (toupper(answer) == 'Y') Prot_Tot += Prot_Amt;
			else cout << "Let's try this again! \n\n\n";
		} while (toupper(answer) != 'Y');
		
		//this block determines if the user is done for the day and ends the loop, if so.
		do
		{		
			cout << "Are you finished for the day? Y or N\n";
			cin >> answer;
			cout << "Just to be sure, you entered " << answer << ". Is that correct? Y or N\n";
			cin >> ans_type;
			if (toupper(ans_type) != 'Y') cout << "Let's try this again!\n\n\n";
		} while (toupper(ans_type) != 'Y');
	} while (toupper(answer) != 'Y');
	
	//compares the amount of sodium consumed to the amount the user set as their goal.
	cout << "Your goal for the day's sodium intake is " << Na_Goal << " milligrams. You consumed " << Na_Tot << " milligrams.\n";
	if (Na_Goal > Na_Tot) cout << "You consumed less sodium than what you had set as your goal by " << (Na_Goal - Na_Tot) << " milligrams.\n\n\n";
	else if (Na_Goal < Na_Tot) cout << "You ate too much sodium by " << (Na_Tot - Na_Goal) << " milligrams. \n\n\n"; 
	else if (Na_Goal == Na_Tot) cout << "You ate exactly the amount of sodium you were hoping to eat today.\n\n\n";

	//compares the amount of saturated fat consumed to the amount the user set as their goal.
	cout << "Your goal for the day's saturated fat intake is " << Sat_Goal << " grams. You consumed " << Sat_Tot << " grams.\n";
	if (Sat_Goal > Sat_Tot) cout << "You consumed less saturated fat than you had set as your goal by " << (Sat_Goal - Sat_Tot) << " grams.\n\n\n";
	else if (Sat_Goal < Sat_Tot) cout << "You ate too much saturated fat by " << (Sat_Tot-Sat_Goal) << " grams.\n\n\n";
	else if (Sat_Goal == Sat_Tot) cout << "You ate exactly the amount of saturated fat you were hoping to eat today.\n\n\n"; 

	//compares the amount of protein eaten to teh amount the user set as their goal.
	cout << "Your goal for the day's protein intake is " << Prot_Goal << " grams. You consumed " << Prot_Tot << " grams.\n";
	if (Prot_Goal > Prot_Tot) cout << "You consumed less protein than what you set as your goal by " << (Prot_Goal - Prot_Tot) << " grams.\n\n\n";
	else if (Prot_Goal < Prot_Tot) cout << "You ate too much protein by " << (Prot_Tot-Prot_Goal) << " grams. \n\n\n";
	else if (Prot_Goal == Prot_Tot) cout << "You ate exactly the right amount of protein as you were hoping to eat today.\n\n\n";
	
	//thanks the user and ends the program
	cout << "Thanks for using the nutritional counter 5000! See you tomorrow!\n\n\n"; 
	return 0;
}

//goes over the rules with the user if they need them
void welcome()
{
	char ans;
	do
	{	
		cout << "Welcome to the nutritional counter 6000! Have you used the program before? Please answer Y or N" << endl;
		cin >>	ans;
		if (toupper(ans) != 'Y' && toupper(ans) != 'N') 
			cout << "Hey dummy, I said Y or N. Now let's try that again!" << endl << endl;
	} while (toupper(ans) != 'Y' &&  toupper(ans) !='N');
	if (toupper(ans) == 'N')
	{
		cout << "So here's the deal, I'm going to ask you for your daily goals for sodium, protein, and saturated fats." << endl
		     << "Once you entered your goal amounts, all you have to do is, every time you eat a meal, enter in the amount  " << endl
		     << "of each nutrient you've eaten. At the end of the day I will tell you the total of each nutrient you have taken in and compare " << endl
		     << "that number to the goal you set." << endl << endl;
	} else cout << "Welcome back!" << endl << endl;
}

 
