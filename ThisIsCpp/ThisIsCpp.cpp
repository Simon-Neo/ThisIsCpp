// ThisIsCpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"

void TestFunc(const CMyString& rParam)
{
	cout << rParam.GetString() << endl;
}


int main()
{
	CMyString pCMyString;

	pCMyString.SetString("Knock.. Knock..");
	
	TestFunc(pCMyString);

    return 0;
}

