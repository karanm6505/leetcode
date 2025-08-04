double powerPos(double x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return x;
    }
    else if(n%2 == 0)
    {
        double y = powerPos(x,n/2);
        return y*y;
    }
    else
    {
        double y = powerPos(x,n/2);
        return x*y*y;
    }
}
double myPow(double x, int n) 
{
    long long N = n;
    if(N < 0)
        return 1.0 / powerPos(x, -N);
    else
        return powerPos(x, N);
}