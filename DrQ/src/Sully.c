#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define SOY "#include <fcntl.h>%c#include <stdio.h>%c#include <stdlib.h>%c#define SOY %c%s%c%cint main(void)%c{int i=%d;%cif (i == 0) return (0);%cchar *sully; asprintf(&sully, %cSully_%cd.c%c, i-1);%cchar *compile; asprintf(&compile, %cgcc -Wall -Werror -Wextra -o Sully_%cd Sully_%cd.c%c, i-1, i-1);%cchar *run; asprintf(&run, %c./Sully_%cd%c, i-1);%ci--;%cint fd = open(sully, O_RDWR|O_CREAT|O_TRUNC,0777);%cdprintf(fd, %c%s%c, 10, 10, 10, 34, SOY, 34, 10, 10, i, 10, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, 37, 34, 10, 10, 10, 34, SOY, 34);system(compile);system(run);return (0);}"
int main(void)
{int i=5;
if (i == 0) return (0);
char *sully; asprintf(&sully, "Sully_%d.c", i-1);
char *compile; asprintf(&compile, "gcc -Wall -Werror -Wextra -o Sully_%d Sully_%d.c", i-1, i-1);
char *run; asprintf(&run, "./Sully_%d", i-1);
i--;
int fd = open(sully, O_RDWR|O_CREAT|O_TRUNC,0777);
dprintf(fd, "#include <fcntl.h>%c#include <stdio.h>%c#include <stdlib.h>%c#define SOY %c%s%c%cint main(void)%c{int i=%d;%cif (i == 0) return (0);%cchar *sully; asprintf(&sully, %cSully_%cd.c%c, i-1);%cchar *compile; asprintf(&compile, %cgcc -Wall -Werror -Wextra -o Sully_%cd Sully_%cd.c%c, i-1, i-1);%cchar *run; asprintf(&run, %c./Sully_%cd%c, i-1);%ci--;%cint fd = open(sully, O_RDWR|O_CREAT|O_TRUNC,0777);%cdprintf(fd, %c%s%c, 10, 10, 10, 34, SOY, 34, 10, 10, i, 10, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, 37, 34, 10, 10, 10, 34, SOY, 34);system(compile);system(run);return (0);}", 10, 10, 10, 34, SOY, 34, 10, 10, i, 10, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, 37, 34, 10, 10, 10, 34, SOY, 34);system(compile);system(run);return (0);}