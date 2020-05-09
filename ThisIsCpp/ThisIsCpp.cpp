// ThisIsCpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <crtdbg.h>

#include "MyString.h"


void TestFunc(const CMyString & strParam)
{
	cout << strParam[0] << endl;
	cout << strParam[strParam.GetLength() - 1] << endl;
}

int main()
{
	CMyString strLeft("Test"), strRight("String");

	if (strLeft == strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	strLeft = CMyString("String");


	if (strLeft != strRight)
		cout << "Different" << endl;
	else
		cout << "Same" << endl;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}