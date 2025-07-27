int romanCharToInt(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(const char *s) {
    int total = 0;
    int prev = 0;
    int curr = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        curr = romanCharToInt(s[i]);
        if (curr < prev)
            total -= curr;
        else
            total += curr;
        prev = curr;
    }

    return total;
}