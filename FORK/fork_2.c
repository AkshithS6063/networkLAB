#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{  
int f1,f2,f3;
f1=fork();
if(f1==0) //c2
{
 printf("\nchild2 process is created: %d\n", getpid());
}
else if(f1>0) //p1
{
 printf(" \nparent process is created: %d\n", getppid());
 f2=fork();
 if(f2==0) //c1
 {
    printf("\nChild1 process is created: %d\n",getpid());
   f3=fork();
   if(f3==0) 
   {
     printf("\nChild3 process is created: %d\n",getpid());
    }
   else{
     printf(" \nparent process C1 created: %d\n", getppid());
     }
  }
 else if(f2>0) //p1
 {
  printf(" \nparent process is created: %d\n", getppid());
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
return 0; 
}