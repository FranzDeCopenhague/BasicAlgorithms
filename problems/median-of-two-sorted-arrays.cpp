// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArray(const vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        if (1 == nums.size() % 2) {
            auto k = nums.size() / 2;
            return nums[k];
        }
        auto k2 = nums.size() / 2;
        auto k1 = k2-1;
        return (nums[k1]+nums[k2]) / 2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // empty vectors
        if (nums1.empty()) {
            return findMedianSortedArray(nums2);
        }
        if (nums2.empty()) {
            return findMedianSortedArray(nums1);
        }

        auto size = nums1.size() + nums2.size();
        int toCount = (size / 2)+1;

        int v1 = *nums1.end();
        int v2 = *nums2.end();

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        auto has1 = it1 != nums1.end();
        auto has2 = it2 != nums2.end();
        while ( --toCount >= 0 && ( has1 || has2)) {
            v1 = v2;
            if (has1 && has2) {
                if (*it2 < *it1) {
                    v2 = *it2;
                    ++it2;
                } else {
                    v2 = *it1;
                    ++it1;
                }
            } else {
                if (has1) {
                    v2 = *it1;
                    ++it1;
                } else {
                    v2 = *it2;
                    ++ it2;
                }
            }
            has1 = (it1 != nums1.end());
            has2 = (it2 != nums2.end());
        }

        return (1 == size % 2) ? v2 : (v1+v2) / 2.0;
    }
};
