#include "http_client.h"
#include <iostream>
#include <string>

__declspec(dllexport) int add(int a, int b){
	std::cout << "add" << std::endl;
	return a + b;
}

__declspec(dllexport) int subtract(int a, int b){
	std::cout << "sub" << std::endl;
	return a - b;
}

__declspec(dllexport) int getIp(void (* print)(std::string)){

	(*print)("加入组件没崩溃");

	return 1;
}

typedef void(*pfCallBack)(char b[]);
pfCallBack CallBackfun = NULL;
char ch[200];

__declspec(dllexport) void aaa(std::string  cc)
{
	memset(ch, '\0', 200);
	strcpy(ch, cc.c_str());
	//strcpy(ch, "in the aaa fun");
	CallBackfun(ch);

	std::cout << "aaa " << cc.c_str() << std::endl;
}
__declspec(dllexport) void __stdcall call(void(*CallBack)(char b[]))
{
	CallBackfun = CallBack;
	aaa(">>>>>>>>>>>>>>>>>>>>>>");
	std::string url2 = "http://.../appauth/login/thirdAuthCode";
	//std::string usl3 = "client_id=...&client_secret=e31ac1bb84934aaa9e46d5daf08301d9&username=15093301927";
	// 屏蔽参数
	HttpClient::PostReq(url2, aaa, usl3);

	aaa("<<<<<<<<<<<<<<<<<<<<<<");
	
}