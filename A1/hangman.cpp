#include "hangman.h"
#include <iostream>
#include <cctype>
using namespace std;

int guessLetter (const std::string& word, char letter, char letters[])
{
	int numberofTimes=0;
	letter=(tolower(letter)); //in case the user inputs an uppercase lower
	for (int i =0; i<word.length(); i++)
	{
		if (letter == word[i])
		{
			numberofTimes++;
			letters[i]=letter;
		}
	}
	cout<<"Your word is now :";
	for (int i =0; i<word.length(); i++)
	{
		cout<<letters[i];
	}
	cout<<endl;
	return numberofTimes;
}

bool playHangman(std::string word, unsigned int maxWrong)
{
	unsigned int length = word.length();
	char letters[length];
	char guess;
	int times=0;
	int wrong=0;
	for (int i=0; i<length; i++) //fills letter with *'s
	{
		letters[i]='*';
	}
	for (int i=0; i<length; i++)
	{
		if (letters[i]=='*')
		{
			guess=getNextGuess((const char*)letters, length); //const char* is needed
			times=guessLetter(word, guess,letters);
			if (times == 0)
			{
				wrong++;
				cout<<"You did not guess any characters"<<endl;
				cout<<"You have "<<maxWrong-wrong<<" tries remaining"<<endl;
				i=0;
			}
			if (wrong==maxWrong)
				return false;
			}
		}
	return true;
}
