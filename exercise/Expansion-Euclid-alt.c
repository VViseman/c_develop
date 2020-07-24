#include <stdio.h>

int meuclid(int x,int y,int *A,int *B,int *gcd){/* A,B,gcdがポインタ変数 */
	int r[3],n=0;
	int q[1],a[3],b[3];

	r[1]=y,r[0]=x;
	a[0]=1,a[1]=0;
	b[0]=0,b[1]=1;

	for(;r[1]>0;){
		r[2]=r[0]%r[1];
		q[0]=r[0]/r[1];
		a[2]=a[0]-q[0]*a[1];
		b[2]=b[0]-q[0]*b[1];
		r[0]=r[1];
		r[1]=r[2];
		a[0]=a[1],a[1]=a[2];
		b[0]=b[1],b[1]=b[2];
	}
	*A=a[0];
	*B=b[0];
	*gcd=r[0];

    return 0;
}

int main(){
	int x,y;
	int x_inv,y_inv;
	int gcd;

	printf("x>=y\n");
	printf("x=");
	scanf("%d",&x);
	printf("y=");
	scanf("%d",&y);

	if(x<y){
		printf("%d<%dです\n",x,y);
		return 1;
	}
	meuclid(x,y,&x_inv,&y_inv,&gcd);

	printf("%d*(%d)+%d*(%d)=%d\n",x,x_inv,y,y_inv,gcd);
	return 0;
}