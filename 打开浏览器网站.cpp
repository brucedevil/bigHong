#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    //启动浏览器并打开固定网站
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));//将结构体中的数据清零作为初始化
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);//将si结构体的第一个成员赋值, 用来记录当前的结构体有多大
    TCHAR lpApplicationName[] = TEXT("D:\\36\\360极速浏览器极简版优化免安装版13.52.2022.0\\Application\\360chrome.exe");
    TCHAR lpCommandLine[] = TEXT("\" https://www.baidu.com\"");
    TCHAR cmdline[] = TEXT(" http://community.csdn.net/");
    if (!CreateProcess(
        lpApplicationName, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi
    )) {
        MessageBox(NULL, (char*)GetLastError(), "Message", MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}

