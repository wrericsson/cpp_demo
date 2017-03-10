/*
 **************************************************************************************
 *       Filename:  pure-vir.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-09 17:11:10
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <iostream>

using namespace std;

class Shape{
public:
	Shape(){};
	virtual ~Shape(){};
	virtual long GetArea() const = 0;
	virtual long GetPerim()const = 0;
	virtual void Draw()=0;
private:

};
//void Shape::Draw()
//{
	//cout << "Draw deconstruct" << endl;
//}
class Circle:public Shape
{
public:
	Circle(int radius):itsRadius(radius){}
	virtual ~Circle(){};
	long GetArea()const{return (3*itsRadius*itsRadius);}
	long GetPerim()const{return 9*itsRadius;}
	void Draw();
private:
	int itsRadius;
	int itsCircumference;
};
void Circle::Draw(){
	cout << " Circle drawing" << endl;
//	Shape::Draw();
}
int main(int argc, const char *argv[])
{
	int choice;
	bool fQuit = false;
	Shape *sp;

	while(1){
		cout << "pls input your choice:::::"<< endl;
		cin >> choice;
		
		switch(choice){
			case 1:
				sp = new Circle(100);
				break;
			default:
				fQuit = true;
				break;}
		if(fQuit)
			break;
		sp->Draw();
		delete sp;
		cout << "234";
	}
	return 0;
}


/********************************** END **********************************************/

