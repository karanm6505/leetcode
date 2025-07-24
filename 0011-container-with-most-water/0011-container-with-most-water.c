int minimum(int x, int y) 
{
    return (x < y) ? x : y;
}
int maxArea(int* height, int heightSize) 
{
    int l = 0;
    int r = heightSize - 1;
    int max = INT_MIN;
    int area = 0;
    while(l < r)
    {
        area = (r-l) * minimum(height[l],height[r]);
        if(area > max) max = area;
        if(height[l] < height[r]) {l++;}
        else {r--;}
    }
    return max;
}