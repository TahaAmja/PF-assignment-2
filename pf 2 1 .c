#include<stdio.h>
int main()
{
int m,n;
int x;
int min2;
int arr[5];
printf("Enter an array:");
for(n=0;n<5;n++)
{
scanf(" %d " ,&arr);
if(arr[n] > 9999)
{break;}
}
int min=arr[0];
for(m=0;m<3;m++)
{if(arr[m]<min)
min=arr[m];

}
 
min2=arr[0];
for(m=0;m<3;m++)
{if(arr[m]<min2 && arr[m]!=min)
min2=arr[m];
}
printf("Second minimum number is: %d " , min2);
return 0;}