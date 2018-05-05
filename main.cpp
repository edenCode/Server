#include "server/server.hpp"
// udp server 下载
int main(int argc,char argv[])
{
    Server * s = Server.getServer();
    
    s->connect();
    
    s->doLoop(NULL);
}