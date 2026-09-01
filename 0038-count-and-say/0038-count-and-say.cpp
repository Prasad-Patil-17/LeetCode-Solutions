class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";

        string str = countAndSay(n-1);

        string emp_str = "";

        int freq = 1;
        char ch = str[0];

        for(int i=1;i<str.size();i++){
            if(ch == str[i]){
                freq++;
            }
            else{
                emp_str += (to_string(freq) + ch);
                freq = 1;
                ch = str[i];
            }
        }

        emp_str += (to_string(freq) + ch);

        return emp_str;
    }
};