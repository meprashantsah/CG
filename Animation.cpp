//Automation
#include<GL/glut.h>

float theta[3]={0,0,0};
int axis=2;
#define CUBE 1
#define ICOSAHEDRON 2
#define TETRAHEDRON 3
#define CONE 4
#define TEAPOT 5
int OBJ = CUBE;

void display(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(1,0,0);
  glRotatef(theta[0],1,0,0);
  glRotatef(theta[1],0,1,0);
  glRotatef(theta[2],0,0,1);
  
  switch(OBJ){
    case CUBE:
    glutWireCube(2);
    break;
    case ICOSAHEDRON:
    glutWireIcosahedron();
    break;
    case TETRAHEDRON:
    glutWireTetrahedron();
    break;
    case CONE:
    glutWireCone(2,3,20,20);
    break;
    case TEAPOT:
    glutWireTeapot(2);
    break;
  
  }
  
  glPopMatrix();
  glutSwapBuffers();
}

void idle(){
  theta[axis]+=0.4;
  if(theta[axis]>=360) theta[axis]-=360;
  glutPostRedisplay();
}

void mouse(int button,int state,int x, int y){
  if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
  axis=0;
  else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  axis=1;
  else if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
  axis=2;
  glutPostRedisplay();
}

void myinit(){
  glMatrixMode(GL_PROJECTION);
  glOrtho(-5,5,-5,5,-20,20);
  glMatrixMode(GL_MODELVIEW);
}

void menu(int id){
  switch(id){
    case CUBE:
    OBJ=CUBE;
    break;
    case ICOSAHEDRON:
    OBJ=ICOSAHEDRON;
    break;
    case TETRAHEDRON:
    OBJ=TETRAHEDRON;
    break;
    case CONE:
    OBJ=CONE;
    break;
    case TEAPOT:
    OBJ=TEAPOT;
    break;

  }

}

int main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutCreateWindow("Animation of simple Objects");
  myinit();
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutMouseFunc(mouse);
  glEnable(GL_DEPTH_TEST);
  glutCreateMenu(menu);
  glutAddMenuEntry("cube",1);
  glutAddMenuEntry("icosahedron",2);
  glutAddMenuEntry("tetrahedron",3);
  glutAddMenuEntry("cone",4);
  glutAddMenuEntry("teapot",5);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();
  return 0;
}
