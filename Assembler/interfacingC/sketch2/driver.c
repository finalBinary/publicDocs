#include <stdio.h>
/* prototype for assembly routine */
void print_int_array( int , int *) __attribute__((cdecl ));

int main( void )
{
	int n = 5;
	int array[5] = {7, 1, 2, 3, 4};

	printf ("Array is :\n");
	
	print_int_array(n, array);

	printf ("\n");
	return 0;

}
