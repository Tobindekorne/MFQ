// ObjectQueue.java
#ifndef OBJECTQUEUE_H
#define OBJECTQUEUE_H


class ObjectQueue {
	private: 
	Object item[];
	int front;
	int rear;
      	int size;

	public: 
		ObjectQueue();
		ObjectQueue(int max);
		bool isEmpty();
		bool isFull();
		void clear();
		void insert(Object x);
 		Object remove();
		Object query();
};

#endif
