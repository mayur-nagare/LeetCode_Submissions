class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> high;
    priority_queue<int, vector<int>, greater<int>> low;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(high.empty() || high.top() > num)
            high.push(num);
        else
            low.push(num);
        
        if(high.size()>low.size()+1){
            low.push(high.top());
            high.pop();
        }
        else if(low.size()>high.size()+1){
            high.push(low.top());
            low.pop();
        }
    }
    
    double findMedian() {
        if(high.size() == low.size())
            return (double)((double)high.top() + (double)low.top())/2.0;
        
        if(high.size() > low.size()) return (double)(high.top());
        else return (double)(low.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */