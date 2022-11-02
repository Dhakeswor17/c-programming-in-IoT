/*Ex 9.
Write a function that takes a pointer to student information structure and a string (city) as a
parameter and returns an integer. The function prints all students that live in the given city. The
information must be printed in formatted columns where text is aligned to left and numbers are
aligned to right. The array of student structures passed as parameter is assumed have a terminating
entry where the student number is zero. The terminating element must not be printed. The function
returns the number of students that were printed.
The student information structure must contain the following information:
? Name of the student
? Student number
? Street address
? City
? Total number of credits
Write a program that defines a 15-element array of students and initializes the array with an
initializer that contains at least 7 students and the terminating entry.
The program asks user to enter a city and prints the students using the function described above. If
no students were printed the program must print: “No students live in the given city”. Then program
asks user to enter another city. Program can be stopped by entering “stop” as the name of the city.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define elements 15
#define INPUT_LEN 200

typedef struct cars {
    char    name[20];
    char    address[20];
    char    city[20];
    int    number[20];
    int     credit;
    bool    avail;
    int LEN;
    int i;
} names;

void read_input(char *str,char *address, char *city,  int *number, int *credit,bool,number);
void displayNames(names *c, char *str);
void res(names *c, char *str);
void printer(names *c, int i);

int main(void)
{
    char str[INPUT_LEN];
    int choice;
    names studens[STUDENT_SIZE] =
    
        {"Santosh", "kilo", "Espooo", 001, 110, false},
        {"Michael", "tikurilla", "Vantaa",002, 230, true},
        {"Rony", "leppavara", "Espoo", 003, 281, false},
        {"Markus", "lintuvara", "Espoo", 004,210, true},
        {"Aneel", "malmi", "Helsinki", 005, 110, true},
        {"Rikka", "kivisto", "Vantaa",006, 212, false},
        {"Nicolas", "kilo", "Espoo", 007, 174, false}
    };

    printf("Please choose an action:\n");
    printf("1. print all student name\n2. print all address  of given student name\n");
    printf("3.total grade of the studnet\n4. quit the program.\nI choose: ");
    read_input(str, &choice, true);

    switch (choice) {
        case 1:
            strcpy(str, "*");
            displayNames(students  , str);
            break;
        case 2:
            printf("Type student number please: ");
            read_input(str, &choice, false);
            displayName(students, str);
            break;
        case 3:
            printf("Type the address of the students: ");
            read_input(str, &choice, false);
            reservation(garage, str);
            break;
        case 4:
            printf("No student live i this city!\n");
            break;
        default:
            
            break;
    }
    return 0;
}

void read_input(char *str, int *choice, bool number)
{
    int i;
    fgets(str, INPUT_LEN, stdin);
        if(str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
        }
    if(number) {
        i = sscanf(str, "%d", choice);
        while(i !=1 || *choice < 1 || *choice > 4) {
            printf("Please choose an action by typing integer in range 1-4: ");
            fgets(str, INPUT_LEN, stdin);
            if (str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
            i = sscanf(str, "%d", choice);
        }
    }
}
void printer(names *c, int i)
{
    printf("No %d: %-6s %-7s %-9s %-7s %7d %-10s",
            i, c->students, c->adddress, c->city, c-student_number>credits;
            
}
int i;
void displayNames(names *c, char *str)

{
    printf("name   address   city     student number  credits");
    for(i = 0; i< STUDENTS_SIZE; i++) {
        if(c[i].avail && strcmp(c[i].students, str) == 0) {
            printer(&c[i],i);
        }
        else if(strcmp("*", str) == 0 && c[i].regN[0] != '\0') {
            printer(&c[i],i);
        }
    }
}
void reservation(students *c, char *str)
{
    bool found = false;
    for(i = 0; i< STUDENT_SIZE; i++) {
        if(strcmp(c[i].regN, str) == 0) {
            found = true;
            c[i].avail = (c[i].avail == true) ? false : true;
            printf("Car with registration number %s now is %s\n",
            c[i].regN, c[i].avail ? "availiable" : "NOT availiable");
        }
        else if (!found && i == STUDENTS_SIZE-1) {
            printf("Student is not found %s is not found.\n", str);
        }
    }
}
