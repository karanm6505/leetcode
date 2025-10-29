int numberOfBits(int n){
    if(n == 0 || n == 1) return 1;
    else
    {
        return 1 + numberOfBits(n/2);
    }
}

int smallestNumber(int n) 
{
    return pow(2,numberOfBits(n)) - 1;
}
