#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int main(){

    int sockfd;
    char buff[MAX];
    struct sockaddr_in servaddr;
  
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    for(;;){
        int n, len;
        len = sizeof(servaddr);
        bzero(buff,MAX);
        scanf("%[^\n]%*c", buff);
        sendto(sockfd, (const char *)buff, strlen(buff),
            MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
                len);
        
        n = recvfrom(sockfd, (char *)buff, MAX,MSG_WAITALL, (struct sockaddr *) &servaddr,&len);
        printf("From server: %s (msg length: %ld chars)\nTo server : ", buff, strlen(buff));
        // printf("Server : %s\n", buff);
    }
    

    return 0;
}