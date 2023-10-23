//The object of hangman is to guess the secret word before the stick figure is hung. 
//Players take turns selecting letters to narrow the word down.
//Players can take turns or work together. 
//Gameplay continues until the players guess the word or they run out of guesses and the stick figure is hung.


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Initialising maximum tries as 5
const int MAX_TRIES=5;

//Functions declaration
int letterCheck (char, string, string&);
void HangMan(int wrongGuess);
int letterCheck (char guess, string hiddenWord, string &guessWord);


//Drawing hangman 
//As number of wrong guesses increase so will be the sticks 

void HangMan(int wrongGuess)
{

    //No of wrong guesses=5
    if(wrongGuess==5)
    {
        cout<<"     _______\n";
        cout<<   "|/      |\n";
        cout<<   "|      (_)\n";
        cout<<  "|     __|__\n";
        cout<<  "|       |\n";
        cout<<   "|     __|__\n";
        cout<<  "|\n";
        cout<<  "|___\n";
    }
    
    //No of wrong guesses=4
    if(wrongGuess==4)
    {
        cout<<"     _______\n";
        cout<<   "|/      |\n";
        cout<<   "|      (_)\n";
        cout<<  "|     __|__\n";
        cout<<  "|       |\n";
        cout<<   "|       |\n";
        cout<<  "|\n";
        cout<<  "|___\n";
    }

    //No of wrong guesses=3
    if(wrongGuess==3)
    {
        cout<<"     _______\n";
        cout<<   "|/      |\n";
        cout<<   "|      (_)\n";
        cout<<  "|       |\n";
        cout<<  "|       |\n";
        cout<<   "|       |\n";
        cout<<  "|\n";
        cout<<  "|___\n";
    }

    //No of wrong guesses=2
    if(wrongGuess==2)
    {
        cout<<"     _______\n";
        cout<<   "|/      |\n";
        cout<<   "|      (_)\n";
        cout<<  "|\n";
        cout<<  "|\n";
        cout<<   "|\n";
        cout<<  "|\n";
        cout<<  "|___\n";
    }

    //No of wrong guess=1
    if(wrongGuess==1)
    {
        cout<<"     _______\n";
        cout<<   "|/      |\n";
        cout<<   "|\n";
        cout<<  "|\n";
        cout<<  "|\n";
        cout<<   "|\n";
        cout<<  "|\n";
        cout<<  "|___\n";
    }
}


// Take the secret word and a one-character guess, then complete the guessWord field.
// amount of characters that were found to match.
// Additionally, if the character has already been predicted, returns zero.

//Checking whether the letter guessed is present in the word or not

int letterCheck (char guess, string hiddenWord, string &guessWord)
{
	int noOfMatch=0;
	int length=hiddenWord.length();

    int i;

    //To check letter in the whole word

	for (i = 0; i< length; i++)
	{
		//If this letter has already been guessed before
		if (guess == guessWord[i])
        {
            return 0;
        }
			
		//If this letter matches a letter in the hidden word
		if (guess == hiddenWord[i])
		{
			guessWord[i] = guess;
			noOfMatch++;
		}
	}
	return noOfMatch;
}

//Main function

int main ()
{
    
	int wrongGuess=0;
	string word;
    string name;
	char letter;

    //list of states
	string words[] =
	{
		"delhi",
		"assam",
		"bihar",
		"goa",
		"gujarat",
		"jharkhand",
		"maharashtra",
		"manipur",
		"hyderabad",
		"haryana",
        "mizoram",
        "telangana",
        "karnataka",
        "nagaland",
        "tripura",
        "chattisgarh",
        "kerela",
        "orissa",
        "uttarakhand",
        "punjab",
        "rajasthan",
        "meghalaya"
	};

	//Choosing a random state name from list of words
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];
    
	//Initialize the hidden word with the * character.
	string unknown(word.length(),'*');

	//Welcome the user

    cout << "\n\n...WELCOME...\n\n";

    cout << " _   _                                         " << endl;   
    cout << "| | | |                                        " << endl;
    cout << "| |_| |  __ _ _ __   __ _ _ __ ___   __ _ _ __ " << endl;
    cout << "|  _  | / _` | '_ | / _` | '_ ` _ | / _` | '_ |" << endl;
    cout << "| | | | (_| | | | | (_| | | | | | | (_| | | | |" << endl;
    cout << "|_| |_| __,_|_| |_| __, |_| |_| |_| __,_|_| |_|" << endl;
    cout << "                    __/ |                      " << endl;
    cout << "                   |___/                       " << endl;


	cout << endl;
    cout << "Guess name of a state of India";
    cout << endl;
    cout << endl;
	cout << "Each letter is represented by a star.";
    cout << endl;
	cout << "You have to type only one letter in one try";
    cout << endl;
	cout << "You have " << MAX_TRIES << " tries to try and guess the word.";
    cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    //Rules
    cout << endl;
    cout << endl;
    cout << "RULES:";
    cout << endl;
    cout << "If a guessed letter is present in the word, it is revealed in the correct positions.";
    cout << endl;
	cout << "If a guessed letter is not in the word, a part of the hangman figure is drawn.";
    cout << endl;
    cout << "The game continues until the players guess the word correctly or the hangman figure is completed.";
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    //Continue the loop until the available guesses are exhausted
	while (wrongGuess < MAX_TRIES)
	{
	    cout << endl;
	    cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << endl;
        cout << "Word is :  ";
		cout << unknown;
        cout << endl;
        cout << endl;
		cout << "Guess a letter: ";
		cin >> letter;

		//Fill secret word with letter if the guess is correct,
		//Or else increment the number of wrong guesses.

        //if wrong letter was guessed
		if (letterCheck(letter, word, unknown)==0)
		{
			cout << endl << "Umm! Sorry,but the guess was incorrect" << endl;
			wrongGuess++;
			HangMan(wrongGuess);
		}

        //if correct letter was guessed
		else
		{
			cout << endl << "Woah!! You found a letter" << endl;
		}

		//Number of guesses left
        cout << endl;
		cout << "You have " << MAX_TRIES - wrongGuess;
		cout << " guesses left." << endl;

		//Guessed correct word
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Congratulations! You got it!";
			break;
		}
	}

    //All tries exhausted
    //hence the game will end

	if(wrongGuess == MAX_TRIES)
	{
        cout << endl;
		cout << "Sorry, you have run out of tries....";
        cout << endl;
        cout << "You've been hanged";
        cout << endl;
		cout << "The word was : " << word;
        cout << endl;
	}


	return 0;
}
