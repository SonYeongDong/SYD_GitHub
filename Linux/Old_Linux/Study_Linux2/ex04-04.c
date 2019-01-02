#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *filename = "y_test.txt";
	
	if( access(filename, R_OK)==-1){
	perror("cannot read\n"); 
	fprintf(stderr, "User cannot read file %s \n", filename);
	exit(1);
	}
	printf("%s readable, proceeding \n", filename);
}

