#include <stdio.h>

int main(int argc, char * argv[])
{
	if(argc < 3)
	{
		printf("입력된 인자값이 없습니다\n");
		printf("입력 파일명, 출력 파일명에 2개의 인자를 입력해야 합니다\n");
		return 1;
	}		
	
	FILE *input_file = fopen(argv[1], "rt");
	
	if (input_file == NULL)
	{
		printf("입력 파일명에 대한 인자값을 찾지못했습니다\n");
		printf("프로그램을 종료합니다\n");
		return 2; 
	}

	FILE *output_file = fopen(argv[2], "wt");
	
	char conversion;

	while(!feof(input_file))
	{
		conversion = fgetc(input_file);
		if(conversion == 0x0A)
		{
			fputc(0x0D, output_file);
			fputc(0x0A, output_file);
			continue;
		}
		fputc(conversion, output_file);
	}

	printf("리눅스 텍스트파일->윈도우 텍스트파일[변환완료]\n");

	fclose(input_file);
	fclose(output_file);

	return 0;
}
