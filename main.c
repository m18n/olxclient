#include"client.h"
#include"time.h"
#include"olxclient.h"
int main(){
   
    printf("HELLO CLIENT START\n");
    
    cl_InitClient(&client);
    InitREQpack(&client);
    cl_ClientConnect(&client,"192.168.0.105",9999);
   
    StartOlxClient(&client);
    // strcpy(auth.name,"misha");
    // strcpy(auth.password,"123");
    // RES_auth_t auth;
    // CreateRES_auth(&auth);
    // strcpy(auth.name,"misha");
    // strcpy(auth.password,"123");
    // start=clock();
    // for(int i=0;i<1000;i++){
    //     cl_SendPack(&client,&auth,AUTH,NULL);
    // }
    
    while (true)
    {
        /* code */
    }
    
    return 0;
}