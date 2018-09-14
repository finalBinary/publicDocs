#include <stdio.h>
/* prototype for assembly routine */
void print_char_array( int , char *) __attribute__((cdecl ));

int main( void )
{
	int n = 5;
	//char array[5] = {'a', 'b', 'c', 'd', 'e'};
	char * array = "fooB!";

	printf ("Array is :\n");
	
	print_char_array(n, array);

	printf ("\n");
	return 0;

}
