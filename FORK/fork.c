#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{  
int f1,f2;
f1=fork();
if(f1==0)
{
 printf("\nchild process is created: %d\n", getpid());
 printf("\nparent process of child1: %d\n", getppid());
}
else if(f1>0)
{
 printf(" \nparent process is created: %d\n", getpid());

 f2=fork();
 if(f2==0)
 { 
   printf("\nChild process is created: %d\n",getpid());
   printf("\nparent process of child2: %d\n", getppid());
 }
 else if(f2>0)
 {
  printf(" \nparent process is created: %d\n", getpid());
 }
 else
 {
   printf("\nprocess creation is failed\n");
 }
}
else
 {
  printf("\nprocess creation is failed\n");
 }
}