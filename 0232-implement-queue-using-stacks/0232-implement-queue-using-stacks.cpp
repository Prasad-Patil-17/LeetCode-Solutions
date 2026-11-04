class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {}
    
    void push(int x) {

        if(st.empty()){
            st.push(x);
            return;
        }

        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }

        st.push(x);

        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        int popped_element = st.top();
        st.pop();

        return popped_element;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.size() == 0) return true;

        return false;
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