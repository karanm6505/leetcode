int maxFreq(int* count) 
{
    int max = 0;
    for (int i = 0; i < 26; i++) 
    {
        if (count[i] > max) max = count[i];
    }
    return max;
}

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int l = 0, res = 0, n = strlen(s);

    for (int r = 0; r < n; r++) {
        count[s[r] - 'A']++;

        while ((r - l + 1) - maxFreq(count) > k) {
            count[s[l] - 'A']--;
            l++;
        }

        if (r - l + 1 > res) res = r - l + 1;
    }

    return res;
}
