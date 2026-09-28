#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000
void main()
{
int si = 0, di = 0, count = 0; /* si = source index, di = destination index*/
char str[MAX], dest[MAX];
char flag[MAX] = "01111110";
clrscr(); //clear the screen
printf("Enter the user data in 1's & 0's :");
scanf("%s", str);
di=strlen(flag); //get the string length of 'flag'
strcpy(dest,flag); //copy 'flag' to 'dest'
//start of stuffing
while(str[si] != '\0')
{
if(str[si] == '1')
count++;
else
count = 0;

Page 20 of 43

dest[di++] = str[si++];
if(count == 5)
{
count = 0;
dest[di++] = '0'; //bit stuffed
}
} // end of while loop
dest[di] = '\0'; //add null char to the end of 'dest'
strcat(dest, flag); //concatenate 'dest' & 'flag'
printf("Stuffed message is :%s", dest);
// end of stuffing
di = strlen(dest) - strlen(flag);
dest[di] = '\0'; // to remove trailing flag
for(di = strlen(flag), si = 0; dest[di]!='\0'; si++, di++)
str[si] = dest[di];
str[si] = '\0'; //add null char to the end of 'str'
//start of destuffing
si = 0, di = 0, count = 0;
while(str[si] != '\0')
{
if(str[si] == '1')
count++;
else
count = 0;
dest[di++] = str[si++];
if(count == 5)
{
count = 0;
si++; //skip the bit '0' that was stuffed
}
} // end of while loop
dest[di] = '\0';
//end of destuffing
printf("\nDestuffed message is :%s", dest);
getch();
}
