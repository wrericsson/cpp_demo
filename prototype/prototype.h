/*
 **************************************************************************************
 *       Filename:  prototype.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2017-03-15 20:13:10
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;
class AbsGoods{
public:
	virtual AbsGoods* Clone() = 0;
	string _mName;
protected:	
	AbsGoods(const AbsGoods& another){}
	~AbsGoods(){}
	AbsGoods(){}
	
	int _Price;
};


class Mp3:public AbsGoods{
public:
	Mp3(){_mName = "MP3"; _Price = 200;}
	virtual AbsGoods* Clone()
	{
		return new Mp3(*this);
	}
private:	
	Mp3(const Mp3& another)
	{
		_mName = another._mName;
		_Price = another._Price;
	}
};



class Computer:public AbsGoods{
public:
	Computer(const Computer& another)
	{
		_mName = another._mName;
		_Price = another._Price;
	}
	Computer(){_mName = "COMPUTER"; _Price = 4000;}
	virtual AbsGoods* Clone()
	{
		return new Computer(*this);
	}
};



class Person{
public:
	Person(){_CountGoods = 0;}
	virtual bool addGoods(AbsGoods* aGoods)
	{
		if(NULL == aGoods) return false;
		if(_CountGoods >= 10)
			return false;
		_myGoods[_CountGoods] = aGoods;
		_CountGoods++;
		return true;
	}
	virtual void out()
	{
		for(int i=0; i<_CountGoods; i++)
		{
			cout<<_myGoods[i]->_mName<<" PRO ";
		}
	
	}
	virtual int getGoodsNum()const {
		return _CountGoods;
	}
	AbsGoods* getGoods(int Num)
	{
		return _myGoods[Num-1];
	}
private:
	AbsGoods* _myGoods[10];
	int _CountGoods;
};




class Mical : public Person{
public:
	static Mical* getMical()
	{
		if(NULL == _thisMical)
		{
			_thisMical = new Mical;
		}
		return _thisMical;
	}
private:
	Mical(){}
	Mical(const Mical& another){}
	void operator = (const Mical& another);
	static Mical* _thisMical;
};





class Merry : public Person{
public:
	static Merry* getMerry()
	{
		if(NULL == _thisMerry)
		{
			_thisMerry = new Merry;
		}
		return _thisMerry;
	}
private:
	Merry(){}
	Merry(const Merry& another){}
	void operator = (const Merry& another);
	static Merry* _thisMerry;
};



#endif /*PROTOTYPE_H_INCLUDED*/

/********************************** END **********************************************/

