#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
  
int main() {
  int fd1[2];
  int fd2[2];
  pid_t p;
  char string1[] = " Akshith";
  char string2[] = "S";
  pipe(fd1);
  pipe(fd2);
  p = fork();
  if (p > 0) {
    char output[20];
    close(fd1[0]);
    write(fd1[1], string2, strlen(string2)+1);
    close(fd1[1]);
    wait(NULL);
    close(fd2[1]);
    read(fd2[0], output, 20);
    printf("%s\n", output);
    close(fd2[0]);
  } else {
    int i;
    close(fd1[1]);
    char input[20];
    read(fd1[0], input, 20);
    int len = strlen(input);
    input[len++] = '\0'; 
    strcat(input, string1);
    close(fd1[0]);
    close(fd2[0]);
    write(fd2[1], input, strlen(input)+1);
    close(fd2[1]);
    exit(0);
  }
}