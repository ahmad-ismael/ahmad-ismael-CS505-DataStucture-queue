class Stack {
    class node {
        public:
            int e;
            node * next;
    };

    typedef node * ptr;
    ptr top;
    int count;
    


    public:
        Stack();
        Stack(const Stack &s);
        ~Stack();
        bool stackIsEmpty();
        void push(int);
        void pop(int &);
        void stackTop(int &);
        int stackSize();
};