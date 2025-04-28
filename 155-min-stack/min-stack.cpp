class MinStack {
private:
    stack<int> st;
    stack<int> ss;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (ss.empty() || val <= ss.top()) {
            ss.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }
        int ans = st.top();
        st.pop();
        if (ans == ss.top()) {
            ss.pop();
        }
    }
    
    int top() {
        if (st.empty()) return 0;
        return st.top();
    }
    
    int getMin() {
        if (!ss.empty()) {
            return ss.top();
        }
        return 0;
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