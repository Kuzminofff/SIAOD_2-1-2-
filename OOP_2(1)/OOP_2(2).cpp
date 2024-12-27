﻿#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    void printTrie(TrieNode* node, string prefix) {
        if (node->isEndOfWord) {
            cout << prefix << endl;
        }
        for (auto& pair : node->children) {
            printTrie(pair.second, prefix + pair.first);
        }
    }
};


string generateRandomWord() {
    string word;
    for (int i = 0; i < 10; i++) {
        char c = 'A' + rand() % 4;
        word += c;
    }
    return word;
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    vector<string> words;
    Trie trie;

    for (int i = 0; i < 30; i++) {
        string word = generateRandomWord();
        words.push_back(word);
        trie.insert(word);
    }

    cout << "Сгенерированные слова:\n";
    for (const auto& w : words) {
        cout << w << endl;
    }

    cout << "\nПрефиксное дерево:\n";
    trie.printTrie(trie.root, "");

    string inputWord;
    cout << "\nВведите слово для поиска: ";
    cin >> inputWord;

    if (trie.search(inputWord)) {
        cout << "Слово \"" << inputWord << "\" найдено в дереве." << endl;
    }
    else {
        cout << "Слово \"" << inputWord << "\" не найдено." << endl;
    }

    return 0;
}