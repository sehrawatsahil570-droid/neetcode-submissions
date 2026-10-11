 
class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void solve(string input, string output, vector<string>& ans) {
        // Base case
        if (input.empty()) {
            ans.push_back(output);
            return;
        }

        // Get letters corresponding to the first digit
        char digit = input[0];
        string letters = mp[digit];

        // Try every possible letter
        for (int i = 0; i < letters.size(); i++) {
            char ch = letters[i];

            string newInput = input.substr(1);
            string newOutput = output + ch;

            solve(newInput, newOutput, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()) return ans;

        solve(digits, "", ans);

        return ans;
    }
};
