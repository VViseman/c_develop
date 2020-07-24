#include <stdio.h>

int multi(int x,int y,int r){/* multi関数の内容 */
	int jouyo1;/*ローカル変数*/

 	jouyo1=0;

	if(x<0){
		x=x+r;
	}
	if(y<0){
		y=y+r;
	}
	for(;y>=1;){
		if((y&1) == 1){
			jouyo1=(jouyo1+x)%r;
		}
		x=(x*2)%r;
		y=y/2;
	}
	if(jouyo1<0){
		jouyo1=jouyo1+r;
	}
	return jouyo1;/*戻り値*/
} /*multi関数終わり*/

int main(){
	int a=0;
	int x=0;
	int m=1000000000;
	int n=0;
	int nsyoki=0;
	int jouyo=1;

	printf("a=");
	scanf("%d",&a);
	printf("n=");
	scanf("%d",&nsyoki);
	n=nsyoki;
	x=a%m;

	for(;n>=1;){
		if((n&1) == 1){
			jouyo=multi(jouyo,x,m);	/* jouyo=(jouyo*x)%m */
		}

		n=n/2;
		x=multi(x,x,m);	/* x=(x*x)%m */
	}

	if(jouyo<0){
		jouyo=jouyo+m;
	}
	printf("%dの%d乗は%d mod %d\n", a, nsyoki,jouyo,m);

	return 0;
}
