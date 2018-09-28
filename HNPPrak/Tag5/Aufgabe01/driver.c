#include <stdio.h>

int secret_func( int ) __attribute__((cdecl));

int main( void )
{
	int n = 5;
	int result = secret_func(n);
	
	printf ("%d\n", result);
	return 0;
}
