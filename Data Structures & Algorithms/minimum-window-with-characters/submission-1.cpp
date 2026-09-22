class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        // Frequency required from t
        for (char c : t) {
            mp[c]++;
        }

        int l = 0, r = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = -1;

        while (r < s.size()) {

            // If s[r] is needed
            if (mp[s[r]] > 0) {
                count++;
            }

            mp[s[r]]--;
            r++;

            // Window is valid
            while (count == t.size()) {

                // Update minimum answer
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                // Remove s[l]
                mp[s[l]]++;

                if (mp[s[l]] > 0) {
                    count--;
                }

                l++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};