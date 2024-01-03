//************函数指针************
#include<stdio.h>
int sum(int a, int b) {
	return a + b;
}
int main()
{
	int (*sum_p)(int, int);//函数由三部分组成: 返回值, 函数名, 参数; 函数指针对函数的函数名和参数做了修改
	sum_p = sum;
	printf("%d\n",sum_p(100,100));
}

//************指针函数************
//指针函数: 函数的返回值类型为指针的函数就是指针函数
#include<stdio.h>
int* sum(int a, int b) {
	int c=a + b;
	return &c;//把函数堆栈中的数据的地址返回
}
int main()
{
	printf("%x\n",sum(100,100));
}
