#include <stdio.h>
#include <string.h>

#define max 100
int top=-1,j;
char stack[max];
char s1[1000];

void push(char x)
{
    if (top == max-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        stack[++top] = x;
    }
}
char pop()
{
    char c;
    c=stack[top];
    top--;
    return c;
}
int main()
{
    char name[20],str[200];
    printf("Enter the filename in .txt format : ");
    scanf("%s",name);
    FILE *ptr;
    ptr=fopen(name,"r");
    fscanf(ptr,"%[^\n]s",str);

    int i=0;
    
    while (i<strlen(str))
    {
       if (str[i]!=' ')
       {
           push(str[i]);
       }
       else
       {
           while (top!=-1)
           {
               s1[j]=pop();
               j++;
                
           }
           if(str[i+1]!=' ')
           {
           if (top==-1)
               {
                   s1[j++]=' ';
               }
           }   
       }
       i++; 
    }
   
    FILE *new;
    new=fopen("output.txt","a");
    fprintf(new,"%s",s1);
    printf("The output is :");
    printf("%s",s1);
    fclose(new);
    fclose(ptr);
    return 0; 
}