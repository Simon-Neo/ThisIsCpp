#include "stdafx.h"
#include "MyData.h"


CMyData::CMyData(int iData, const char* pszName)
	:m_iNum(iData), m_pszName(pszName)
{
	cout << "int iData, const char* pszName - " << m_pszName << endl;
}

CMyData::CMyData(const CMyData & rhs)
	: m_iNum(rhs.m_iNum), m_pszName(rhs.m_pszName)
{
	cout << "CMyData::CMyData(const CMyData & rhs) -" << m_pszName << endl;
}

CMyData::CMyData(CMyData && rrhs)
	:m_iNum(rrhs.m_iNum), m_pszName(rrhs.m_pszName)
{
	cout << "CMyData::CMyData(CMyData && rrhs)-" << m_pszName << endl;
}

CMyData::~CMyData()
{
	
	cout << "CMyData::~CMyData()-" << m_pszName << endl;
	Release();
}

CMyData & CMyData::operator=(const CMyData & rhs)
{
	m_iNum = rhs.m_iNum;
	//m_pszName = rhs.m_pszName;

	cout << "CMyData & CMyData::operator=(const CMyData & rhs)" << m_pszName << endl;
	return *this;
}

void CMyData::Release()
{
	m_pszName = nullptr;
}

void CMyData::Render()
{
	cout << "Num = " << m_iNum << "Name = " << m_pszName << endl;
}

//CMyData::CMyData(const CMyData & rhs)
//{
//	cout << "CMydata(const CMydata& rhs)" << endl;
//}
