#include"Trie.h"
#include <string>
using namespace std;

int main()
{

    TRIE trie;
    trie.dictionary();
    cout <<endl << endl;
    cout << "тест консольный" << endl << endl;
    cout << endl;
    trie.prefix("te");
    cout << "тест пользовательский" <<endl<<endl;
    string pref = trie.entPref();
    trie.prefix(pref);

    return 0;
}


