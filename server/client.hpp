 #include "utils/utils.hpp"   


typedef enum TYPE{
    MSG_DOWN = 1,
    MSG_UP,
    MSG_FILE
}TYPE;

typedef struct message{
    int client_id, // 客户端 id
    TYPE type, // 消息类型
    int size, // 数据大小
    void * buf // 数据
}message;

class Client{
    public:
        Client(int id):client_id(0){this->client_id = id;};
    private:
        int client_id;
        message msg;
        sockaddr_in addr;
};


