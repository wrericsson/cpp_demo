/*
 **************************************************************************************
 *       Filename:  singleton.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-10 22:09:05
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
#define TF_DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete;         \
  void operator=(const TypeName&) = delete

template <typename T>
class Singleton
{
private:
    class Proxy
    {
    public:
        Proxy() : instance_(0)
        {
        }
        ~Proxy()
        {
            if(instance_)
            {
                delete instance_;
                instance_ = 0;
            }
        }
        T* createInstance()
        {
            T *p = instance_;
            if(p == 0)
            {
              	std::lock_guard<std::mutex> guard(lock_);
                if((p = instance_) ==0)
                {
                    instance_ = p = new T;
                }
            }
            return instance_;
        }
        void deleteInstance()
        {
            if(proxy_.instance_)
            {
                delete proxy_.instance_;
                proxy_.instance_ = 0;
            }
        }
        T *instance_;
        std::mutex lock_;
    };
    TF_DISALLOW_COPY_AND_ASSIGN(Singleton);
    static Proxy proxy_;
    static int  abc_;
protected:
    Singleton(){}
    ~Singleton(){}
public:
    static T* getInstancePtr()
    {
        if(0 == proxy_.instance_)
        {
            createInstance();
        }
        return proxy_.instance_;
    }

    static T& getInstanceRef()
    {
        if(0 == proxy_.instance_)
        {
            createInstance();
        }
        return *(proxy_.instance_);
    }

    static T* createInstance()
    {
        return proxy_.createInstance();
    }

    static void deleteInstance()
    {
        proxy_.deleteInstance();
    }
};
template <class T> 
class Singleton<T>::Proxy Singleton<T>::proxy_;
template <class T> 
int  Singleton<T>::abc_ = 100;

//class SomeMustBeOneObject : private Singleton<SomeMustBeOneObject>
//{};


int main(int argc,char* arcv[])
{

char* o1 = Singleton<char>::getInstancePtr();
char* o2 = Singleton<char>::getInstancePtr();
//SomeMustBeOneObject& o3 = Singleton<SomeMustBeOneObject>::getInstanceRef();
        if ( o1== o2)
		cout <<"1 = 2\n"<< endl;

	return 0;
}


//// usage
//assert(o1 == o2);
//assert(o1 == &o3);
//SomeMustBeOneObject* o4 = new SomeMustBeOneObject; // Compile Error!
//SomeMustBeOneObject o5;

 

/********************************** END **********************************************/

