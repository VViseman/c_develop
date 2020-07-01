#include <stdio.h>
#include <math.h>
#include <string.h>

//グローバル変数
#define a 10
#define A 0.00001
#define b 10
#define dt 0.001 //刻み幅

int main(void){

	double t=0.0;
	double y=0.0;
//	double Q=0;
//	double dQ=0;
//	double Vc=0;
	FILE *fp;
	FILE *gp;
	char graph[10];

	strcpy(graph,"rc.dat");
	fp=fopen(graph,"w");

	while(t<1000){
//		dQ=(Vin-Vc)*dt/R;
//		Q+=dQ;
//		Vc=Q/C;
		y = (a * A * exp(a * t)) / (1 + b * A * exp(a * t));
		fprintf(fp,"%f %f\n",t,y);
		t+=dt;
	}

	gp=popen("gnuplot -persist","w");
	fprintf(gp, "plot \"%s\" u 1:2 w st lw 3\n",graph);
	fclose(fp);
	fclose(gp);
	printf("%sを作成しました。\n",graph);
	return 0;
}