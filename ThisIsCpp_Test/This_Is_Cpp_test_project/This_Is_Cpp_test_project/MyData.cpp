#include "stdafx.h"
#include "MyData.h"


CMyData::CMyData()
{
	cout << "CMyData::CMyData()" << endl;
}


CMyData::~CMyData()
{
}

void CMyData::PrintData() const
{
	cout << "------------------- Render -------------------------" << endl;
}
