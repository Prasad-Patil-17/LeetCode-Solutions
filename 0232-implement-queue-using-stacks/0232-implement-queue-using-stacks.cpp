class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue(){}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        
        //empty st into helper;
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }

        int front_element = helper.top();
        helper.pop();

        //empty hlper into the st;
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }

        return front_element;
    }
    
    int peek() {
        //empty st into helper;
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }

        int front_element = helper.top();

        //empty hlper into the st;
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }

        return front_element;
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