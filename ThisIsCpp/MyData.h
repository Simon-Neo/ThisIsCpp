#pragma once

class CMyData
{
public:
	CMyData(int iNum);
	~CMyData();
	
	CMyData(const CMyData& rhs);

	CMyData(CMyData&& rrhs);

	operator int() { return m_iNum; }

	// +
	CMyData operator+(const CMyData& rhs);
	// = 
	CMyData& operator=(const CMyData& rhs);
public:
	const int GetData() const { return m_iNum; }
	void SetData(int iNum) { m_iNum = iNum; }
public:
	//void SetData(const int iData) { m_iData = iData; }
	//int GetData() const { return m_iData; }

	void RenderData() { cout << m_iNum << endl; }
private:
	int m_iNum = 0;
};

