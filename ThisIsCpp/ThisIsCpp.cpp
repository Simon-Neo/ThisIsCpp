// ThisIsCpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <crtdbg.h>

#include "MyString.h"


void TestFunc(const CMyString& rMyString)
{
	cout << rMyString << endl;
}

int main()
{
	CMyString cA("Kock Knock");


	TestFunc(cA);
	TestFunc(CMyString("I will put you right Through"));

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}