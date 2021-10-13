// CodeHunter.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string textToAnalyze;
	int foo = 0;
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int spaces = 0;
	int lengthOfStringSubmittedForAnalysis = 0;
	int unknownCharacters = 0;
	int checkSum = 0;
	int bar = 0;

	cout << "Welcome to the CIA Code Hunter Program!" << endl;
	cout << "Please type in text to analyze: " << endl;

	/* This is a form of cin I haven't seen before, but based on what I remember from the book 
	cin << userInput doesn't work great for longer input.
	So getline takes everything and stores it in the variable textToAnalyze. */
	getline(cin, textToAnalyze);
	cout << "\n\n";

	// This for loop will repeat a number of times equal to the length of the string that the player input.
	for (int i = 0; i < textToAnalyze.length(); ++i)
	{
		/* This if condition is detecting whether the character in the current loop is a vowel.
		textToAnalyze[i] when i=0 would be looking at the first character in the string, i=1 would be looking at the second character, etc. */
		if (textToAnalyze[i] == 'a' || textToAnalyze[i] == 'e' || textToAnalyze[i] == 'i' ||
			textToAnalyze[i] == 'o' || textToAnalyze[i] == 'u' || textToAnalyze[i] == 'A' ||
			textToAnalyze[i] == 'E' || textToAnalyze[i] == 'I' || textToAnalyze[i] == 'O' ||
			textToAnalyze[i] == 'U')
		{
			/* After debugging it's clear this was likely meant to be a ++vowels, not --vowels, so that it displays a positive number of vowels used in the string.
			After each character in the string is divided up and then added back together to equal checkSum, it would be way off due to adding a negative number*/
			++vowels;
		}
		/* This else if is checking whether the character in the current loop is a consonant.
		Even though the else if would allow a vowel input, the if above would always fire first and skip the else if. */
		else if ((textToAnalyze[i] >= 'a' && textToAnalyze[i] <= 'z') || (textToAnalyze[i] >= 'A' && textToAnalyze[i] <= 'Z'))
		{
			/* After debugging it's clear this was not meant to be commented, as then the compiler treats it as whitespace and consonants would never increase.
			After each character in the string is divided up and if there were 5 consonants total, checkSum would be 5 less than what it should be. */
			++consonants;
		}
		// This else if is checking whether the character in the loop is an integer.
		else if (textToAnalyze[i] >= '0' && textToAnalyze[i] <= '9')
		{
			++digits;
		}
		// This else if is checking whether the character is just a space.
		else if (textToAnalyze[i] == ' ')
		{
			++spaces;
		}
		// If none of the ifs conditions above are met, the character is branded as being unknown. This would include every symbol on the keyboard.
		else
		{
			++unknownCharacters;
		}
	}

	// lengthOfStringSubmittedForAnalysis is set equal to the length of the string the user input
	lengthOfStringSubmittedForAnalysis = textToAnalyze.length();

	// checkSum is set equal to all the things that were separated and iterated above combined, which if everything is working properly, should still equal textToAnalyze.length()
	checkSum = unknownCharacters + vowels + consonants + digits + spaces;

	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White spaces: " << spaces << endl;
	cout << "Length of string submitted for analysis: " << lengthOfStringSubmittedForAnalysis << endl;
	cout << "Number of characters CodeHunter could not identify: " << unknownCharacters << endl;
	cout << "Checksum: " << checkSum << endl;

	// This compares checkSum to lengthOfStringSubmittedForAnalysis. If it's true, the if's condition is met.
	if (checkSum == lengthOfStringSubmittedForAnalysis)
	{
		cout << "This program self checking has found this Analysis to be valid." << endl;
	}
	// If the condition wasn't met, it'll move on to the else, which will tell you something went wrong.
	else
	{
		cout << "WARNING! *** This program self checking has found this Analysis to be invalid! Do not use this data!" << endl;
	}

	system("pause");

	return 0;
}