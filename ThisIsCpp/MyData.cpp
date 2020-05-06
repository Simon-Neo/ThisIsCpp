#include "stdafx.h"
#include "MyData.h"

CMyData::CMyData(int iNum)
	:m_iNum(iNum)
{
	cout << "CMyData::CMyData(int iNum)" << m_iNum << endl;
}

CMyData::~CMyData()
{
	cout << "CMyData::~CMyData()" << m_iNum <<  endl;
}

CMyData::CMyData(const CMyData & rhs)
	:m_iNum(rhs.m_iNum)
{
	cout << "CMyData::CMyData(const CMyData & rhs)" << endl;
}

CMyData::CMyData(CMyData && rrhs)
	:m_iNum(rrhs.m_iNum)
{
	cout << "CMyData::CMyData(CMyData && rrhs)" << m_iNum << endl;
}

