#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
  int f1,f2,f3,f4;
  f1 = fork();
  if(f1 > 0)
  {
    f2 = fork();
    if(f2 > 0)
    {
      printf("Parent process P: %d\n",getppid());
    }
    else if(f2 == 0)
    {
      printf("Child Process C2: %d \tParent ID: %d\n", getpid(),getppid());
    }
  }
  else if(f1 == 0)
  {
    f3 = fork();
    {
      if(f3>0)
      {
        //printf("Child process C1: %d\n",getpid());
        f4=fork();
        if(f4>0)
        {
          printf("Child Process C1: %d \tParent ID: %d\n",getppid(),getppid());
        }
        else if(f4 == 0)
        {
          printf("Child Process C4: %d \tParent ID: %d\n",getpid(),getppid());
        }
      }
      else if(f3==0)
      {
        printf("Child process C3: %d \tParent ID: %d\n",getpid(),getppid());
      }
    }
  }
  else
  {
    printf("Error\n");
  }
}