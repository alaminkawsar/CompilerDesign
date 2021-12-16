#include<stdio.h>
#include<string.h>
#include<ctype.h>

char st[100];

int isInvalid(){
    for(int i=0;st[i];i++){
        if((st[i]>='a' && st[i]<='z') || (st[i]>='A' && st[i]<='Z') || (st[i]>='0' && st[i]<='9')){
            //ok ok
        }else return 1;
    }
    return 0;
}

int isLetter(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return 1;
    }else return 0;
}

int isAllDigit(){
    for(int i=0;st[i];i++){
        if(st[i]<='0' && st[i]>='9')
            return 0;
    }
    return 1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);
    if(isInvalid()){
        printf("Input invalid\n");
        return 0;
    }


    //solution (a)
    printf("Integer? ");
    if((st[0]>='i' && st[0]<='n') || (st[0]>='I' && st[0]<='N')){
        printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (b)
    printf("Short Integer? ");
    if(st[0]!='0' && strlen(st)<=4){
        printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (c)
    printf("Long Integer? ");
    if(st[0]!=0 && strlen(st)>=5 && isAllDigit()){
        printf("YES\n");
    }else printf("NO\n\n");


}