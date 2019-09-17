#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[80],ns[80];
    int i,k=0,size=80;
    char *ptr=(char *)getline(&s,&size,stdin);
    printf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if ((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
            continue;     
        ns[k++]=s[i];
    }
    ns[k]='\0';
    printf("%s",ns);
	return 0;
}