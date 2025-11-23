// class MyQueue {
// public:
//     MyQueue() {
    
//     }

//     stack<int> st1;
//     stack<int> st2;
    
//     void push(int x) {
//         while(!st1.empty()){
//             int it = st1.top(); st1.pop();
//             st2.push(it);
//         }

//         st1.push(x);

//         while(!st2.empty()){
//             int it = st2.top(); st2.pop();
//             st1.push(it);
//         }
//     }
    
//     int pop() {
//         int x = st1.top();
//         st1.pop();

//         return x;
//     }
    
//     int peek() {
//         return st1.top();
//     }
    
//     bool empty() {
//         if(st1.empty()){
//             return true;
//         }

//         return false;
//     }
// };



// Follow Up, Part, Push is to st1 and pop is from st2
class MyQueue {
public:
    MyQueue() {
    
    }

    stack<int> st1;
    stack<int> st2;
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        int x = st2.top();
        st2.pop();

        return x;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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













// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */