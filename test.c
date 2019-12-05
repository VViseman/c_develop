#include<stdio.h>
#include<GL/glut.h>

void display(void);

int main(int argc,char *argv[]){
	
	//call window
	glutInit(&argc,argv);
	glutCreateWindow("sample window");//string literal or argv(string) 
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}


void display(){
	//pass
}
