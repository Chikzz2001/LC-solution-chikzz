class MyCircularQueue {

List <Integer> queue;
 int ind=0;
 int size=0;

public MyCircularQueue(int k) {
    queue=new ArrayList<>();
    size=k;
}

public boolean enQueue(int value) {
    if(ind < size)
    {
        queue.add(value);
        ind++;
        System.out.println(ind);
        return true;
    }
    return false;
    
}

public boolean deQueue() {
    if(queue.size()!=0)
    {
        queue.remove(0);
        ind--;
        return true;
    }
    return false;
        
}

public int Front() {
    if(queue.size()==0)
        return -1;
    else return queue.get(0);
}

public int Rear() {
    System.out.println(ind);
    int rear=ind-1;
    if(queue.size()==0)
        return -1;
    else return queue.get(rear);
}

public boolean isEmpty() {
    if(ind==0)
        return true;
    else
        return false;
}

public boolean isFull() {
    if(ind==size)
        return true;
    else
        return false;
}
}