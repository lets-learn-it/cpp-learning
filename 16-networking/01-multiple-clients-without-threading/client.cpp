#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int sockfd, connfd;
  struct sockaddr_in serv_addr;
  char sendline[1024], recvline[1024];

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
    perror("error while creating socket...");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8081);

  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
    perror("addre");
    exit(-1);
  } 

  if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof serv_addr) < 0) {
    perror("connect error...");
    exit(1);
  }
  
  while(true) {
    memset(recvline, 0, 1024);
    memset(sendline, 0, 1024);
    
    cin.getline(sendline, 1024, '\n');

    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, 1024);

    cout << recvline << endl;
  }

  return 0;
}
