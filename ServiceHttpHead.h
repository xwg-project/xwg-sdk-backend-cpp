#ifndef SERVICE_HTTP_HEAD_FILE
#define SERVICE_HTTP_HEAD_FILE

//////////////////////////////////////////////////////////////////////////////////
//�����ļ�

//MFC �ļ�
#include <Nb30.h>
#include <Afxmt.h>
#include <AtlBase.h>


//////////////////////////////////////////////////////////////////////////////////
//��������

//��������
#ifndef SERVICE_HTTP_CLASS
	#ifdef  SERVICE_HTTP_DLL
		#define SERVICE_HTTP_CLASS _declspec(dllexport)
	#else
		#define SERVICE_HTTP_CLASS _declspec(dllimport)
	#endif
#endif

//ģ�鶨��
#ifndef _DEBUG
	#define SERVICE_HTTP_DLL_NAME	TEXT("ServiceHttp.dll")			//�������
#else
	#define SERVICE_HTTP_DLL_NAME	TEXT("ServiceHttpD.dll")		//�������
#endif

//////////////////////////////////////////////////////////////////////////////////
//�����ļ�

#ifndef SERVICE_HTTP_DLL
	#include "HttpConnect.h"
	#include "HttpSocket.h"
#endif

//////////////////////////////////////////////////////////////////////////////////

#endif