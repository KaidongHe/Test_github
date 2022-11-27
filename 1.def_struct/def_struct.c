#include "stdio.h"

// typedef a b 含义就是用b代替a的所有内容

// 定义一个结构体类型
struct point {
	int x;
	int y;
};

struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point* p);

int main(int argc, char const* argv[]) 
{
	//声明结构体变量
	struct point y = { 0,0 };
	//传入结构体变量的地址
	getStruct(&y);
	//传入结构体
	output(y);
	//传入结构体的地址后，return了结构体的地址，并通过地址访问结构体
	output(*getStruct(&y));
	//传入结构体变量的地址，传出地址
	print(getStruct(&y));

	return 0;
}

/// <summary>
/// 表示getStruct返回一个struct变量
/// </summary>
struct point* getStruct(struct point* p)
{
	scanf_s("%d", &p->x);
	scanf_s("%d", &p->y);
	printf("%d, %d\n", p->x, p->y);
	return p;

}

void output(struct point p)
{
	printf("%d ,%d\n", p.x, p.y);
		
}

void print(const struct point* p)
{
	printf("%d, %d\n", p->x, p->y);

}