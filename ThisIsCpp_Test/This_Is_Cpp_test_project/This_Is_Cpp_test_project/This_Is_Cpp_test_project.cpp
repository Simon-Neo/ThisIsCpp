// This_Is_Cpp_test_project.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include "MyDataEx.h"

int main()
{
	CMyDataEx cData;

	cData.SetData(77);
	cout << cData.GetData() << endl;
	
	cData.TestFunc();
    return 0;
}

