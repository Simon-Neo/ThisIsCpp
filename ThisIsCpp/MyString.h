#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
public:
	int SetString(const char* pszParam);
	int SetString(int) = delete;
	int SetString(float) = delete;
	const char* GetString() const { return m_pszData; }
	void Release();
private:
	// str pointer Heap memory allocation
	char* m_pszData = nullptr;
	// str Length
	int m_iLength = 0;
};

