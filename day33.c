#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int precedence(char x){
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

int main(){
    char infix[100];
    
    scanf("%s", infix);

    for(int i=0;i<strlen(infix);i++){
        char ch = infix[i];

        if(isalnum(ch)){   // operand
            printf("%c", ch);
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(stack[top] != '('){
                printf("%c", pop());
            }
            pop(); // remove '('
        }
        else{  // operator
            while(top!=-1 && precedence(stack[top]) >= precedence(ch)){
                printf("%c", pop());
            }
            push(ch);
        }
    }

    while(top!=-1){
        printf("%c", pop());
    }

    return 0;
}
