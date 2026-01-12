int scoreOfString(char* s) 
{
    int n = strlen(s);
    int sum = 0;
    for(int i = 1; i < n ; i++){
        sum += abs(s[i] - s[i-1]);
    }
    return sum;
}