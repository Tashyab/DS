#include<stdio.h>
#include<string.h>
#define max 100
FILE *ptr, *out;

int top, stack[max];
void push(char x)
{
    if(top == max-1)
        printf("Stack Overflow");
    else
        stack[++top] = x;
} 

char pop()
{
    return stack[top--];
}

void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) 
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseWords(char* s)
{
    char* word_begin = s;
    char* temp = s;
    while (*temp) 
    {
        temp++;
        if (*temp == '\0') 
        {
            reverse(word_begin, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
    reverse(s, temp - 1);
}


int main()
{
    out=fopen("output.txt", "w+");
    char str[100];
    char st2[100];
    char filename[50];
    printf("Enter the filename with txt extension: ");
    scanf("%s", filename);
    ptr = fopen(filename,"r");
    fgets(str,100,ptr);
    int i;
    int len = strlen(str);

    for(i=0;i<len;i++)
        push(str[i]);


    char txt[200];
    for(i=0;i<len;i++)
    {
        txt[i]=pop();
        printf("%c", txt[i]);
    }

    fgets(txt, strlen(txt)+1, out);
    reverseWords(txt);
    printf("\n%s", txt);
    fputs(txt, out);

    fclose(ptr);
    fclose(out);
}