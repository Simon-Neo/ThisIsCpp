#pragma once
class CMyData
{
public:
	CMyData();
	~CMyData();

public:
	void SetData(const int iData) { m_iData = iData; }
	int GetData() { return m_iData; }

protected:
	void PrintData() const ;
private:
	int m_iData = 0;
};

