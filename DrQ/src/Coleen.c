#include <stdio.h>
void a_function(){return;}
/*
	A comment
*/
char maining[] = "#include <stdio.h>%cvoid a_function(){return;}%c/*%c%cA comment%c*/%cchar maining[] = %c%s%c;%cint main(){a_function();%c/*%c%cAnother comment%c*/%cprintf(%c%s%c, 10, 10, 10, 9, 10, 10, 34, maining, 34, 10, 10, 10, 9, 10, 10, 34, maining, 34, 10);return 0;}%c";
int main(){a_function();
/*
	Another comment
*/
printf("#include <stdio.h>%cvoid a_function(){return;}%c/*%c%cA comment%c*/%cchar maining[] = %c%s%c;%cint main(){a_function();%c/*%c%cAnother comment%c*/%cprintf(%c%s%c, 10, 10, 10, 9, 10, 10, 34, maining, 34, 10, 10, 10, 9, 10, 10, 34, maining, 34, 10);return 0;}%c", 10, 10, 10, 9, 10, 10, 34, maining, 34, 10, 10, 10, 9, 10, 10, 34, maining, 34, 10);return 0;}
