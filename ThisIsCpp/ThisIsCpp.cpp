// ThisIsCpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <crtdbg.h>

#include "MyString.h"
#include "MyData.h"


CMyData TestFunc(int iParam)
{
	CMyData cA(iParam, "A");
	return cA; 
}

int main()
{
	CMyData cB(77, "B");

	cout << "Begin" << endl;


	CMyData& rData = TestFunc(11);

	cB = rData;

	cout << "End" << endl;

	cout << cB.GetData() << endl;
	

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}