#include "utils/utils.hpp"
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

int Server::socket()
{
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
    {
        printf("error: socket create \n");
        return -1;
    }
}

int Server::bind(uint16_t port,uint32_t ip)
{
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = htonl(ip);
    if(bind(sockfd,(struct sockaddr *)&s_addr,sizeof(s_addr)) < 0)
    {
        printf("error : bind address \n");
        return -2;
    }
}

int Server::connect()
{
    socket();
    bind();
}

int Server::disconnect()
{
    close(sockfd);
    delete s;
}


void Server::doLoop(void * data)
{   
    FILE * fp_r = NULL,* fp_w = NULL;
    char * buf = new char[1024 * 4];
    char * sendbuf = new char[1024*4];
    int size = -1;
    message msg;

    msg.size = 4 * 1024;
    msg.buf = buf;
   
    utils::getFilelist("./download",&filelist);

    while(1)
    {
            size = recvfrom(sockfd,(void *)&msg,1024,0,(sockaddr *)&addr,sizeof addr);
            if(size > 0)
            {
                printf("reciver size :  %d byte %s\n",size,msg.buf);
                switch(msg.type)
                {
                    case MSG_FILE:
                               fp_r = fopen(msg.buf,"r+");
                        break;
                    case MSG_DOWN:
                             size = fread(sendbuf,1024*4,1,fp);
                             if(size > 0)
                                sendto(sockfd,sendbuf,4*1024,1,(sockaddr *)&addr,sizeof addr);
                         
                    default:
                        fp_w = fopen(msg.buf,"w+");
                        fwrite(msg.buf,msg.size,1,fp_w);
                        break;
                }
            }
    }
    
}