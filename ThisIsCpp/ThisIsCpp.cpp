// ThisIsCpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

