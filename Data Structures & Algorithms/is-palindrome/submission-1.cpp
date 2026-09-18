class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        // Put all elements into set
        for (int num : nums) {
            s.insert(num);
        }

        int longest = 0;

        for (int num : s) {

            // num is the starting point
            if (s.count(num - 1) == 0) {

                int current = num;
                int length = 1;

                // Keep checking next consecutive numbers
                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};