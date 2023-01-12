#include"client.h"
#include"time.h"
#include"olxclient.h"
int main(){
    printf("HELLO CLIENT START\n");
    ConnectMainServer();
    StartOlxClient(&client);
   
    while (true)
    {
        /* code */
    }
    
    return 0;
}