
#include "server.hpp"
// typedef struct message{
//     int client_id, // 客户端 id
//     int type, // 消息类型
//     int size, // 数据大小
//     void * buf // 数据
// }message;

Server * Server::getServer()
{
    if(!s)
    {
        s = new Server();
    }

    return s;
}

Server::Server(){
}

Server::Server(uint16_t port,uint32_t ip)
{
 
}

Server::init()
{
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
    {
        printf("error: socket create \n");
        return -1;
    }
}