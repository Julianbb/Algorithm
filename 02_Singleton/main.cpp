/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-07 09:36
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


// lazy
class Singleton
{
private:
    Singletopn(){}
    static Singleton* myself;

public:
    static Singleton* creat(void)
    {
	if(myself != NULL)
	    return myself;
	else
	    return new Singleton();
    }
};

Singleton* Singleton::myself = NULL;



//hungry
class Singleton
{

private:
    Singleton(){}

    static Singleton* myself;

public:

static Singleton* creat(void)
{
    return myself;
}

}

Singleton* Singleton::myself = new Singleton;
