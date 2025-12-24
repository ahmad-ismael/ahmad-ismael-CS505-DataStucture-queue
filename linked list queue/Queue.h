class Queue {
    private:
        class pcb {
            public:
                int pid;
                pcb * next;
        };
        typedef pcb * np;
        np front, rear;
        int count;

    public:
        Queue();
        Queue(const Queue &);
        ~Queue();
        bool queueIsEmpty() const;
        int queueLength() const;
        void queueFront(int &) const;
        void enqueue(int);
        void dequeue(int &);
};