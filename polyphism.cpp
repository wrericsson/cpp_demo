/*
 **************************************************************************************
 *       Filename:  polyphism.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-09 10:21:00
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <iostream>
#include <stdio.h>
using namespace  std;


typedef int HANDS;
enum COLOR {Red,Green,Blue,White,Black};
class Horse
{
public: 
	Horse(COLOR color, HANDS height);
	virtual ~Horse(){cout << "Horse dest" << endl ;}
	virtual void Whinny()const{cout << "whinny" << endl;}
	virtual HANDS Getight()const{return itsHeight;}
	virtual HANDS GetColor()const{return itsColor;}

private:
	HANDS itsHeight;
	COLOR itsColor;
};
Horse::Horse(COLOR color,HANDS height):
	itsColor(color),
	itsHeight(height)
{
	cout<< "horse constr\n";
}

class Bird
{
public:
	Bird(COLOR color,bool migrates);
	virtual ~Bird(){cout << "Bird destructor ... \n";}
	virtual void Chirp()const{cout << "Chirp ...\n";}
	virtual void Fly()const{cout << "I can fly!!I can fly";}
	virtual COLOR GetColor()const{return itsColor;};
	virtual bool GetMigration()const{return itsMigration;};
private:
	COLOR itsColor;
	bool itsMigration;
};
Bird::Bird(COLOR color,bool migrates)
	:itsColor(color),
	 itsMigration(migrates){
   cout << "Bird Construct "<< endl;
}

class Pe: public Horse,public Bird
{
public:
	void Chip()const{Whinny();}
	Pe(COLOR,HANDS,bool,long long);
	~Pe(){cout << "Pe decons";}
	virtual long GetNumberB()const
	{
		return itsNumberBelievers;
	}
private:
	long long itsNumberBelievers;
};

Pe::Pe(COLOR pcolor,
	HANDS height,
	bool mig,
	long long Numb):
	Horse(pcolor,height),
	Bird(pcolor,mig),
	itsNumberBelievers(Numb){

	cout<<"Pe constructor" <<endl;	
	
}

int main(int argc, const char *argv[])
{
	Horse *h = new Horse(Blue,100);
	cout << h->Getight() <<endl ;
	Pe *pe = new Pe(Red,99,true,100*10000);
	pe->Whinny();
	return 0;
}
/********************************** END **********************************************/

