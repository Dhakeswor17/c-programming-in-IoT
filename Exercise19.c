#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define LARGEST 0
#define SECOND_LARGEST 1
#define THIRD_LARGEST 2
#define FOURTH_LARGEST 3
#define FIFTH_LARGEST 4

bool read_string(char* str, int size)
{
	if (fgets(str, size, stdin) != NULL)
	{
		size_t len = strlen(str);
		if (str[len - 1] == '\n')
		{
			str[len - 1] = '\0';
		}
		else
		{
			printf("Too long line. Discarding rest of the line");
			while (getchar() != '\n');
		}
	}
	return true;
}

long get_file_size(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
	long seek = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return seek;
}

void get_top_5_max_value(int* letter_count)
{
	/*	arr[0] = largest value
		arr[1] = 2nd largest value
		arr[2] = 3rd largest value
		arr[3] = 4th largest value
		arr[4] = 5th largest value	*/

	int arr[5] = { 0 };

	arr[LARGEST] = letter_count[0];

	int largest_value_index = 0, second_largest_value_index = 0, third_largest_value_index = 0;
	int fourth_largest_value_index = 0, fifth_largest_value_index = 0;
	for (int i = 1; i < 26; i++)
	{
		if (letter_count[i] > arr[LARGEST]) {
			arr[LARGEST] = letter_count[i];
			largest_value_index++;
		}
#if 0
		if (arr[LARGEST] == letter_count[i])
		{
			largest_value_index++;
		}
#endif
	}

	for (int i = 1; i < 26; i++)
	{
		if (letter_count[i] > arr[SECOND_LARGEST] && arr[SECOND_LARGEST] < arr[LARGEST])
		{
			arr[SECOND_LARGEST] = letter_count[i];
			second_largest_value_index++;
		}
		if (arr[SECOND_LARGEST] == arr[LARGEST])
		{
			arr[SECOND_LARGEST] = letter_count[i - 1];
			second_largest_value_index -= 1;
			break;
		}
	}

	for (int i = 1; i < 26; i++)
	{
		if (letter_count[i] > arr[THIRD_LARGEST] && arr[THIRD_LARGEST] < arr[SECOND_LARGEST])
		{
			arr[THIRD_LARGEST] = letter_count[i];
			third_largest_value_index++;
		}
		if (arr[THIRD_LARGEST] == arr[SECOND_LARGEST])
		{
			arr[THIRD_LARGEST] = letter_count[i - 1];
			third_largest_value_index -= 1;
			break;
		}
	}

	for (int i = 1; i < 26; i++)
	{
		if (letter_count[i] > arr[FOURTH_LARGEST] && arr[FOURTH_LARGEST] < arr[THIRD_LARGEST])
		{
			arr[FOURTH_LARGEST] = letter_count[i];
			fourth_largest_value_index++;
		}
		if (arr[FOURTH_LARGEST] == arr[THIRD_LARGEST])
		{
			arr[FOURTH_LARGEST] = letter_count[i - 1];
			fourth_largest_value_index -= 1;
			break;
		}
	}

	for (int i = 1; i < 26; i++)
	{
		if (letter_count[i] > arr[FIFTH_LARGEST] && arr[FIFTH_LARGEST] < arr[FOURTH_LARGEST])
		{
			arr[FIFTH_LARGEST] = letter_count[i];
			fifth_largest_value_index++;
		}
		if (arr[FIFTH_LARGEST] == arr[FOURTH_LARGEST])
		{
			arr[FIFTH_LARGEST] = letter_count[i - 1];
			fifth_largest_value_index -= 1;
			break;
		}
	}

	printf("%-10s%-10s\n", "Letter", "Count");


	printf("%-10c%-10d\n", 'a' + largest_value_index, arr[0]);
	printf("%-10c%-10d\n", 'a' + second_largest_value_index, arr[1]);
	printf("%-10c%-10d\n", 'a' + third_largest_value_index, arr[2]);
	printf("%-10c%-10d\n", 'a' + fourth_largest_value_index, arr[3]);
	printf("%-10c%-10d\n", 'a' + fifth_largest_value_index, arr[4]);



}

int main(void)
{
	FILE* file;
	char filename[32], ch;
	char* words;
	long filesize = 0;
	int top_5_max_value[5] = { 0 };

	printf("Enter filename:");
	read_string(filename, 32);

	file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Unable to open %s file\n", filename);
		exit(1);
	}

	int letter_counts[26] = { 0 };

	filesize = get_file_size(file);

	words = malloc(filesize);
	if (words == NULL)
	{
		printf("Malloc failed\n");
		exit(1);
	}

	while (!feof(file))
	{
		fscanf(file, "%s", words);
		ch = tolower(words[0]);

		//check if it is a letter
		if (ch >= 'a' && ch <= 'z')
		{
			letter_counts[ch - 'a']++;		//increment the respective letter count
		}
	}

	get_top_5_max_value(letter_counts);

	fclose(file);

	return 0;
}
