//stack sıralı tutulacak(sadece pop ve push ile)
#include <stdio.h>

int stack[50] = {0};
short top = 0;

int push2(short x){
    for(size_t i = 0; i < top; i++)
    {
        if(x <= stack[i]){
            return i;
            break;
        }
    }
}

void push(short x){
        if(top == 0) stack[top++] =x;
        else if(top == 50) printf("Stack Overflow!\n");
        else{
            int where = push2(x);
            for(size_t i = top-1; i >= where; i--){
                stack[i+1] = stack[i];
            }
            stack[where] = x;
            top++;
        }
}

void display(){
    
    for(size_t i = 0; i < top; i++){
        printf("%d -> %d\n", i, stack[i]);
    }
    printf("End\n");
    
}

int main(){
    push(1);
    display();
    push(3);
    display();
    push(2);
    display();
    push(6);
    display();
    push(4);
    display();
    //patliyor -> push(-3);
    //display();
    
    return 0;
}
