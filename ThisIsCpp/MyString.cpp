#include "stdafx.h"
#include "MyString.h"


#define NOT_USE_FUNCTION_MYSTRING
CMyString::CMyString(const char* pszData)
{
	SzHeapAllocation(pszData);
}


CMyString::~CMyString()
{
	Release();
}

CMyString::CMyString(const CMyString & rhs)
{
	Release();

	SzHeapAllocation(rhs.m_pszData, rhs.m_iLength);
}

const CMyString & CMyString::operator=(const CMyString & rhs)
{
	if (&rhs != this)
	{
		Release();
		SzHeapAllocation(rhs.m_pszData, rhs.m_iLength);
	}
	return *this;
}


int CMyString::SetString(const char * pszParam)
{
	Release();

	// If Someone Enter Param nullptr is mean Init value;
	if (nullptr == pszParam)
		return 0;
#ifdef NOT_USE_FUNCTION_MYSTRING
	int iSize = 0;
	int iIndex = 0;
	while (pszParam[iSize] != '\0')
		++iSize;

	if (iSize <= 0)
		return 0;

	m_pszData = new char[iSize + 1];

	for (int i = 0; i < iSize + 1; ++i)
		m_pszData[i] = pszParam[i];

	m_iLength = iSize;
	
#else
	SzHeapAllocation(pszParam);
#endif // NOT_USE_FUNCTION_MYSTRING

	return m_iLength;
}

void CMyString::SzHeapAllocation(const char * pszData, int iSourLength )
{
	if (0 >= iSourLength)
		m_iLength = strlen(pszData);
	else
		m_iLength = iSourLength;

	if (0 >= m_iLength)
	{
		cout << "CMyString::SzHeapAllocation() _. Lenght 0" << endl;
		return;
	}
	
	m_pszData = new char[m_iLength + 1];
	if (nullptr == m_pszData)
	{
		cout << "CMyString::SzHeapAllocation() _. HeapAllocation Fail." << endl;
		return;
	}
	strcpy_s(m_pszData, sizeof(pszData[0]) * (m_iLength + 1), pszData);
}

void CMyString::Release()
{
	if (nullptr != m_pszData)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_iLength = 0;
}