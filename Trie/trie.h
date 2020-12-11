#include <iostream>
#include <map>

const unsigned ALPHA_SIZE = 26;//tamanio del alfabeto de letras minusculas
using namespace std;

class Trie{
private:
    struct TrieNode{        
        std::map<char, TrieNode *> children;
        //para indicar si es final de una palabra
        bool endWord;

        TrieNode(){           
            endWord = false;            
        }        
    };
    TrieNode* root;

public:
    Trie(): root(nullptr) {}

    void insert(string key){
        if(root == nullptr) root = new TrieNode();
        TrieNode* temp = root;
        //recorrer por todo el prefijo
        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.find(key[i]) == temp->children.end()) 
                temp->children[key[i]] = new TrieNode();
            temp = temp->children[key[i]];
        }
        //siempre indicar fin de la palabra
        temp->endWord = true;
    }

    bool search(string key){
        if(root == nullptr) return false;
        TrieNode* temp = root;
        //recorrer por todo el prefijo
        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.find(key[i]) == temp->children.end())  return false ;
            temp = temp->children[key[i]];
        }

        return temp != nullptr && temp->endWord;
    }

    void remove(string key){
        remove(root, key);
    }
    
    void display(){
        display(root);
    }

private:
    bool isEmpty(TrieNode* node){
        return node->children.size() == 0;
    }
    
    void remove(TrieNode* &node, string key, int pos=0){
        if(node == nullptr) return;
        if(pos < key.size() ){        
            auto it = node->children.find(key[pos]);
            if(it != node->children.end())            
            {
                remove(it->second, key, pos + 1);
                if(it->second == nullptr)
                    node->children.erase(it);
            }            
            if(isEmpty(node) && !node->endWord){                
                delete node;
                node = nullptr;                
            }
        }else{
            //descativar indicador de fin de palabra
            if(node->endWord) node->endWord = false;
            //si ya no hay mas hijos, proceder a eliminar
            if(isEmpty(node)){
                delete node;
                node = nullptr; 
            }
        }
    }  

    void display(TrieNode* node, string base = ""){
        if(node == nullptr) return;
        if(node->endWord) cout<<base<<endl;
        for (auto &it : node->children)
            display(it.second, base + it.first); 
    }  
};
