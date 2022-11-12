class MedianFinder {
    priority_queue<int>minHeap,maxHeap;
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(minHeap.size()<maxHeap.size())
            minHeap.push(-num);
        else
            maxHeap.push(num);
        
        if(minHeap.empty()||maxHeap.empty())return;
        
        if(-minHeap.top()<maxHeap.top())
        {
            int top1=-minHeap.top();minHeap.pop();
            int top2=maxHeap.top();maxHeap.pop();
            minHeap.push(-top2);
            maxHeap.push(top1);
        }
    }
    
    double findMedian() 
    {
        if((maxHeap.size()+minHeap.size())&1)
            return maxHeap.top();
        else
        {
            double res=0;
            res+=maxHeap.top();
            res-=minHeap.top();
            return res/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */