/*
 **************************************************************************************
 *       Filename:  AbstractFactory.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-13 11:29:42
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
class AbstractProductA
{
public:
    virtual ~AbstractProductA();
};

class AbstractProductB
{
public:
    virtual ~AbstractProductB();
};

class ProductA1: public AbstractProductA
{
};
class ProductA2: public AbstractProductA
{
};  

class ProductB1: public AbstractProductB
{
};
class ProductB2: public AbstractProductB
{
};

class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual AbstractProductA *CreateProductA() = 0;
    virtual AbstractProductB *CreateProductB() = 0;
};

class ConcreteFactory1: public AbstractFactory
{
public:
    AbstractProductA *CreateProductA() { return new ProductA1; }
    AbstractProductB *CreateProductB() { return new ProductB1; }
};
class ConcreteFactory2: public AbstractFactory
{
public:
    AbstractProductA *CreateProductA() { return new ProductA2; }
    AbstractProductB *CreateProductB() { return new ProductB2; }
};

//usage
int main(int argc, char *argv[])
{
    AbstractFactory *cf1 = new ConcreteFactory1();
    cf1->CreateProductA();
    cf1->CreateProductB();

    AstractFactory *cf2 = new ConcreteFactory2();
    cf2->CreateProductA();
    cf2->CreateProductB();
}



/********************************** END **********************************************/

