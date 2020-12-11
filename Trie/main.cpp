#include "trie.h"

int main(){
    string diccionario[9] = {"romano", "roma", "romario", 
                        "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};
    Trie* trie = new Trie();
    int n = 9;
    for (int i = 0; i < n; i++)
        trie->insert(diccionario[i]);
    trie->display();

    //buscar
    if(trie->search("amorcito")) cout<<"Si\n"; else cout<<"No\n";    
    if(trie->search("raton")) cout<<"Si\n"; else cout<<"No\n";    

    //eliminar
    trie->remove("amorcito");
    if(trie->search("amorcito")) cout<<"Si\n"; else cout<<"No\n";   

    trie->display();
}