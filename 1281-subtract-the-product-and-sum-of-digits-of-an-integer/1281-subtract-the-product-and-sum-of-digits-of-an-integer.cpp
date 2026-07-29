class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int last_digit = 0;
        while(n>0){
            last_digit = n%10;
            product = product*last_digit;
            sum = sum+last_digit;
            n = n/10;
        }
        int Result = product - sum;
        return Result;
    }
};