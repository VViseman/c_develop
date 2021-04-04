#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 6789

int main(){
  int i;
  int srcSocket; //自分
  int dstSocket; //相手
  // sockaddr_in 構造体
  struct sockaddr_in srcAddr;
  struct sockaddr_in dstAddr;
  int dstAddrSize = sizeof(dstAddr);
  // 各種パラメータ

  int numrcv;
  char buf[1024];

  while(1){
    bzero((char *)&srcAddr, sizeof(srcAddr));
    srcAddr.sin_port = htons(PORT);
    srcAddr.sin_family = AF_INET;
    srcAddr.sin_addr.s_addr = INADDR_ANY;

    //ソケットの生成
    srcSocket = socket(AF_INET, SOCK_STREAM, 0);
    //ソケットのバインド
    bind(srcSocket, (struct sockaddr *)&srcAddr, sizeof(srcAddr));
    //接続の許可
    listen(srcSocket, 1);

    //接続待ち
    printf("接続を待っています。\n");
    dstSocket = accept(srcSocket, (struct sockaddr *)&dstAddr, &dstAddrSize);
    printf("%sから接続を受けました。\n",inet_ntoa(dstAddr.sin_addr));
    close(srcSocket);

    while(1){
      //パケットの受信
      numrcv = recv(dstSocket, buf, 1024,0);
      printf("\x1b[41m");
      printf("相手 %s\n",buf);
      printf("\x1b[44m");
      printf("自分 ");
      scanf("%s",buf);
      // パケットの送信
      send(dstSocket, buf, 1024,0);
    }
  }
  return(0);
}