#ifndef TOWOBJECTS
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "TowGraphics.h"
using namespace std;
#define TOWOBJECTS

class TowObject
{
protected:
	double X,Y,Z;
	int MapX,MapZ;
public:
	double GetX();
	double GetY();
	double GetZ();
	int GetMapX();
	int GetMapZ();
	void SetX(double NewX);
	void SetY(double NewY);
	void SetZ(double NewZ);
	void SetMapX(int NewMapX);
	void SetMapZ(int NewMapZ);
	virtual ~TowObject();
};

class TowBarrier: public TowObject
{
protected:
	int Tip;
public:
	int GetTip();
	void SetTip(int NewTip);
	TowBarrier(double FirstX, double FirstY, double FirstZ,int FirstMapX,int FirstMapZ, int FirstTip);
	virtual ~TowBarrier();
};

class TowSmoke: public TowObject
{
protected:
	double Speed;
	int TimeToDie;
public:
	double GetSpeed();
	int GetTimeToDie();
	void SetSpeed(double NewSpeed);
	void SetTimeToDie(int NewTimeToDie);
	//---------------------------------------
	bool MoveAndCheck(int MS);
	bool FlyIsOver();
	//---------------------------------------
	TowSmoke(double FirstX, double FirstY, double FirstZ,int FirstMapX,int FirstMapZ, double FirstSpeed, int FirstTimeToDie);
	virtual ~TowSmoke();
};

class TowMineral: public TowObject
{
protected:
	int Size;
public:
	int GetSize();
	void SetSize(int NewSize);
	TowMineral(double FirstX, double FirstY, double FirstZ,int FirstMapX,int FirstMapZ, double FirstSize);
	virtual ~TowMineral();
};

class TowMissle: public TowObject
{
protected:
	int Damage;
	double Speed;
	int TargetX,TargetZ;
public:
	int GetDamage();
	double GetSpeed();
	void SetDamage(int NewDamage);
	void SetSpeed(double NewSpeed);
	//------------------------------
	void SetTarget(int FTargetX,int FTargetZ);
	int GetTargetX();
	int GetTargetZ();
	void MakeMove(int MS);
	bool OnTarget();
	//------------------------------
	TowMissle(double FirstX, double FirstY, double FirstZ, int FirstDamage, double FirstSpeed, int FTX, int FTZ);
	virtual ~TowMissle();
};

class TowTower: public TowObject
{
protected:
	int Active;
	int Built;
	int TimeToBuild;
	int MaxHealth;
	int Health;
	int Tip;
	//для строительства
	double ZoneRad;
	//для добычи
	int GatheringTime;
	int TimeToGather;
	int HowMuchGather;
	//для срельбы
	int RechargeTime;
	int TimeToShot;
	int Damage;
	double Rad;
	//цель
	int TargetX,TargetZ;
	//
public:
	int GetActive();
	int GetBuilt();
	int GetTimeToBuild();
	int GetMaxHealth();
	int GetHealth();
	int GetTip();
	//для строительства
	bool BuildTower(int MS);
	//для зоны
	double GetZoneRad();
	//для добычи
	bool IsGathered(int MS);
	int GetHowMuchGather();
	//для стрельбы
	int GetRechargeTime();
	int GetTimeToShot();
	int GetDamage();
	int GetTargetX();
	int GetTargetZ();
	double GetRad();
	void SetTarget(int FirstTargetX,int FirstTargetZ);
	bool TimePass(int MS);
	void ShotDone();
	//
	void SetActive(int NewActive);
	void SetBuilt(int NewBuilt);
	void SetTimeToBuild(int NewTimeToBuilt);
	void SetMaxHealth(int NewMaxHealth);
	void SetHealth(int NewHealth);
	void DecHealth(int Harm);
	TowTower(double FirstX, double FirstY, double FirstZ, int FirstMapX, int FirstMapZ,
			 int FirstActive, int FirstBuilt, int FirstTimeToBuild, int FirstMaxHealth, int FirstHealth,
			 int FirstTip,int FRechargeTime,int FDamage,double FRad);
	virtual ~TowTower();
};

class TowFraction
{
private:
	vector<TowTower> Castles;
	vector<TowTower> Towers;
	int Minerals;
	int BuildMap[20][20];
	int Tip;
public:
	int GetMinerals();
	void SetMinerals(int NewMinerals);
	void AddMinerals(int AddMinerals);
	void DecMinerals(int DecMinerals);
	//--------------------------------
	//--------------------------------
	void MakeMap(int* AllMap[20][20]);
	void ClearMap();
	int GetMapValue(int X,int Y);
	void SetMapValue(int X,int Y,int NewValue);
	//--------------------------------
	int GetTip();
	int GetCastleSize();
	int GetCastleMapX(int Nom);
	int GetCastleMapZ(int Nom);
	int GetCastleBuildRad(int Nom);
	int GetTowerBuilt(int Nom);
	bool TowerBuildTower(int Nom, int MS);
	int GetTowerSize();
	int GetTowerMapX(int Nom);
	int GetTowerMapZ(int Nom);
	int GetTowerTip(int Nom);
	int GetTowerTargetX(int Nom);
	int GetTowerTargetZ(int Nom);
	int GetTowerDamage(int Nom);
	double GetTowerRad(int Nom);
	double GetBuildRad(int Nom);
	void SetTarget(int Nom, int NTargetX, int NTargetZ);
	bool TowerTimePass(int Nom,int MS);
	void TowerShotDone(int Nom);
	//--------------------------------
	bool TowerIsGathered(int Nom,int MS);
	int TowerGetHowMuchGather(int Nom);
	//--------------------------------
	int FindTowerInRad(int TowX,int TowZ,double Rad);
	bool IsTowerInRad(int TowX,int TowZ,double Rad);
	bool IsTowerHere(int TowX,int TowZ);
	int CheckForDamage(int TowX,int TowZ,int Damage);
	//--------------------------------
	void BuildTower(int FirstMapX, int FirstMapZ,
			        int FirstTimeToBuild, int FirstMaxHealth, int FirstHealth,
			        int FirstTip);
	void AddTower(int FirstMapX, int FirstMapZ,
				  int FirstMaxHealth, int FirstHealth,
				  int FirstTip);
	int CanBuild(int FirstMapX, int FirstMapZ, int FirstTip);
	//--------------------------------
	TowFraction(int FirstTip, int FirstCastleX, int FirstCastleZ, int FirstMinerals);
	~TowFraction();
};


class TowWorld
{
private:
	vector<TowFraction> Fractions;
	vector<TowMissle> Missles;
	vector<TowMineral> Minerals;
	vector<TowBarrier> Barriers;
	vector<TowSmoke> Smokes;
	vector<TowSmoke> MineSmokes;
	int Map[20][20];
	int Map0[20][20];
	int Map1[20][20];
	//int i;
	//для режима строительства
	int BuildCannonTowers;
	vector<int> Prices;
	vector<int> Healthes;
	vector<int> BuildTimes;
	vector<int> BuildX;
	vector<int> BuildZ;
	int ActionType;//  0 -игра 1-строительство 2-конец
	int GameOver;
	int BuildingTower;
	int MoneyAllertTime;
	//конец режима
	TowWorldGraphics WorldGraphics1;
public:
	void ClearMap();
	void MakeMap0();
	void MakeMap1();
	int GetMapValue(int X,int Y);
	void SetMapValue(int X,int Y, int NewValue);
	void LoadMapFromFile(const char * MapFileName);
	//---------------------------------------------
	bool BuySomeTowers(int FrackNomber,int TowerType);
	//---------------------------------------------
	void DelNeedlessMissles();
	void DelNeedlessSmokes();
	void DelNeedlessMineSmokes();
	//---------------------------------------------
	void PCMakeItsMove();
	bool OnBorder(int x,int z);
	//---------------------------------------------
	void TimerFunc(int MS);
	void MouseFunc(int button,int state,int x,int y);
	void DrawAll();
	void DrawObjects();
	void DrawCountMinerals(int Count);
	void DrawBuilding(int FractionNomer, int TowerType);
	void DrawSmallMap();
	void DrawBuildPannel();
	void DrawMoneyAllert();
	void DrawWin();
	void DrawLose();
	int RetrieveObjectID(int x, int y);
	void WChangeSize(GLsizei w, GLsizei h);
	void WSetupRC();
	TowWorld();
	~TowWorld();
};
class TowTarget
{
private:
	int X,Z;
public:
	int GetX();
	int GetZ();
	TowTarget(int FirstX,int FirstZ);
	~TowTarget();
};
#endif TOWOBJECTS