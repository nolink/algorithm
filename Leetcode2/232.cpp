class Queue {
private:
    stack<int> first;
    stack<int> second;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(first.empty()){
            first.push(x);
        }else{
            second.push(x);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        first.pop();
        if(first.empty()){
            while(!second.empty()){
                first.push(second.top());
                second.pop();
            }
        }
    }

    // Get the front element.
    int peek(void) {
        return first.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return first.empty();
    }
};
