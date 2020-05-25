#include "stdafx.h"
#include "MyDataEx.h"


CMyDataEx::CMyDataEx()
{
	cout << "CMyDataEx::CMyDataEx()" << endl;
}


CMyDataEx::~CMyDataEx()
{
}

void CMyDataEx::TestFunc()
{
	PrintData();
	SetData(5);
	cout << CMyData::GetData() << endl;
}
