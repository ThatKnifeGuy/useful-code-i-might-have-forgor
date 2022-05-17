#include <stdio.h>
#include <stdlib.h>

//%d déclare le format de la variable(%d=int,%ld=long,%f=float,%f=double)
int main(int argc, char const *argv[])
{
	int variable = 5;
	int variable2 = 2;
	int variable3 =variable+variable2;
	printf("variable3 vaut %d soit : %d + %d\n",variable3,variable,variable2);
	return 0;
}
