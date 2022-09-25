class MyCircularQueue {
    
    vector<int>que;
    int total_size, size=0;
    int front = -1, rear = -1;
    
public:
    MyCircularQueue(int k) {
        total_size = k;
        que.resize(total_size);
    }
    
    bool enQueue(int value) {
        
        if(isFull()){
            return false;
        }

        if(isEmpty()){
            front = rear = 0;
            que[rear] = value;
            size++;
            return true;
        }
        
        rear = (rear + 1)%total_size;
        que[rear] = value;
        size++;
        
        return true;
    }
    
    bool deQueue() {
        
        if(isEmpty()){
            return false;
        }
        
        front = (front + 1)%total_size;
        size--;
        
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : que[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : que[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == total_size;
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