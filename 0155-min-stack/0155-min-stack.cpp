class MinStack {
private:
    stack<long long> st;
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        }
        else if (val >= minVal) {
            st.push(val);
        }
        else {
            st.push(2LL * val - minVal);
            minVal = val;
        }
    }

    void pop() {
        long long topVal = st.top();
        st.pop();

        if (topVal < minVal) {
            minVal = 2LL * minVal - topVal;
        }
    }

    int top() {
        if (st.top() < minVal) {
            return static_cast<int>(minVal);
        }
        return static_cast<int>(st.top());
    }

    int getMin() {
        return static_cast<int>(minVal);
    }
};