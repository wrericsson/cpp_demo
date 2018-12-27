/*
 **************************************************************************************
 *       Filename:  building.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2018-12-27 14:46:50
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "state.h"

#include <map>
#include <iostream>
using namespace std;

enum StateType
{
    BUILDING, INJURED, REPAIR, UPGRADE, PRODUCTION
};

class absBuilding
{
public:
    absBuilding(char* name):mName(name){}
    virtual void show() 
    {
        cout<<mName<<"表现:"<<endl;
        map<StateType, absState*>::iterator beg = mStates.begin();
        for ( ; beg != mStates.end(); beg++)
        {
            beg->second->show();
        }
        cout<<endl;
    };
    void eraseState(StateType type)
    {
        auto result = mStates.find(type);
        if(result != mStates.end())
            mStates.erase(result);
    }
protected:
    char* mName;
    map<StateType, absState*> mStates;
};

class concreteBuilding:public absBuilding
{
public:
    concreteBuilding(char* name):absBuilding(name)
    {
        mStates[BUILDING] = new buildingState();
    }
    void upGrade()
    {
        auto result = mStates.find(UPGRADE);
        if(result == mStates.end())
        {
            mStates[UPGRADE] = new upGradeState();
        }
        eraseState(BUILDING);
        eraseState(PRODUCTION);
    }
    void production()
    {
        auto result = mStates.find(PRODUCTION);
        if(result == mStates.end())
        {
            mStates[PRODUCTION] = new upGradeState();
        }
        eraseState(BUILDING);
        eraseState(UPGRADE);
    }
    void injured()
    {
        auto result = mStates.find(INJURED);
        if(result == mStates.end())
        {
            mStates[INJURED] = new fireState();
        }
    }
    void repair()
    {
        auto injuredVal = mStates.find(INJURED);
        if(injuredVal == mStates.end())
            return;
        auto result = mStates.find(REPAIR);
        if(result == mStates.end())
        {
            mStates[REPAIR] = new repairState();
        }
     }
};


#endif /*BUILDING_H_INCLUDED*/

/********************************** END **********************************************/

