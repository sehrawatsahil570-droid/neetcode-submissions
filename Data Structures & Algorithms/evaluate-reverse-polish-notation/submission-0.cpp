class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            
            if (isdigit(token[0]) || 
                (token.size() > 1 && token[0] == '-')) {
                
                st.push(stoi(token));
            }

    
            else {
                int y = st.top();
                st.pop();

                int x = st.top();
                st.pop();

                if (token == "+") {
                    st.push(x + y);
                }
                else if (token == "-") {
                    st.push(x - y);
                }
                else if (token == "*") {
                    st.push(x * y);
                }
                else if (token == "/") {
                    st.push(x / y);
                }
            }
        }

        return st.top();
    }
};