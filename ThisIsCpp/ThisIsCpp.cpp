// ThisIsCpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <crtdbg.h>

#include "MyString.h"

int main()
{
	CMyString cA("Kock Knock");

	cout << cA.GetString() << endl;


	CMyString cB(cA);
	cout << cB.GetString() << endl;

	CMyString cC;

	cC = cB;
	cout << cC.GetString() << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}