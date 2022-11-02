/*Write a function that takes an array of integers and array size as a parameter and returns a float. The
function calculates average value of the array and returns it.
Write a program that uses an array to hold course grades. The array is initialized to zero in the
beginning. The program asks user how many students are to be graded. Program must not allow
values that are greater that the array size.
Then the program asks user to enter a grade for each student. Only values in the range 0-5 are
accepted. Student number that is displayed to the user is array index + 45000.
(For example if array index is 2 user is asked to enter grade for student nr: 45002)
Program must check that array bounds are not violated!
In the end program calculates the average of course grades using the average function and prints the
average with one decimal accuracy.
Remember to write both function declaration and definition*/



#include<stdio.h>
#define STUDENTS 40
#define GRADE_MIN 0
#define GRADE_MAX 5

float grades_average(int array, int array_size);

int main(void)
{
    int grades[STUDENTS] = {};
    int student_to_grade = STUDENTS;


    
    {
        printf("Enter number of students to be graded, please: ");
        scanf("%d", &student_to_grade);
        if(student_to_grade <=0 || student_to_grade > STUDENTS)
        {
            printf("You can grade only up to %d students\n", STUDENTS);
        }
    } while(student_to_grade <=0 || student_to_grade > STUDENTS);


         for(int i = 0; i<student_to_grade; i++)
    {
        printf("Enter grade of student %d, please: ", 45001+i);
        scanf("%d", &grades[i]);


        while(grades[i] < GRADE_MIN || grades[i] > GRADE_MAX)
        {
            printf("Grade must be in range %d to %d\n", GRADE_MIN, GRADE_MAX);
            printf("Enter grade of student %d within valid range, please: ", 45001+i);
            scanf("%d", &grades[i]);
        }
    }


    float result = grades_average(grades, student_to_grade);
    printf("Average of %d students is %0.2f\n", student_to_grade, result);
    return 0;
}


float grades_average(int *array, int array_size)
{
    int sum = 0;
    for(int i = 0; i<array_size; i++)
    {
        sum += array[i];
    }
    float average = (float) sum/array_size;
    return average;
} 

