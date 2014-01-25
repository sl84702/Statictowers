#include <stdio.h>
#include "TowObjects.h"

TowWorld World1;

void Draw(void)
{
	World1.DrawAll();
}
void ChangeSize1(GLsizei w, GLsizei h)
{
	World1.WChangeSize(w,h);
}
void TimerFunction(int value)
{
	World1.TimerFunc(60);
	glutPostRedisplay();
	glutTimerFunc(40,TimerFunction, 1);
}
void MouseFunction(int button,int state,int x,int y)
{
	World1.MouseFunc(button,state,x,y);
}

void main()
{
	srand(time(NULL));
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Towers");
	glutDisplayFunc(Draw);
	glutReshapeFunc(ChangeSize1);
	glutTimerFunc(40,TimerFunction, 1);
	glutMouseFunc(MouseFunction);
	World1.WSetupRC();
	glutMainLoop();
	//delete (World1);
}