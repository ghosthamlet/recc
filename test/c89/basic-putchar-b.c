/*
	Copyright 2015 Robert Elder Software Inc.  All rights reserved.

	This software is not currently available under any license, and unauthorized use
	or copying is not permitted.

	This software will likely be available under a common open source license in the
	near future.  Licensing is currently pending feedback from a lawyer.  If you have
	an opinion on this subject you can send it to recc [at] robertelder.org.

	This program comes with ABSOLUTELY NO WARRANTY.  In no event shall Robert Elder
	Software Inc. be liable for incidental or consequential damages in connection with
	use of this software.
*/

#include <stdio.h>

void fun(void);

void fun(void){
	return;
}

static int arr[3][3] = {
	{98,99,100},
	{101,102,103},
	{104,105,106}
};

int main(void){
	putchar('b');
	putchar(arr[0][0]);
	putchar(arr[0][1]);
	putchar(arr[0][2]);
	putchar(arr[1][0]);
	putchar(arr[1][1]);
	putchar(arr[1][2]);
	putchar(arr[2][0]);
	putchar(arr[2][1]);
	putchar(arr[2][2]);
	fun();
	return 0;
}