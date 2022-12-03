#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int sockfd, connfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serv_addr;
  int addrlen = sizeof serv_addr;
  char inbuffer[1024] = {0};
  char outBuffer[1024] = {0};

  if(sockfd <= 0) {
    perror("error while creating socket...");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8081);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // https://stackoverflow.com/questions/2208581/socket-listen-doesnt-unbind-in-c-under-linux
  int opt = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void *) &opt, sizeof(opt));

  if(bind(sockfd, (struct sockaddr *) &serv_addr, addrlen) < 0) {
    perror("bind failed...");
    exit(1);
  } 

  if(listen(sockfd, 3) < 0) {
    perror("Listen failed ...");
    exit(1);
  }

  if((connfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &addrlen)) < 0) {
    perror("accept error...");
    exit(1);
  }

  while(true) {
    memset(inbuffer, 0, 1024);
    memset(outBuffer, 0, 1024);

    read(connfd, inbuffer, 1024);
    cout << inbuffer << endl;
    cin.getline(outBuffer, 1024, '\n');
    
    write(connfd, outBuffer, strlen(outBuffer));
  }

  return 0;
}
