class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }

        s2.push(x);
        while(!s2.empty()){
            int x = s2.top();
            s2.pop();
            s1.push(x);
        }
    }
    
    int pop() {
        if(!s1.empty()){
            int x = s1.top();
            s1.pop();

            return x;
        }

        return -1;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(!s1.empty()){
            return false;
        }


        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */