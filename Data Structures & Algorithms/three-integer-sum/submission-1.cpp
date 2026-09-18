class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;                        
            if (i > 0 && nums[i] == nums[i-1]) {
            continue; 
            }
         
            int str = i + 1;
            int end  = n - 1;
            while (str < end) {
                int sum = nums[i] + nums[str] + nums[end];
                if (sum < 0) {
                    str++;}
                else if (sum > 0) {
                    end--;}
                else {
                   ans.push_back({nums[i],
                   nums[str],
                   nums[end]
                   });
                while(str<end && nums[str] == nums[str+1]){
                    str++;

                }
                while(str<end && nums[end] == nums[end-1]){
                    end--;
                }
                str++;
                end--;
                  
            }
        }
    }
        return ans;
    }
};