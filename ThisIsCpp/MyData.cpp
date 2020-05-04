#include "stdafx.h"
#include "MyData.h"


CMyData::CMyData(int iData)
	:m_iData(iData)
{
}


CMyData::~CMyData()
{
}

CMyData::CMyData(const CMyData & rhs)
	:m_iData(rhs.m_iData)
{
	cout << "CMydata(const CMydata& rhs)" << endl;
}
