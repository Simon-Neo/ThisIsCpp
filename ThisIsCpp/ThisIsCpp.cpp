// ThisIsCpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <crtdbg.h>

#include "MyString.h"
#include "MyData.h"


void TestFunc(const CMyData& rData)
{
	cout << rData[3] << endl;
}

int main()
{
	int iArraySize = 5;
	CMyData cData(iArraySize);

	for (int i = 0; i < iArraySize; ++i)
		cData[i] = i * 10;

	cData.Render();

	TestFunc(cData);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}