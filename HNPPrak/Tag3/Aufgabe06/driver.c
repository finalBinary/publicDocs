#include <stdio.h>
#include "cdecl.h"

int PRE_CDECL asm_haupt( void ) POST_CDECL;

int main()
{
	int ret_status;
	ret_status = asm_haupt();
	return ret_status;
}
