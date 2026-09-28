#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 1000
void main()
{
int si = 0, di = 0; /* si = source index, di = destination index*/
char src[MAX], dest[MAX];
char flag1[] = "DLESTX", flag2[] = "DLEETX";
clrscr(); //clear the screen
printf("Enter the STRING data : ");
scanf("%s", src);
di=strlen(flag1); //get the string length of 'flag1'
strcpy(dest,flag1); //copy 'flag1' to 'dest'
//start of stuffing
while(src[si] != '\0')
{
if(src[si] == 'D' && src[si+1] == 'L' && src[si+2] == 'E')
{
dest[di+5] = 'E';

}
else

dest[di] = 'D', dest[di+1] = 'L', dest[di+2] = 'E', dest[di+3] = 'D', dest[di+4] = 'L',
di +=6;
si+=3;

Page 24 of 43

dest[di++] = src[si++];

} // end of while loop
dest[di] = '\0'; //add null char to the end of 'dest'
strcat(dest, flag2); //concatenate 'dest' & 'flag2'
printf("Stuffed message is : %s", dest);
// end of stuffing
di = strlen(dest) - strlen(flag2);
dest[di] = '\0'; // to remove trailing flag
for(di = strlen(flag1), si = 0; dest[di]!='\0'; si++, di++)
src[si] = dest[di];
src[si] = '\0'; //add null char to the end of 'src'
//start of destuffing
si = 0, di = 0;
while(src[si] != '\0')
{
{

}
else
if(src[si] == 'D' && src[si+1] == 'L' && src[si+2] == 'E')
dest[di] = 'D', dest[di+1] = 'L', dest[di+2] = 'E';
si +=6;
di+=3;

dest[di++] = src[si++];

} // end of while loop
dest[di] = '\0';
//end of destuffing
printf("\nDestuffed message is : %s", dest);
getch();
}
