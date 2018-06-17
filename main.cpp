#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <unistd.h>

int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
//        exit(1);
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        return 2;
    }

    char message[] = "Hello there0123456789!\n";
    char buf[1024];

    send(sock, message, 1024, 0);
    recv(sock, buf, 1024, 0);

    printf(buf);
    close(sock);

    return 0;
}