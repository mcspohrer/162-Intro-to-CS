//Matthew Spohrer
//ID#958566579
//CS162

//The purpose of this program is to ask for a phrase from a user and have someone 
//try to guess the phrase. The game is two player so there will be two phrases and
//subsequent wrong guesses will reveal a new hint about the phrase.

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 201, WORD_SIZE = 21;//SIZE is for the phrase, WORD_SIZE is for the individual words in the hints
void welcome();//welcomes the user and briefly describes the game
void get_phrase(char phrase[], int& turn);//gets secret phrase from each of the players
void guess(char phrase[], int& turn, bool& solved, int& score);//gets the guessed phrase from each player and determines
	//whether it has been solved or now
void hint(char phrase[], int turn);//manages hints and provides the first hint
void hint2(char phrase[]);//provides the first word hint
void hint3(char phrase[]);//provides the last word hint
void show_score(int score1, int score2);//outputs the score to the screen



int main ()
{
	
	int score1=0, score2=0;
	welcome();
	do
	{	
		int turn = 1;
		char phrase1[SIZE], phrase2[SIZE];
		bool solved1 = false, solved2 = false;
		get_phrase(phrase2, turn); //gets the ohrase player1 would like player2  to guess
		get_phrase(phrase1, turn); //gets the phrase player2 would like player1 to guess
		do
		{
			if (solved1 == false) hint(phrase1, turn);
			guess(phrase1, turn, solved1, score1);
			cout << "\n\n\n\n\n\n\n\n";
			if (solved2 == false) hint(phrase2, turn);
			guess(phrase2, turn, solved2, score2);
			cout << "\n\n\n\n\n\n\n\n";
		} while (turn < 9);
		show_score(score1, score2);
	} while (score1<5 && score2<5);
}

//this function show's each player's score and declares a winner if need be
void show_score(int score1, int score2)
{
	cout << "So, as it stands, the score is \nPlayer1: " << score1 << "\nPlayer2: " << score2 <<"\n\n\n\n\n\n\n\n\n";
	if (score1 == 5) cout << "Whoa whoa whoa, stop the train! It seems as though we have a winner! PLAYER 2 ....."
			      << " is not as smart as player 1! Player 1 is the winner!!!!\n\n\n\n\n\n\n\n\n\n\n";
	if (score2 == 5) cout << "HAHAHAHAHHAHAHAHA player 1 is so dumb, huh player 2? Why? Because player 2 is the"
			      << " winner!!!! Congratulations player 2! Your prize is you get to do my next "
			      << "homework assignment!\n\n\n\n\n\n\n\n";
}
	
//determines the last word of the secret phrase for the third hint.
void hint3(char phrase[])
{
	int length=strlen(phrase), word_i=-1;
	char last_word[WORD_SIZE];
	for (int i = length; phrase[i] != ' '; --i) ++word_i;
	for (int i= length; phrase[i] != ' '; --i) 
	{
		last_word[word_i] = phrase[i];
		--word_i;
	}
	cout << "And because you still couldn't guess the phrase, even after such a revealing hint last round, the last word of the phrase is " << last_word <<endl;
}


//determines and displays the second hint when needed
void hint2(char phrase[])
{
	char first_word[WORD_SIZE];
	for (int i=0; phrase[i] != ' '; ++i)
	{
		first_word[i] = phrase[i];
		if (phrase[i+1] == ' ') first_word[i+1] = '\0';
	}	
	cout << "Because you couldn't guess the first time around, the first word of the phrase is " << first_word <<endl;
}


//prints the first hint and calls on the second two hints if needed.
void hint(char phrase[], int turn)
{
	int length=strlen(phrase), num_words=1, num_vows=0;
	for (int i=0; i<=length; ++i)
	{
		if (phrase[i] == ' ') ++num_words;
		if (phrase[i]== 'a' || phrase[i]== 'e'|| phrase[i] == 'o'||phrase[i]=='i'||phrase[i]=='u') ++num_vows;
	}
	cout << "There are " << num_words<< " words and " << num_vows << " vowels in the phrase you are guessing. Good Luck!\n";
	if (turn > 4 && num_words > 1) hint2(phrase);
	else if (turn > 4 && num_words== 1) cout << "I'd give you a word but the secret phrase is only one word!\n";
	if (turn > 6 && num_words > 2) hint3(phrase);
	else if (turn>6 && num_words <3) cout << "There aren't enough words in the secret phrase to give you another hint.\n";
}


//welcomes the users and gives them a run down of the game.
void welcome ()
{
	cout << "\n\n\n\n\n\n\n\nWelcome to the Guess each other's phrase game 999999.9:!\n\n"
	     << "I will be asking two players for a phrase and each player will then try to guess the phrase the other player entered.\n"
	     << "After each round of failed guesses I will reveal a little more information about the phrase.\n"
	     << "The first player to reach 5 points wins the game.\n\n\n"; 
}

//gets the user enter a phrase and checks to see if it is correct then clears the screen
void get_phrase(char phrase[], int& turn)
{
	char response;
	do
	{
		if (turn == 1 ) 
			cout << "Player 1, please enter a phrase for dumb player 2 to try to guess. Please remember to use only letters. \n";
		else cout << "Player 2, please enter a phrase for that idiot player 1 to guess. Please remember to only use letters. \n";
		cin.get(phrase, SIZE, '\n');
		cin.ignore(100,'\n');
		phrase[0] = toupper(phrase[0]);
		cout << "Your phrase is: " << phrase <<endl
		     << "Would you like to use this phrase? Y or N: ";
		cin >> response;
		cin.ignore(100, '\n');
		++turn;	
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	} while (toupper(response) != 'Y');
	
}

//this function gets a guess from the user and checks if it is correct.
void guess(char phrase[], int& turn, bool& solved, int& score)
{
	char guess[SIZE], response = 'n';
	if (solved == false)
	{
		do
		{
			if (turn % 2 == 0) 
				cout << "Player 2, please enter your guess for the phrase. Remember to use only letters, please.\n"; 
			else cout << "Player 1, please enter your guess for the secret phrase. Remember to only use letters, please.\n";
			cin.get(guess, SIZE, '\n');
			cin.ignore(100, '\n');
			guess[0] = toupper(guess[0]);
			cout << "You guessed : " << guess << endl << "Do you want to stick with that answer? Y or N.\n";
			cin >> response;
			cin.ignore(100, '\n');
		} while (toupper(response) != 'Y');
	}
	if (strcmp(phrase, guess) == 0)
	{
		cout << "Holy moly you actually solved it! Good job!! If I new how to program fireworks into this game they'd be going off right now!!\n";
		solved = true;
		++score;
	} else if (solved == false) cout << "Just as I thought, swing and a miss. I'd say nice try but "
					 << "I think we both know I'd be lying...\n";
	++turn;
}
		
