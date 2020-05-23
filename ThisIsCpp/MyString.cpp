#include "stdafx.h"
#include "MyString.h"

#define NOT_USE_FUNCTION_MYSTRING

CMyString::CMyString(const char* pszData)
{
	cout << "CMyString::CMyString(const char* pszData)" << endl;
	SzHeapAllocation(pszData);
}

CMyString::~CMyString()
{
	Release();
}

CMyString::CMyString(const CMyString & rhs)
{
	cout << "CMyString::CMyString(const CMyString & rhs)" << endl;
	Release();

	SzHeapAllocation(rhs.m_pszData, rhs.m_iLength);
}

CMyString::CMyString(CMyString && rrhs)
	:m_pszData(rrhs.m_pszData), m_iLength(rrhs.m_iLength)
{
	cout << "CMyString::CMyString(const CMyString && rrhs -> MoveGenerator!)" << endl;
	rrhs.m_pszData = nullptr;
	rrhs.m_iLength = 0;
}

const CMyString & CMyString::operator=(const CMyString & rhs)
{
	cout << "const CMyString & CMyString::operator=(const CMyString & rhs)" << endl;
	if (&rhs != this)
	{
		Release();
		SzHeapAllocation(rhs.m_pszData, rhs.m_iLength);
	}
	return *this;
}

CMyString & CMyString::operator=(CMyString && rrhs)
{
	cout << "CMyString & CMyString::operator=(CMyString && rrhs)" << endl;
	m_pszData = rrhs.m_pszData;
	m_iLength = rrhs.m_iLength;

	rrhs.m_pszData = nullptr;
	rrhs.m_iLength = 0;

	return *this;
}

CMyString CMyString::operator+(const CMyString & rhs)
{
	CMyString strResult(m_pszData);
	strResult.Append(rhs.GetString());

	return strResult;
}

CMyString & CMyString::operator+=(const CMyString & rhs)
{
	if (nullptr != rhs)
		Append(rhs.GetString());
	return *this;
}

CMyString::operator const char*(void) const
{
	cout << "	operator const char* (void) cons" << endl;
	return m_pszData;
}

const char & CMyString::operator[](int iIndex) const
{
	if (0 > iIndex || m_iLength <= iIndex)
	{
		cout << "Out Of Rnage Index _. CMyString::operator[](int iIndex)" << endl;
		return m_pszData[0];
	}

	return m_pszData[iIndex]; 
}

int CMyString::operator==(const CMyString & rhs)
{
	if (nullptr != m_pszData && nullptr != rhs.m_pszData)
		if (0 == strcmp(m_pszData, rhs.m_pszData))
			return 1;
	return 0;
}

int CMyString::operator!=(const CMyString & rhs)
{
	return !(operator==(rhs));
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

	for (int i = 0; i <= iSize + 1; ++i)
		m_pszData[i] = pszParam[i];

	m_iLength = iSize;

#else
	SzHeapAllocation(pszParam);
#endif // NOT_USE_FUNCTION_MYSTRING

	return m_iLength;
}

int CMyString::Append(const char * pszParam)
{
	if (nullptr == pszParam)
	{
		cout << " CMyString::Append _. 	if (nullptr == pszParam)" << endl;
		return 0;
	}

	int iParamLength = strlen(pszParam);
	if (iParamLength <= 0)
	{
		cout << " CMyString::Append _. 	strlen(pszParam) <= 0" << endl;
		return 0;
	}

	if (nullptr == m_pszData || 0 >= m_iLength)
	{
		Release();
		SzHeapAllocation(pszParam, strlen(pszParam));
		return m_iLength;
	}

	int iNewLength = m_iLength + iParamLength;
	char* pszNewData = new char[iNewLength + 1];

	if(nullptr == pszNewData)
	{
		cout << "CMyString::Append _.  Memory Allocation Fail _. nullptr == pszNewData" << endl;
		return 0;
	}
	memset(pszNewData, 0, sizeof(char) * (iNewLength + 1));

	int i = 0;
	while (m_pszData[i] != '\0')
		pszNewData[i++] = m_pszData[i];
	int j = 0;
	while (pszParam[j] != '\0')
		pszNewData[i++] = pszParam[j++];
	pszNewData[i] = '\0';

	Release();
	m_pszData = pszNewData;
	m_iLength = iNewLength;

	return m_iLength;
}

void CMyString::SzHeapAllocation(const char * pszData, int iSourLength)
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