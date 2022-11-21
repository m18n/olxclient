#include"client.h"
#include"time.h"
#include"olxclient.h"
clock_t start=0;
void AUTH(REQ_status_t* status,void* data){
    static int i=0;
    if(status->code==1){
        printf("\nAUTH SERVER %d\n",i);
        if(i==999){
            clock_t end=clock();
            double time_in_seconds = (double)(end - start) / CLOCKS_PER_SEC;
            printf("%lf\n",time_in_seconds);
        }
    }else{
        printf("ERROR AUTH\n");
    }
    i++;
}
int main(){
   
    printf("HELLO CLIENT START\n");
    cl_client_t client;
    cl_InitClient(&client);
    InitREQpack(&client);
    cl_ClientConnect(&client,"192.168.0.105",9999);

    RES_auth_t auth;
    CreateRES_auth(&auth);
    strcpy(auth.name,"misha");
    strcpy(auth.password,"123");
    start=clock();
    for(int i=0;i<1000;i++){
        cl_SendPack(&client,&auth,AUTH,NULL);
    }
    
    int num=0;
    scanf("%d",&num);
    return 0;
}