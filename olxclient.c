#include"olxclient.h"

void Menu(REQ_status_t* auth){
    system("clear");
    if(auth->code!=102){
        StartOlxClient();
        return;
    }
    printf("_MENU_\nAdd link analiz|1\n");
    int m=0;
    scanf("%d",&m);
    printf("M: %d",m);
}
void StartOlxClient(){
    system("clear");
    printf("START OLX CLIENT\nPLEASE AUTH:\n");
    RES_auth_t auth;
    CreateRES_auth(&auth);
    printf("LOGIN: ");
    scanf("%s",auth.name);
    printf("PASSWORD: ");
    scanf("%s",auth.password);
    cl_SendPack(&client,&auth,Menu,NULL);
}