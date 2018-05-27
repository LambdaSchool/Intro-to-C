#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] =
		{
				"             +         +----     +----     +----     +----     +----     +----     +----  ",
				"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
				"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
				"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
				"             |         |         |         |         |         |         |  /      |  / \\ ",
				"             |         |         |         |         |         |         |         |      ",
				"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

// void printTurn(int guesses, char *guessedStr, char *charsGuessed)
// {
// 	int low = guesses * 10;
// 	int high = (guesses * 10) + 9;
// 	// Prints Hangman pic
// 	for (int i = 0; i <= 6; i++)
// 	{
// 		for (int j = low; j <= high; j++)
// 		{
// 			printf("%c", HANG_STATES[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	// Prints current guessedString
// 	printf("\n%s\n", guessedStr);
// 	//Prints letters guessed so far
// 	printf("\nLetters Guessed so far: %s\n", charsGuessed);
// }

// char *getGuess()
// {
// 	char *guess;
// 	printf("\n\nGuess a letter or the word. Enter quit to leave: ");
// 	scanf("%s", guess);
// 	if (strncmp(guess, "quit", 5) == 0)
// 	{
// 		printf("\n\nCome play again soon!\n\n\n");
// 		exit(3);
// 	}
// 	return guess;
// }

int main(int argc, char *argv[])
{
	/* Your code here */
	char *word;
	char lettersGuessed[100];
	// char *currentGuess;
	int guesses = 0;

	if (argc == 1)
	{
		printf("usage: ./hangman [word to guess]\n");
		exit(1);
	}
	else if (argc > 2)
	{
		printf("useage: ./hangman [word to guess]\n");
		exit(2);
	}
	else
	{
		if (strncmp(argv[1], "quit", 5) == 0)
		{
			printf("Word input can not be \"quit\"\n");
			exit(4);
		}
		word = argv[1];
	}
	char guessedString[strlen(word)];
	for (int i = 0; i < strlen(word); i++)
	{
		guessedString[i] = '-';
	}
	guessedString[strlen(word)] = '\0';
	// printf("guessedString: %s\n", guessedString);

	while (guesses < 8)
	{
		char *currentGuess;
		// printf("guessedString 1: %s\n", guessedString);

		int low = guesses * 10;
		int high = (guesses * 10) + 9;
		// Prints Hangman pic
		printf("\n________________________________________\n\n");
		for (int i = 0; i <= 6; i++)
		{
			for (int j = low; j <= high; j++)
			{
				printf("%c", HANG_STATES[i][j]);
			}
			printf("\n");
		}
		// Prints current guessedString
		printf("\n%s\n", guessedString);
		//Prints letters guessed so far
		printf("\nLetters Guessed so far: %s\n", lettersGuessed);

		printf("\n\nGuess a letter or the word. \nEnter quit to leave: ");
		scanf("%s", currentGuess);
		if (strncmp(currentGuess, "quit", 5) == 0)
		{
			printf("\n\nCome play again soon!\n\n\n");
			exit(3);
		}
		// printf("guessedString 2: %s\n", guessedString);

		if (strlen(currentGuess) == 1)
		{
			int changed = 0;
			for (int i = 0; i < strlen(word); i++)
			{
				if (guessedString[i] == '-' && word[i] == currentGuess[0])
				{
					guessedString[i] = currentGuess[0];
					if (changed == 0)
						strcat(lettersGuessed, currentGuess);
					changed = 1;
				}
			}
			if (changed == 0)
			{
				guesses++;
			}
		}
		else
		{
		}
		// printf("word: %s\n", word);
		if (strncmp(word, currentGuess, strlen(word)) == 0 || strncmp(word, guessedString, strlen(word)) == 0)
		{
			// printf("word: %s\ncurrentGuess: %s\n", word, currentGuess);
			printf("\n\nThe word was \"%s\"\nGreat Job! You win!\n\n\n", word);
			exit(42);
		}
		if (guesses == 8)
		{
			printf("\n\nThe word was \"%s\"\nSorry, try again.\n\n\n", word);
			exit(5);
		}
	}

	return 0;
}
