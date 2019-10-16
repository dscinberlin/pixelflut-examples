#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>

#define SERVER_ADDR "35.242.250.117"
#define PORT 1234

int main()
{
    int sockfd;
    struct sockaddr_in dest;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket");
        exit(errno);
    }

    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(PORT);
    if (inet_aton(SERVER_ADDR, (struct in_addr *)&dest.sin_addr.s_addr) == 0)
    {
        perror(SERVER_ADDR);
        exit(errno);
    }

    if (connect(sockfd, (struct sockaddr *)&dest, sizeof(dest)) != 0)
    {
        perror("Connect ");
        exit(errno);
    }

    char buf[100];
    for (int x = 0; x < 1920; x++)
    {
        for (int y = 0; y < 1080; y++)
        {
            sprintf(buf, "CC %d %d %X\n", x, y, 0xFFAAFF);
            send(sockfd, buf, strlen(buf), 0);
        }
    }

    close(sockfd);
    return 0;
}
