class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;

        if(k % 2 == 0){
            int prev_ans = kthGrammar(n-1,k/2);
            if(prev_ans == 0) return 1;
            else return 0;
        }
        else{
            int prev_ans = kthGrammar(n-1,k/2+1);
            return prev_ans;
        }
    }
};