typedef struct StackNode {
    int val;
    int min;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* s = (MinStack*)malloc(sizeof(MinStack));
    s->top = NULL;
    return s;
}

void minStackPush(MinStack* s, int val) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->val = val;
    node->min = (s->top && s->top->min < val) ? s->top->min : val;
    node->next = s->top;
    s->top = node;
}

void minStackPop(MinStack* s) 
{
    if (s->top) {
        StackNode* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int minStackTop(MinStack* s) {
    return s->top ? s->top->val : INT_MIN;
}

int minStackGetMin(MinStack* s) {
    return s->top ? s->top->min : INT_MIN;
}

void minStackFree(MinStack* s) {
    while (s->top) minStackPop(s);
    free(s);
}
