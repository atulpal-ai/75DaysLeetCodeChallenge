#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
        // Step 1: Frequency count
        for(int num : nums){
            mp[num]++;
        }
        
        // Min Heap (pair: frequency, element)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Step 2: Push into heap
        for(auto it : mp){
            pq.push({it.second, it.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        // Step 3: Extract result
        vector<int> result;
        
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};