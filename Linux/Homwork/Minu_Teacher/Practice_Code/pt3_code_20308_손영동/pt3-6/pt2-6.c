#include <stdio.h>
#include <unistd.h>

int main(int argc, char * pathname[]) 
{
	if(unlink(pathname[1]) == -1) 
	{
		if(remove(pathname[1]) == -1)
			printf("디렉터리 삭제 실패 \n");

			else
			printf("remove를 통해 %s 디렉터리를 삭제 성공.\n", pathname[1]);
	}	
	
	else 
	{
		printf("unlink를 통해 %s 디렉터리를 삭제 성공.\n", pathname[1]);
	}

	return 0;
}
