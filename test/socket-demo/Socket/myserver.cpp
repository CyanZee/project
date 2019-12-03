#include <iostream>
#include <thread>
#include "Socket.hpp"

using namespace std;

void run_recv(Socket::UDP sock)
{
    while(1)
    {
        Socket::Datagram received = sock.receive();
        cout << received.data << endl;
    }
}

void say_hello(Socket::UDP &sock)
{
    sock.send("127.0.0.1", 3000, "Hello!");
}

int main(int argc, const char *argv[])
{
    try
    {
        Socket::UDP sock;
        sock.bind(2000);

        std::thread recv_thr;
        recv_thr = std::thread(&run_recv, sock);
        recv_thr.detach();

        int option;
        while(1)
        {
           cout << "Enter your option: " << endl;
           cin >> option;
           switch(option)
           {
               case 0:
                   goto Exit_Code;
               case 1:
                   say_hello(sock);
                   break;
               case 2:
                   break;
               default:
                   break;
           }
        }
        Exit_Code:
            sock.close();
    }
    catch (Socket::Exception &e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}

