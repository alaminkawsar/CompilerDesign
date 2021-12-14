#include<stdio.h>
char st[100];
int n;


void ActivityA(){

    int wordCount=0, letterCount=0, digitCount=0, otherCount=0;

    for(int i=0;st[i];i++){
        if(st[i]!=' ' && (st[i+1]==' ' || st[i+1]=='\0')){
            wordCount++;
        }
    }

    for(int i=0;st[i];i++){
        if((st[i]>='a' && st[i]<='z') || (st[i]>='A' && st[i]<='Z')){
            letterCount++;
        }
    }

    for(int i=0;st[i];i++){
        if(st[i]>='0'&&st[i]<='9'){
            digitCount++;
        }
    }

    int spaceCount=0;
    for(int i=0;st[i];i++){
        if(st[i]==' ') spaceCount++;
    }

    otherCount = strlen(st)-(spaceCount+digitCount+letterCount);


    printf("Word Count= %d\n",wordCount);
    printf("Letter Count= %d\n",letterCount);
    printf("Digit Count= %d\n",digitCount);
    printf("Other Count= %d\n",otherCount);
}



int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);
    activityA();
    //printf("%s",st);

}