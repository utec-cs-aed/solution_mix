template<typename TK, typename TV> 
class Hash
{
private:    
    struct Node{
        int hashCode;
        TK key;
        TV value;
    };

    int arrayLength;    
    int size;
    Node** array;

public:    
    Hash(int _length){
        arrayLength = _length;
        array = new Node*[arrayLength];
        for(int i=0;i<arrayLength;i++)
            array[i] = nullptr;
    }

    int salto(int step){
        return step;
    }

    void insert(TK key, TV value)
    {
        int hashCode = getHashCode(key); //funcion hash   
        int index = hashCode % arrayLength;//colisiones         
        int i=0;
        while(array[index] != nullptr)
            index = (index + salto(i++)) % arrayLength ;//podemos trabajar con saltos
        array[index] = new Node(hashCode, key, value);
    }

    void insert(Node* node)
    {
        int hashCode = node->hashCode; 
        int index = hashCode % arrayLength;//colisiones         
        while(array[index] != nullptr)
            index = (index + 1) % arrayLength ;//podemos trabajar con saltos
        array[index] = node;
    }

    void rehashing(){
        int tempL = arrayLength;
        Node** temp = array;        

        arrayLength = arrayLength * 2;
        array = new Node*[arrayLength];
        for(int i=0;i<arrayLength;i++)
            array[i] = nullptr;

        for(int i=0;i<tempL;i++)
            insert(temp[i]);
            
        delete[] temp; 
    }

    TV operator[](TK key){
        //TODO
    }

    TV find(TK key){
        // TODO
    }

    bool remove(TK key){
        // TODO
    }

    vector<TK> getAllKeys(){
        // TODO
    }    
    vector<pairs<TK, TV>> getAll(){
        // TODO
    }
};


