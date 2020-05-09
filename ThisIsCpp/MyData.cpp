#include "stdafx.h"
#include "MyData.h"



CMyData::CMyData(int iNum)
	:m_iSize(iNum)
{
	m_piData = new int[iNum];
	memset(m_piData, 0, sizeof(m_piData[0] * iNum));
	cout << "CMyData(int iNum)" << (*m_piData) << endl;
}

CMyData::~CMyData()
{
	cout << "~CMyData()" << endl;
	Release();
}

int& CMyData::operator[](int iIndex)
{
	int* pBeckUp = nullptr;
	if (0 < iIndex)
	{
		cout << "Out Of Range" << endl;
		return m_piData[0];
	}
	else if (m_iSize <= iIndex)
	{

		pBeckUp = new int[iIndex];
		memset(pBeckUp, 0, sizeof(pBeckUp[0] * iIndex));
		memcpy(pBeckUp, m_piData, sizeof(m_piData[0]) * m_iSize);
		Release();

		m_piData = pBeckUp;
		pBeckUp = nullptr;

		m_iSize = iIndex;
	}

	cout << "operator[](int iIndex)" << endl;
	return m_piData[iIndex];

}

const int & CMyData::operator[](int iIndex) const
{

	if (0 < iIndex)
	{
		cout << "Out Of Range" << endl;
		return -1;
	}

	cout << "operator[](int iIndex) const" << endl;
	return m_piData[iIndex];
}

void CMyData::Render()
{
	if (m_piData == nullptr)
		return;
	
	for (int i = 0; i < m_iSize; ++i)
		cout << m_piData[i] << " ";
	cout << endl;
}

void CMyData::Release()
{
	if (nullptr != m_piData)
		delete[] m_piData;
	m_piData = nullptr;
	m_iSize = 0;
	
}
