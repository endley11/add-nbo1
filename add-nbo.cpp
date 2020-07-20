#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){

	FILE *in1;
	FILE *in2;
	

	uint32_t network_buffer[32];
	uint32_t* p =reinterpret_cast<uint32_t*>(network_buffer);
   
	uint32_t n1 =*p;
	uint32_t n2 =*p;
	
	in1 = fopen(argv[1],"rb");
	in2 = fopen(argv[2],"rb");
	fread(&n2, sizeof(n2),1,in2);
   fread(&n1, sizeof(n1),1,in1);
	printf("%d\n %d ", n1, n2);
   int n_1 = ntohl(n1);
	int n_2 = ntohl(n2);
	int sum = n_1+n_2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n_1,n_1,n_2,n_2,sum,sum);
	


	fclose(in1);
   fclose(in2);
}
