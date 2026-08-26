class MyCircularQueue {
    private:
     int *arr;
     int size;
     int rear;
     int front;

public:
 
    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        rear=-1;
        front=-1;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            if(front == -1) front = 0; 
            rear=(rear+1)%size;
            arr[rear]=value;
            return true;
        }
        else{
            return false;
        }
    }
    
   bool deQueue() {
    if(isEmpty()) return false;

    if(front == rear) {
        // last element removed
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
    return true;
}

    
    int Front() {
        if(!isEmpty()){
           
            return arr[front];
        }
        else{
            
            return -1;
        }
    }
    
    int Rear() {
        if(!isEmpty()){
        
           return arr[rear];
        }
        else{
            return -1;
        }
        
    }
    
    bool isEmpty() {
        if(front!=-1){
        
           return false;
        }
        else{
            return true;
        }
    }
    
    bool isFull() {
        if(front == (rear + 1) % size){
            return true;
        }
        else{
            return false;
        }
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