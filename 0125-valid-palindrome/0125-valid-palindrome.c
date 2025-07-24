void cleanAndLowercaseString(char* str) 
{
    if (!str) return;

    int i = 0, j = 0;
    while (str[i]) {
        if (isalnum((char)str[i])) 
        {
            str[j++] = tolower((char)str[i]);
        }
        i++;
    }
    str[j] = '\0';
}
bool isPalindrome(char* s) 
{
    cleanAndLowercaseString(s);
    int l = 0;
    int r = strlen(s) - 1;
    for(int i = 0; i < strlen(s)/2; i++)
    {
        if(*(s+l) == *(s+r))
        {
            l++; r--;
        }
        else
        {
            return false;
        }
    } 
    return true;
}