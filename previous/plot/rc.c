#include <stdio.h>
#include <string.h>

#define R 1000
#define C 0.1
#define Vin 5.0
#define dt 0.001

int main(void){

	double t=0;
	double Q=0;
	double dQ=0;
	double Vc=0;
	FILE *fp;
	FILE *gp;
	char graph[10];

	strcpy(graph,"rc.dat");
	fp=fopen(graph,"w");

	while(t<1000){
		dQ=(Vin-Vc)*dt/R;
		Q+=dQ;
		Vc=Q/C;
		fprintf(fp,"%f %f\n",t,Vc);
		t+=dt;
	}

	gp=popen("gnuplot -persist","w");
	fprintf(gp, "plot \"%s\" u 1:2 w st lw 3\n",graph);
	fclose(fp);
	fclose(gp);
	printf("%sを作成しました。\n",graph);
	return 0;
}