#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/utsname.h>
#include <dirent.h>

class utils{
    public:
     static  int getSystemVersion();
     static  int getFilelist(char * path,list_t &list);
};