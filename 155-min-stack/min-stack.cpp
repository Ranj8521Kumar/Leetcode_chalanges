class MinStack {
    stack<pair<int, int>> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty()){
            minStack.push({val, val});
        }else if(minStack.top().second > val){
            minStack.push({val, val});
        }else{
            minStack.push({val, minStack.top().second});
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */