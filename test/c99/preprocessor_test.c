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

#define stringify(a) # a

#define stringify_indirect(a) stringify(a)

#define eval(...)  eval1(eval1(eval1(__VA_ARGS__)))
#define eval1(...) eval2(eval2(eval2(__VA_ARGS__)))
#define eval2(...) __VA_ARGS__

#define empty()
#define defer(id) id empty()

#define loop() ?    defer(loop_indirect) () ()
#define loop_indirect() loop

/*  Test to make sure that a token that represents a function macro name will only get disabled if you attempt to call the function */
#define recur4(C, T, E) C-T-E
#define recur3(X) [ X ]
#define recur2(C, X) recur4(C(X), recur4(C(X), ,),) |C|
#define recur1(F, X) F(recur3, X)

/*  Make sure you can get the last argument of an empty list sent to vaargs: */
#define empty_va_list(a,...) a
#define empty_va_list_eval(a) empty_va_list a

/*  Make sure joining with empty token lists works: */
#define empty_join_test(a,b) a##b

#include <stdio.h>
#include <stdio.h>

void ignore_spaces_print(const char *);
void ignore_spaces_print(const char * str){
	/*  There are just too many preprocessing whitespaces differences (bugs?) between different compilers. */
	/*  Currently not considering spaces in diffs. */
	const char * c = str;
	while(*c){
		if(*c != ' '){
			printf("%c", *c);
		}
		c++;
	}
}

int main(void){
	ignore_spaces_print(stringify_indirect(__LINE__));
	ignore_spaces_print("\n");
	ignore_spaces_print(stringify_indirect( eval(loop()) ));
	ignore_spaces_print("\n");
	ignore_spaces_print(stringify_indirect( eval(loop_indirect()) ));
	ignore_spaces_print("\n");
	ignore_spaces_print(stringify_indirect( defer(loop_indirect()) ));
	ignore_spaces_print("\n");
	ignore_spaces_print(stringify_indirect( defer(loop_indirect) ));
	ignore_spaces_print("\n");
	ignore_spaces_print(stringify_indirect( defer(loop) ));
	ignore_spaces_print("Crazy token disabling test case:\n");
	ignore_spaces_print(stringify_indirect(recur1(recur2, recur1(recur2, 1))));
	ignore_spaces_print("\n");
	ignore_spaces_print(stringify_indirect( defer(eval(loop_indirect()))() ));
	ignore_spaces_print("Va list case:\n");
	/* Currently causes warnings in clang
	ignore_spaces_print(stringify_indirect(empty_va_list_eval(())));
	*/
	ignore_spaces_print("Concat empty left:\n");
	ignore_spaces_print(stringify_indirect(empty_join_test(, fdasfdasfdsa)));
	ignore_spaces_print("Concat empty right:\n");
	ignore_spaces_print(stringify_indirect(empty_join_test(fjdksajflsdk,)));
	ignore_spaces_print("Concat both empty:\n");
	ignore_spaces_print(stringify_indirect(empty_join_test(,)));
	return 0;
}