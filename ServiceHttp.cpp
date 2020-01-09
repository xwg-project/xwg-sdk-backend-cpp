#include "Stdafx.h"
#include "AfxDllx.h"
#include "ServiceHttpHead.h"

//////////////////////////////////////////////////////////////////////////////////

//��̬����
static AFX_EXTENSION_MODULE ServiceHttpDLL={NULL,NULL};

//////////////////////////////////////////////////////////////////////////////////

//��������
extern "C" int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason==DLL_PROCESS_ATTACH)
	{
		if (!AfxInitExtensionModule(ServiceHttpDLL, hInstance)) return 0;
		new CDynLinkLibrary(ServiceHttpDLL);
	}
	else if (dwReason==DLL_PROCESS_DETACH)
	{
		AfxTermExtensionModule(ServiceHttpDLL);
	}

	return 1;
}

//////////////////////////////////////////////////////////////////////////////////
