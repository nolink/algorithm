class MinStack {
private:
    vector<int> s;
    list<int> minIndex;
    int size;
    int capacity;
public:
    /** initialize your data structure here. */
    MinStack() {
        size = 0;
        capacity = 16;
        s.resize(capacity);
    }
    
    void push(int x) {
        if(size == capacity){
            capacity *= 2;
            s.resize(capacity);
        }
        int minimum = getMin();
        if(x < minimum){
            minIndex.push_back(size);
        }
        s[size++] = x;
    }
    
    void pop() {
        if(minIndex.back() == size - 1) minIndex.pop_back();
        size--;
    }
    
    int top() {
        return s[size - 1];
    }
    
    int getMin() {
        if(size == 0 || minIndex.back() >= size) return INT_MAX;
        return s[minIndex.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
