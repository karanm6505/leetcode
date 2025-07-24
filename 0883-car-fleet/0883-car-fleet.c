typedef struct car
{
    int position;
    int speed;
}Car;
int cmp(const void* a, const void* b) {
    return ((Car*)b)->position - ((Car*)a)->position; 
}
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) 
{
    if (positionSize == 0) return 0;
    Car cars[positionSize];
    for (int i = 0; i < positionSize; i++) 
    {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, positionSize, sizeof(Car), cmp);
    double stack[positionSize];
    int top = -1;

    for (int i = 0; i < positionSize; i++) 
    {
    double time = (double)(target - cars[i].position) / cars[i].speed;
    stack[++top] = time;

    
    if (top > 0 && stack[top] <= stack[top - 1]) {
        top--; 
    }   
    }
    return top+1;
}