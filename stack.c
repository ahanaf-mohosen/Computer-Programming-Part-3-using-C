#include <stdio.h>
#define MAX 10

typedef struct
{
    int top;
    int data[MAX];
} Stack;

void push(Stack *s, int item);
int pop(Stack *s);
int main()
{
    Stack s;
    int item;
    s.top = 0;
    push(&s, 5);
    push(&s, 7);
    push(&s, 11);

    item = pop(&s);
    printf("Pop up item is %d\n", item);
    item = pop(&s);
    printf("Pop up item is %d\n", item);
    item = pop(&s);
    printf("Pop up item is %d\n", item);
    item = pop(&s);
    printf("Pop up item is %d\n", item);
    return 0;
}
void push(Stack *s, int item)
{
    if (s->top < MAX)
    {
        s->data[s->top] = item;
        s->top += 1;
    }
    else
    {
        printf("Stack is full!\n");
    }
}
int pop(Stack *s)
{
    int item;
    if (s->top == 0)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        s->top -= 1;
        item = s->data[s->top];
    }
    return item;
}