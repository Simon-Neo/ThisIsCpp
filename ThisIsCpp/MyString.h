#pragma once
class CMyString
{
public:
	CMyString() = default;
	explicit CMyString(const char* pszData);
	CMyString(const CMyString& rhs);
	CMyString(CMyString&& rrhs);
	~CMyString();

	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);

	const CMyString& operator=(const CMyString& rhs);
	CMyString& operator=(CMyString&& rrhs);

	operator const char* (void) const;
	const char& operator[](int iIndex) const;
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);
public:
	int SetString(const char* pszParam);
	int SetString(int) = delete;
	int SetString(float) = delete;
	const char* GetString() const { return m_pszData; }
	int GetLength() const { return m_iLength; }
public:
	int Append(const char* pszParam);
private:
	void SzHeapAllocation(const char * pszData, int iSourLength = 0);

	void Release();
private:
	// str pointer Heap memory allocation
	char* m_pszData = nullptr;
	// str Length
	int m_iLength = 0;
};

