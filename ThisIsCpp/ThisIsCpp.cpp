// ThisIsCpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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