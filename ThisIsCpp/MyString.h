#pragma once
class CMyString
{
public:
	CMyString() = default;
	explicit CMyString(const char* pszData);
	~CMyString();

	CMyString(const CMyString& rhs);
	const CMyString& operator=(const CMyString& rhs);

	operator const char* (void) const { return m_pszData; }
public:
	int SetString(const char* pszParam);
	int SetString(int) = delete;
	int SetString(float) = delete;
	const char* GetString() const { return m_pszData; }

private:
	void SzHeapAllocation(const char * pszData, int iSourLength = 0);
	void Release();
private:
	// str pointer Heap memory allocation
	char* m_pszData = nullptr;
	// str Length
	int m_iLength = 0;
};

