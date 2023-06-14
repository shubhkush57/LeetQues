class MedianFinder {
public:
    int n = 0;
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        n = n+1;
        if(minHeap.size() == maxHeap.size()){
            if(minHeap.empty() || minHeap.top()<=num){
                // it means maxHeap is also empty();
                // cout<<"min"<<endl;
                minHeap.push(num);
            }
            else{
                // cout<<"max"<<endl;
                maxHeap.push(num);
            }
        }
        else if(minHeap.size()>maxHeap.size()){
            if(minHeap.top()<=num){
                // cout<<"min"<<endl;
                int t = minHeap.top();minHeap.pop();
                maxHeap.push(t); minHeap.push(num);
            }
            else{
                // cout<<"max"<<endl;
                maxHeap.push(num);
            }
                
               
        }
        else{
            if(maxHeap.top() >= num){
                int t = maxHeap.top();
                maxHeap.pop();
                
               // cout<<"max"<<endl;
                maxHeap.push(num); minHeap.push(t);
            }
            else{
                // cout<<"min"<<endl;
                minHeap.push(num);
            }
            
        }
        return;
    }
    
    double findMedian() {
        if(n%2 == 1){
            if(maxHeap.size()>minHeap.size()){
                return maxHeap.top();
            }
            else{
               return minHeap.top();
            }
        }
            int t1 = minHeap.top();
            int t2 = maxHeap.top();
            return ((double)t1+t2)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */