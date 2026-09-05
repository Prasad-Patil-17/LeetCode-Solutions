class Solution {
public:
    bool is_perfect_sq(int num){
        int sq_root = sqrt(num);
        if(sq_root * sq_root == num) return true;
        else return false;
    }

    bool judgeSquareSum(int c) {

        //if we consider num1 = 0 = a^2
        //then c = b^2

        int num1 = 0;
        int num2 = c;

        while(num1 <= num2){

            if(is_perfect_sq(num1) && is_perfect_sq(num2)) return true;
            else if(!is_perfect_sq(num2)){

                //move num2 to its previous perfect sqaure
                num2 = (int)sqrt(num2) * (int)sqrt(num2);
                num1 = c - num2; //remaining left_part must belong to num1
            }
            else{
                //move num1 to its next prefect square
                num1 = ((int)sqrt(num1)+1)*((int)sqrt(num1)+1);
                num2 = c - num1;//remaining left_part must belong to num2
            }
        }

        return false;
    }
};