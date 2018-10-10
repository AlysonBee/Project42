#include <stdio.h>
#include <stdlib.h>
/*
	first
*/
#define MAINSTRING "#include <stdio.h>%c#include <stdlib.h>%c/*%c%cfirst%c*/%c#define MAINSTRING %c%s%c%cchar perc[] = %c%s%c;%cchar second[] = %c%s%c;%c#define MAINY %cMAIN(42)%c%c#define MAIN(x) int main(){FILE *fp = fopen(%cGrace_kid.c%c, %cwb+%c);fprintf(fp, "
char perc[] = "%c%s%s%c%s%c%s;%c";
char second[] = ", 10, 10, 10, 9, 10, 10, 34, MAINSTRING, 34, 10, 34, perc, 34, 10, 34, second, 34, 10, 34, 34, 10, 34, 34, 34, 34, 34, MAINSTRING, perc, 34, second, 10, MAINY, 10); fclose(fp); return (0);}";
#define MAINY "MAIN(42)"
#define MAIN(x) int main(){FILE *fp = fopen("Grace_kid.c", "wb+");fprintf(fp, "#include <stdio.h>%c#include <stdlib.h>%c/*%c%cfirst%c*/%c#define MAINSTRING %c%s%c%cchar perc[] = %c%s%c;%cchar second[] = %c%s%c;%c#define MAINY %cMAIN(42)%c%c#define MAIN(x) int main(){FILE *fp = fopen(%cGrace_kid.c%c, %cwb+%c);fprintf(fp, %c%s%s%c%s%c%s;%c", 10, 10, 10, 9, 10, 10, 34, MAINSTRING, 34, 10, 34, perc, 34, 10, 34, second, 34, 10, 34, 34, 10, 34, 34, 34, 34, 34, MAINSTRING, perc, 34, second, 10, MAINY, 10); fclose(fp); return (0);}
MAIN(42);
