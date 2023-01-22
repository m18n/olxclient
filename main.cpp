#include "client.h"
#include "olxclient.h"
#include "time.h"
int main() {
  printf("HELLO CLIENT START\n");
  try {
    ConnectMainServer();
    
  } catch (NetworkExeption& ntw) {
    std::cout << ntw.what();
  }
  while (true) {
  }
  return 0;
}