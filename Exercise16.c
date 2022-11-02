#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 2048
#define FILENAME 1
#define LINE_NUMBER 2

bool read_string_from_file(char* str, int size, FILE* file)
{
	if (fgets(str, size, file) != NULL)
	{
		size_t len = strlen(str);
		if (str[len - 1] == '\n')
		{
			str[len - 1] = '\0';
		}
	}
	return true;
}

bool isNumber(char number[])
{
	int i = 0;


	if (number[0] == '-')
		i = 1;
	for (; number[i] != 0; i++)
	{
		
		if (!isdigit(number[i]))
			return false;
	}
	return true;
}

void error_handling(int argc, char **argv)
{
	
	if (argc == 1) {
		printf("Please enter the filename as the first parameter and line number as the second parameter(User did not enter any parameter!)\n");
		exit(1);
	}
	
	else if (argc == 2 && !isNumber(argv[FILENAME]))
	{
		printf("Please enter line number as the second parameter\n");
		exit(1);
	}
	
	else if (argc == 2 && isNumber(argv[FILENAME]))
	{
		printf("Please enter the filename as the first parameter and line number as the second parameter\n");
		exit(1);
	}
	
	else if (isNumber(argv[FILENAME]))
	{
		printf("Parameter 1 should be the filename.(User has entered a number!)\n");
		exit(1);
	}
	
	else if (!isNumber(argv[LINE_NUMBER]))
	{
		printf("Parameter 2 should be the line number.(User has entered a string!)\n");
		exit(1);
	}
	
	else if (atoi(argv[LINE_NUMBER]) <= 0)
	{
		printf("Line number should be greater than '0'");
		exit(1);
	}


}

void print_from_nth_line(int argc, char **argv, char* str, FILE *file)
{
	bool keep_reading = true;
	int current_line = 1;

	do
	{
		read_string_from_file(str, MAX_SIZE, file);

		if (feof(file))
		{
			keep_reading = false;
			if (current_line < atoi(argv[LINE_NUMBER]))
			{
				printf("file %s does not have %s lines", argv[FILENAME], argv[LINE_NUMBER]);
			}
		}

		if (current_line == atoi(argv[LINE_NUMBER]))
		{
			printf("%s\n", str);
			while (!feof(file)) {
				read_string_from_file(str, MAX_SIZE, file);
				printf("%s\n", str);
			}
			keep_reading = false;
		}
		current_line++;

	} while (keep_reading);
}

int main(int argc, char** argv)
{
	char str[MAX_SIZE];

	
	error_handling(argc, argv);

	
	FILE* file;
	file = fopen(argv[FILENAME], "r");

	if (file == NULL)
	{
		printf("Unable to open %s file", argv[FILENAME]);
		exit(1);
	}

	print_from_nth_line(argc, argv, str, file);

	fclose(file);

	return 0;
}
