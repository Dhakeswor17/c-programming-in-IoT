/*Ex. 20
Write a password generator function that takes three parameters: character pointer (array), integer
(size of the array), a const char pointer (a word). The function generates password and stores it in
the array. The password must contain the word given as a parameter reversed at a random location
and the rest of the password contains random printable characters. Note that printable characters
are not limited to alphanumerical characters. Hint: fill the password first with random characters and
then copy random word.
Write a program that asks user to enter a word to place in the password or to enter “stop” to stop
the program. If user does not enter stop the program asks user to enter password length in the
range of length of word + 2 to 30. Then program generates a password using the generator
functionand then prints it. Then the program asks for another word.
For example:
User enters: metropolia, 15
Program prints: #8QailoportemGe
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


void passwordGenerator(char *arr, int length, const char *words[])
{
   arr = (char*)malloc(length*sizeof(char));
    int ran = 0, i = 0, ranpos = 0;
    for (i = 0; i < length; i++)
    {
        ran = (rand()%100);
        arr[i] = ran; 
    }
    ran = (rand()%100)%10;
    i = length - strlen(words[ran]);
    ranpos = (rand()%i*10)%i; 

    for (i = 0; i < strlen(words[ran]); i++)
    {
        arr[ranpos] = words[ran][i];
        ranpos++;
    }

    printf("%d letters random password: ",length);
    for (i = 0; i < length; i++) printf("%c", arr[i]);
    printf("\n");

    free(arr);
    return;
}

int main(){

    srand(time(NULL));
    const char *words[11] = {"fish", "cloud", "shark", "flower", "moon",
                             "sky", "stars", "sleep", "tea", "songs", "\0"};
    printf("Array of ten words: ");
    int i;
    for (i = 0; i<5; i++) {
	
	printf("%s ", words);
    printf("\n");
}
    char *password;
    passwordGenerator(password, 5, words);
    

    return 0;
}
