class Solution {
public:
    void push_valid_parentheses(vector<string>& all_valid_parentheses,string emp_str,int open,int close,int n){

        if(close == n){
            all_valid_parentheses.push_back(emp_str);
            return;
        }

        if(open < n) push_valid_parentheses(all_valid_parentheses,emp_str + '(',open+1,close,n);
        if(close < open) push_valid_parentheses(all_valid_parentheses,emp_str + ')',open,close+1,n);

    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> all_valid_parentheses;

        string emp_str = "";
        push_valid_parentheses(all_valid_parentheses,emp_str,0,0,n);

        return all_valid_parentheses;
    }
};