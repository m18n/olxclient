#pragma once
#include"client.h"
using namespace client;
extern Client cl;

// typedef struct RES_auth{
//     cl_packres_t pack;
//     char name[100];
//     char password[20];
// }RES_auth_t;
// void CreateRES_auth(RES_auth_t* auth);
// cl_json_construct_t RES_auth_getjson(RES_auth_t* auth);
class REQ_status:public pack{
private:
    int code;
public:
    bool JsonToData(json_value* json){
        json_object_entry* jcode=pars::jsonGetNameKey(json,"code");
        if(jcode!=NULL&&jcode->value->type==json_integer){
            code=jcode->value->u.integer;
            return true;
        }
        return false;
    }
    void ProcessPack(){
        printf("STATUS: %d\n",code);
    }
    void InitPack(){
        idpack=10;
        code=0;
    }
};
void ConnectMainServer();