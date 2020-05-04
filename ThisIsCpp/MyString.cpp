#include "stdafx.h"
#include "MyString.h"


#define NOT_USE_FUNCTION_MYSTRING
CMyString::CMyString()
{
}


CMyString::~CMyString()
{
	Release();
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
	m_iLength = strlen(pszParam);

	if (m_iLength <= 0)
		return m_iLength;

	m_pszData = new char[m_iLength + 1];

	strcpy_s(m_pszData, sizeof(pszParam[0]) * (m_iLength + 1), pszParam);
#endif // NOT_USE_FUNCTION_MYSTRING

	return m_iLength;
}

void CMyString::Release()
{
	if (nullptr != m_pszData)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_iLength = 0;
}