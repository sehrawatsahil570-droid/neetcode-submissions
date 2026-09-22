class Solution {
public:

    int findMax(vector<int>& v) {
        int maxi = INT_MIN;

        for(int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }

    int calculateTotalHours(vector<int>& v, int hourly) {
        int totalH = 0;
        int n = v.size();

        for(int i = 0; i < n; i++) {
            totalH += ceil((double)v[i] / hourly);
        }

        return totalH;  }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int totalH = calculateTotalHours(piles, mid);

            if(totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;     
    }
};