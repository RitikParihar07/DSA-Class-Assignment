#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

void push(int stack[], int *top, int value) 
{
    if (*top == MAX - 1) 
    {
        printf("stack is full\n");
    } else {
        stack[++(*top)] = value;
    }
}

int pop(int stack[], int *top) 
{
    int temp;

    if (*top == -1) 
    {
        printf("stack is empty\n");
        
    } else 
    {
         temp= stack[(*top)--];
    }
    return temp;
}

int evaluation(int a1, int a2, char op) 
{
    switch (op) {
        case '+':
            return a1 + a2;
        case '-':
            return a1 - a2;
    }
    return 0;
}

void display(int stack[], int top) 
{
    while (top >= 0) { 
        printf("%d", stack[(top)--]);
    }
}
bool isEmpty(int top) {
    return top == -1;
}

int main() {
    int stack[MAX];
    int opstack[MAX];

    int top = -1;
    int optop = -1;
    
    char s[] = "(-121+35)-120+240";
    int len = strlen(s);
    int addDigit = 0;
   int flag=0;

   for (int i = 0; i < len ; i++) 
   {
        if (s[i] >= '0' && s[i] <= '9') 
        {
            addDigit = addDigit * 10 + (s[i] -'0');
        } else if (s[i] == '+' || s[i] == '-') 
        
        {   
            push(opstack, &optop, s[i]);
            push(stack, &top, addDigit);
            addDigit = 0;
        

            if (flag==1) { 
                int a2 = pop(stack, &top);
                int a1 = pop(stack, &top);
                char a = pop(opstack, &(optop));
                char op=pop(opstack, &(optop));
                int r = evaluation(a1, a2, op);
                push(opstack, &optop,a);
                push(stack, &top, r);
                
            }
            flag=1;
        } 
        
       
    }
    
    if (addDigit != 0) {
        push(stack, &top, addDigit);
    }
    if(!isEmpty(optop)){
        int a2 = pop(stack, &top);
        int a1 = pop(stack, &top);
        char op=pop(opstack, &(optop));
        int r = evaluation(a1, a2, op);
        push(stack, &top, r);
    }

    display(stack, top);

    return 0;
}