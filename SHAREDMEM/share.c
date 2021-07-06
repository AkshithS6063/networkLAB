#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/ipc.h>
int main()
{
 int val,*shmptr, shmid;
 printf("\nEnter the value: ");
 scanf("%d",&val);
 shmid=shmget(4567,2,IPC_CREAT|0666);
 shmptr=shmat(shmid,NULL,0);
 int b=fork();
 if(b>0)
 {
   *shmptr=val;
 }
 else
 {
   val=val*val;
   *shmptr=val;
   printf("New value: %d\n",*shmptr);
 }
 shmdt(shmptr);

}