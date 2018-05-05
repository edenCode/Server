#include <thread>
#include <list>
#include "client.hpp"

#define max 10

class Server{
    public:
        friend thread;
        static Server * getServer();
        int connect();
        int disconnect(int socket);
        int socket();
        int bind(uint16_t port,uint32_t ip):port(htons(8888)),ip(htonl(INADDR_ANY));
        int list_in(Client & c);
        int list_out(Client & c);
        void doLoop(void *);
    private:
        Server();
        Server(uint16_t port,uint32_t ip){
            this->port = port;
            this->ip = ip;
        }
        Server operator _Tp&(Server server){};
    private:
        __uint16_t port;
        __uint32_t ip;
        __int32_t sockfd;
        static Server *s;
        struct sockaddr_in s_addr; // just one client connect
        list<Client> list_t; // 维护list 保存client信息
        list<thread> threadpool;
        list<string> filelist;
};