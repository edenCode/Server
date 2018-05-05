 #include "utils.hpp"   

typedef struct message{
    int client_id, // 客户端 id
    int type, // 消息类型
    int size, // 数据大小
    void * buf // 数据
}message;

class Client{
    public:
        Client(int id):client_id(0){this->client_id = id;};
    private:
        int client_id;
        message msg;
};


