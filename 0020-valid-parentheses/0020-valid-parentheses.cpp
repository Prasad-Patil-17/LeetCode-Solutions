class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        st.push(s[0]);

        if(s.length() % 2 != 0) return false;
        
        for(int i=1;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                else{
                    if(s[i] == ')' && st.top() == '(' || 
                    s[i] == ']' && st.top() == '[' || 
                    s[i] == '}' && st.top() == '{') st.pop();
                    else st.push(s[i]);
                }
            }
        }

        if(st.empty()) return true;

        return false;
    }
};