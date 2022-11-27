#include "stdio.h"

float data[1][1024];

int main(int argc, char const* argv[])
{
	FILE *fp;
	errno_t err = fopen_s(&fp, "100.txt", "r");
	if (fp) {
		for(int i = 1; i<1024; i++)
		{ 
			fscanf_s(fp, "%f", &data[0][i]);
			printf("%f\n", &data[0][i]);
			fclose(fp);
		}

	}
	else {
		printf("无法直接打开文件\n");
	}
	return 0;
}