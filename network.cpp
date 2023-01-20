#include"network.h"
Client cl;
// void CreateRES_auth(RES_auth_t* auth){
//     cl_CreatePackRes(&auth->pack);
//     auth->pack.GetJsonPack=RES_auth_getjson;
//     auth->pack.idpack=1;
// }
// cl_json_construct_t RES_auth_getjson(RES_auth_t* auth){
//     cl_json_construct_t json;
//     cl_CreateJson_Construct(&json);
//     cl_json_item_t name;
//     cl_CreateJson_Item(&name);
//     cl_json_item_setname(&name,"name");
//     cl_json_item_setstrvalue(&name,auth->name);
//     cl_json_construct_addelement(&json,name);
//     cl_json_item_t password;
//     cl_CreateJson_Item(&password);
//     cl_json_item_setname(&password,"password");
//     cl_json_item_setstrvalue(&password,auth->password);
//     cl_json_construct_addelement(&json,password);
//     return json;
// }
// void CreateREQ_status(REQ_status_t* status){
//     cl_CreatePackReq(&status->pack);
//     status->pack.JsonToObject=REQ_status_jsontoobject;
//     status->pack.ProcessPack=REQ_status_process;
// }
// bool REQ_status_jsontoobject(REQ_status_t* status,json_value* values){
//     json_object_entry* jcode=cl_GetNameKey(values,"code");
//     if(jcode!=NULL&&jcode->value->type==json_integer){
//         status->code=jcode->value->u.integer;
//         return true;
//     }
//     return false;
// }
// void REQ_status_process(REQ_status_t* status){
//     printf("STATUS: %d\n",status->code);
// }
// void InitREQpack(cl_client_t* client){
//     cl_client_adduserpacks(client,CreateREQ_status,sizeof(REQ_status_t),2);
// }
void ConnectMainServer(){
    cl.AddPack(new REQ_status(),sizeof(REQ_status));
    cl.ConnectToServer("127.0.0.1",9999,true);
    cl.StartGetPack();
}