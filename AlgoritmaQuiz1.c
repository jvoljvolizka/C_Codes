//tek bir dizi ile iki ayrı stack tut
#define kapasite 50
#include <stdio.h>

char stack[kapasite] = {' '};
short top = 0, top2 = kapasite-1;

void push(short nereye, char neyi){
    if(top == top2){
        printf("Stack overflow!\n");
    }
    else{
        if(nereye == 0) stack[top++] = neyi;
        else stack[top2--] = neyi;
    }
}

void pop(short neresi){
    if(neresi==0){
        if(top == 0){
            printf("There is nothing to pop it!\n");
        }
        else{
            top--;
            printf("Stack1 is popped\n");
        }
    }
    else {
        if(top2 == kapasite-1){
            printf("There is nothing to pop it!\n");
        }
        else{
            top2++;
            printf("Stack2 is popped\n");
        }
    }
}


void display(short neresi){
    short i;
    if(neresi == 0){
        printf("Stack 1:\n");
        for(i = top-1; i >=0; i--) printf("%c", stack[i]);
        printf("\n");
    }
    else{
        printf("Stack 2:\n");
        for(i = top2+1; i < kapasite ; i++) printf("%c", stack[i]);
        printf("\n");
    }
}


int main(){

    push(0, 'a');
    push(0, 'b');
    push(1, 'c');
    push(1, 'd');
    push(0, 'e');


    display(0);
    display(1);

    pop(0);
    pop(1);

    display(0);
    display(1);

    return 0;
}
