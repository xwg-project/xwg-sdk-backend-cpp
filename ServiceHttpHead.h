#ifndef SERVICE_HTTP_HEAD_FILE
#define SERVICE_HTTP_HEAD_FILE

//////////////////////////////////////////////////////////////////////////////////
//包含文件

//MFC 文件
#include <Nb30.h>
#include <Afxmt.h>
#include <AtlBase.h>


//////////////////////////////////////////////////////////////////////////////////
//公共定义

//导出定义
#ifndef SERVICE_HTTP_CLASS
	#ifdef  SERVICE_HTTP_DLL
		#define SERVICE_HTTP_CLASS _declspec(dllexport)
	#else
		#define SERVICE_HTTP_CLASS _declspec(dllimport)
	#endif
#endif

//模块定义
#ifndef _DEBUG
	#define SERVICE_HTTP_DLL_NAME	TEXT("ServiceHttp.dll")			//组件名字
#else
	#define SERVICE_HTTP_DLL_NAME	TEXT("ServiceHttpD.dll")		//组件名字
#endif

//////////////////////////////////////////////////////////////////////////////////
//导出文件

#ifndef SERVICE_HTTP_DLL
	#include "HttpConnect.h"
	#include "HttpSocket.h"
#endif

//////////////////////////////////////////////////////////////////////////////////

#endif