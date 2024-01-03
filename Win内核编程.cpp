mov eax,dword ptr fs:[OXFFF]//为什么FS的Limit是fff,代码写成左边的样式直接出错
//原因: dword ptr代表要取4B, fs:[0xFFF]代表先跳到边界, 因此可以理解成先跳到边界再取4B的数据, 所以照样超出范围, 所以会出错
