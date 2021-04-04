#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>

#define PORT 6789

int main(){
  // IP アドレス，ソケット，sockaddr_in 構造体
  char destination[32];
  int dstSocket;
  struct sockaddr_in dstAddr;

  //struct sockaddr_in addr;
  struct hostent *hp;
  char   buf[1024];
  int    numrcv;
  printf("サーバーマシンのIPは？:");
  scanf("%s", destination);

  //sockaddr_in 構造体のセット
  bzero((char *)&dstAddr, sizeof(dstAddr));
  dstAddr.sin_family = AF_INET;
  dstAddr.sin_port = htons(PORT);

  hp = gethostbyname(destination);
  bcopy(hp->h_addr, &dstAddr.sin_addr, hp->h_length);

  //ソケットの生成
  dstSocket = socket(AF_INET, SOCK_STREAM, 0);

  //接続
  if (connect(dstSocket, (struct sockaddr *)&dstAddr, sizeof(dstAddr)) < 0){
    printf("%s に接続できませんでした。\n",destination);
    return(-1);
  }
  printf("%s に接続しました。\n",destination);
  printf("チャットが利用できます。\n");

  while (1){
    printf("\x1b[44m");
    printf("自分 ");
    scanf("%s",buf);
    //パケットの送信
    send(dstSocket, buf, 1024,0);
    //パケットの受信
    numrcv = recv(dstSocket, buf, 1024,0);
    printf("\x1b[41m");
    printf("相手 %s\n",buf);
  }
  close(dstSocket);
  return(0);
}