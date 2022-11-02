/*write a function that converts all white space in a string to underscores.
Write a program that asks user to enter a string. When user has entered a string, the program calls
the function above and prints the string. The program keeps asking for strings until user enters
"stop" or "STOP". When user enters stop the program terminates.
Note. To avoid platform dependent problems with string use strncmp and compare only the first
four characters to detect stop.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


void convert(char* string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == ' ')
		{
			string[i] = '_';
		}
		if (string[i] == '\t')
		{
			string[i] = '_';
		}
		if (string[i] == '\n')
		{
			string[i] = '_';
		}
		if (string[i] == '\v')
		{
			string[i] = '_';
		}
		if (string[i] == '\f')
		{
			string[i] = '_';
		}
		if (string[i] == '\r')
		{
			string[i] = '_';
		}
	}

	printf("%s\n\n", string);
}


void convert(char* string);
int main(void)
{
	printf("This program converts all spaces in a string to an underscore\n");
	printf("up to 100 characters long.\n");
	printf("You can stop the program by typing stop or STOP.\n\n");

	char typed_text[150];
	while (1)
	{
		printf("Please enter your text:\n");
		fgets(typed_text, 150, stdin);

		if (typed_text[strlen(typed_text) - 1] == '\n')
		{
			typed_text[strlen(typed_text) - 1] = '\0';
		}

		if (strcmp(typed_text, "stop") == 0 || strcmp(typed_text, "STOP") == 0)
		{
			break;
		}

		convert(typed_text);
	}

	return 0;

}
