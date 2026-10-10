
class Solution {
public:
    set<vector<int>> st;

    void solve(vector<int>& ip, vector<int>& op) {
        if (ip.empty()) {
            st.insert(op);
            return;
        }

        int x = ip[0];

        
        op.push_back(x);
        ip.erase(ip.begin());

        solve(ip, op);

        
        ip.insert(ip.begin(), x);
        op.pop_back();

     
        ip.erase(ip.begin());

        solve(ip, op);

        
        ip.insert(ip.begin(), x);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ip = nums;
        vector<int> op;

        st.clear();
        solve(ip, op);

        return vector<vector<int>>(st.begin(), st.end());
    }
};
