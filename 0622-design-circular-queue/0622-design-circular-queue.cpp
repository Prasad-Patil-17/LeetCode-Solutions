class MyCircularQueue {
public:
    vector<int> queue;
    int front;
    int rear;
    int current_size;
    int capacity;

    MyCircularQueue(int k) {
        front = 0;
        rear = -1;
        current_size = 0;
        capacity = k;
        queue.resize(capacity);
    }
    
    bool enQueue(int value) {
        if(current_size == capacity) return false;

        rear = (rear+1) % capacity;
        queue[rear] = value;
        current_size++;

        return true;
    }
    
    bool deQueue() {
        if(current_size == 0) return false;
        front = (front + 1) % capacity;
        current_size--;

        return true;
    }
    
    int Front() {
        if(current_size == 0) return -1;
        
        return queue[front];
    }
    
    int Rear() {
        if(current_size == 0) return -1;

        return queue[rear];
    }
    
    bool isEmpty() {
        if(current_size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(current_size == capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */