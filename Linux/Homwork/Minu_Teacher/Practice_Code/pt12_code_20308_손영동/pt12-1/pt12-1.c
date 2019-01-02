#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(void)
{
	char *address = "192.168.1.1";
	in_addr_t ipaddr;
	int ip_value, i, mask = 255;
	
	printf("in_addr_t의 사이즈 : %d\n", sizeof(in_addr_t));
	ipaddr = inet_addr(address);
	
	printf("int형의 사이즈 : %d\n", sizeof(int));
	
	for(i = 0; i < sizeof(int); i++)
	{
		ip_value = (ipaddr >> (i * 8)) & mask;
		printf("ipaddr : %d / 10진수 : %d / 16진수 :  %x\n ", ipaddr, ip_value, ip_value);
	}
	return 0;
}	
