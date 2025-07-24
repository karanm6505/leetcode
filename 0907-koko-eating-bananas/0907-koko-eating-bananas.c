int getMax(int* piles, int n) {
    int maxVal = piles[0];
    for (int i = 1; i < n; i++) {
        if (piles[i] > maxVal) maxVal = piles[i];
    }
    return maxVal;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int l = 1, r = getMax(piles, pilesSize);

    while (l <= r) {
        int k = l + (r - l) / 2;
        long long hours = 0;

        for (int i = 0; i < pilesSize; i++) {
            hours += ((long long)piles[i] + k - 1) / k;
        }

        if (hours <= h) {
            r = k - 1;  
        } else {
            l = k + 1;  
        }
    }

    return l; 
}
