#include "server.hpp"
// udp server 下载
int main(int argc,char argv[])
{
    int sockfd = -1;
    struct sockaddr_in s_addr;
    list_t<string> list;
    //string filename;
    getFilelist("./download",list);



    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(8880);
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd,(struct sockaddr *)&s_addr,sizeof(s_addr)) < 0)
    {
        printf("error : bind address \n");
        return -2;
    }

    thread t(download,);
    // if(listen(sockfd,20) < 0)
    // {
    //     perror("listen\n");
    //     return -3;
    // }
    
    
}