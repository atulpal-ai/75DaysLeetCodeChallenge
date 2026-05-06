#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int currentSum = 0;
        int count = 0;
        
        for(int num : nums){
            
            currentSum += num;
            
            if(mp.find(currentSum - k) != mp.end()){
                count += mp[currentSum - k];
            }
            
            mp[currentSum]++;
        }
        
        return count;
    }
};