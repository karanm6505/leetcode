char *mergeAlternately(char *word1, char *word2) {

    int n1 = strlen(word1);
    int n2 = strlen(word2);

    char *word = malloc((n1 + n2 + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        word[k++] = word1[i++];
        word[k++] = word2[j++];
    }

    while (i < n1)
        word[k++] = word1[i++];

    while (j < n2)
        word[k++] = word2[j++];

    word[k] = '\0';

    return word;
}