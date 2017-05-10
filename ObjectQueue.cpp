 #include "ObjectQueue.h" 
  
  
  ObjectQueue::ObjectQueue() {
        size = 100;
        item = new Object[size];
        front = size-1;
        rear  = size-1;
    }

    ObjectQueue::ObjectQueue(int max) {
        size = max;
        item = new Object[size];
        front = size-1;
        rear  = size-1;
    }

    bool ObjectQueue::isEmpty() {
        return front == rear;
    }
    
   bool ObjectQueue::isFull() {
       return rear == size-1 ? front == 0 : front == rear+1;
    }
    
    void ObjectQueue::clear() {
        front = size-1;
        rear  = size-1;
    }
    
 
    void ObjectQueue::insert(Object x) {
        if (isFull()) {
            System.out.println("Insert Runtime Error: Queue Overflow");
            System.exit(1);
        }
        if (rear == size-1)			// or rear = (rear+1) % size;
            rear = 0;
        else
            rear++;
        item[rear] = x;
    }
    
    Object ObjectQueue::remove() {
        if (isEmpty()) {
            System.out.println("Remove Runtime Error: Queue Underflow");
            System.exit(1);
        }
        if (front == size-1)			// or front = (front+1) % size;
            front = 0;
        else
            front++;
        return item[front];
    }
    
    Object ObjectQueue::query() {
        if (isEmpty()) {
            System.out.println("Query Runtime Error: Queue Underflow");
            System.exit(1);
        }
        if (front == size-1)
            return item[0];
        else
            return item[front+1];
    }
