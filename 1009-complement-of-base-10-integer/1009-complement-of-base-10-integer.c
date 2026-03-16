int bits(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return 1 + bits(n/2);
}
int bitwiseComplement(int n) {
    return pow(2, bits(n)) - 1 - n;
}