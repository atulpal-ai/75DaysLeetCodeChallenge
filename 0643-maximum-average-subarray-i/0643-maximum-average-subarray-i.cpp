#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // Step 1: first window sum
        int window_sum = 0;
        for(int i = 0; i < k; i++){
            window_sum += nums[i];
        }
        
        int max_sum = window_sum;
        
        // Step 2: sliding window
        for(int i = k; i < n; i++){
            window_sum += nums[i];
            window_sum -= nums[i - k];
            
            max_sum = max(max_sum, window_sum);
        }
        
        return (double)max_sum / k;
    }
};