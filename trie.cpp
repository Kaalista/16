#include "Trie.h"
#include <string>
using namespace std;

TrieNode::TrieNode(){
    OfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        children[i] = nullptr;}
TrieNode::~TrieNode(){
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (children[i])
            delete children[i];}

TRIE::TRIE(){root = new TrieNode();}

TRIE::~TRIE(){if (root)delete root;}

TrieNode* TRIE::getNewNode(){
    struct TrieNode* pNode = new TrieNode;
    pNode->OfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;
    return pNode;}

void TRIE::insert(TrieNode* root, const string& key){
    TrieNode* pINNode = root;
    for (int i = 0; i < key.length(); i++)
    {int index = key[i] - 'a';

        if (!pINNode->children[index])
        { pINNode->children[index] = getNewNode();}
     pINNode = pINNode->children[index];
    }
    pINNode->OfWord = true;}

TrieNode* TRIE::search(const string& key) {
    TrieNode* current = root;
    for (size_t i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] && (index < ALPHABET_SIZE && index >= 0))
          {current = current->children[index]; }
        else
          {current = nullptr; break;}
    }
    return current;
}

vector<string> TRIE::vectorWords(TrieNode* pNode, string str, vector<string> vec){
    if (pNode->OfWord && str.size())
    {vec.push_back(str);}

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        string curr = str;
        if (pNode->children[i])
        {curr += i + 'a';
            vec = vectorWords(pNode->children[i], curr, vec); }
    }
    return vec;
}

void TRIE::prefix(string pref){
    setlocale(LC_ALL, "");
    vector<string> temp;
    TrieNode* current = search(pref);
    if (current == nullptr || current == root)
    { return;}

    vector<string> vec = vectorWords(current, pref, temp);
    if (vec.empty())
    { cout << "Не найдено слов: " << pref << endl;
        return;}
    else
    {
      cout << " Жмите Enter :  " << pref << endl << endl;
        for (int i = 0; i < vec.size(); i++)
        {
           cout << vec[i];
          cout << endl << endl;
          int put = cin.get();
          cout << endl << endl;
            if (put == 13)
            { std::cout << vec[i]; break;}
        }
    }
}

std::string TRIE::entPref(){
    setlocale(LC_ALL, "");
   cout << "Введите префикс: ";
   string str;
    cin >> str;
    cout << endl;
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}
void TRIE::dictionary()
{insert(root, "test");}

