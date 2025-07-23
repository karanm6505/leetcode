
bool isAnagram(char* s, char* t) 
{   
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) 
    {
        return false;
    }
    int counts[256] = {0};
    for(int i = 0; i < len_s; i++)
    {
        counts[s[i]]++;
    }
    for(int i = 0; i < len_t; i++)
    {
        counts[t[i]]--;
    }
    for(int i = 0; i < 256; i++)
    {
        if(counts[i] != 0)
        {
            return false;
        }
    }
    return true;


}
    

