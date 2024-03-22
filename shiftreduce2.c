#include <stdio.h>
#include <string.h>
struct Production
{
    char left[10];
    char right[10];
};
int main()
{
int flag=0;
    char name[20];
    char rollno[20];
    char input[20], stack[50], temp[50], ch[2], *token1, *token2, *substring;
    int i, j, stack_length, substring_length, stack_top, production_count = 0;
    struct Production prod[10];
    stack[0] = '\0';
    printf("\nEnter the Number of Productions: ");
    scanf("%d", &production_count);
    printf("\nEnter the Productions: \n");
    for (i = 0; i < production_count; i++)
    {
        scanf("%s", temp);
        token1 = strtok(temp, "->");
        token2 = strtok(NULL, "->");
        strcpy(prod[i].left, token1);
        strcpy(prod[i].right, token2);
    }
    printf("\nEnter Name of the Student:");
    scanf("%s",name);
    printf("\nEnter Rollno of the sStudent:");
    scanf("%s",rollno);
    printf("\nName of the Student  is :%s",name);
    printf("\n\nRollno of the Student is :%s",rollno);
    printf("\nEnter the Input String: ");
    scanf("%s", input);
    printf("\n--------------------------\n");
    printf("STACK\t INPUT\tAction");
    printf("\n--------------------------\n");
    i=0;
    while (1)
    {
        if (i < strlen(input))
        {
            ch[0] = input[i];
            ch[1] = '\0';
            i++;
            strcat(stack, ch);
            printf("\n%s\t", stack);
            for (int k = i; k < strlen(input); k++)
            {
                printf("%c", input[k]);
            }
            printf("\tShift %s\n", ch);
        }
        for (j = 0; j < production_count; j++)
        {
            substring = strstr(stack, prod[j].right);
            if (substring != NULL)
            {
                stack_length = strlen(stack);
                substring_length = strlen(substring);
                stack_top = stack_length - substring_length;
                stack[stack_top] = '\0';
                strcat(stack, prod[j].left);
                printf("%s\t", stack);
                for (int k = i; k < strlen(input); k++)
                {
                    printf("%c", input[k]);
                }
                printf("\tReduce %s->%s\n", prod[j].left, prod[j].right);
                j=-1;
            }
         }
        if (strcmp(stack, prod[0].left) == 0 && i == strlen(input))
        {
            printf("\nString successfully Parsed");
	 flag=1;
            break;
        }
      else if(input[i]=='\0')
      {
	break;
      }

     }
     if(flag==0)
     {
	printf("\nString is not Parsed");
     }
}