//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<math.h>
//int main(int argc, char* argv[])   //命令行传参，argc代表传入参数个数，argv表示传入的参数
//{
//	int i, j;
//	int k = 0;
//	int count = 0;  //统计文件中字符个数
//	int sum_row;  //统计文件中字符个数
//	int flag = 0;
//	FILE* fp;  //文件指针
//	FILE* fp1;
//	int a_in[200];  //保存文件内容的数组
//	int b_in[200];  //保存文件内容的数组
//	//fp = fopen_s(argv[1], "r");   //打开文件，只读2
//	errno_t err = fopen_s(&fp, argv[1], "r");
//	//fp1=fopen("int_data.txt","r"); 
//	errno_t err1 = fopen_s(&fp1, argv[1], "r");
//	if (fp == NULL)
//	{
//		printf("File cannot open! ");
//		//exit;  
//		return 0;
//	}
//	if (argc != 2)   //判断输入参数个数，如果不为2个就报错
//	{
//		printf("参数个数错误");
//		return -1;
//	}
//
//	while (!feof(fp))   //读文件，直到文件末尾
//	{
//		flag = fgetc(fp);  //将文件内容附给flag
//		if (flag == '\n')  //如果为\n表示到行尾，便进行计数
//			count++;
//	}
//	sum_row = count + 1; //加上文件最后一行，即为文件总的行数
//	printf("文件行数为：%d", sum_row);  //打印文件行数，因为每行只有一个数，所以即统计文件中有多少个数
//	printf("\n");
//	for (i = 0; i < 200; i++)  //控制文件行数
//	{
//		for (j = 0; j < 1; j++)  //控制文件列数
//		{
//			fscanf_s(fp1, "%d", &a_in[j]);  //将文件其中一行内容保存到数组中
//			b_in[k] = a_in[j];  //将读到的每一行的数据都保存到b_in数组中
//			k++;  //行数加一
//		}
//	}
//	printf("文件内容为：\n");
//	for (i = 0; i < k; i++)  //循环打印保存到数组中的数据
//	{
//		printf("%d\t", b_in[i]);  //打印
//	}
//	fclose(fp);  //关闭文件，释放指向文件的指针
//	fclose(fp1);  //关闭文件，释放指向文件的指针
//	return 0;
//}
