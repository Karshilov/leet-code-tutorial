class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int sz1 = nums1.size();
        const int sz2 = nums2.size();
        if (sz1 == 0 || sz2 == 0) {
            if (sz1 == 0) {
                if (sz2 & 1) {
                    return nums2[sz2 / 2];
                }
                return ((nums2[sz2 / 2] + nums2[sz2 / 2 - 1]) / 2.);
            }
            else {
                if (sz1 & 1) {
                    return nums1[sz1 / 2];
                }
                return ((nums1[sz1 / 2] + nums1[sz1 / 2 - 1]) / 2.);
            }
        }
        const int total = sz1 + sz2;
        int a[sz1], b[sz2], c[sz1 + sz2];
        for (int i = 0; i < sz1; i++) a[i] = nums1[i];
        for (int i = 0; i < sz2; i++) b[i] = nums2[i];
        merge(a, a + sz1, b, b + sz2, c);
        if (total & 1) {
            return c[total / 2];
        }
        return ((c[total / 2] + c[total / 2 - 1]) / 2.);
    }
};