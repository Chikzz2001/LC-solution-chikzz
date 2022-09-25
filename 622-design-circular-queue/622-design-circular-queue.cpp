class MyCircularQueue {
    vector<int>circular_queue;
    int front=0,back=0,size=0,curr=0;
public:
    MyCircularQueue(int k) {
        circular_queue=vector<int>(k,-1);
        size=k;
    }
    
    bool enQueue(int value) {
        if(curr==size)return 0;
        circular_queue[back]=value;
        curr++;
        back=(back+1)%size;
        return 1;
    }
    
    bool deQueue() {
        if(curr==0)return 0;
        circular_queue[front]=-1;
        curr--;
        front=(front+1)%size;
        return 1;
    }
    
    int Front() {
        if(curr==0)return -1;
        return circular_queue[front];
    }
    
    int Rear() {
        if(curr==0)return -1;
        return back==0?circular_queue[size-1]:circular_queue[back-1];
    }
    
    bool isEmpty() {
        return !curr;
    }
    
    bool isFull() {
        return curr==size;
    }
};
//1 2 3 

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