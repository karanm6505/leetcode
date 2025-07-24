#define MAX_SIZE 10001
typedef struct 
{
    char items[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s) 
{
    s->top = -1;
}
int isEmpty(Stack *s) 
{
    return (s->top == -1);
}
int isFull(Stack *s) 
{
    return (s->top >= MAX_SIZE - 1);
}
void push(Stack *s, char c) 
{
    if (isFull(s)) return;
    s->items[++(s->top)] = c;
}
char pop(Stack *s) 
{
    if (isEmpty(s)) return '\0';
    return s->items[(s->top)--];
}
int isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
bool isValid(char *expr)
{
    Stack s;
    initStack(&s);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(&s, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') 
        {
            if (isEmpty(&s)) return 0;  
            char popped = pop(&s);
            if (!isMatching(popped, expr[i])) {
                return 0;
            }
        }
    }
    
    return isEmpty(&s);  // Stack should be empty for valid expression
}