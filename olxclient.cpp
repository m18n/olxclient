#include"olxclient.h"

void Menu(void* pack){
    system("clear");
    REQ_status* auth=(REQ_status*)pack;
    if(auth->GetCode()!=102){
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
    std::cout<<"START OLX CLIENT\nPLEASE AUTH:\n";
    RES_auth auth;
    std::cout<<"LOGIN: ";
    std::string user;
    std::cin>>user;
    std::cout<<"PASSWORD: ";
    std::string pass;
    std::cin>>pass;
    std::cout<<"USER PASS: "<<user<<" "<<pass<<"\n";
    auth.SetName(user);
    auth.SetPassword(pass);
    cl.SendPack(&auth,Menu);
    cl.SendPack(&auth,Menu);
}