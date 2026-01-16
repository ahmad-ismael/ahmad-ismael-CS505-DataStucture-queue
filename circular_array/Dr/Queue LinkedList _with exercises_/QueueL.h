class QueueL
{
   public:


      QueueL();						// Constructor
	  ~QueueL();					// Destructor
      void enqueue(int );			// Add to rear
	  void dequeue(int &);			// Remove from front
	   void enqueue(char );			// Add to rear
	  void dequeue(char &);
	  void queueFront(int &) const;	// retrieve front
      bool queueIsEmpty() const;	// Test for Empty queue
	  int  queueLength() const;		// Queue Length

   private:
	// Node Class
	   class node
	   {
		public:
			int e;					// queue element
			node *next;				// pointer to next node
		}; // end of class node declaration

	typedef node * NodePointer;

	NodePointer front , rear;		// Pointers
	int count;						// length

};
