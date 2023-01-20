#include"client.h"
#include"time.h"
#include"olxclient.h"
int main(){
    printf("HELLO CLIENT START\n");
    try{
        ConnectMainServer();
    }catch(NetworkExeption& ntw){
        std::cout<<ntw.what();
    }
    while(true){
        
    }
    return 0;
}