#include<stdio.h>
#include<string.h>
#include<ctype.h>

char st[100];

int isLetter(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return 1;
    }else return 0;
}
int isDigit(char ch){
    if(ch>='0' && ch<='9') return 1;
    else return 0;
}

int isVowel(char ch){
    if(ch == 'a' || ch == 'A'||ch == 'e' || ch == 'E' ||ch == 'i' ||ch == 'I' || ch == 'o'|| ch == 'O'||ch == 'u'||ch == 'U'){
        return 1;
    }else return 0;
}


void activityA(){

    int wordCount=0, letterCount=0, digitCount=0, otherCount=0;

    for(int i=0;st[i];i++){
        if(st[i]!=' ' && (st[i+1]==' ' || st[i+1]=='\0')){
            wordCount++;
        }
    }

    for(int i=0;st[i];i++){
        if(isLetter(st[i])){
            letterCount++;
        }
    }

    for(int i=0;st[i];i++){
        if(isDigit(st[i])){
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
    printf("Other Count= %d\n\n",otherCount);
}

void activityB(){

    printf("Letters are: ");
    for(int i=0;st[i];i++){
        if(isLetter(st[i])){
            printf("%c ",st[i]);
        }
    }
    printf("\nDigits are: ");

    for(int i=0;st[i];i++){
        if(isDigit(st[i])){
            printf("%c ",st[i]);
        }
    }
    printf("\nOthers are: ");
    for(int i=0;i<st[i];i++){
        if(!isDigit(st[i]) && !isLetter(st[i]) && st[i]!=' '){
            printf("%c ",st[i]);
        }
    }
    printf("\n\n");
}

void activityC(){
    int countVowel=0,countConsonant=0;
    for(int i=0;st[i];i++){
        if(isVowel(st[i])) countVowel++;
        else if(isLetter(st[i])) countConsonant++;
    }
    printf("Number of Vowels: %d\n",countVowel);
    printf("Number of Consonant: %d\n\n",countConsonant);
}

void activityD(){
    int marka[26]={0};
    printf("Vowels are: ");
    for(int i=0;st[i];i++){
        if(isVowel(st[i]) && (marka[tolower(st[i])-'a']==0)){
            marka[tolower(st[i])-'a']=1;
            printf("%c ",st[i]);
        }
    }
    printf("\nConsonant are: ");
    for(int i=0;st[i];i++){
        if(isLetter(st[i]) && (marka[tolower(st[i])-'a']==0)){
            marka[tolower(st[i])-'a']=1;
            printf("%c ",st[i]);
        }
    }
    printf("\n\n");
}

void activityE(){
    int j=0;
    char word[40];
    printf("First Letter Vowel Words are: ");
    for(int i=0;st[i];i++){
        if(isLetter(st[i])){
            word[j++]=st[i];
        }else{
            if(j>0 && isVowel(word[0])){
                word[j]='\0';
                printf("%s ",word);
            }
            j=0;
        }
    }
    if(j>0 && isVowel(word[0])){
        word[j]='\0';
        printf("%s ",word);
    }

    printf("\nFirst Letter Consonant Words are: ");
    j=0;
    for(int i=0;st[i];i++){
        if(isLetter(st[i])){
            word[j++]=st[i];
        }else{
            if(j>0 && !isVowel(word[0])){
                word[j]='\0';
                printf("%s ",word);
            }
            j=0;
        }
    }
    if(j>0 && !isVowel(word[0])){
        word[j]='\0';
        printf("%s ",word);
    }
    
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);

    activityA();
    activityB();
    activityC();
    activityD();
    activityE();



}