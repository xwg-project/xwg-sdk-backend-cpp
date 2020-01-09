#pragma once
#include "IHttpInterface.h"
#include "ServiceHttpHead.h"

//ÿ�ζ�ȡ���ֽ���
#define READ_BUFFER_SIZE		4096
#define DOWNLOAD_BUFFER_SIZE	4096

#ifndef HINTERNET
#define HINTERNET LPVOID
#endif

class SERVICE_HTTP_CLASS CHttpConnect: public IHttpInterface
{
public:
	CHttpConnect(void);
	virtual ~CHttpConnect(void);
	string	Request(const string& strUrl, REQUEST_TYPE type, const string& strPostData="", string strHeader="");
	string	Request(const wstring& strUrl, REQUEST_TYPE type, const wstring& strPostData=L"", wstring strHeader=L"");
	bool	Download(const wstring& strUrl, const wstring& strSavePath);
	bool	Download(const string& strUrl, const string& strSavePath);
	void	SetWnd(HWND hWnd) { m_hWnd=hWnd; }
	void	SetMsg(const UINT msg) { m_uMsg=msg; }
	const	wstring&	GetErrorMsg()const { return m_strErrorMsg; }
	const	wchar_t*	GetErrorBuffer()const { return m_strErrorMsg.c_str(); }
	void	FreeInstance();
	//////////////////////////////////////////////////////////////////
	//  ���� app id �� secret ��ȡ��token
	string	RequestToken(const string& client_id, const string& client_secret);
	//	��ȡָ����Ʒ��Ϣ
	string	RequestCollectible(const string& collectible_id);
	//	��ȡָ����Ʒ������Ϣ
	string	RequestCollectibleTool(const string& collectible_id);
	// ��ȡ��Ʒ���߷����б�
	string	RequestCategoryList(const string& collectible_id);

	// ��ȡָ����Ʒ�µĵ����б�
	string	RequestCategoryListByID(const string& collectible_id);

	// ��ȡ�����б�
	string	RequestOrderList(const string& client_id, const string& client_secret);

	// ��ȡ֤ͨ����
	string	RequestOrderRate();

	// ��ȡ֤ͨ�б� 
	string	RequestTZList();

	// �̻�ʵʱת�� 
	string	TransferTransOrder();

	// �̻�ʵʱ�˿� 
	string	RefundTradeOrder();
	////////////////////////////////////////////////////////////////////
protected:
	//���ó�����Ϣ
	void	SetErrorMsg(const wchar_t* pMsg);
	//��URL�н��������������ļ���
	void	ParseURL(const string& strUrl);
	void	ParseURL(const wstring& strUrl);
	//���HTTPЭ��ͷ
	void	GetHttpHeader(string& strHeader);
	void	GetHttpHeader(wstring& strHeader);
	//ת��
	wstring StringToWstring(const string& str);
	string	WstringToString(const wstring& str);
	wstring Utf8ToUnicode(const string& strUtf8);
	//�رվ��
	void	ReleaseHandle(HINTERNET& hInternet);
	void	Release();
	CString UTF82WCS(const char* szU8);
private:
	HWND	m_hWnd;
	UINT	m_uMsg;
	HINTERNET	m_hSession;
	HINTERNET	m_hConnect;
	HINTERNET	m_hRequest;
	//������
	string		m_strHostName;
	wstring		m_wstrHostName;
	//ҳ����
	string		m_strPageName;
	wstring		m_wstrPageName;
	//������Ϣ
	wstring		m_strErrorMsg;
};
