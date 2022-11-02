  #pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>

#define FILENAME 1
#define SIZE 2

long get_file_size(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
	long seek = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return seek;
}

int main(int argc, char* argv[])
{
	FILE* mainfile_ptr;
	char mainfile[32];

	strcpy(mainfile, argv[FILENAME]);
	mainfile_ptr = fopen(mainfile, "rb");

	if (mainfile_ptr == NULL)
	{
		printf("Unable to open %s file.", argv[FILENAME]);
		exit(1);
	}

	int size_entered_by_user = atoi(argv[SIZE]);

	
	long mainfile_size = get_file_size(mainfile_ptr);


	int nr_of_files = ceil((float)mainfile_size / size_entered_by_user);

	int* data = malloc(mainfile_size);


	if (data == NULL)
	{
		printf("Not able to allocate memory\n");
		exit(1);
	}

	int length = size_entered_by_user / sizeof(data);

	int files_created = 0;
	int j = 0;
	int k = 0;

	for (int i = 0; i < nr_of_files; i++) {

		FILE* file_ptr;
		char filename[64];

		strcpy(filename, mainfile);
		char suffix[16];
		sprintf(suffix, ".part%d%d%d", j, k, i + 1);
		strcat(filename, suffix);

		file_ptr = fopen(filename, "wb");

		if (file_ptr == NULL)
		{
			printf("Unable to open %s file.", filename);
			exit(1);
		}

		
		if (i + 1 == nr_of_files) {
			int temp = size_entered_by_user * i;
			int bytes_of_last_file = mainfile_size - temp;
			int length_for_last_file = ceil((float)bytes_of_last_file / sizeof(data));


			fread(data, sizeof(data), length_for_last_file, mainfile_ptr);

			
			fwrite(data, sizeof(data), length_for_last_file, file_ptr);

		}
		else
		
			
			fread(data, sizeof(data), length, mainfile_ptr);

			
			fwrite(data, sizeof(data), length, file_ptr);
		}

		files_created++;

		
		if (i == 9) {
			k++;
			i = 0;
		}
		if (k == 9 && i == 9) {
			j++;
			k = 0;
			i = 0;
		}

		fclose(file_ptr);
	}

	free(data);

	fclose(mainfile_ptr);

	return 0;
}
