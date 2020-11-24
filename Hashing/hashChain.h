template <typename TK, typename TV>
class Hash
{
private:    
    struct Node {
        int hashCode;
        TK value;
        TV value;
        Node* next;        
    };

    int arrayLength;
    int size;
    Node** array;

public:    
    Hash(int _length)
    {
        arrayLength = _length;
        array = new Node*[arrayLength];
        for (int i = 0; i < arrayLength; i++)
            array[i] = nullptr;
    }

    void insert(TK key, TV value)
    {
        int hashCode = getHashCode(key);    //funcion hash
        int index = hashCode % arrayLength; //colisiones       
        if (array[index] == nullptr)
            array[index] = new Node(hashCode, value);
        else
            push_front(array[index], new Node(hashCode, key, value));
    }

    void insert(Node* node)
    {
        int hashCode = node->hashCode; 
        int index = hashCode % arrayLength;//colisiones                
        node->next = nullptr;
        if (array[index] == nullptr)
            array[index] = node;
        push_front(array[index], node);
    }

    void rehashing()
    {
        int tempL = arrayLength;
        Node** temp = array;      

        arrayLength = arrayLength * 2;
        array = new Node*[arrayLength];
        for(int i=0;i<arrayLength;i++)
            array[i] = nullptr;

        for (int i = 0; i < tempL; i++)
        {            
            for(Node* node = temp[i]; node != null; node = node->next)
                insert(node);
        }

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


