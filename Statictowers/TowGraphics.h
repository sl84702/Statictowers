#ifndef TOWGRAPHICS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
using namespace std;
#define TOWGRAPHICS
class TowOneElement
{
private:
	int Tip,Parametr;
	double d1,d2,d3;
public:
	int GetTip();
	int GetParametr();
	double Getd1();
	double Getd2();
	double Getd3();
	void ChangeOneElement(int NTip,int NParametr,double Nd1,double Nd2,double Nd3);
	TowOneElement(int FTip,int FParametr,double Fd1,double Fd2,double Fd3);
	~TowOneElement();
};
class TowOneGraphics
{
private:
	vector<TowOneElement> Elements;
public:
	void LoadGraphicsFromFile(const char * ModelFileName);//указать из какого файла загружать
	void DrawOneGraphics(double Cx,double Cy,double Cz,double Zoom);
	TowOneGraphics();
	TowOneGraphics(const char * FirstModelFileName);
	~TowOneGraphics();
};
class TowWorldGraphics
{
private:
	vector<TowOneGraphics> Models;
	int NowH,NowW;
public:
	int GetH();
	int GetW();
	void LoadModels();
	void DrawWorld();
	void DrawWorldBegin();
	void DrawWorldRotNTrans();
	void DrawWorldEnd();
	void DrawOneModel(int Model,double Cx,double Cy,double Cz,double Zoom);
	void ChangeSize(GLsizei w, GLsizei h);
	void SetupRC();
	TowWorldGraphics();
	~TowWorldGraphics();
};
#endif