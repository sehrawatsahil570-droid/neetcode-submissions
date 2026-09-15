class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // 1. Count frequency
        for (int num : nums) {
            mp[num]++;
        }

        // 2. Store {frequency, element}
        vector<pair<int, int>> v;

        for (auto it : mp) {
            v.push_back({it.second, it.first});
        }

        // 3. Sort by frequency
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        // 4. Take first k elements
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};