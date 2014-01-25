#define Zoom1 8.0
#include "TowObjects.h"
//TowObject

double TowObject::GetX()
{
	return this->X;
}
double TowObject::GetY()
{
	return this->Y;
}
double TowObject::GetZ()
{
	return this->Z;
}
int TowObject::GetMapX()
{
	return this->MapX;
}
int TowObject::GetMapZ()
{
	return this->MapZ;
}
void TowObject::SetX(double NewX)
{
	this->X = NewX;
}
void TowObject::SetY(double NewY)
{
	this->Y = NewY;
}
void TowObject::SetZ(double NewZ)
{
	this->Z = NewZ;
}
void TowObject::SetMapX(int NewX)
{
	this->MapX = NewX;
}
void TowObject::SetMapZ(int NewZ)
{
	this->MapZ = NewZ;
}

TowObject::~TowObject()
{
}
//TowBarrier
int TowBarrier::GetTip()
{
	return this->Tip;
}
void TowBarrier::SetTip(int NewTip)
{
	this->Tip=NewTip;
}
TowBarrier::TowBarrier(double FirstX, double FirstY, double FirstZ,int FirstMapX,int FirstMapZ, int FirstTip)
{
	this->X = FirstX;
	this->Y = FirstY;
	this->Z = FirstZ;
	this->MapX = FirstMapX;
	this->MapZ = FirstMapZ;
	this->Tip = FirstTip;
}
TowBarrier::~TowBarrier()
{
}
//TowSmoke
double TowSmoke::GetSpeed()
{
	return this->Speed;
}
int TowSmoke::GetTimeToDie()
{
	return this->TimeToDie;
}
void TowSmoke::SetSpeed(double NewSpeed)
{
	this->Speed = NewSpeed;
}
void TowSmoke::SetTimeToDie(int NewTimeToDie)
{
	this->TimeToDie = NewTimeToDie;
}
bool TowSmoke::MoveAndCheck(int MS)
{
	bool ans=false;
	this->Y = this->Y+this->Speed*MS;
	this->TimeToDie = this->TimeToDie-MS;
	if(this->TimeToDie<0)
	{
		ans = true;
	}
	return ans;
}
bool TowSmoke::FlyIsOver()
{
	bool ans=false;
	if(this->TimeToDie<0)
	{
		ans = true;
	}
	return ans;
}
TowSmoke::TowSmoke(double FirstX, double FirstY, double FirstZ,int FirstMapX,int FirstMapZ, double FirstSpeed, int FirstTimeToDie)
{
	this->X = FirstX;
	this->Y = FirstY;
	this->Z = FirstZ;
	this->MapX = FirstMapX;
	this->MapZ = FirstMapZ;
	this->Speed = FirstSpeed;
	this->TimeToDie = FirstTimeToDie;
}
TowSmoke::~TowSmoke()
{
}
//TowMineral
int TowMineral::GetSize()
{
	return this->Size;
}
void TowMineral::SetSize(int NewSize)
{
	this->Size = NewSize;
}
TowMineral::TowMineral(double FirstX, double FirstY, double FirstZ,int FirstMapX,int FirstMapZ, double FirstSize)
{
	this->X = FirstX;
	this->Y = FirstY;
	this->Z = FirstZ;
	this->MapX = FirstMapX;
	this->MapZ = FirstMapZ;
	this->Size = FirstSize;
}
TowMineral::~TowMineral()
{
	
}
//TowMissle
int TowMissle::GetDamage()
{
	return this->Damage;
}
double TowMissle::GetSpeed()
{
	return this->Speed;
}
void TowMissle::SetDamage(int NewDamage)
{
	this->Damage = NewDamage;
}
void TowMissle::SetSpeed(double NewSpeed)
{
	this->Speed = NewSpeed;
}
void TowMissle::SetTarget(int FTargetX,int FTargetZ)
{
	this->TargetX=FTargetX;
	this->TargetZ=FTargetZ;
}
int TowMissle::GetTargetX()
{
	return this->TargetX;
}
int TowMissle::GetTargetZ()
{
	return this->TargetZ;
}
void TowMissle::MakeMove(int MS)
{
	this->X=this->X+(double)MS*this->Speed*((this->TargetX - this->X)/sqrt(pow((this->Z - (double)this->TargetZ),2)+pow((this->X - (double)this->TargetX),2)));
	this->Z=this->Z+(double)MS*this->Speed*((this->TargetZ - this->Z)/sqrt(pow((this->Z - (double)this->TargetZ),2)+pow((this->X - (double)this->TargetX),2)));
	
}
bool TowMissle::OnTarget()
{
	bool ans;
	ans = false;
	double ToX = (double)this->TargetX;
	double ToZ = (double)this->TargetZ;
	if((fabs(this->X-ToX)<0.4) && (fabs(this->Z-ToZ)<0.4))
	{
		ans = true;
	}
	return ans;
}
TowMissle::TowMissle(double FirstX, double FirstY, double FirstZ, int FirstDamage, double FirstSpeed,int FTX, int FTZ)
{
	this->X = FirstX;
	this->Y = FirstY;
	this->Z = FirstZ;
	this->TargetX = FTX;
	this->TargetZ=FTZ;
	this->MapX = 0;
	this->MapZ = 0;
	this->Damage = FirstDamage;
	this->Speed = FirstSpeed;
}
TowMissle::~TowMissle()
{
}
//TowTower
int TowTower::GetActive()
{
	return this->Active;
}
int TowTower::GetBuilt()
{
	return this->Built;
}
int TowTower::GetTimeToBuild()
{
	return this->TimeToBuild;
}
int TowTower::GetMaxHealth()
{
	return this->MaxHealth;
}
int TowTower::GetHealth()
{
	return this->Health;
}
int TowTower::GetTip()
{
	return this->Tip;
}
bool TowTower::BuildTower(int MS)
{
	bool ans = false;
	this->TimeToBuild = this->TimeToBuild - MS;
	if(this->TimeToBuild < 1)
	{
		ans = true;
		this->Built = 1;
	}
	return ans;
}
double TowTower::GetZoneRad()
{
	return this->ZoneRad;
}
bool TowTower::IsGathered(int MS)
{
	bool ans = false;
	this->TimeToGather = this->TimeToGather - MS;
	if(this->TimeToGather<1)
	{
		ans = true;
		this->TimeToGather = this->GatheringTime;
	}
	return ans;
}
int TowTower::GetHowMuchGather()
{
	return this->HowMuchGather;
}
//для стрельбы
int TowTower::GetRechargeTime()
{
	return this->RechargeTime;
}
int TowTower::GetTimeToShot()
{
	return this->TimeToShot;
}
int TowTower::GetDamage()
{
	return this->Damage;
}
int TowTower::GetTargetX()
{
	return this->TargetX;
}
int TowTower::GetTargetZ()
{
	return this->TargetZ;
}
double TowTower::GetRad()
{
	return this->Rad;
}
void TowTower::SetTarget(int FirstTargetX,int FirstTargetZ)
{
	this->TargetX = FirstTargetX;
	this->TargetZ = FirstTargetZ;
}
bool TowTower::TimePass(int MS)
{
	bool ans=false;
	this->TimeToShot = this->TimeToShot - MS;
	if(this->TimeToShot<1)
	{
		ans = true;
	}
	return ans;
}
void TowTower::ShotDone()
{
	this->TimeToShot = this->RechargeTime;
}
//конец//для стрельбы
void TowTower::SetActive(int NewActive)
{
	this->Active = NewActive;
}
void TowTower::SetBuilt(int NewBuilt)
{
	this->Built = NewBuilt;
}
void TowTower::SetTimeToBuild(int NewTimeToBuild)
{
	this->TimeToBuild = NewTimeToBuild;
}
void TowTower::SetMaxHealth(int NewMaxHealth)
{
	this->MaxHealth = NewMaxHealth;
}
void TowTower::SetHealth(int NewHealth)
{
	this->Health = NewHealth;
}
void TowTower::DecHealth(int Harm)
{
	this->Health = this->Health - Harm;
	if(this->Health < 0)
	{
		this->Health = 0;
	}
}
TowTower::TowTower(double FirstX, double FirstY, double FirstZ, int FirstMapX, int FirstMapZ,
				   int FirstActive, int FirstBuilt, int FirstTimeToBuild, int FirstMaxHealth, int FirstHealth,
				   int FirstTip,int FRechargeTime,int FDamage,double FRad)
{
	this->ZoneRad=4.0;
	this->Tip = FirstTip;
	this->X = FirstX;
	this->Y = FirstY;
	this->Z = FirstZ;
	this->TargetX=-15;
	this->TargetZ=-15;
	this->RechargeTime = FRechargeTime;
	this->TimeToShot = FRechargeTime;
	this->Damage = FDamage;
	this->Rad = FRad;
	this->MapX = FirstMapX;
	this->MapZ = FirstMapZ;
	this->Active = FirstActive;
	this->Built = FirstBuilt;
	this->TimeToBuild = FirstTimeToBuild;
	this->MaxHealth = FirstMaxHealth;
	this->Health = FirstHealth;
	//добыча, пока вшивается намертво
	this->GatheringTime=5000;
	this->TimeToGather=5000;
	this->HowMuchGather=10;
}
TowTower::~TowTower()
{
}
//TowFraction
int TowFraction::GetMinerals()
{
	return this->Minerals;
}
void TowFraction::SetMinerals(int NewMinerals)
{
	this->Minerals = NewMinerals;
}
void TowFraction::AddMinerals(int AddMinerals)
{
	this->Minerals = this->Minerals + AddMinerals;
}
void TowFraction::DecMinerals(int DecMinerals)
{
	this->Minerals = this->Minerals - DecMinerals;
}
void TowFraction::MakeMap(int* AllMap[20][20])
{
	
}
void TowFraction::ClearMap()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0; j<20; j++)
		{
			this->BuildMap[i][j]=0;
		}
	}
}
int TowFraction::GetTip()
{
	return this->Tip;
}
int TowFraction::GetCastleSize()
{
	return this->Castles.size();
}
int TowFraction::GetCastleMapX(int Nom)
{
	return this->Castles[Nom].GetMapX();
}
int TowFraction::GetCastleMapZ(int Nom)
{
	return this->Castles[Nom].GetMapZ();
}
int TowFraction::GetCastleBuildRad(int Nom)
{
	return this->Castles[Nom].GetZoneRad();
}
int TowFraction::GetTowerBuilt(int Nom)
{
	return this->Towers[Nom].GetBuilt();
}
bool TowFraction::TowerBuildTower(int Nom, int MS)
{
	return this->Towers[Nom].BuildTower(MS);
}
int TowFraction::GetTowerSize()
{
	return this->Towers.size();
}
int TowFraction::GetTowerMapX(int Nom)
{
	return this->Towers[Nom].GetMapX();
}
int TowFraction::GetTowerMapZ(int Nom)
{
	return this->Towers[Nom].GetMapZ();
}
int TowFraction::GetTowerTip(int Nom)
{
	return this->Towers[Nom].GetTip();
}
int TowFraction::GetTowerTargetX(int Nom)
{
	return this->Towers[Nom].GetTargetX();
}
int TowFraction::GetTowerTargetZ(int Nom)
{
	return this->Towers[Nom].GetTargetZ();
}
int TowFraction::GetTowerDamage(int Nom)
{
	return this->Towers[Nom].GetDamage();
}
double TowFraction::GetTowerRad(int Nom)
{
	return this->Towers[Nom].GetRad();
}
double TowFraction::GetBuildRad(int Nom)
{
	return this->Towers[Nom].GetZoneRad();
}
void TowFraction::SetTarget(int Nom, int NTargetX, int NTargetZ)
{
	this->Towers[Nom].SetTarget(NTargetX,NTargetZ);
}
bool TowFraction::TowerTimePass(int Nom,int MS)
{
	return this->Towers[Nom].TimePass(MS);
}
void TowFraction::TowerShotDone(int Nom)
{
	this->Towers[Nom].ShotDone();
}
bool TowFraction::TowerIsGathered(int Nom,int MS)
{
	return this->Towers[Nom].IsGathered(MS);
}
int TowFraction::TowerGetHowMuchGather(int Nom)
{
	return this->Towers[Nom].GetHowMuchGather();
}
bool TowFraction::IsTowerInRad(int TowX,int TowZ,double Rad)
{
	bool ans;
	ans = false;
	for(int i=0;i<this->Towers.size();i++)
	{
		if(sqrt(pow((double)this->Towers[i].GetMapX()-(double)TowX,2)+pow((double)this->Towers[i].GetMapZ()-(double)TowZ,2))<Rad)
		{
			ans = true;
			break;
		}
	}
	for(int i=0;i<this->Castles.size();i++)
	{
		if(sqrt(pow((double)this->Castles[i].GetMapX()-(double)TowX,2)+pow((double)this->Castles[i].GetMapZ()-(double)TowZ,2))<Rad)
		{
			ans = true;
			break;
		}
	}
	return ans;
}
int TowFraction::FindTowerInRad(int TowX,int TowZ,double Rad)
{
	int derX,derZ;
	for(int i=0;i<this->Towers.size();i++)
	{
		if(sqrt(pow((double)this->Towers[i].GetMapX()-(double)TowX,2)+pow((double)this->Towers[i].GetMapZ()-(double)TowZ,2))<Rad)
		{
			derX=this->Towers[i].GetMapX();
			derZ=this->Towers[i].GetMapZ();
			break;
		}
	}
	for(int i=0;i<this->Castles.size();i++)
	{
		if(sqrt(pow((double)this->Castles[i].GetMapX()-(double)TowX,2)+pow((double)this->Castles[i].GetMapZ()-(double)TowZ,2))<Rad)
		{
			derX=this->Castles[i].GetMapX();
			derZ=this->Castles[i].GetMapZ();
			break;
		}
	}
	return derX*100+derZ;
}
bool TowFraction::IsTowerHere(int TowX,int TowZ)
{
	bool ans;
	ans = false;
	for(int i=0;i<this->Towers.size();i++)
	{
		if(this->Towers[i].GetMapX() ==TowX && this->Towers[i].GetMapZ() == TowZ)
		{
			ans = true;
			break;
		}
	}
	for(int i=0;i<this->Castles.size();i++)
	{
		if(this->Castles[i].GetMapX() ==TowX && this->Castles[i].GetMapZ() == TowZ)
		{
			ans = true;
			break;
		}
	}
	return ans;
}
int TowFraction::CheckForDamage(int TowX,int TowZ,int Damage)
{
	//нанести урон всем кто на этой точке
	int Ans=-10;
	int Done;
	int Dead,Tip,Nom;
	Dead=0;
	Tip=0;
	Nom=0;
	Done=0;
	//замки
	for(int j=0;j<this->Castles.size();j++){
		if(this->Castles[j].GetMapX() == TowX && this->Castles[j].GetMapZ() == TowZ)
		{
			this->Castles[j].DecHealth(Damage);
			Done=1;
			//проверка на смерть
			if(this->Castles[j].GetHealth()<1)
			{
				Dead=1;
				Tip=1;
				Nom=j;
			}
		}
	}
	if(Done == 0)
	{
		for(int j=0;j<this->Towers.size();j++){
			if(this->Towers[j].GetMapX() == TowX && this->Towers[j].GetMapZ() == TowZ)
			{
				this->Towers[j].DecHealth(Damage);
				Done=1;
				if(this->Towers[j].GetHealth()<1)
				{
					Dead=1;
					Tip=2;
					Nom=j;
				}
			}
		}
		
	}
	if(Dead == 1)
	{
		if(Tip==1)
		{
			Ans=this->Castles[Nom].GetMapX()*100+this->Castles[Nom].GetMapZ();
			this->Castles.erase(this->Castles.begin()+Nom, this->Castles.begin()+Nom+1);
		}else{
			Ans=this->Towers[Nom].GetMapX()*100+this->Towers[Nom].GetMapZ();
			this->Towers.erase(this->Towers.begin()+Nom, this->Towers.begin()+Nom+1);
		}
	}
	return Ans;
	//башни
}

int TowFraction::GetMapValue(int X,int Y)
{
	return this->BuildMap[X][Y];
}
void TowFraction::SetMapValue(int X,int Y,int NewValue)
{
	this->BuildMap[X][Y] = NewValue;
}
void TowFraction::AddTower(int FirstMapX, int FirstMapZ,
						   int FirstMaxHealth, int FirstHealth,
						   int FirstTip)
{
	this->Towers.push_back(TowTower(0.0, 0.0, 0.0, FirstMapX, FirstMapZ, 1, 1, 0, FirstMaxHealth, FirstHealth,FirstTip,1500,25,3.2));
}
void TowFraction::BuildTower(int FirstMapX, int FirstMapZ,
							 int FirstTimeToBuild, int FirstMaxHealth, int FirstHealth,
							 int FirstTip)
{
	this->Towers.push_back(TowTower(0.0, 0.0, 0.0, FirstMapX, FirstMapZ, 1, 0, FirstTimeToBuild, FirstMaxHealth, FirstHealth,FirstTip,1500,25,3.2));
}
int TowFraction::CanBuild(int FirstMapX, int FirstMapZ, int FirstTip)
{
	int ans;
	ans = 0;
	if (FirstTip == 1 || FirstTip == 3)
	{
		if(this->BuildMap[FirstMapX][FirstMapZ] == 1)
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
	}
	if (FirstTip == 2)
	{
		if(this->BuildMap[FirstMapX][FirstMapZ] == 2)
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
	}
	
	return ans;
}
TowFraction::TowFraction(int FirstTip, int FirstCastleX, int FirstCastleZ, int FirstMinerals)
{
	//this->ClearMap();
	this->Minerals = FirstMinerals;
	//this->Models.push_back(TowOneGraphics("Pack_of_New/Smoke.txt"));
	this->Castles.push_back(TowTower(0.0, 0.0, 0.0, FirstCastleX, FirstCastleZ, 1, 1, 0,1000,1000,0,0,0,0.0));
	this->Tip = FirstTip;
}
TowFraction::~TowFraction()
{

}

//TowWorld
void TowWorld::ClearMap()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0; j<20; j++)
		{
			this->Map[i][j]=0;
		}
	}
}

void TowWorld::MakeMap0()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			this->Map0[i][j]=0;
		}
	}
	//перебирать башни зоны
	//проверять точки в их радиусе
	for(int i=0;i<this->Fractions[0].GetTowerSize();i++)
	{
		if(this->Fractions[0].GetTowerTip(i) == 3 && this->Fractions[0].GetTowerBuilt(i)== 1)
		{
			for(int PoX = this->Fractions[0].GetTowerMapX(i) - (int)this->Fractions[0].GetBuildRad(i);PoX <= this->Fractions[0].GetTowerMapX(i) + (int)this->Fractions[0].GetBuildRad(i); PoX++)
			{
				for(int PoZ = this->Fractions[0].GetTowerMapZ(i) - (int)this->Fractions[0].GetBuildRad(i);PoZ <= this->Fractions[0].GetTowerMapZ(i) + (int)this->Fractions[0].GetBuildRad(i); PoZ++)
				{
					//в радиусе
					if(sqrt(pow((double)this->Fractions[0].GetTowerMapX(i)-(double)PoX,2)+pow((double)this->Fractions[0].GetTowerMapZ(i)-(double)PoZ,2))<=this->Fractions[0].GetBuildRad(i))
					{
						if(PoX >-1 && PoX <20 && PoZ >-1 && PoZ < 20)
						{
							//и если она пуста
							if(this->Map[PoX][PoZ] == 0)
							{
								this->Map0[PoX][PoZ]=1;
							}
							//или с ресурсом
							if(this->Map[PoX][PoZ] == 2)
							{
								this->Map0[PoX][PoZ]=2;
							}
						}
					}
				}
			}
		}
	}
	//повторить для замков
	for(int i=0;i<this->Fractions[0].GetCastleSize();i++)
	{
			for(int PoX = this->Fractions[0].GetCastleMapX(i) - (int)this->Fractions[0].GetCastleBuildRad(i);PoX <= this->Fractions[0].GetCastleMapX(i) + (int)this->Fractions[0].GetCastleBuildRad(i); PoX++)
			{
				for(int PoZ = this->Fractions[0].GetCastleMapZ(i) - (int)this->Fractions[0].GetCastleBuildRad(i);PoZ <= this->Fractions[0].GetCastleMapZ(i) + (int)this->Fractions[0].GetCastleBuildRad(i); PoZ++)
				{
					//в радиусе
					if(sqrt(pow((double)this->Fractions[0].GetCastleMapX(i)-(double)PoX,2)+pow((double)this->Fractions[0].GetCastleMapZ(i)-(double)PoZ,2))<=this->Fractions[0].GetCastleBuildRad(i))
					{
						if(PoX >-1 && PoX <20 && PoZ >-1 && PoZ < 20)
						{
							//и если она пуста
							if(this->Map[PoX][PoZ] == 0)
							{
								this->Map0[PoX][PoZ]=1;
							}
							//или с ресурсом
							if(this->Map[PoX][PoZ] == 2)
							{
								this->Map0[PoX][PoZ]=2;
							}
						}
					}
				}
			}
		
	}
}

void TowWorld::MakeMap1()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			this->Map1[i][j]=0;
		}
	}
	//перебирать башни зоны
	//проверять точки в их радиусе
	for(int i=0;i<this->Fractions[1].GetTowerSize();i++)
	{
		if(this->Fractions[1].GetTowerTip(i) == 3 && this->Fractions[1].GetTowerBuilt(i)== 1)
		{
			for(int PoX = this->Fractions[1].GetTowerMapX(i) - (int)this->Fractions[1].GetBuildRad(i);PoX <= this->Fractions[1].GetTowerMapX(i) + (int)this->Fractions[1].GetBuildRad(i); PoX++)
			{
				for(int PoZ = this->Fractions[1].GetTowerMapZ(i) - (int)this->Fractions[1].GetBuildRad(i);PoZ <= this->Fractions[1].GetTowerMapZ(i) + (int)this->Fractions[1].GetBuildRad(i); PoZ++)
				{
					//в радиусе
					if(sqrt(pow((double)this->Fractions[1].GetTowerMapX(i)-(double)PoX,2)+pow((double)this->Fractions[1].GetTowerMapZ(i)-(double)PoZ,2))<=this->Fractions[1].GetBuildRad(i))
					{
						if(PoX >-1 && PoX <20 && PoZ >-1 && PoZ < 20)
						{
							//и если она пуста
							if(this->Map[PoX][PoZ] == 0)
							{
								this->Map1[PoX][PoZ]=1;
							}
							//или с ресурсом
							if(this->Map[PoX][PoZ] == 2)
							{
								this->Map1[PoX][PoZ]=2;
							}
						}
					}
				}
			}
		}
	}
	//повторить для замков
	for(int i=0;i<this->Fractions[1].GetCastleSize();i++)
	{
			for(int PoX = this->Fractions[1].GetCastleMapX(i) - (int)this->Fractions[1].GetCastleBuildRad(i);PoX <= this->Fractions[1].GetCastleMapX(i) + (int)this->Fractions[1].GetCastleBuildRad(i); PoX++)
			{
				for(int PoZ = this->Fractions[1].GetCastleMapZ(i) - (int)this->Fractions[1].GetCastleBuildRad(i);PoZ <= this->Fractions[1].GetCastleMapZ(i) + (int)this->Fractions[1].GetCastleBuildRad(i); PoZ++)
				{
					//в радиусе
					if(sqrt(pow((double)this->Fractions[1].GetCastleMapX(i)-(double)PoX,2)+pow((double)this->Fractions[1].GetCastleMapZ(i)-(double)PoZ,2))<=this->Fractions[1].GetCastleBuildRad(i))
					{
						if(PoX >-1 && PoX <20 && PoZ >-1 && PoZ < 20)
						{
							//и если она пуста
							if(this->Map[PoX][PoZ] == 0)
							{
								this->Map1[PoX][PoZ]=1;
							}
							//или с ресурсом
							if(this->Map[PoX][PoZ] == 2)
							{
								this->Map1[PoX][PoZ]=2;
							}
						}
					}
				}
			}
		
	}
}

int TowWorld::GetMapValue(int X,int Y)
{
	return this->Map[X][Y];
}
void TowWorld::SetMapValue(int X,int Y,int NewValue)
{
	this->Map[X][Y] = NewValue;
}

void TowWorld::LoadMapFromFile(const char * MapFileName)
{
	ifstream file1(MapFileName);
	if(!file1){
		cout << "Can't open file!\n" << MapFileName;
	}
	int x,z,money,fraction,tip;
	x=0;
	tip=0;
	fraction=0;
	z=0;
	money=0;
	char c;
	while   (!file1.eof()){
		file1>>c;
		if(c == 'f'){
			file1 >> tip >> x >> z >> money;
			this->Fractions.push_back(TowFraction(tip,x,z,money));
			this->Map[x-1][z-1]=1;
			this->Map[x-1][z]=1;
			this->Map[x-1][z+1]=1;
			this->Map[x][z-1]=1;
			this->Map[x][z]=1;
			this->Map[x][z+1]=1;
			this->Map[x+1][z-1]=1;
			this->Map[x+1][z]=1;
			this->Map[x+1][z+1]=1;
		}
		if(c == 'm'){
			file1 >> x >> z;
			this->Minerals.push_back(TowMineral(0.0,0.0,0.0,x,z,10000));
			this->Map[x][z]=2;
		}
		if(c == 'b'){
			file1 >> x >> z;
			this->Barriers.push_back(TowBarrier(0.0,0.0,0.0,x,z,1));
			this->Map[x][z]=1;
		}
		if(c == 't'){
			file1 >> fraction >> tip >> x >> z;
			this->Fractions[fraction].AddTower(x,z,this->Healthes[tip],this->Healthes[tip],tip);
			if(tip == 2){
				this->Map[x][z]=3;
			}else{
				this->Map[x][z]=1;
			}
		}
	}
	file1.close();
}
//-------------------------------
bool TowWorld::BuySomeTowers(int FrackNomber,int TowerType)
{
	bool ans = false;
	if(this->Fractions[FrackNomber].GetMinerals() < this->Prices[TowerType])
	{
		if(FrackNomber == 0){
			this->MoneyAllertTime = 750;
		}
		ans = false;
	}else{
		this->Fractions[FrackNomber].DecMinerals(this->Prices[TowerType]);
		ans = true;
	}
	return ans;
}
//-------------------------------
void TowWorld::DelNeedlessMissles()
{
	int k=0;
	int Nom=0;
	
	for(int i=0;i<this->Missles.size();i++)
	{
		if(this->Missles[i].OnTarget())
		{
			k=1;
			Nom=i;
		}
	}
	if(k==1)
	{
		this->Missles.erase(this->Missles.begin()+Nom, this->Missles.begin()+Nom+1);
		this->DelNeedlessMissles();
	}
}
void TowWorld::DelNeedlessSmokes()
{
	int k=0;
	int DelElement=0;
	for(int i=0;i<this->Smokes.size();i++)
	{
		if(this->Smokes[i].FlyIsOver())
		{
			k=1;
			DelElement=i;
		}
	}
	if(k==1)
	{
		this->Smokes.erase(this->Smokes.begin()+DelElement, this->Smokes.begin()+DelElement+1);
		this->DelNeedlessSmokes();
	}
}
//-----------------------------
void TowWorld::DelNeedlessMineSmokes()
{
	int k=0;
	int DelElement=0;
	for(int i=0;i<this->MineSmokes.size();i++)
	{
		if(this->MineSmokes[i].FlyIsOver())
		{
			k=1;
			DelElement=i;
		}
	}
	if(k==1)
	{
		this->MineSmokes.erase(this->MineSmokes.begin()+DelElement, this->MineSmokes.begin()+DelElement+1);
		this->DelNeedlessSmokes();
	}
}
//-----------------------------
void TowWorld::PCMakeItsMove()
{
	//результат - это либо постройка башни - либо ожидание
	vector<int>RX;
	vector<int>RZ;
	int BZ,BX = 0;
	int TipOfTower = 1;
	bool CanBuild = false;
	bool WantBuildMine = false;
	bool WantBuildZone = false;
	bool WantBuildCannon = false;
	this->MakeMap1();
	RZ.clear();
	RX.clear();
	//1.Если в моей зоне строительства есть ресурс сторить шахту
	//3.Если в нет ресурса - строить башню зоны в случайно выбранном месте, граничащим с пустотой
	//4.Если ресурсов > 3 то можно построить 3 башни пушки, потом еще ресурс, потом еще 3 башни пушки и тд
	for(int i = 0;i < 20;i++)
	{
		for(int j = 0;j < 20;j++)
		{
			if(Map1[i][j] == 2){
				WantBuildMine = true;
				BX = i;
				BZ = j;
				TipOfTower = 2;
			}
		}
	}
	if(WantBuildMine){
		//проверить на кол-во денег
		if(this->BuySomeTowers(1,2))
		{
			CanBuild = true;
		}
	}else{
		//
		for(int i = 0;i < 20;i++)
		{
			for(int j = 0;j < 20;j++)
			{
				if(this->BuildCannonTowers<1){
					if(Map1[i][j] == 1 && this->OnBorder(i,j)){
						RX.push_back(i);
						RZ.push_back(j);
						WantBuildZone = true;
					}
				}else{
					if(Map1[i][j] == 1 && this->OnBorder(i,j)){
						RX.push_back(i);
						RZ.push_back(j);
						WantBuildCannon = true;
					}
				}
			}
		}
		if(WantBuildZone){
				int RandPos = rand() % RX.size();
				BX = RX[RandPos];
				BZ = RZ[RandPos];
				TipOfTower = 3;
				if(this->BuySomeTowers(1,3))
				{
					CanBuild = true;
					this->BuildCannonTowers = 1;
				}
		}
		if(WantBuildCannon){
				int RandPos = rand() % RX.size();
				BX = RX[RandPos];
				BZ = RZ[RandPos];
				TipOfTower = 1;
				if(this->BuySomeTowers(1,1))
				{
					CanBuild = true;
					this->BuildCannonTowers = this->BuildCannonTowers - 1;
				}
		}
		//
	}
	if(CanBuild)
	{
		this->Fractions[1].BuildTower(BX,BZ,this->BuildTimes[TipOfTower],this->Healthes[TipOfTower],this->Healthes[TipOfTower],TipOfTower);
		this->Map[BX][BZ]=this->Map[BX][BZ]+1;
	}
}
//----------------------------------------
bool TowWorld::OnBorder(int x,int z)
{
	bool ans = false;
	if(x>0 && z>0){
		if((this->Map1[x-1][z-1] == 0) && ((this->Map[x-1][z-1] == 0) || (this->Map[x-1][z-1] == 2)))
		 {
			 ans = true;
		 }
	}
	if(x>0){
		if((this->Map1[x-1][z] == 0) && ((this->Map[x-1][z] == 0) || (this->Map[x-1][z] == 2)))
		{
			 ans = true;
		}
	}
	if(x>0 && z<19){
		 if((this->Map1[x-1][z+1] == 0) && ((this->Map[x-1][z+1] == 0) || (this->Map[x-1][z+1] == 2)))
		 {
			 ans = true;
		 }
	}
	if(z>0){
		 if((this->Map1[x][z-1] == 0) && ((this->Map[x][z-1] == 0) ||  (this->Map[x][z-1] == 2)))
		 {
			 ans = true;
		 }
	}
	if(z<19){
		 if((this->Map1[x][z+1] == 0) && ((this->Map[x][z+1] == 0) || (this->Map[x][z+1] == 2)))
		 {
			 ans = true;
		 }
	}
	if(x<19 && z>0){
		 if((this->Map1[x+1][z-1] == 0) && ((this->Map[x+1][z-1] == 0) || (this->Map[x+1][z-1] == 2)))
		 {
			 ans = true;
		 }
	}
	if(x<19){
		if((this->Map1[x+1][z] == 0) && ((this->Map[x+1][z] == 0) || (this->Map[x+1][z] == 2)))
		{
			 ans = true;
		}
	}
	if(x<19 && z<19){
		 if((this->Map1[x+1][z+1] == 0) && ((this->Map[x+1][z+1] == 0) || (this->Map[x+1][z+1] == 2)))
		 {
			 ans = true;
		 }
	}
	return ans;
}
//-----------------------------
void TowWorld::DrawObjects()
{
	this->WorldGraphics1.DrawOneModel(0,0.0,0.0,0.0,1.0);
	for(int i = 0;i < this->Barriers.size();i++)
	{ 
		this->WorldGraphics1.DrawOneModel(4,-76.0+this->Barriers[i].GetMapX()*Zoom1,0.0,-76.0+this->Barriers[i].GetMapZ()*Zoom1,Zoom1);
	}
	for(int i = 0;i < this->Minerals.size();i++)
	{ 
		this->WorldGraphics1.DrawOneModel(1,-76.0+this->Minerals[i].GetMapX()*Zoom1,0.0,-76.0+this->Minerals[i].GetMapZ()*Zoom1,Zoom1);
	}
	for(int i = 0;i < this->Missles.size();i++)
	{ 
		this->WorldGraphics1.DrawOneModel(2,-76.0+this->Missles[i].GetX()*Zoom1,Missles[i].GetY()*Zoom1,-76.0+this->Missles[i].GetZ()*Zoom1,Zoom1);
	}
	for(int i = 0;i < this->Smokes.size();i++)
	{ 
		this->WorldGraphics1.DrawOneModel(3,-76.0+this->Smokes[i].GetMapX()*Zoom1,this->Smokes[i].GetY()*Zoom1,-76.0+this->Smokes[i].GetMapZ()*Zoom1,Zoom1*2);
	}
	for(int i = 0;i < this->MineSmokes.size();i++)
	{ 
		this->WorldGraphics1.DrawOneModel(8,-76.0+this->MineSmokes[i].GetMapX()*Zoom1+0.2*Zoom1,this->MineSmokes[i].GetY()*Zoom1,-76.0+this->MineSmokes[i].GetMapZ()*Zoom1-0.2*Zoom1,Zoom1*0.6);
	}
	for(int i = 0;i < this->Fractions.size();i++)
	{
		if(this->Fractions[i].GetTip() == 1){
			for(int j = 0; j < this->Fractions[i].GetCastleSize();j++)
			{
				this->WorldGraphics1.DrawOneModel(10,-76.0+this->Fractions[i].GetCastleMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetCastleMapZ(j)*Zoom1,Zoom1);
			}
			for(int j = 0; j < this->Fractions[i].GetTowerSize();j++)
			{
				if(this->Fractions[i].GetTowerBuilt(j) == 1){
					switch(this->Fractions[i].GetTowerTip(j))
					{
					case 1:
						{
							this->WorldGraphics1.DrawOneModel(13,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1*0.8);
							this->WorldGraphics1.DrawOneModel(16,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,1.5*Zoom1*0.8,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 2:
						{
							this->WorldGraphics1.DrawOneModel(22,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 3:
						{
							this->WorldGraphics1.DrawOneModel(19,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					}
				}else{
					switch(this->Fractions[i].GetTowerTip(j))
					{
					case 1:
						{
							this->WorldGraphics1.DrawOneModel(14,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1*0.8);
							this->WorldGraphics1.DrawOneModel(17,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,1.5*Zoom1*0.8,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 2:
						{
							this->WorldGraphics1.DrawOneModel(23,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 3:
						{
							this->WorldGraphics1.DrawOneModel(20,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					}
				}
			}

		}
		else
		{
			for(int j = 0; j < this->Fractions[i].GetCastleSize();j++)
			{
				this->WorldGraphics1.DrawOneModel(40,-76.0+this->Fractions[i].GetCastleMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetCastleMapZ(j)*Zoom1,Zoom1);
			}
			for(int j = 0; j < this->Fractions[i].GetTowerSize();j++)
			{
				//----=+++
				if(this->Fractions[i].GetTowerBuilt(j) == 1){
					switch(this->Fractions[i].GetTowerTip(j))
					{
					case 1:
						{
							this->WorldGraphics1.DrawOneModel(43,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1*0.8);
							this->WorldGraphics1.DrawOneModel(46,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,1.5*Zoom1*0.8,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 2:
						{
							this->WorldGraphics1.DrawOneModel(52,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 3:
						{
							this->WorldGraphics1.DrawOneModel(49,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					}
				}else{
					switch(this->Fractions[i].GetTowerTip(j))
					{
					case 1:
						{
							this->WorldGraphics1.DrawOneModel(44,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1*0.8);
							this->WorldGraphics1.DrawOneModel(47,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,1.5*Zoom1*0.8,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 2:
						{
							this->WorldGraphics1.DrawOneModel(53,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					case 3:
						{
							this->WorldGraphics1.DrawOneModel(50,-76.0+this->Fractions[i].GetTowerMapX(j)*Zoom1,0.0,-76.0+this->Fractions[i].GetTowerMapZ(j)*Zoom1,Zoom1);
						}
						break;
					}
				}
				//---=++
			}
		}
	}
	//this->WorldGraphics1.DrawOneModel(10,-76.0,0.0,-76.0,8.0);
}
//--------------------------------------------------------------
void TowWorld::DrawCountMinerals(int Count)
{
	int Numeral=0;
	Numeral = (Count % 10)+70;
	this->WorldGraphics1.DrawOneModel(Numeral,-6.0,40.0,-70.0,4.0);
	if(Count > 9){
		Numeral = ((Count % 100)/10)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-16.0,40.0,-70.0,4.0);
	}
	if(Count > 99){
		Numeral = ((Count % 1000)/100)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-26.0,40.0,-70.0,4.0);
	}
	if(Count > 999){
		Numeral = ((Count % 10000)/1000)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-40.0,40.0,-70.0,4.0);
	}
	if(Count > 9999){
		Numeral = ((Count % 100000)/10000)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-50.0,40.0,-70.0,4.0);
	}
	this->WorldGraphics1.DrawOneModel(1,-68.0,40.0,-70.0,16.0);
}
//------------------------------------------------------------------
void TowWorld::DrawMoneyAllert()
{
	if(this->MoneyAllertTime > 0)
	{
		if(this->MoneyAllertTime > 0 && this->MoneyAllertTime < 150)
		{
			this->WorldGraphics1.DrawOneModel(7,4.0,40.0,-70.0,8.0);
		}
		if(this->MoneyAllertTime > 300 && this->MoneyAllertTime < 450)
		{
			this->WorldGraphics1.DrawOneModel(7,4.0,40.0,-70.0,8.0);
		}
		if(this->MoneyAllertTime > 600 && this->MoneyAllertTime < 750)
		{
			this->WorldGraphics1.DrawOneModel(7,4.0,40.0,-70.0,8.0);

		}
	}
}
//------------------------------------------------------------------
void TowWorld::DrawWin()
{
	this->WorldGraphics1.DrawOneModel(89,0.0,0.0,-355.0,7.0);
	this->WorldGraphics1.DrawOneModel(80,-63.0,-10.5,-353.0,7.0);//Y
	this->WorldGraphics1.DrawOneModel(81,-42.0,-10.5,-353.0,7.0);//O
	this->WorldGraphics1.DrawOneModel(82,-21.0,-10.5,-353.0,7.0);//U
	//---------------------------------------------------------//
	this->WorldGraphics1.DrawOneModel(83,21.0,-10.5,-353.0,7.0);//W
	this->WorldGraphics1.DrawOneModel(84,42.0,-10.5,-353.0,7.0);//I
	this->WorldGraphics1.DrawOneModel(85,63.0,-10.5,-353.0,7.0);//N
}
void TowWorld::DrawLose()
{
	this->WorldGraphics1.DrawOneModel(89,0.0,0.0,-355.0,7.0);
	this->WorldGraphics1.DrawOneModel(80,-73.5,-10.5,-353.0,7.0);//Y
	this->WorldGraphics1.DrawOneModel(81,-52.5,-10.5,-353.0,7.0);//O
	this->WorldGraphics1.DrawOneModel(82,-31.5,-10.5,-353.0,7.0);//U
	//---------------------------------------------------------//
	this->WorldGraphics1.DrawOneModel(86,11.5,-10.5,-353.0,7.0);//L
	this->WorldGraphics1.DrawOneModel(81,32.5,-10.5,-353.0,7.0);//O
	this->WorldGraphics1.DrawOneModel(87,53.5,-10.5,-353.0,7.0);//S
	this->WorldGraphics1.DrawOneModel(88,74.5,-10.5,-353.0,7.0);//E
}
//------------------------------------------------------------------
void TowWorld::DrawBuilding(int FractionNomer, int TowerType)
{
	this->BuildX.clear();
	this->BuildZ.clear();
	this->MakeMap0();
	//отрисовывает по карте
	if(TowerType == 1 || TowerType == 3)
	{
		for(int i=0; i<20;i++)
		{
			for(int j=0; j<20;j++)
			{
				if(Map0[i][j]==1)
				{
					this->BuildX.push_back(i);
					this->BuildZ.push_back(j);
					glPushName(this->BuildX.size()-1);
					this->WorldGraphics1.DrawOneModel(5,-76.0+i*Zoom1,0.1,-76.0+j*Zoom1,Zoom1);
					glPopName();
				}
			}
		}
	}
	if(TowerType == 2)
	{
		for(int i=0; i<20;i++)
		{
			for(int j=0; j<20;j++)
			{
				if(Map0[i][j]==2)
				{
					this->BuildX.push_back(i);
					this->BuildZ.push_back(j);
					glPushName(this->BuildX.size()-1);
					this->WorldGraphics1.DrawOneModel(6,-76.0+i*Zoom1,0.1,-76.0+j*Zoom1,Zoom1);
					glPopName();
				}
			}
		}
	}
}
//-------------------------------------------------------------------
void TowWorld::DrawSmallMap()
{
	int Numeral;
	for(int i = 0; i< 20;i++){
		for(int j = 0; j<20; j++){
			Numeral = this->Map1[i][j]+70;
			this->WorldGraphics1.DrawOneModel(Numeral,30.00+i*4.0,90.0 - j*4.0,-362.0,1.0);
			Numeral = this->Map[i][j]+70;
			this->WorldGraphics1.DrawOneModel(Numeral,30.00+i*4.0,0.0 - j*4.0,-362.0,1.0);
			//this->WorldGraphics1.DrawOneModel(Numeral,-87.00,46.0,-362.0,1.0);
		}
	}
}
//---------------------------------------------------------------------------
void TowWorld::DrawBuildPannel()
{
	glInitNames();
	glPushName(2001);
	int Numeral=0;
	this->WorldGraphics1.DrawOneModel(13,-90.0,50.0,-362.0,Zoom1);
	this->WorldGraphics1.DrawOneModel(16,-90.0,50.0+1.5*Zoom1,-362.0,Zoom1);
	//цена
	Numeral = (this->Prices[1] % 10)+70;
	this->WorldGraphics1.DrawOneModel(Numeral,-87.00,46.0,-362.0,1.0);
	if(this->Prices[1] > 9){
		Numeral = ((this->Prices[1] % 100)/10)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-90.0,46.0,-362.0,1.0);
	}
	if(this->Prices[1] > 99){
		Numeral = ((this->Prices[1] % 1000)/100)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-93.00,46.0,-362.0,1.0);
	}
	glPopName();
	glPushName(2002);
	this->WorldGraphics1.DrawOneModel(22,-90.0,30,-362.0,Zoom1*1.2);
	this->WorldGraphics1.DrawOneModel(1,-90.0,32,-362.0,Zoom1*1.2);
    //цена
	Numeral = (this->Prices[2] % 10)+70;
	this->WorldGraphics1.DrawOneModel(Numeral,-87.00,26.0,-362.0,1.0);
	if(this->Prices[2] > 9){
		Numeral = ((this->Prices[2] % 100)/10)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-90.0,26.0,-362.0,1.0);
	}
	if(this->Prices[2] > 99){
		Numeral = ((this->Prices[2] % 1000)/100)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-93.00,26.0,-362.0,1.0);
	}
	glPopName();
	glPushName(2003);
	this->WorldGraphics1.DrawOneModel(19,-90.0,6,-362.0,Zoom1);
	//цена
	Numeral = (this->Prices[3] % 10)+70;
	this->WorldGraphics1.DrawOneModel(Numeral,-87.00,2.0,-362.0,1.0);
	if(this->Prices[3] > 9){
		Numeral = ((this->Prices[3] % 100)/10)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-90.0,2.0,-362.0,1.0);
	}
	if(this->Prices[3] > 99){
		Numeral = ((this->Prices[3] % 1000)/100)+70;
		this->WorldGraphics1.DrawOneModel(Numeral,-93.00,2.0,-362.0,1.0);
	}
	glPopName();
}

//-----------------------------------------------------------------
int TowWorld::RetrieveObjectID(int x, int y)
{
    int objectsFound = 0;   // Общее количество кликнутых обьектов
    int viewportCoords[4] = {0};    // Массив для хранения экранных координат


    // Переменная для хранения ID обьектов, на которые мы кликнули.
    // Мы делаем массив в 32 элемента, т.к. OpenGL также сохраняет другую
    // информацию, которая нам сейчас не нужна. Для каждого обьекта нужно
    // 4 слота.
    unsigned int selectBuffer[32] = {0};

    // glSelectBuffer регистрирует массив как буфер выбора обьектов. Первый параметр - размер
    // массива. Второй - сам массив для хранения информации.

    glSelectBuffer(32, selectBuffer);   // Регистрируем буфер для хранения выбранных обьектов

    // Эта функция возвращает информацию о многих вещах в OpenGL. Мы передаём GL_VIEWPOR,
    // чтобы получить координаты экрана. Функция сохранит их в переданном вторым параметром массиве
    // в виде top,left,bottom,right.
    glGetIntegerv(GL_VIEWPORT, viewportCoords); // Получаем текущие координаты экрана

    // Теперь выходим из матрицы GL_MODELVIEW и переходим в матрицу GL_PROJECTION.
    // Это даёт возможность использовать X и Y координаты вместо 3D.

    glMatrixMode(GL_PROJECTION);    // Переходим в матрицу проекции

    glPushMatrix();         // Переходим в новые экранные координаты

        // Эта функция делает так, что фреймбуфер не изменяется при рендере в него, вместо этого
        // происходит запись имён (ID) примитивов, которые были бы отрисованы при режиме
        // GL_RENDER. Информация помещается в selectBuffer.

        glRenderMode(GL_SELECT);    // Позволяет рендерить обьекты без изменения фреймбуфера

        glLoadIdentity();       // Сбросим матрицу проекции

        // gluPickMatrix позволяет создавать матрицу проекции около нашего курсора. Проще говоря,
        // рендерится только область, которую мы укажем (вокруг курсора). Если обьект рендерится
        // в этой области, его ID сохраняется (Вот он, смысл всей функции).
        // Первые 2 параметра - X и Y координаты начала, следующие 2 - ширина и высота области
        // отрисовки. Последний параметр - экранные координаты. Заметьте, мы вычитаем 'y' из
        // НИЖНЕЙ экранной координаты. Мы сделали это, чтобы перевернуть Y координаты. 
        // В 3д-пространстве нулевые y-координаты начинаются внизу, а в экранных координатах
        // 0 по y находится вверху. Также передаём регион 2 на 2 пиксела для поиска в нём обьекта. 
        // Это может быть изменено как вам удобнее.

        gluPickMatrix(x, viewportCoords[3] - y, 2, 2, viewportCoords);
        // Далее просто вызываем нашу нормальную функцию gluPerspective, точно так же, как
        // делали при инициализации.
		gluPerspective(30.0f, (GLfloat)this->WorldGraphics1.GetW()/(GLfloat)this->WorldGraphics1.GetH(), 300.0, 800.0);
  

        glMatrixMode(GL_MODELVIEW); // Возвращаемся в матрицу GL_MODELVIEW

		//this->DrawAll();        // Теперь рендерим выбранную зону для выбора обьекта
		this->WorldGraphics1.DrawWorldBegin();
		this->DrawBuildPannel();
		this->WorldGraphics1.DrawWorldRotNTrans();
		if(this->ActionType == 1){
			if(this->BuildingTower == 1 || this->BuildingTower == 3){
				this->DrawBuilding(0,1);
			}else{
				this->DrawBuilding(0,2);
			}
		}
		this->WorldGraphics1.DrawWorldEnd();

        // Если мы вернёмся в нормальный режим рендеринга из режима выбора, glRenderMode
        // возвратит число обьектов, найденных в указанном регионе (в gluPickMatrix()).

        objectsFound = glRenderMode(GL_RENDER); // Вернемся в режим отрисовки и получим число обьектов

		glMatrixMode(GL_PROJECTION);    // Вернемся в привычную матрицу проекции

	glPopMatrix();              // Выходим из матрицы


    glMatrixMode(GL_MODELVIEW);     // Вернемся в матрицу GL_MODELVIEW

    // УФФ! Это было немного сложно. Теперь нам нужно выяснить ID выбранных обьектов.
    // Если они есть - objectsFound должно быть как минимум 1.

    if (objectsFound > 0)
    {
        // Если мы нашли более 1 обьекта, нужно проверить значения глубины всех
        // выбоанных обьектов. Обьект с МЕНЬШИМ значением глубины - ближайший
        // к нам обьект, значит и щелкнули мы на него. В зависимости от того, что
        // мы программируем, нам могут понадобится и ВСЕ выбранные обьекты (если
        // некоторые были за ближайшим), но в этом уроке мы позаботимся только о
        // переднем обьекте. Итак, как нам получить значение глубины? Оно сохранено
        // в буфере выбора (selectionBuffer). Для каждого обьекта в нем 4 значения.
        // Первое - "число имен в массиве имен на момент события, далее минимум и
        // максимум значений глубины для всех вершин, которые были выбраны при прошлом
        // событии, далее по содержимое массива имен, нижнее имя - первое;
        // ("the number of names in the name stack at the time of the event, followed
        // by the minimum and maximum depth values of all vertices that hit since the
        // previous event, then followed by the name stack contents, bottom name first.") - MSDN.
        // Единстве, что нам нужно - минимальное значение глубины (второе значение) и
        // ID обьекта, переданного в glLoadName() (четвертое значение).
        // Итак, [0-3] - данные первого обьекта, [4-7] - второго, и т.д...
        // Будте осторожны, так как если вы отображаете на экране 2Д текст, он будет 
        // всегда находится как ближайший обьект. Так что убедитесь, что отключили вывод
        // текста при рендеринге в режиме GL_SELECT. Я для этого использую флаг, передаваемый
        // в RenderScene(). Итак, получим обьект с минимальной глубиной!

        // При старте установим ближайшую глубину как глубину первого обьекта.
        // 1 - это минимальное Z-значение первого обьекта.
        unsigned int lowestDepth = selectBuffer[1];

        // Установим выбранный обьект как первый при старте.
        // 3 - ID первого обьекта, переданный в glLoadName().
        int selectedObject = selectBuffer[3];

        // Проходим через все найденные обьекты, начиная со второго (значения первого
        // мы присвоили изначально).
        for(int i = 1; i < objectsFound; i++)
        {
            // Проверяем, не ниже ли значение глубины текущего обьекта, чем предидущего.
            // Заметьте, мы умножаем i на 4 (4 значения на каждый обьект) и прибавляем 1 для глубины.
            if(selectBuffer[(i * 4) + 1] < lowestDepth)
            {
                // Установим новое низшее значение
                lowestDepth = selectBuffer[(i * 4) + 1];

                // Установим текущий ID обьекта
                selectedObject = selectBuffer[(i * 4) + 3];
            }
        }

        // Вернем выбранный обьект
        return selectedObject;
    }

    // Если не щелкнули ни на 1 обьект, вернём -1
    return -1;

}
//-------------------------------------------------
void TowWorld::TimerFunc(int MS)
{
	int SmokePosition;
	SmokePosition=-10;
	//проверка на конец игры
	if(this->Fractions[0].GetCastleSize() > 0 && this->Fractions[1].GetCastleSize() > 0)
	{
	}else{
		this->ActionType = 2;
		if(this->Fractions[0].GetCastleSize() > 0){
			this->GameOver = 1;
		}else{
			this->GameOver = 2;
		}
	}
	//если не конец игры
	if(ActionType != 2){
	this->PCMakeItsMove();
	//vector<int> NomToDel;
	//проверяем снаряды
	for(int i=0;i<this->Missles.size();i++)
	{
		this->Missles[i].MakeMove(MS);
		if(this->Missles[i].OnTarget())
		{
			for(int j=0;j<this->Fractions.size();j++)
			{

				SmokePosition = this->Fractions[j].CheckForDamage(this->Missles[i].GetTargetX(),this->Missles[i].GetTargetZ(),this->Missles[i].GetDamage());
				//int WasInMap = this->Map[SmokePosition / 100][SmokePosition % 100];
				if(SmokePosition > -1){
					this->Map[SmokePosition / 100][SmokePosition % 100]= this->Map[SmokePosition / 100][SmokePosition % 100] - 1;
					this->Smokes.push_back(TowSmoke(0.0,0.0,0.0,SmokePosition / 100,SmokePosition % 100,0.001,1000));
				}
			}
		}
	}
	this->DelNeedlessMissles();
	this->DelNeedlessMineSmokes();
	//создаем дымок на месте взорваной башни
	//обработка дыма
	for(int i=0;i<this->Smokes.size();i++)
	{
		if(this->Smokes[i].MoveAndCheck(MS))
		{
		}
	}
	for(int i=0;i<this->MineSmokes.size();i++)
	{
		if(this->MineSmokes[i].MoveAndCheck(MS))
		{
		}
	}
	this->DelNeedlessSmokes();
	
	//проверка башен - стрельба
	for(int i=0;i<this->Fractions.size();i++)
	{
		for(int j=0;j<this->Fractions[i].GetTowerSize();j++)
		{
			if(this->Fractions[i].GetTowerBuilt(j) == 1){
			///----+++++
			if(this->Fractions[i].GetTowerTip(j) == 1)
			{
				//проверяем цель
				//если там есть башня то стрелять
				//если нет, то сбросить цель и искать новую
				int CheckFrack;
				if(i==0)
				{
					CheckFrack=1;
				}else{
					CheckFrack=0;
				}
				if(this->Fractions[CheckFrack].IsTowerHere(this->Fractions[i].GetTowerTargetX(j),this->Fractions[i].GetTowerTargetZ(j)))
				{
					//цель ок
				}else{
					int NewTarget;
					if(this->Fractions[CheckFrack].IsTowerInRad(this->Fractions[i].GetTowerMapX(j),this->Fractions[i].GetTowerMapZ(j),this->Fractions[i].GetTowerRad(j)))
					{
						NewTarget = this->Fractions[CheckFrack].FindTowerInRad(this->Fractions[i].GetTowerMapX(j),this->Fractions[i].GetTowerMapZ(j),this->Fractions[i].GetTowerRad(j));
						this->Fractions[i].SetTarget(j,NewTarget / 100,NewTarget % 100);
					}else{
						this->Fractions[i].SetTarget(j,-15,-15);
					}
				}
				//стреляем если цель есть
				//проходит перезарядка
				if(this->Fractions[i].TowerTimePass(j,MS)){
					if(this->Fractions[i].GetTowerTargetX(j) > -1)
					{
						//стреляем по цели снарядом
						//this->Missles.push_back(TowMissle((double)this->Fractions[i].GetTowerMapX(j), 1.4,(double)this->Fractions[i].GetTowerMapZ(j),
							//							  50, 0.001,this->Fractions[i].GetTowerTargetX(j),this->Fractions[i].GetTowerTargetZ(j)));
						//double FromX = (double) Fractions[i].GetTowerTargetX(j);
						//double FromZ = (double) Fractions[i].GetTowerTargetZ(j);
						this->Missles.push_back(TowMissle(Fractions[i].GetTowerMapX(j), 1.4,Fractions[i].GetTowerMapZ(j),
														  Fractions[i].GetTowerDamage(j), 0.007,this->Fractions[i].GetTowerTargetX(j),this->Fractions[i].GetTowerTargetZ(j)));
						this->Fractions[i].TowerShotDone(j);

					}
				}			
			}
			if(this->Fractions[i].GetTowerTip(j) == 2)
			{
				//добытчик
				//найти ресурс под собой - не надо т.к. ресурсы бесконечные
				//если время вышло добыть ресурс
				//
				if(this->Fractions[i].TowerIsGathered(j,MS))
				{
					this->Fractions[i].AddMinerals(this->Fractions[i].TowerGetHowMuchGather(j));
					this->MineSmokes.push_back(TowSmoke(0.0,1.3,0.0,Fractions[i].GetTowerMapX(j),Fractions[i].GetTowerMapZ(j),0.001,1000));
					
				}
			}
			/////----++++
			}else{
				////
				if(this->Fractions[i].TowerBuildTower(j,MS))
				{
				}
			}
		}
	}
	//проверка денежной тревоги
	if(this->MoneyAllertTime > 0)
	{
		this->MoneyAllertTime = this->MoneyAllertTime - MS;
	}
	}else{
		//ничего не делать
	}
}
void TowWorld::MouseFunc(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		int PressOn;
		PressOn = this->RetrieveObjectID(x,y);
		if(PressOn != -1)
		{
			if(this->ActionType == 1 ){
				if(PressOn < 2000){
					int RHealth;
					int RTimeToBuild;
					RHealth = this->Healthes[BuildingTower];
					RTimeToBuild = this->BuildTimes[BuildingTower];
					if(this->BuySomeTowers(0,this->BuildingTower)){
						this->Fractions[0].BuildTower(this->BuildX[PressOn],this->BuildZ[PressOn],RTimeToBuild,RHealth,RHealth,this->BuildingTower);
						this->Map[this->BuildX[PressOn]][this->BuildZ[PressOn]]=1;
					}
					this->ActionType = 0;
				}else{
					if(PressOn - 2000 == this->BuildingTower)
					{
						this->ActionType = 0;
					}else{
						this->BuildingTower = PressOn - 2000;
					}
				}
			}else{
				if(PressOn == 2001)
				{
					this->ActionType = 1;
					this->BuildingTower = 1;
				}
				if(PressOn == 2002)
				{
					this->ActionType = 1;
					this->BuildingTower = 2;
				}
				if(PressOn == 2003)
				{
					this->ActionType = 1;
					this->BuildingTower = 3;
				}
			}
		}
	}
}
void TowWorld::DrawAll()
{
	this->WorldGraphics1.DrawWorldBegin();
	this->DrawBuildPannel();
	if(this->ActionType == 2){
		if(this->GameOver == 1){
			this->DrawWin();
		}else{
			this->DrawLose();
		}
	}
	//this->DrawSmallMap(); 
	this->WorldGraphics1.DrawWorldRotNTrans();
	//this->WorldGraphics1.DrawWorld();
	//this->WorldGraphics1.DrawWorldBegin();
	//this->DrawBuilding(0,1);
	//this->WorldGraphics1.DrawWorldEnd();
	this->DrawObjects();
	//this->MakeMap0();
	if(this->ActionType == 1 )
	{
		if(this->BuildingTower == 1 || this->BuildingTower == 3)
		{
			this->DrawBuilding(0,1);
		}else{
			this->DrawBuilding(0,2);
		}
	}
	this->DrawCountMinerals(this->Fractions[0].GetMinerals());
	this->DrawMoneyAllert(); 
	//this->DrawCountMinerals(98271);
	this->WorldGraphics1.DrawWorldEnd();
}
void TowWorld::WChangeSize(GLsizei w, GLsizei h)
{
	this->WorldGraphics1.ChangeSize(w,h);
}
void TowWorld::WSetupRC()
{
	this->WorldGraphics1.SetupRC();
}
//-----------------------------
TowWorld::TowWorld()
{
	this->ClearMap();
	this->BuildCannonTowers = 0;
	this->MoneyAllertTime = 0;
	this->Prices.clear();
	this->Healthes.clear();
	this->BuildTimes.clear();
	this->Prices.push_back(0);
	this->Healthes.push_back(1000);
	this->BuildTimes.push_back(0);
	//1
	this->Prices.push_back(50);
	this->Healthes.push_back(200);
	this->BuildTimes.push_back(4500);
	//2
	this->Prices.push_back(115);
	this->Healthes.push_back(300);
	this->BuildTimes.push_back(7500);
	//3
	this->Prices.push_back(65);
	this->Healthes.push_back(150);
	this->BuildTimes.push_back(3000);
	this->LoadMapFromFile("Map1.txt");
	this->ActionType = 0;
	this->BuildingTower = 1;
	
	/*this->Missles.push_back(TowMissle(7.0, 1.4, 11.0, 10, 0.007,7,11));
	this->Missles.push_back(TowMissle(1.0, 1.4, 5.0, 10, 0.007,7,11));
	this->Missles.push_back(TowMissle(17.0, 1.4, 3.0, 10, 0.007,7,11));
	if(this->Fractions[1].IsTowerInRad(7,11,12.0)){
		int targ=this->Fractions[1].FindTowerInRad(7,11,12.0);
		this->Missles[0].SetTarget(targ / 100,targ % 100);
		this->Missles[1].SetTarget(targ / 100,targ % 100);
		this->Missles[2].SetTarget(targ / 100,targ % 100);
	}*/
}
TowWorld::~TowWorld()
{

}
//Target
int TowTarget::GetX()
{
	return this->X;
}
int TowTarget::GetZ()
{
	return this->Z;
}
TowTarget::TowTarget(int FirstX,int FirstZ)
{
	this->X = FirstX;
	this->Z = FirstZ;
}
TowTarget::~TowTarget()
{
}