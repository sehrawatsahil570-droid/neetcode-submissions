class Solution {
public:
    vector<vector<int>> ans;
    vector <int> temp;
    void solve (int index, vector<int>& nums,int target){
        int n = nums.size();
        if (target == 0 ){
            ans.push_back(temp);
            return;
        
        }
        if (target < 0){
            return ;
        }
        for (int i = index ; i < n ; i++){
            temp.push_back(nums[i]);
            solve ( i, nums ,target - nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve (0, nums , target);
        return ans;
    }
};
  