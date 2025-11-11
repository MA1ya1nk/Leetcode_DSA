class MedianFinder {
public:
    priority_queue<int> lowerHalf; // max-heap
    priority_queue<int, vector<int>, greater<int>> upperHalf; // min-heap

    MedianFinder() { }
    
    void addNum(int num) {
        if (lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
        } else {
            upperHalf.push(num);
        }

        // Balance the heaps
        if (lowerHalf.size() > upperHalf.size() + 1) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } 
        else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }
    
    double findMedian() {
        if (lowerHalf.size() > upperHalf.size()) {
            return lowerHalf.top();
        } else {
            return (lowerHalf.top() + upperHalf.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */