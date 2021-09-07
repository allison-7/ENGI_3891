//Original by Mitchell Stride
//Edited by Daniel Power
#include <iostream>
#include "hangman.h"

using namespace std;
//fixed style
int main()
{
	char answer;
    	cout << "Would you like to play hangman? (y/n)";
    	cin >> answer;
      	if(answer != 'y')
	{
		cout << "Goodbye" << endl;
        	return 0;
        }
   	cout<< "Awesome lets begin!" << endl;
      	string secretword = "runescape";
      	bool win = playHangman(secretword, 8);
        if (win)
	{
        	cout << "Test finished, You won!" << endl;
        }
        else
	{
         	 cout << "Test  finished, You lost!" << endl;
        }
	return 0;
}

char getNextGuess(const char letters[], unsigned int length)
{
	char guessedLetter;
	//added a for loop to check if the letter had already been guessed
	for (int i=0;i<length;i++)
	{
		if (i==0)
			cin>>guessedLetter;
		if (guessedLetter == letters[i])
		{
			cout<<"You already guessed that letter"<<endl;
			i=0;
		}
	}
	return guessedLetter;
}
