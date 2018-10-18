#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

// Create and return a socket.
int make_socket(uint16_t port) 
{
    int sock;
    struct sockaddr_in name;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Could not create the socket.");
        exit(EXIT_FAILURE);
    }
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl (INADDR_ANY);

    if(bind(sock, (struct sockaddr *) &name, sizeof(name)) < 0) {
        perror("Could not bind socket.");
        exit(EXIT_FAILURE);
    }
    return sock;
}

int main() {
    uint16_t port = 8099;
    int sock = make_socket(port);
    socklen_t size;
    char *msg = "Hello World";
    struct sockaddr_in clientname;
    printf("Listening on port %d\n", port);
    if(listen(sock, 5) < 0) {
        perror("Could not listen.");
        exit(EXIT_FAILURE);
    }
    while(1) {
        size = sizeof(clientname);
        int new = accept(sock, (struct sockaddr *) &clientname, &size);
        if(new < 0) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        fprintf (stderr,
            "Server: connect from host %s, port %hd.\n",
            "Yo bro",
            ntohs(clientname.sin_port));
        write(sock, msg, strlen(msg) + 1);
        //close(new);
    }
}
