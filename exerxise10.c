/*e a program that defines an array of 20 integers. Then program asks user to enter numbers and
to enter a negative number to stop. Program keeps asking more numbers until negative number is
entered or 20 numbers have been read. Then program opens a text file “numbers.txt” for writing,
writes the entered numbers to the file, and closes it. All numbers must be separated by white space*/
#include<stdio.h>
#define LENGTH 20
main(){
int a[20];
int i;

FILE *fp;
fp = fopen("number.txt", "w");
if(fp ==NULL){
	printf("File doesnot exists \n");
	return;
	
}
for(i=0; i< LENGTH; i++){
  printf("Enter the interge %d:\t", i+1);
  scanf("%d", &a[i]);
  if(a[i]<0){
  break;
  }
  fwrite(a, sizeof(int),20,fp);
  
fclose(fp);
  
}

return 0;
}
