// ThisIsCpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"
#include "MyData.h"

void TestFunc(CMyData cData)
{
	cout << cData.GetData() << endl;
}

CMyData& Test()
{
	CMyData B(88);
	return B;
}

int main()
{
	CMyData cA(77);
	
	cout << Test().GetData() << endl;

    return 0;
}

