#include "utils.hpp"


int utils::getSystemVersion()
{   
    int ret = -1;
    struct utsname name;
   // char version[_UTSNAME_MACHINE_LENGTH];

    uname(&name);
    printf("version %s",name.machine);
    if(strncmp(name.machine,"x86_64",_UTSNAME_MACHINE_LENGTH) == 0)
    {
        return 64;
    }
    
    return 32;
}

int utils::getFilelist(char * path,list_t &list)
{
    int retval = -1;
    struct stat files;
    struct DIR * dir;
    struct dirent* dirs;

    dir = opendir(path);
    if(!dir){
        printf("error : Failed to opendir %s",path);
        return -1;
    }
    while(dirs = readdir(dir))
    {
        if(dirs->d_type & DT_REG)
        {
            list->push_back(string(dirs->d_name));
        }
    }
    //retval = stat(".",&files);
    return 0;
}