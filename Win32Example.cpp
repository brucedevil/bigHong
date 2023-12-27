#include"Win32_XIMU.h"
//处理函数
HINSTANCE hAppInstance;
void CreateButton(HWND hwnd) {
	HWND hwndPushButton;
	HWND hwndCheckBox;
	HWND hwndRadio;
	hwndPushButton = CreateWindow(
		TEXT("button"),
		TEXT("普通按钮"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,
		10, 10,
		80, 20,
		hwnd,//父窗口句柄
		(HMENU)1001,//菜单句柄(转成了菜单类型)
		hAppInstance,//当前应用程序的句柄(所有的窗口都属于一个应用)
		NULL
	);
	hwndCheckBox = CreateWindow(
		TEXT("button"),
		TEXT("复选框"),
		WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX,
		10, 40,
		80, 20,
		hwnd,
		(HMENU)1002,
		hAppInstance,
		NULL
	);
	hwndRadio = CreateWindow(
		TEXT("button"),
		TEXT("单选按钮"),
		WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
		10, 70,
		80, 20,
		hwnd,
		(HMENU)1003,
		hAppInstance,
		NULL
	);
}
LRESULT CALLBACK WindowProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
)
{
	switch (uMsg) {
	case WM_CREATE:
	{
		CREATESTRUCT* createst = (CREATESTRUCT*)lParam;
		return 0;
	}
	case WM_MOVE:
	{
		POINTS points = MAKEPOINTS(lParam);
		return 0;
	}
	/*case WM_SIZE:
	{
		int newWidth = (int)(short)LOWORD(lParam);
		int newHeight = (int)(short)HIWORD(lParam);
	}*/
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_KEYUP:
	{
		return 0;
	}
	case WM_KEYDOWN:
	{
		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		//POINTS points = MAKEPOINTS(Param);
		return 0;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 1001://1001,1002,1003是窗口的编号 
			MessageBox(hwnd, "Hello Button1", "Demo", MB_OK);
			return 0;
		case 1002:
			MessageBox(hwnd, "Hello Button2", "Demo", MB_OK);
			return 0;
		case 1003:
			MessageBox(hwnd, "Hello Button3", "Demo", MB_OK);
			return 0;
		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);//让windows来处理剩余的消息
};
int WINAPI WinMain(
	HINSTANCE hInstance,      // handle to current instance
	HINSTANCE hPrevInstance,  // handle to previous instance
	LPSTR lpCmdLine,          // command line
	int nCmdShow              // show state
) 
{
	hAppInstance = hInstance;
	//创建一个窗口类
	WNDCLASS wndclass = { 0 };
	CHAR className[] = "FirstMFC";
	wndclass.hbrBackground = (HBRUSH)COLOR_MENU;
	wndclass.lpfnWndProc = WindowProc;//并没有调用消息处理函数, 是windows调用的, 我们只需要写好放在那由windows调用
	wndclass.lpszClassName = className;
	wndclass.hInstance = hInstance; 
	//注册窗口
	RegisterClass(&wndclass);
	//创建一个窗口
	HWND hwnd = CreateWindow(
		className,					//类名
		TEXT("FirstWindwo"),		//窗口标题
		WS_OVERLAPPEDWINDOW,		//窗口外观样式
		10,							//相对于父窗口的x坐标
		10,							//相对于父窗口的y坐标
		600,						//窗口的宽度
		300,						//窗口的高度
		NULL,						//父窗口句柄, 为NULL
		NULL,						//菜单句柄,为NULL
		hInstance,					//当前应用程序的句柄
		NULL						//附加数据一般为NULL
	);
	CreateButton(hwnd);
	//显示窗口
	ShowWindow(hwnd, SW_SHOW);
	//消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);//分发消息给操作系统
	}

}
