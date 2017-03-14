/*
 **************************************************************************************
 *       Filename:  builder.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-14 14:17:58
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <vector>
#include <map>
using namespace std;
class Food     //定义产品类，指示拉面的一些属性
{
private:
    vector<string> mFoodName;
    vector<int> mPrice;
public:
    void add(string foodName,int price)
    {
        mFoodName.push_back(foodName);
        mPrice.push_back(price);
    }

    void show()
    {
        cout<<"food list:"<<endl;
        cout<<"_______________________"<<endl;
        for(int i=0;i<mFoodName.size();++i)
        {
            cout<<mFoodName[i]<<"  "<<mPrice[i]<<endl;
        }
    }

};

class Builder  //定义抽象的制作类，含有三个制作的环节和一个返回制作出来的产品方法
{
public:
    virtual void BuildCoolDish() = 0;
    virtual void BuildDrink() = 0;
    virtual void BuildRice() = 0;
    virtual Food* GetFood() = 0;
};


class BuilderA:public Builder  //制作者A，我们假定他做出来的凉菜收20，饮料15，拉面25，总共60元，也就是说收银员接到60元的套餐就交给A来做
{
public:
    BuilderA()
    {
        food = new Food();
    }
    virtual void BuildCoolDish()
    {
        cout<<"凉菜已经制作好，已加入制作工序容器（其实也就是做好了一样放在了盘子里）"<<endl;
        food->add("CoolDish",20);
    }

    virtual void BuildDrink()
    {
        cout<<"饮料制作好了，已加入制作工序容器(放在了杯子里)"<<endl;
        food->add("drink",15);
    }

    virtual void BuildRice()
    {
        cout<<"拉面做好了，放弃制作工序容器（放在了盘子里）"<<endl;
        food->add("Rice",25);
    }

    virtual Food* GetFood()
    {
        return food;
    }
private:
    Food *food;
};

class BuilderB:public Builder  //制作者B，我们假定他做出来的凉菜收30，饮料20，拉面20，总共70元，也就是说收银员接到70元的套餐就交给B来做
{
public:
    BuilderB()
    {
        food = new Food();
    }
    virtual void BuildCoolDish()
    {
        cout<<"凉菜已经制作好，已加入制作工序容器（其实也就是做好了一样放在了盘子里）"<<endl;
        food->add("CoolDish",30);
    }

    virtual void BuildDrink()
    {
        cout<<"饮料制作好了，已加入制作工序容器(放在了杯子里)"<<endl;
        food->add("drink",20);
    }

    virtual void BuildRice()
    {
        cout<<"拉面做好了，放弃制作工序容器（放在了盘子里）"<<endl;
        food->add("Rice",20);
    }

    virtual Food* GetFood()
    {
        return food;
    }
private:
    Food *food;
};

//定义收银员
class FoodManager
{
private:
    Builder *builder;
public:
    FoodManager(){builder = NULL;};

    Food* FoodInfo(char ch)
    {
        if(ch == 'A')
            builder = new BuilderA();
        else if(ch == 'B')
            builder = new BuilderB();
        else
            //你还可以加其他套餐;
            ;
        builder->BuildCoolDish();
        builder->BuildDrink();
        builder->BuildRice();

        return builder->GetFood();
    }

};

int main()
{
    FoodManager *p = new FoodManager();
    char ch;
    //客户到来，输入需要哪种套餐
    for(int i=0;i<5;i++)
    {
        cin>>ch;
        p->FoodInfo(ch)->show();
        cout<<endl;
    }
    system("pause");
    return 0;
}





/********************************** END **********************************************/

