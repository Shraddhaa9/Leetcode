class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto str : tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int result;

                if (str == "+")
                    result = a + b;
                else if (str == "-")
                    result = b - a;
                else if (str == "*")
                    result = a * b;
                else if (str == "/")
                    result = b / a;

                st.push(result);
            } else {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};