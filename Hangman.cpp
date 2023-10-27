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
        std::cout<<"     _______\n";
        std::cout<<   "|/      |\n";
        std::cout<<   "|      (_)\n";
        std::cout<<  "|     __|__\n";
        std::cout<<  "|       |\n";
        std::cout<<   "|     __|__\n";
        std::cout<<  "|\n";
        std::cout<<  "|___\n";
    }
    
    //No of wrong guesses=4
    if(wrongGuess==4)
    {
        std::cout<<"     _______\n";
        std::cout<<   "|/      |\n";
        std::cout<<   "|      (_)\n";
        std::cout<<  "|     __|__\n";
        std::cout<<  "|       |\n";
        std::cout<<   "|       |\n";
        std::cout<<  "|\n";
        std::cout<<  "|___\n";
    }

    //No of wrong guesses=3
    if(wrongGuess==3)
    {
        std::cout<<"     _______\n";
        std::cout<<   "|/      |\n";
        std::cout<<   "|      (_)\n";
        std::cout<<  "|       |\n";
        std::cout<<  "|       |\n";
        std::cout<<   "|       |\n";
        std::cout<<  "|\n";
        std::cout<<  "|___\n";
    }

    //No of wrong guesses=2
    if(wrongGuess==2)
    {
        std::cout<<"     _______\n";
        std::cout<<   "|/      |\n";
        std::cout<<   "|      (_)\n";
        std::cout<<  "|\n";
        std::cout<<  "|\n";
        std::cout<<   "|\n";
        std::cout<<  "|\n";
        std::cout<<  "|___\n";
    }

    //No of wrong guess=1
    if(wrongGuess==1)
    {
        std::cout<<"     _______\n";
        std::cout<<   "|/      |\n";
        std::cout<<   "|\n";
        std::cout<<  "|\n";
        std::cout<<  "|\n";
        std::cout<<   "|\n";
        std::cout<<  "|\n";
        std::cout<<  "|___\n";
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

    std::cout << "\n\n...WELCOME...\n\n";

    std::cout << " _   _                                         " << endl;   
    std::cout << "| | | |                                        " << endl;
    std::cout << "| |_| |  __ _ _ __   __ _ _ __ ___   __ _ _ __ " << endl;
    std::cout << "|  _  | / _` | '_ | / _` | '_ ` _ | / _` | '_ |" << endl;
    std::cout << "| | | | (_| | | | | (_| | | | | | | (_| | | | |" << endl;
    std::cout << "|_| |_| __,_|_| |_| __, |_| |_| |_| __,_|_| |_|" << endl;
    std::cout << "                    __/ |                      " << endl;
    std::cout << "                   |___/                       " << endl;


	std::cout << endl;
    std::cout << "Guess name of a state of India";
    std::cout << endl;
    std::cout << endl;
	std::cout << "Each letter is represented by a star.";
    std::cout << endl;
	std::cout << "You have to type only one letter in one try";
    std::cout << endl;
	std::cout << "You have " << MAX_TRIES << " tries to try and guess the word.";
    std::cout << endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    //Rules
    std::cout << endl;
    std::cout << endl;
    std::cout << "RULES:";
    std::cout << endl;
    std::cout << "If a guessed letter is present in the word, it is revealed in the correct positions.";
    std::cout << endl;
	std::cout << "If a guessed letter is not in the word, a part of the hangman figure is drawn.";
    std::cout << endl;
    std::cout << "The game continues until the players guess the word correctly or the hangman figure is completed.";
    std::cout << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    //Continue the loop until the available guesses are exhausted
	while (wrongGuess < MAX_TRIES)
	{
	    std::cout << endl;
	    std::cout << endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << endl;
        std::cout << "Word is :  ";
		std::cout << unknown;
        std::cout << endl;
        std::cout << endl;
		std::cout << "Guess a letter: ";
		cin >> letter;

		//Fill secret word with letter if the guess is correct,
		//Or else increment the number of wrong guesses.

        //if wrong letter was guessed
		if (letterCheck(letter, word, unknown)==0)
		{
			std::cout << endl << "Umm! Sorry,but the guess was incorrect" << endl;
			wrongGuess++;
			HangMan(wrongGuess);
		}

        //if correct letter was guessed
		else
		{
			std::cout << endl << "Woah!! You found a letter" << endl;
		}

		//Number of guesses left
        std::cout << endl;
		std::cout << "You have " << MAX_TRIES - wrongGuess;
		std::cout << " guesses left." << endl;

		//Guessed correct word
		if (word==unknown)
		{
			std::cout << word << endl;
			std::cout << "Congratulations! You got it!";
			break;
		}
	}

    //All tries exhausted
    //hence the game will end

	if(wrongGuess == MAX_TRIES)
	{
        std::cout << endl;
		std::cout << "Sorry, you have run out of tries....";
        std::cout << endl;
        std::cout << "You've been hanged";
        std::cout << endl;
		std::cout << "The word was : " << word;
        std::cout << endl;
	}


	return 0;
}
