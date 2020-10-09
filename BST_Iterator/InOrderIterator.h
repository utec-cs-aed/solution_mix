class Iterator {
    private:
        NodeBT<T>* current;
        StackList<NodeBT<T>*> stack; 
    public:
        Iterator(): current(nullptr) {};
        Iterator(NodeBT<T>* node) {            
            while(node != nullptr){
                this->stack.push(node);
                node = node->left;
            }
            if(!this->stack.empty())
                current = this->stack.top();            
            else
                current = nullptr;
        }
        Iterator<T>& operator++(){
            if(this->stack.empty()) throw std::out_of_range("It's not possible");
            NodeBT<T>* node = this->stack.pop()->right;            
            while(node != nullptr) {
                this->stack.push(node);
                node = node->left;
            }            
            this->current = this->stack.empty() ? nullptr : stack.top();
            return *this;
        }
}