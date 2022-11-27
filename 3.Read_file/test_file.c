#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char* argv[])   //命令行传参，argc代表传入参数个数，argv表示传入的参数
{
	int i, j;
	int k = 0;
	int count = 0;  //统计文件中字符个数
	int sum_row;  //统计文件中字符个数
	int flag = 0;  //用于暂时将文件内容保存
	FILE* fp;    //文件指针
	FILE* fp1;
	FILE* fp2;
	int* a_in;   //用于读文件中的数据
	int* b_in;   //用于保存从文件中读入的数据
	//fp = fopen_s(argv[1], "r");   //打开文件，只读2
	errno_t err = fopen_s(&fp, argv[1], "r");
	errno_t err1 = fopen_s(&fp1, argv[1], "r");
	errno_t err2 = fopen_s(&fp2, "test_write.txt", "w");
	//fp = fopen(argv[1], "r");   //打开文件，只读，argv[1]代表从命令行输入的文件名称，即运行.exe程序时输入的第二个参数
	//fp1 = fopen(argv[1], "r");   //再次打开文件，（第一次打开文件用于统计文件的行数，即数据的个数）用于将文件内容保存到指针数组里
	//fp2 = fopen("test1.txt", "w");   //打开文件，只写，用于将数组内容重新保存到另一个文件中
	if (fp == NULL)    //打开文件失败
	{
		printf("File cannot open! ");
		//exit;  
		return 0;
	}
	if (argc != 2)   //判断输入参数个数，如果不为2个就报错
	{
		printf("参数个数错误");
		return -1;
	}

	while (!feof(fp))  //读文件，直到文件末尾
	{
		flag = fgetc(fp);  //将文件内容附给flag
		if (flag == '\n')  //如果为\n表示到行尾，便进行计数
		{
			count++;  //统计文件行数
		}
	}
	sum_row = count + 1; //加上文件最后一行，即为文件总的行数
	printf("文件行数为：%d", sum_row);  //统计文件行数，因为每行只有一个数，所以即统计文件中有多少个数
	printf("\n");
	a_in = (int*)malloc(sizeof(int) * sum_row);  //动态分配用于保存文件内容的指针数组长度，以免溢出
	b_in = (int*)malloc(sizeof(int) * sum_row);  //动态分配用于保存文件内容的指针数组长度，以免溢出
	if (!a_in)   //动态内存分配失败
	{
		printf("内存分配失败");
		return-1;
	}
	if (!b_in)  //动态内存分配失败
	{
		printf("内存分配失败");
		return-1;
	}

	for (i = 0; i < sum_row; i++)  //控制文件行数
	{
		for (j = 0; j < 1; j++)   //控制文件列数
		{
			fscanf_s(fp1, "%d", &a_in[j]);  //将文件其中一行内容保存到指针数组中
			b_in[k] = a_in[j];    //将读到的每一行的数据都保存到b_in指针数组中
			k++;  //行数加一
		}
	}
	printf("文件内容为：\n");
	for (i = 0; i < k; i++)  //循环打印保存到指针数组中的数据
	{
		printf("%d\t", b_in[i]);  //打印
		fprintf(fp2, "%d\n", b_in[i]);  //将保存到数组的数据保存到test1.txt文件中
	}
	fclose(fp);  //关闭文件，释放指向文件的指针
	fclose(fp1);  //关闭文件，释放指向文件的指针
	fclose(fp2);
	return 0;
	free(a_in);  //释放指针
	free(b_in);  //释放指针
	return 0;
}
