class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        int n = arr.size();

        bool visited[1001] = {false};

        int freq[1001];
        int freqCount = 0;

        // Frequency count
        for (int i = 0; i < n; i++) {

            if (visited[i])
                continue;

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (arr[j] == arr[i]) {
                    count++;
                    visited[j] = true;
                }
            }

            freq[freqCount] = count;
            freqCount++;
        }

        // Check duplicate frequencies
        for (int i = 0; i < freqCount; i++) {

            for (int j = i + 1; j < freqCount; j++) {

                if (freq[i] == freq[j]) {
                    return false;
                }
            }
        }

        return true;
    }
};