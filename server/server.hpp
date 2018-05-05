
#include <list>
#include "client.hpp"
class Server{
    public:
        static Server * getServer();
        int connect(uint16_t port,uint32_t ip):port(htons(8888)),ip(htonl(INADDR_ANY));
        int disconnect(int socket);
        int setIp(uint32_t ip);
        int setPort(uint16_t port);
        int list_in(Client & c);
        int list_out(Client & c);
    private:
        Server();
        Server(uint16_t port,uint32_t ip){
            this->port = port;
            this->ip = ip;
        }
    private:
        __uint16_t port;
        __uint32_t ip;
        __int32_t sockfd;
        static Server *s;
        list<Client> list_t; // 维护list 保存client信息
};