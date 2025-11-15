---
496. Next Greater Element I
Solved

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

---


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> box;

        unordered_map<int,int> map1;
        
        int n = nums2.size();

        for(auto i = 0; i < n; i++){
            while( !box.empty() && nums2[i] > nums2[box.top()] ){
                map1[nums2[box.top()]] = nums2[i];
                box.pop();
            }

            box.push(i);
        }   
        while (!box.empty()) {
            map1[nums2[box.top()]] = -1;
            box.pop();
        }

        vector<int> ans (nums1.size());

        for( auto i = 0; i < ans.size(); i++ ){
            ans[i] = map1[nums1[i]];
        }
        return ans;
    }
};