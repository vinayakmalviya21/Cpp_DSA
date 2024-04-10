#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    // Convert character to uppercase
    char ch = toupper(word[0]);
    int index = ch - 'A';
    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        return root->isTerminal;
    }

    // Convert character to uppercase
    char ch = toupper(word[0]);
    int index = ch - 'A';
    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }
    return searchWord(child, word.substr(1));
}

int main() {

    // * Tries
    // ! It is data structure and it is multi way tree structure and use mainly for pattern searching.

    TrieNode* root = new TrieNode('-');

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babbar");

    if (searchWord(root, "codingkl")) {
        cout << "Present" << endl;
    }
    else {
        cout << "Absent" << endl;
    }

    return 0;
}
