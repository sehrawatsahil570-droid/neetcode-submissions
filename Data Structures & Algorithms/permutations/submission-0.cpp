
class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& ip, vector<int>& op) {
        if (ip.empty()) {
            ans.push_back(op);
            return;
        }

        for (int i = 0; i < ip.size(); i++) {
            int x = ip[i];

            op.push_back(x);
            ip.erase(ip.begin() + i);

            solve(ip, op);

            ip.insert(ip.begin() + i, x);
            op.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ip = nums;
        vector<int> op;

        solve(ip, op);
        return ans;
    }
};
