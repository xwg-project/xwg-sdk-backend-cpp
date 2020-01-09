#include "StdAfx.h"
#include "HttpConnect.h"
#include <Wininet.h>
#include <sstream>
#pragma comment(lib, "Wininet")


CHttpConnect::CHttpConnect(void)
:m_strHostName("")
,m_wstrHostName(L"")
,m_strPageName("")
,m_wstrPageName(L"")
,m_hSession(NULL)
,m_hConnect(NULL)
,m_hRequest(NULL)
,m_hWnd(NULL)
,m_uMsg(0)
{
}

CHttpConnect::~CHttpConnect(void)
{
	Release();
}
////////////////////////////////////////////////////////////////////////////////////////
//	获取指定藏品信息
string	CHttpConnect::RequestToken(const string& client_id, const string& client_secret)
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	str = "http://192.168.1.121:8888/appauth/login/thirdAuthCode?client_id=" + client_id + "&client_secret=" + client_secret + "&username=15093301927";
	
	//return Request(str, post, strPostData, strHeader);

	return "{\"code\": 0,\"message\": \"success\",\"data\": \"McCnKnAb\"}";

}

string	CHttpConnect::RequestCollectible(const string& collectible_id)
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;
	str = "http://192.168.1.121:8888/wallet/collectible/info/query?collectible_id=" + collectible_id + "&performer_app_id=&performer_user_id=&version=1.0&method=collectible.info.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);

}

//	获取指定藏品道具信息
string	CHttpConnect::RequestCollectibleTool(const string& collectible_id)
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;
	str = "http://192.168.1.121:8888/wallet/collectible/item/list/query?collectible_ids=" + collectible_id +"&page_num=1&page_size=1&performer_app_id=&performer_user_id=&version=1.0&method=collectible.item.list.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);
}

//	获取指定藏品道具信息
string	CHttpConnect::RequestCategoryList(const string& collectible_id)
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;
	str = "http://192.168.1.121:8888/wallet/collectible/item/category/list/query?collectible_ids=" + collectible_id + "&page_num=1&page_size=1&performer_app_id=&performer_user_id=&version=1.0&method=collectible.item.category.list.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);
}


// 获取指定藏品下的道具列表
string	CHttpConnect::RequestCategoryListByID(const string& collectible_id)
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;
	str = "http://192.168.1.121:8888/wallet/collectible/item/list/query?collectible_ids=" + collectible_id  + "&page_num=1&page_size=1&performer_app_id=&performer_user_id=&version=1.0&method=collectible.item.list.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);
}

string	CHttpConnect::RequestOrderList(const string& client_id, const string& client_secret)
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;

	str = "http://192.168.1.121:8888/wallet/merchant/order/list/query?performer_app_id=" + client_id + "&performer_app_secret= " + client_secret + "&page_num=1&page_size=1&performer_app_id=&performer_user_id=&version=1.0&method=merchant.order.list.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);
}

// 获取通证汇率
string	CHttpConnect::RequestOrderRate()
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;

	str = "http://192.168.1.121:8888/wallet/token/exchange_rate/query?pairs=&performer_app_id=&version=1.0&method=token.exchange_rate.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);
}

// 获取通证列表
string	CHttpConnect::RequestTZList()
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;

	str = "http://192.168.1.121:8888/wallet/token/list/query?version=1.0&performer_app_id=&performer_user_id=&method=token.list.query&timestamp=" + timestr;

	return Request(str, post, strPostData, strHeader);
}

// 商户实时转账
string	CHttpConnect::TransferTransOrder()
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;

	str = "http://192.168.1.121:8888/wallet/merchant/order/trans/transfer?method=merchant.order.trans.transfer&notify_url=http://www.baidu.com&out_order_no=OS12221746038394&payee_id=1170939526797991938&performer_app_id=1561527878813&performer_app_secret=e31ac1bb84934aaa9e46d5daf08301d9&performer_user_id=1170939526797991938&symbol=XWG&timestamp=1577432627555&total_amount=1000000000&version=1.0&operator_id=&remark=测试";

	return Request(str, post, strPostData, strHeader);
}

// 商户实时退款
string	CHttpConnect::RefundTradeOrder()
{
	std::string strHeader;
	std::string strPostData;
	std::string str = "";

	string timestr;
	time_t time1 = time(0);
	std::stringstream ss;
	ss << time1;
	ss >> timestr;

	str = "http://192.168.1.121:8888/wallet/merchant/order/trans/transfer?method=merchant.order.trans.transfer&notify_url=http://www.baidu.com&out_order_no=OS12221746038394&payee_id=1170939526797991938&performer_app_id=1561527878813&performer_app_secret=e31ac1bb84934aaa9e46d5daf08301d9&performer_user_id=1170939526797991938&symbol=XWG&timestamp=1577432627555&total_amount=1000000000&version=1.0&operator_id=&remark=测试";

	return Request(str, post, strPostData, strHeader);
}

////////////////////////////////////////////////////////////////////////////////////////
string CHttpConnect::Request( const string& strUrl, REQUEST_TYPE type, const string& strPostData/*=""*/, string strHeader/*=""*/)
{
	if ( strUrl.empty() )
		return "";
	Release();
	m_hSession=InternetOpen(L"Http-connect", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
	if ( NULL == m_hSession )
	{
		SetErrorMsg(L"初始化HTTP接口失败");
		return "";
	}
	ParseURL(strUrl);
	INTERNET_PORT port=INTERNET_DEFAULT_HTTP_PORT;
	int nPos=m_strHostName.find(":");
	if ( string::npos != nPos )
	{
		string strPort=m_strHostName.substr(nPos+1);
		m_strHostName=m_strHostName.substr(0, nPos);
		port=atoi(strPort.c_str());
	}
	m_hConnect=InternetConnectA(m_hSession, m_strHostName.c_str(), port, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL);
	if ( NULL == m_hConnect )
	{
		SetErrorMsg(L"连接HTTP服务器失败");
		return "";
	}
	char* pRequestType=NULL;
	if ( get == type )
		pRequestType="GET";
	else
		pRequestType="POST";
	m_hRequest=HttpOpenRequestA(m_hConnect, pRequestType, m_strPageName.c_str(), "HTTP/1.1", NULL, NULL, INTERNET_FLAG_RELOAD, NULL);
	if ( NULL == m_hRequest )
	{
		SetErrorMsg(L"初始化HTTP请求失败");
		return "";
	}
	if ( strHeader.empty() )
		GetHttpHeader(strHeader);
	BOOL bRet=FALSE;
	if ( get == type )
		bRet=HttpSendRequestA(m_hRequest, strHeader.c_str(), strHeader.size(), NULL, 0);
	else
		bRet=HttpSendRequestA(m_hRequest, strHeader.c_str(), strHeader.size(), (LPVOID)strPostData.c_str(), strPostData.size());
	if ( !bRet )
	{
		SetErrorMsg(L"发送HTTP请求失败");
		return "";
	}
	char szBuffer[READ_BUFFER_SIZE+1]={0};
	DWORD dwReadSize=READ_BUFFER_SIZE;
	bRet=HttpQueryInfoA(m_hRequest, HTTP_QUERY_RAW_HEADERS, szBuffer, &dwReadSize, NULL);
	if ( !bRet )
	{
		SetErrorMsg(L"查询HTTP返回头失败");
		return "";
	}
	string strRetHeader=szBuffer;
	if ( string::npos != strRetHeader.find("404") )//页面不存在
	{
		SetErrorMsg(L"请求页面不存在");
		return "";
	}
	string strRet;
	while( true )
	{
		bRet=InternetReadFile(m_hRequest, szBuffer, READ_BUFFER_SIZE, &dwReadSize);
		if ( !bRet || (0 == dwReadSize) )
			break;
		szBuffer[dwReadSize]='\0';
		strRet.append(szBuffer);
	}

	//strRet = "aaaa";
//	CString aa;
//	aa.Format(TEXT("%s"), UTF82WCS(strRet.c_str()));
//	AfxMessageBox(aa);
	//string ss = (CStringA)aa;

	return strRet;
}

string CHttpConnect::Request( const wstring& strUrl, REQUEST_TYPE type, const wstring& strPostData/*=L""*/, wstring strHeader/*=L""*/ )
{
	if ( strUrl.empty() )
		return "";
	Release();
	m_hSession=InternetOpen(L"Http-connect", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
	if ( NULL == m_hSession )
	{
		SetErrorMsg(L"初始化HTTP接口失败");
		return "";
	}
	ParseURL(strUrl);
	INTERNET_PORT port=INTERNET_DEFAULT_HTTP_PORT;
	int nPos=m_wstrHostName.find(L":");
	if ( wstring::npos != nPos )
	{
		wstring strPort=m_wstrHostName.substr(nPos+1);
		m_wstrHostName=m_wstrHostName.substr(0, nPos);
		port=_wtoi(strPort.c_str());
	}
	m_hConnect=InternetConnectW(m_hSession, m_wstrHostName.c_str(), port, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL);
	if ( NULL == m_hConnect )
	{
		SetErrorMsg(L"连接HTTP服务器失败");
		return "";
	}
	wchar_t* pRequestType=NULL;
	if ( get == type )
		pRequestType=L"GET";
	else
		pRequestType=L"POST";
	m_hRequest=HttpOpenRequestW(m_hConnect, pRequestType, m_wstrPageName.c_str(), L"HTTP/1.1", NULL, NULL, INTERNET_FLAG_RELOAD, NULL);
	if ( NULL == m_hRequest )
	{
		SetErrorMsg(L"初始化HTTP请求失败");
		return "";
	}
	if ( strHeader.empty() )
		GetHttpHeader(strHeader);
	BOOL bRet=FALSE;
	if ( get == type )
		bRet=HttpSendRequestW(m_hRequest, strHeader.c_str(), strHeader.size(), NULL, 0);
	else
	{
		string str=WstringToString(strPostData);
		bRet=HttpSendRequestW(m_hRequest, strHeader.c_str(), strHeader.size(), (LPVOID)str.c_str(), str.size());
	}
	if ( !bRet )
	{
		SetErrorMsg(L"发送HTTP请求失败");
		return "";
	}
	DWORD dwReadSize=READ_BUFFER_SIZE;
	{
		wchar_t szBuffer[READ_BUFFER_SIZE+1]={0};
		memset(szBuffer, 0, READ_BUFFER_SIZE);
		bRet=HttpQueryInfoW(m_hRequest, HTTP_QUERY_RAW_HEADERS, szBuffer, &dwReadSize, NULL);
		if ( !bRet )
		{
			SetErrorMsg(L"查询HTTP返回头失败");
			return "";
		}
		wstring strRetHeader=szBuffer;
		if ( wstring::npos != strRetHeader.find(L"404") )//页面不存在
		{
			SetErrorMsg(L"请求页面不存在");
			return "";
		}
	}
	string strRet;
	char szBuffer[READ_BUFFER_SIZE+1]={0};
	while( true )
	{
		bRet=InternetReadFile(m_hRequest, szBuffer, READ_BUFFER_SIZE, &dwReadSize);
		if ( !bRet || (0 == dwReadSize) )
			break;
		szBuffer[dwReadSize]='\0';
		strRet.append(szBuffer);
	}
	return strRet;
}

void CHttpConnect::ParseURL( const string& strUrl)
{
	string strTemp=strUrl;
	int nPos=strTemp.find("http://");
	if (string::npos != nPos )
		strTemp=strTemp.substr(nPos+7, strTemp.size()-nPos-7);
	nPos=strTemp.find('/');
	if ( string::npos == nPos )//没有找到 /
	{
		m_strHostName=strTemp;
		return ;
	}
	m_strHostName=strTemp.substr(0, nPos);
	m_strPageName=strTemp.substr(nPos, strTemp.size()-nPos);
}

void CHttpConnect::ParseURL( const wstring& strUrl )
{
	wstring strTemp=strUrl;
	int nPos=strTemp.find(L"http://");
	if (wstring::npos != nPos )
		strTemp=strTemp.substr(nPos+7, strTemp.size()-nPos-7);
	nPos=strTemp.find('/');
	if ( wstring::npos == nPos )//没有找到 /
	{
		m_wstrHostName=strTemp;
		return ;
	}
	m_wstrHostName=strTemp.substr(0, nPos);
	m_wstrPageName=strTemp.substr(nPos, strTemp.size()-nPos);
}

void CHttpConnect::GetHttpHeader( string& strHeader )
{
	strHeader="";
	strHeader.append("nReferer: ");
	strHeader+=m_strHostName;
	strHeader.append("\r\nContent-Type: application/x-www-form-urlencoded\r\n");
	strHeader.append("Accept: */*\r\n");
	strHeader.append("Connection: Keep-Alive\r\n\r\n");
}

void CHttpConnect::GetHttpHeader( wstring& strHeader )
{
	strHeader=L"";
	strHeader.append(L"nReferer: ");
	strHeader+=m_wstrHostName;
	strHeader.append(L"\r\nContent-Type: application/x-www-form-urlencoded\r\n");
	strHeader.append(L"Accept: */*\r\n");
	strHeader.append(L"Connection: Keep-Alive\r\n\r\n");
}

void CHttpConnect::SetErrorMsg( const wchar_t* pMsg )
{
#ifdef _DEBUG
	m_strErrorMsg=pMsg;
	wchar_t szBuffer[20]={0};
	wsprintf(szBuffer, L",系统错误码：%u", GetLastError());
	m_strErrorMsg.append(szBuffer);
#else
	m_strErrorMsg=L"发送请求失败，请检查网络";
#endif
}

wstring CHttpConnect::StringToWstring( const string& str )
{
	int nLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	wchar_t* wp=new wchar_t[nLen+1];
	memset(wp,0,nLen+1);
	nLen=MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), wp, nLen);
	wp[nLen]='\0';
	wstring wstr=wp;
	delete[] wp;
	return wstr;
}

wstring CHttpConnect::Utf8ToUnicode(const string& strUtf8)  
{  
	wstring wstrRet(L"");
	int nLen=MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, NULL, 0);  
	if (nLen == ERROR_NO_UNICODE_TRANSLATION)  
		throw "Utf8ToUnicode出错：无效的UTF-8字符串。";  
	wstrRet.resize(nLen+1,'\0');
	MultiByteToWideChar(CP_UTF8,0,strUtf8.c_str(), -1,(LPWSTR)wstrRet.c_str(), nLen);
	return wstrRet;  
}

string CHttpConnect::WstringToString( const wstring& str )
{
	int nLen= WideCharToMultiByte(CP_ACP, 0, str.c_str(), str.size(), NULL, 0, NULL, NULL);
	char* pBuffer=new char[nLen+1];
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), str.size(), pBuffer, nLen,NULL,NULL);
	pBuffer[nLen]='\0';
	string strRet(pBuffer);
	delete[] pBuffer;
	return strRet;
}

bool CHttpConnect::Download( const wstring& strUrl, const wstring& strSavePath )
{
	bool bResult=false;
	try
	{
		if ( strUrl.empty() )
			throw L"下载地址为空";
		Release();
		m_hSession=InternetOpen(L"Http-connect", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
		if ( NULL == m_hSession ) throw L"初始化HTTP接口失败";
		ParseURL(strUrl);
		m_hConnect=InternetConnectW(m_hSession, m_wstrHostName.c_str(), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL);
		if ( NULL == m_hConnect ) throw L"连接HTTP服务器失败";
		m_hRequest=HttpOpenRequestW(m_hConnect, L"GET", m_wstrPageName.c_str(), L"HTTP/1.1", NULL, NULL, INTERNET_FLAG_RELOAD, NULL);
		if ( NULL == m_hRequest ) throw L"初始化HTTP请求失败";
		wstring strHeader;
		if ( strHeader.empty() )
			GetHttpHeader(strHeader);
		BOOL bRet=HttpSendRequestW(m_hRequest, strHeader.c_str(), strHeader.size(), NULL, 0);
		if ( !bRet ) throw L"发送HTTP请求失败";
		char szBuffer[DOWNLOAD_BUFFER_SIZE+1]={0};
		DWORD dwReadSize=DOWNLOAD_BUFFER_SIZE;
		bRet=HttpQueryInfoA(m_hRequest, HTTP_QUERY_RAW_HEADERS, szBuffer, &dwReadSize, NULL);
		if ( !bRet ) throw L"查询HTTP返回头失败";
		string strRetHeader=szBuffer;
		if ( string::npos != strRetHeader.find("404") ) throw L"请求文件不存在!";
		dwReadSize=DOWNLOAD_BUFFER_SIZE;
		bRet=HttpQueryInfoA(m_hRequest, HTTP_QUERY_CONTENT_LENGTH, szBuffer, &dwReadSize, NULL);
		if ( !bRet ) throw L"查询HTTP返回头失败";
		szBuffer[dwReadSize]='\0';
		const UINT uFileSize=atoi(szBuffer);
		int nFindPos=0;
		while( wstring::npos != (nFindPos=strSavePath.find(L"\\", nFindPos)) )
		{
			wstring strChildPath=strSavePath.substr(0, nFindPos);
			if (INVALID_FILE_ATTRIBUTES == ::GetFileAttributes(strChildPath.c_str())) 
				CreateDirectory(strChildPath.c_str(), NULL);
			nFindPos++;
		}
		FILE* fp=NULL;
	//	_wfopen(&fp, strSavePath.c_str());
		if ( NULL == fp ) throw L"创建文件失败，可能是文件正在被占用";
		UINT uWriteSize=0;
		while( true )
		{
			bRet=InternetReadFile(m_hRequest, szBuffer, DOWNLOAD_BUFFER_SIZE, &dwReadSize);
			if ( !bRet || (0 == dwReadSize) )
				break;
			szBuffer[dwReadSize]='\0';
			fwrite(szBuffer, dwReadSize, 1, fp);
			uWriteSize+=dwReadSize;
			if ( m_hWnd ) ::PostMessage(m_hWnd, m_uMsg, uWriteSize, 0);

		}
		fclose(fp);
		if ( uFileSize!=uWriteSize ) throw L"下载文件失败，请检查网络设置";
		bResult=true;
	}
	catch( const wchar_t* pError )
	{
		SetErrorMsg(pError);
	}
	return bResult;
}

bool CHttpConnect::Download( const string& strUrl, const string& strSavePath )
{
	wstring strNewUrl = StringToWstring(strUrl);
	wstring strNewSavePath = StringToWstring(strSavePath);
	return Download(strNewUrl, strNewSavePath);
}

void CHttpConnect::FreeInstance()
{
	delete this;
}

void CHttpConnect::ReleaseHandle( HINTERNET& hInternet )
{
	if (hInternet) 
	{ 
		InternetCloseHandle(hInternet); 
		hInternet=NULL; 
	}
}

void CHttpConnect::Release()
{
	ReleaseHandle(m_hRequest); 
	ReleaseHandle(m_hConnect); 
	ReleaseHandle(m_hSession);
}
//UTF - 8 转 Unicode
CString CHttpConnect::UTF82WCS(const char* szU8)
{
	//预转换，得到所需空间的大小;
	int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
	//分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
	wchar_t* wszString = new wchar_t[wcsLen + 1];
	//转换
	::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
	//最后加上'\0'
	wszString[wcsLen] = '\0';
	CString unicodeString(wszString);
	delete[] wszString;
	wszString = NULL;
	return unicodeString;
}