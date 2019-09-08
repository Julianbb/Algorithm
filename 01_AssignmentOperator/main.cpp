/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-07 09:14
#   Describe      :
#
# ====================================================*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;


class CMyString
{
    public:

	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator=(const CMyString& other)
	{
	    if(&other == this)
		return *this;

	    delete m_pData;
	    m_pData = nullptr;

	    m_pData = new char[strlen(other.m_pData)+1];
	    strcpy(m_pData, other.m_pData);
	    
	    return *this;
	}
    private:

	char* m_pData;


};
