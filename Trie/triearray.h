#include <iostream>

const unsigned ALPHA_SIZE = 26;//tamanio del alfabeto de letras minusculas
using namespace std;

class TrieArray{
private:
    struct TrieNode{        
        TrieNode **children;
        //para indicar si es final de una palabra
        bool endWord;

        TrieNode(){
            children = new TrieNode*[ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; i++)
                children[i] = nullptr;
            endWord = false;            
        }
        ~TrieNode(){
            delete[] children;
        }
    };
    TrieNode* root;

public:
    TrieArray(): root(nullptr) {}

    void insert(string key){
        if(root == nullptr) root = new TrieNode();
        TrieNode* temp = root;
        int index = -1;
        //recorrer por todo el prefijo
        for (int i = 0; i < key.size(); i++)
        {
            index = key[i]  - 'a';
            if(temp->children[index] == nullptr) 
                temp->children[index] = new TrieNode();
            temp = temp->children[index];
        }
        //siempre indicar fin de la palabra
        temp->endWord = true;
    }

    bool search(string key){
        if(root == nullptr) return false;
        TrieNode* temp = root;
        int index = -1;
        //recorrer por todo el prefijo
        for (int i = 0; i < key.size(); i++)
        {
            index = key[i]  - 'a';
            if(temp->children[index] == nullptr)  return false ;
            temp = temp->children[index];
        }

        return temp->endWord;
    }

    void remove(string key){
        remove(root, key);
    }

    
    //TODO 
    void display(){
        display(root);
    }

private:
    bool isEmpty(TrieNode* node){
        for (int i = 0; i < ALPHA_SIZE; i++)
            if(node->children[i] != nullptr) return false;
        return true;
    }
    
    void remove(TrieNode* &node, string key, int pos=0){
        if(node == nullptr) return;
        if(pos < key.size() ){
            int index = key[pos]  - 'a';
            remove(node->children[index], key, pos + 1);
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
        for (int i = 0; i < ALPHA_SIZE; i++)
            if(node->children[i] != nullptr)
                display(node->children[i], base + char('a' + i));        
    }  
};
