#pragma once

class CMyData
{
public:
	CMyData(int iNum);
	~CMyData();
	
	CMyData(const CMyData& rhs);

	CMyData(CMyData&& rrhs);

	operator int() { return m_iNum; }


public:
	const int GetData() const { return m_iNum; }
public:
	//void SetData(const int iData) { m_iData = iData; }
	//int GetData() const { return m_iData; }

	void RenderData() { cout << m_iNum << endl; }
private:
	int m_iNum = 0;
};

