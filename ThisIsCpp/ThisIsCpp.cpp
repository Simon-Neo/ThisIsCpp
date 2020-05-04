// ThisIsCpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

