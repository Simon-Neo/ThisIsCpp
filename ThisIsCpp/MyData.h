#pragma once
class CMyData
{
public:
	CMyData(int iData);
	~CMyData();
	
	CMyData(const CMyData& rhs);

public:
	void SetData(const int iData) { m_iData = iData; }
	int GetData() const { return m_iData; }
private:
	int m_iData = 0;
};

