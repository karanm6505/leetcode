int hammingWeight(int n) 
{
    if(n == 1){ return 1;}
    else 
    {
        if(n%2 == 1)
        {
            return 1 + hammingWeight(n/2);
        }
        else
        {
            return hammingWeight(n/2);
        }
    }
}