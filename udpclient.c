#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

char message[] = "Hello Serv!\n";


int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sendto(sock, message, sizeof(message), 0,
           (struct sockaddr *)&addr, sizeof(addr));

    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    send(sock, message, sizeof(message), 0);

    close(sock);

    return 0;
}
