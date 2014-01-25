#include "TowGraphics.h"
#define GL_PI 3.1415f
//TowOneElement
//функции получения параметров
 
int TowOneElement::GetTip()
{
	return this->Tip;
}
int TowOneElement::GetParametr()
{
	return this->Parametr;
}
double TowOneElement::Getd1()
{
	return this->d1;
}
double TowOneElement::Getd2()
{
	return this->d2;
}
double TowOneElement::Getd3()
{
	return this->d3;
}

//изменение элемента
void TowOneElement::ChangeOneElement(int NTip,int NParametr,double Nd1,double Nd2,double Nd3)
{
	this->Tip = NTip;
	this->Parametr = NParametr;
	this->d1 = Nd1;
	this->d2 = Nd2;
	this->d3 = Nd3;
}
//конструктор и деструктор
TowOneElement::TowOneElement(int FTip,int FParametr,double Fd1,double Fd2,double Fd3)
{
	this->Tip = FTip;
	this->Parametr = FParametr;
	this->d1 = Fd1;
	this->d2 = Fd2;
	this->d3 = Fd3;
}
TowOneElement::~TowOneElement()
{
}

//TowOneGraphics
//загрузка модели из файла
void TowOneGraphics::LoadGraphicsFromFile(const char * ModelFileName)
{
	this->Elements.clear();
	ifstream file1(ModelFileName);
	if(!file1){
		cout << "Can't open file!\n" << ModelFileName;
	}
	double d1,d2,d3;
	d1 = 0.0;
	d2 = 0.0;
	d3 = 0.0;
	int param,tip1;
	param = 0;
	tip1 = 0;
	char c;
	while   (!file1.eof()){
		file1>>c;
		if(c == 'v'){
			file1 >> tip1;
			switch(tip1)
			{
				case 1:
				{
					file1 >> param;
					this->Elements.push_back(TowOneElement(tip1,param,0.0,0.0,0.0));
				}
				break;
				case 2:
				{
					this->Elements.push_back(TowOneElement(tip1,0,0.0,0.0,0.0));
				}
				break;
				case 3:
				{
					file1 >> d1 >> d2 >> d3;
					this->Elements.push_back(TowOneElement(tip1,0,d1,d2,d3));
				}
				break;
				case 4:
				{
					file1 >> d1 >> d2 >> d3;
					this->Elements.push_back(TowOneElement(tip1,0,d1,d2,d3));
				}
				break;
			}
		}
	}
	file1.close();
}
//отрисовка модели
void TowOneGraphics::DrawOneGraphics(double Cx,double Cy,double Cz,double Zoom)
{
	for(int i=0;i<this->Elements.size();i++)
	{
		switch(this->Elements[i].GetTip())
		{
			case 1:
			{
				switch(this->Elements[i].GetParametr())
				{
					case 0:
					{
						glBegin(GL_POINTS);
					}
					break;
					case 1:
					{
						glBegin(GL_LINES);
					}
					break;
					case 2:
					{
						glBegin(GL_LINE_STRIP);
					}
					break;
					case 3:
					{
						glBegin(GL_TRIANGLES);
					}
					break;
					case 4:
					{
						glBegin(GL_TRIANGLE_STRIP);
					}
					break;
					case 5:
					{
						glBegin(GL_TRIANGLE_FAN);
					}
					break;
					case 6:
					{
						glBegin(GL_QUADS);
					}
					break;
					case 7:
					{
						glBegin(GL_QUAD_STRIP);
					}
					break;
					case 8:
					{
						glBegin(GL_POLYGON);
					}
					break;
				}
			}
			break;
			case 2:
			{
				glEnd();
			}
			break;
			case 3:
			{
				glVertex3f(1.0f*(this->Elements[i].Getd1()*Zoom+Cx),1.0f*(this->Elements[i].Getd2()*Zoom+Cy),1.0f*(this->Elements[i].Getd3()*Zoom+Cz));				
			}
			break;
			case 4:
			{
				glColor3f(1.0f*this->Elements[i].Getd1(),1.0f*this->Elements[i].Getd2(),1.0f*this->Elements[i].Getd3());
			}
			break;
		}
		
	}
}
//конструктор и деструктор
TowOneGraphics::TowOneGraphics()
{
}
TowOneGraphics::TowOneGraphics(const char * FirstModelFileName)
{
	this->LoadGraphicsFromFile(FirstModelFileName);
}
TowOneGraphics::~TowOneGraphics()
{
}
//TowWorldGraphics
//Отрисовка
void TowWorldGraphics::DrawWorldBegin()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();	
}
void TowWorldGraphics::DrawWorldRotNTrans()
{
	glTranslatef(0.0f,0.0f,-400.0f);
	glRotatef(65.0f,1.0f,0.0f,0.0f);
}
void TowWorldGraphics::DrawWorld()
{	
	this->Models[0].DrawOneGraphics(0.0,0.0,0.0,1.0);
	this->Models[4].DrawOneGraphics(-40.0,0.0,0.0,25.0);
	this->Models[4].DrawOneGraphics(-15.0,0.0,0.0,25.0);
	this->Models[4].DrawOneGraphics(-40.0,0.0,25.0,25.0);
	this->Models[4].DrawOneGraphics(-15.0,0.0,25.0,25.0);
	this->Models[4].DrawOneGraphics(-40.0,0.0,-25.0,25.0);
	this->Models[4].DrawOneGraphics(-15.0,0.0,-25.0,25.0);
	this->Models[10].DrawOneGraphics(40.0,0.2,0.0,25.0);
}
void TowWorldGraphics::DrawWorldEnd()
{	
	
	//Востонавливаем преобразования
	glPopMatrix();
	//Очищаем стек команд рисования
	glutSwapBuffers();
}
void TowWorldGraphics::DrawOneModel(int Model,double Cx,double Cy,double Cz,double Zoom)
{
	this->Models[Model].DrawOneGraphics(Cx,Cy,Cz,Zoom);
}
//функция при изменении размера экрана
void TowWorldGraphics::ChangeSize(GLsizei w, GLsizei h)
{
	this->NowH = h;
	this->NowW = w;
	GLfloat fAspect;
	GLfloat nRange = 100.0f;
	//предотвращает делениена ноль
	if(h == 0)
		h = 1;
	//Устанавливает размеры окнаросмотра равнымиразмерам окна
	glViewport(0,0,w,h);
	fAspect = (GLfloat)w/(GLfloat)h;
	//Обновляем систему координат
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30.0f, fAspect, 300.0, 800.0);
	glMatrixMode(GL_MODELVIEW);
	
}
//функция начальных настроек
void TowWorldGraphics::SetupRC(void)
{
	//цвет фона теперь черный
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//цвет заливки
	glColor3f(0.0f, 1.0f, 0.0f);
	//Цвет модели затенения выбирается неструктурированым
	glShadeModel(GL_FLAT);

}

int TowWorldGraphics:: GetH()
{
	return this->NowH;
}
int TowWorldGraphics:: GetW()
{
	return this->NowW;
}
//Загрузка моделей
void TowWorldGraphics::LoadModels()
{
	this->Models.clear();
	//--------------------------------------------------------------------
	//модели мира
	//земля
	this->Models.push_back(TowOneGraphics("Pack_of_New/Land.txt"));
	//минерал
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mineral.txt"));
	//снаряд
	this->Models.push_back(TowOneGraphics("Pack_of_New/Missle.txt"));
	//дымок после взрыва
	this->Models.push_back(TowOneGraphics("Pack_of_New/Smoke.txt"));
	//елки
	this->Models.push_back(TowOneGraphics("Pack_of_New/Forest.txt"));
	//модель строительства - место
	this->Models.push_back(TowOneGraphics("Pack_of_New/BuildGreen_Place.txt"));//5
	//модель строительства - минерал
	this->Models.push_back(TowOneGraphics("Pack_of_New/BuildGreen_Mineral.txt"));//6
	//модель денежной тревоги
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNMoneyAllert.txt"));//7
	//модель дымка из шахты
	this->Models.push_back(TowOneGraphics("Pack_of_New/MineSmoke.txt"));//8
	//пустые фрагменты
	for(int i=0; i<1; i++)
	{
		this->Models.push_back(TowOneGraphics("Pack_of_New/Empty.txt"));
	}
	//--------------------------------------------------------------------
	//модели красных - целая, строящаяся, разрушеная
	//замок
	this->Models.push_back(TowOneGraphics("Pack_of_New/Castle_Red.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Castle_Red_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Castle_Red_Broken.txt"));
	//башня
	this->Models.push_back(TowOneGraphics("Pack_of_New/Tower_Red.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Tower_Red_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Tower_Red_Broken.txt"));
	//пушка
	this->Models.push_back(TowOneGraphics("Pack_of_New/Cannon_Red.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Cannon_Red_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Cannon_Red_Broken.txt"));
	//башня-зоны
	this->Models.push_back(TowOneGraphics("Pack_of_New/ZoneTower_Red.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/ZoneTower_Red_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/ZoneTower_Red_Broken.txt"));
	//шахта
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mine_Red.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mine_Red_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mine_Red_Broken.txt"));
	//пустые элементы
	for(int i=0; i<15; i++)
	{
		this->Models.push_back(TowOneGraphics("Pack_of_New/Empty.txt"));
	}
	//--------------------------------------------------------------------
	//модели синих - целая, строящаяся, разрушеная
	//замок
	this->Models.push_back(TowOneGraphics("Pack_of_New/Castle_Blue.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Castle_Blue_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Castle_Blue_Broken.txt"));
	//башня
	this->Models.push_back(TowOneGraphics("Pack_of_New/Tower_Blue.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Tower_Blue_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Tower_Blue_Broken.txt"));
	//пушка
	this->Models.push_back(TowOneGraphics("Pack_of_New/Cannon_Blue.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Cannon_Blue_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Cannon_Blue_Broken.txt"));
	//башня-зоны
	this->Models.push_back(TowOneGraphics("Pack_of_New/ZoneTower_Blue.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/ZoneTower_Blue_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/ZoneTower_Blue_Broken.txt"));
	//шахта
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mine_Blue.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mine_Blue_Build.txt"));
	this->Models.push_back(TowOneGraphics("Pack_of_New/Mine_Blue_Broken.txt"));
	//пустые элементы
	for(int i=0; i<15; i++)
	{
		this->Models.push_back(TowOneGraphics("Pack_of_New/Empty.txt"));
	}
	//--------------------------------------------------------------------
	//цифры 0-9
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNZero.txt"));//0
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNOne.txt"));//1
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNTwo.txt"));//2
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNThree.txt"));//3
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNFour.txt"));//4
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNFive.txt"));//5
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNSix.txt"));//6
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNSeven.txt"));//7
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNEight.txt"));//8
	this->Models.push_back(TowOneGraphics("Pack_of_New/TNNine.txt"));//9
	//с 80 пойдет
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtY.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtO.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtU.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtW.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtI.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtN.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtL.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtS.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtE.txt"));//Y
	this->Models.push_back(TowOneGraphics("Pack_of_New/LtBar.txt"));//Y
}
//конструктор и деструктор
TowWorldGraphics::TowWorldGraphics()
{
	this->LoadModels();
	this->NowH=0;
	this->NowW=0;
}
TowWorldGraphics::~TowWorldGraphics()
{
}