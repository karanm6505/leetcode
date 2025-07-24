#define SIZE 10000

typedef struct {
    int top;
    int stack[SIZE];
} Stack;

Stack* initStack() {
    Stack* s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int pop(Stack* s) {
    if (isEmpty(s)) return INT_MIN;
    return s->stack[s->top--];
}

void push(Stack* s, int val) {
    if (s->top >= SIZE - 1) return;
    s->stack[++s->top] = val;
}

int evalRPN(char** tokens, int tokensSize) {
    Stack* s = initStack();

    for (int i = 0; i < tokensSize; i++) {
        char* tok = tokens[i];

        // If it's an operator
        if (strcmp(tok, "+") == 0 || strcmp(tok, "-") == 0 ||
            strcmp(tok, "*") == 0 || strcmp(tok, "/") == 0) {

            int b = pop(s);
            int a = pop(s);
            int res = 0;

            if (strcmp(tok, "+") == 0) res = a + b;
            else if (strcmp(tok, "-") == 0) res = a - b;
            else if (strcmp(tok, "*") == 0) res = a * b;
            else if (strcmp(tok, "/") == 0) res = a / b;

            push(s, res);
        }
        else {
            // Convert token string to int
            int num = atoi(tok);
            push(s, num);
        }
    }

    int final = pop(s);
    free(s);
    return final;
}