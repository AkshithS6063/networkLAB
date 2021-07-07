#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int main(){

    int sockfd;
    char buff[MAX];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr , cliaddr ; 

    sockfd = socket(AF_INET , SOCK_DGRAM , 0);

    bzero(&servaddr, sizeof(servaddr));
    bzero(&cliaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (SA*)&servaddr, sizeof(servaddr));

    int len , n ;
    len = sizeof(cliaddr);

    n = recvfrom(sockfd, (char *)buff, MAX,MSG_WAITALL, (struct sockaddr *)&cliaddr,&len);
    buff[n] = '\0';
    printf("Client : %s\n", buff);

    sendto(sockfd, (const char *)hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
            len);
    printf("Hello message sent.\n"); 

    return 0;
}