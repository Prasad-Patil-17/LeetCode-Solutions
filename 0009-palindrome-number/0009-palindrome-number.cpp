class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0) return false;
        int temp = x;

        int last_dig = 0;
        long long rev_num = 0;

        while(temp != 0){
            last_dig = temp % 10;
            rev_num = rev_num*10 + last_dig;
            temp = temp / 10;
        }

        if(rev_num == x) return true;
        
        return false;
    }
};