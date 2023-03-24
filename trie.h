#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool OfWord;

    TrieNode();
    ~TrieNode();
};

class TRIE
{
public:
    TRIE();
    ~TRIE();

    TrieNode* getNewNode();
    void insert(TrieNode* root, const string& key);
    TrieNode* search(const string& key);
    void dictionary();
  string entPref();
  vector<string> vectorWords(TrieNode* pNode, string str, vector<string> vec);//
    void prefix(string pref);

private:
    TrieNode* root;
};
