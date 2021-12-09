#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char* argv)
{
   int i=0;
   int s;
   int j,count=0;
   double pi;
   double x,y,z;

   printf("Enter the number of trials");
   scanf("%d",&i);
   printf("Enter the seed value");
   scanf("%d",&s);
   
   srand(s);
   for (j=0;j<i;j++) 
   {
       x=(double)rand()/RAND_MAX;
       y=(double)rand()/RAND_MAX;
       z=x*x+y*y;
       if (z<=1)
           count++;
       }
   pi=(double)count/i*4;
   printf("Pi val:%g\n",pi);
}
 
