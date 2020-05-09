#pragma once

class CMyData
{
public:
	explicit CMyData(int iNum);
	~CMyData();

	int& operator[](int iIndex);
	const int& operator[](int iIndex)const;
public:

	void Render();

private:
	void Release();
private:
	int* m_piData = nullptr;
	int m_iSize = 0;
};

