class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        // Always binary search the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int l = 0;
        int r = n;

        int total = n + m;
        int leftSize = (total + 1) / 2;

        while (l <= r) {

            int cut1 = l + (r - l) / 2;
            int cut2 = leftSize - cut1;

            // Elements immediately around partition
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd number of elements
                if (total % 2 == 1) {
                    return max(left1, left2);
                }

                // Even number of elements
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // We took too many elements from nums1
            else if (left1 > right2) {
                r = cut1 - 1;
            }

            // We took too few elements from nums1
            else {
                l = cut1 + 1;
            }
        }

        return 0.0;
    }
};