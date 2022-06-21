#define MAX_LEN 100
#include <stdio.h>
#include <string.h>

int main()
{
        char filename[MAX_LEN];
        int line,character;

        printf("파일이름 : ");
        scanf("%s",filename,sizeof(filename));

        printf("라인 : ");
        scanf("%d",&line);

        printf("문자열 : ");
        scanf("%d",&character);
        function(filename,line,character);
}

void function(char *filename,int line,int character)
{
        FILE* fs;
        int count = 0, i = 0;
        char str[MAX_LEN];
        char *b[MAX_LEN] = {NULL};

        fs = fopen(filename,"r");
        if(fs == NULL)
        {
                printf("no file\n");
                return 0;
        }

        while(fgets(str,MAX_LEN,fs) != NULL)
        {
                count++;
                if(count == line)
                {
                        char *a = strtok(str," ");
                        while(a != NULL)
                        {
                                b[i] = a;
                                i++;
                                a = strtok(NULL," ");
                        }
                        if(b[character-1] == NULL) printf("문자열 에러\n");
                        else printf("%s\n",b[character-1]);
                }
        }
        if(count < line) printf("line error\n");
}
