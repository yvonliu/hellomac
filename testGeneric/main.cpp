#include <iostream>
#include <cstdint>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

void print_addrinfo(addrinfo * ai)
{
    if (AF_INET == ai->ai_family )
    {
        sockaddr_in * addr = reinterpret_cast<sockaddr_in*>(ai->ai_addr);
        cout << "sin_family: " << (int) addr->sin_family << endl;
        cout << "sin_port: " << ntohs(addr->sin_port)<< endl;
        cout << "sin_addr: " << addr->sin_addr.s_addr << endl;

        char buf[INET_ADDRSTRLEN] = {0};
        inet_ntop(AF_INET, &(addr->sin_addr), buf, sizeof(buf));
        cout << buf << endl;
    }
    else if (AF_INET6 == ai->ai_family)
    {
        sockaddr_in6 * addr = reinterpret_cast<sockaddr_in6*>(ai->ai_addr);
        cout << "sin_family: " << (int) addr->sin6_family << endl;
        cout << "sin_port: " << ntohs(addr->sin6_port) << endl;
        cout << "sin_addr: ";

        char buf[INET6_ADDRSTRLEN] = {0};
        inet_ntop(AF_INET6, &(addr->sin6_addr), buf, sizeof(buf));
        cout << buf << endl;
    }
}
int main(int argc, char** argv)
{
    addrinfo * ai;
    addrinfo hints = {0};

    hints.ai_flags = AI_ADDRCONFIG;
    hints.ai_socktype = SOCK_STREAM;

    int e = getaddrinfo(argv[1], "http", &hints, &ai);
    if (e != 0)
    {
        cout << "error getaddrinfo: " << e << endl;
        return e;
    }

    for (addrinfo * p = ai; p != NULL; p = ai->ai_next)
    {
        print_addrinfo(p);
        int sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock != -1)
        {
            if (0 == connect(sock, p->ai_addr, p->ai_addrlen))
            {
                cout << "!!!connected!!!" << endl;
                close(sock);
                break;
            }
            cout << "no connection..." << endl;
            close(sock);
        }
    }
    freeaddrinfo(ai);
    return 0;
}