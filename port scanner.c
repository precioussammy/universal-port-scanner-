#include <stdio.h> 
#include "cs50.h"

#ifdef _WIN32
    #include <winsock2.h>
    #define  CLOSE_SOCKET closesocket
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define  CLOSE_SOCKET close
    #define  SOCKET int 
#endif    

void scan_host(int port_number);

int main(void)
{
    
    #ifdef _WIN32
        WSADATA wsa;
        WSAStartup(MAKEWORD(2,2), &wsa);
    #endif

    
    int target_port = get_int("Enter port to scan: ");

    printf("\nScanning local machine...\n");
    
    
    scan_host(target_port);

    
    #ifdef _WIN32
        WSACleanup();
    #endif

    return 0;
}
void scan_host(int port_number)
{
    
    SOCKET my_socket = socket(AF_INET, SOCK_STREAM, 0);

    
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port_number);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");

    
    int result = connect(my_socket, (struct sockaddr *)&target, sizeof(target));

    
    if (result == 0)
    {
        printf("Port %i --> [OPEN]\n", port_number);
    }
    else
    {
        printf("Port %i --> [CLOSED]\n", port_number);
    }

    
    CLOSE_SOCKET(my_socket);
}