class Solution {
public:
    int hammingWeight(int n) {
        int rem = 0;
        int sum = 0;
        while(n !=0){
            rem = n%2;
            sum = sum+rem;
            n = n/2;
        }
        return sum;
        
    }
};