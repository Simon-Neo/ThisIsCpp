// This_Is_Cpp_test_project.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

