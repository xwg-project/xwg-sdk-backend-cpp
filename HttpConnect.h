#pragma once
#include "IHttpInterface.h"
#include "ServiceHttpHead.h"

//每次读取的字节数
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
	//  根据 app id 和 secret 获取到token
	string	RequestToken(const string& client_id, const string& client_secret);
	//	获取指定藏品信息
	string	RequestCollectible(const string& collectible_id);
	//	获取指定藏品道具信息
	string	RequestCollectibleTool(const string& collectible_id);
	// 获取藏品道具分类列表
	string	RequestCategoryList(const string& collectible_id);

	// 获取指定藏品下的道具列表
	string	RequestCategoryListByID(const string& collectible_id);

	// 获取订单列表
	string	RequestOrderList(const string& client_id, const string& client_secret);

	// 获取通证汇率
	string	RequestOrderRate();

	// 获取通证列表 
	string	RequestTZList();

	// 商户实时转账 
	string	TransferTransOrder();

	// 商户实时退款 
	string	RefundTradeOrder();
	////////////////////////////////////////////////////////////////////
protected:
	//设置出错信息
	void	SetErrorMsg(const wchar_t* pMsg);
	//从URL中解析出主域名和文件名
	void	ParseURL(const string& strUrl);
	void	ParseURL(const wstring& strUrl);
	//填充HTTP协议头
	void	GetHttpHeader(string& strHeader);
	void	GetHttpHeader(wstring& strHeader);
	//转码
	wstring StringToWstring(const string& str);
	string	WstringToString(const wstring& str);
	wstring Utf8ToUnicode(const string& strUtf8);
	//关闭句柄
	void	ReleaseHandle(HINTERNET& hInternet);
	void	Release();
	CString UTF82WCS(const char* szU8);
private:
	HWND	m_hWnd;
	UINT	m_uMsg;
	HINTERNET	m_hSession;
	HINTERNET	m_hConnect;
	HINTERNET	m_hRequest;
	//主域名
	string		m_strHostName;
	wstring		m_wstrHostName;
	//页面名
	string		m_strPageName;
	wstring		m_wstrPageName;
	//错误信息
	wstring		m_strErrorMsg;
};
