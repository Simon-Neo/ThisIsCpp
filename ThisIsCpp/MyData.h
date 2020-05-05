#pragma once

class CMyData
{
public:
	CMyData(int iData, const char* pszName);
	~CMyData();
	
	CMyData(const CMyData& rhs);

	CMyData(CMyData&& rrhs);

	CMyData& operator= (const CMyData& rhs);
	
	const int GetData() const { return m_iNum; }
public:
	//void SetData(const int iData) { m_iData = iData; }
	//int GetData() const { return m_iData; }

	void Release();
	void Render();
private:
	int m_iNum = 0;
	const char* m_pszName = nullptr;
};

