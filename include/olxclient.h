#pragma once
#include"client.h"
typedef struct RES_auth{
    cl_packres_t pack;
    char name[100];
    char password[20];
}RES_auth_t;
void CreateRES_auth(RES_auth_t* auth);
cl_json_construct_t RES_auth_getjson(RES_auth_t* auth);
typedef struct REQ_status{
    cl_packreq_t pack;
    int code;
}REQ_status_t;
void CreateREQ_status(REQ_status_t* status);
bool REQ_status_jsontoobject(REQ_status_t* status,json_value* values);
void REQ_status_process(REQ_status_t* status);
void InitREQpack(cl_client_t* client);

