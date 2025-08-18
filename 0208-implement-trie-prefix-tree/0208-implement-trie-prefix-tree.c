typedef struct Trie {
    struct Trie* children[26];
    bool isEndOfWord;
} Trie;

Trie* trieCreate() 
{
    Trie* node = (Trie*)malloc(sizeof(Trie));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            node->children[i] = NULL;
    }
    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie* node = obj;
    while (*word) {
        int index = *word - 'a';
        if (index < 0 || index >= 26) return; 
        if (!node->children[index])
            node->children[index] = trieCreate();
        node = node->children[index];
        word++;
    }
    node->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* node = obj;
    while (*word) {
        int index = *word - 'a';
        if (index < 0 || index >= 26) return false;
        if (!node->children[index])
            return false;
        node = node->children[index];
        word++;
    }
    return node->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* node = obj;
    while (*prefix) {
        int index = *prefix - 'a';
        if (index < 0 || index >= 26) return false;
        if (!node->children[index])
            return false;
        node = node->children[index];
        prefix++;
    }
    return true;
}

void trieFree(Trie* obj) {
    if (!obj) return;
    for (int i = 0; i < 26; i++) {
        if (obj->children[i])
            trieFree(obj->children[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/