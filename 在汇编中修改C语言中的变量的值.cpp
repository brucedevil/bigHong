#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main() {
	int var = 0;
	printf("%d\n",var);
	__asm {
		mov ax, ss;
		mov ds, ax;
		mov edx, 30;
		mov dword ptr ds : [var] , edx;//key
	}
	printf("%d\n",var);
}
