#include"client.h"
#include"olxclient.h"
void AUTH(REQ_status_t* status){
    if(status->code==1){
        printf("\nAUTH SERVER\n");
    }else{
        printf("ERROR AUTH\n");
    }
}
int main(){
   
    printf("HELLO CLIENT START\n");
    cl_client_t client;
    cl_InitClient(&client);
    InitREQpack(&client);
    cl_ClientConnect(&client,"192.168.0.105",9999);
    RES_auth_t auth;
    CreateRES_auth(&auth);
    printf("INPUT NAME: ");
    scanf("%s",auth.name);
    printf("INPUT PASSWORD: ");
    scanf("%s",auth.password);
    
    cl_SendPack(&client,&auth,AUTH);

    printf("END\n");
    int num=0;
    scanf("%d",&num);
    return 0;
}