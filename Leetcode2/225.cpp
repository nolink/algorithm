class Stack {
private:
    bool usingFirst;
    queue<int> first;
    queue<int> second;
public:
    Stack(){
        usingFirst = true;
    }
    // Push element x onto stack.
    void push(int x) {
        if(usingFirst){
            second.push(x);
            while(!first.empty()){
                second.push(first.front());
                first.pop();
            }
        }else{
            first.push(x);
             while(!second.empty()){
                first.push(second.front());
                second.pop();
            }
        }
        usingFirst = !usingFirst;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(usingFirst) first.pop();
        else second.pop();
    }

    // Get the top element.
    int top() {
        return usingFirst ? first.front() : second.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return first.empty() && second.empty();
    }
};
