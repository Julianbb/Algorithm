/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-21 10:12
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


class Person
{
private:
   Person (){}

   ~Person(){}

public:
   static Person* GetInstance()
   {
      return new Person();
   }


   static void Delete(Person* p)
   {
       delete p;
   }

};


// class Son :public Person
// {
//     Son()
//     {

//     }
// };


template<typename T>
class A
{
    friend T;
private:
    A()
    {
	cout << "this is A constructor" << endl;
    }
    ~A(){}
};

class B : virtual public A<B>
{
public:
    B()
    {
	cout << "this is B constructor" << endl;
    }
    ~B(){}

};

class C : public B
{
    public:
    C()
    {
	cout << "this is c constructor " << endl;
    }
};


int main(void)
{
    B b;
    C c;

    return 0;
}
