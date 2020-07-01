#include <stdio.h>
#include <math.h>
#include <string.h>


#define N 100 //分割数

double f(double x,double y);
double y_true(double x);

double a = 10;
double b = 10;

int main(void){
  //初期値
  double x=0.0;
  double y=4.0;
  double h=(3.0-0.0)/(double)N; //刻み幅
	FILE *fp;
	FILE *gp;
	char graph[10];

	strcpy(graph,"rc.dat");
	fp=fopen(graph,"w");

  printf("x       y       y_true\n");
  for(double i=0; i<N; i++){
    y = y + h*f(x,y);
    x = x + h;
    fprintf(fp,"%f %f\n",x,y);
    printf("%5.5lf, %5.5lf, %5.5lf\n",x,y,y_true(x));
  }

	gp=popen("gnuplot -persist","w");
	fprintf(gp, "plot \"%s\" u 1:2 w st lw 3\n",graph);
	fclose(fp);
	fclose(gp);
}

double f(double x,double y){
//  return x*y;
  return a * y - b * y * y;
}
double y_true(double x){
  return 4.0*exp(x*x/2.0);
}