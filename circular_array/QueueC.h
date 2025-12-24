#ifndef QUEUEC_H
#define QUEUEC_H

class QueueC {
    private:
        int * queue; // dynamic array
        int front;
        int rear;
        int count;
        int maxSize;

    public:
        QueueC(int nelements = 128);
        QueueC(const QueueC &);
        ~QueueC();
        
        bool queueIsEmpty() const;
        bool queueIsFull() const;
        int queueLength() const;
        void queueFront(int &) const;
        void enqueue(int);
        void dequeue(int &);
};

#endif // QUEUEC_H