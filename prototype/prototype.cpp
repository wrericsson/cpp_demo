/*
 **************************************************************************************
 *       Filename:  prototype.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-15 20:09:47
 *
 *       Revision:  initial draft;
 *******************:*******************************************************************
 */
#include <iostream>
#include "prototype.h"

using namespace std;


Mical* Mical::_thisMical = NULL;
Merry* Merry::_thisMerry = NULL;
int main(int argc,char* argvi[])
{
	Mical* mical = Mical::getMical();
	Merry* merry = Merry::getMerry();

	mical->addGoods(new Computer);
	mical->addGoods(new Mp3);

	for(int i=0; i<mical->getGoodsNum(); i++)
	{
		merry->addGoods(mical->getGoods(i+1)->Clone());
	}
	cout<<"Mical's Goods : ";
	mical->out();
	cout<<endl;
	cout<<"Merry's Goods : ";
	merry->out();
	cout<<endl;
	//free(Mp3);
	//delete(Computer);
	return 0;
}




/********************************** END **********************************************/

