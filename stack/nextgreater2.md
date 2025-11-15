---
503. Next Greater Element II
Solved
Medium

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

---
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         vector<int> ans (nums.size() ,-1);

        stack<int> box;

        int n = nums.size();

        for(int i = n-1; i>=0; i--){
            while(!box.empty() && nums[i] >= box.top()){
                box.pop();
            }
            
            box.push(nums[i]);
        }

         for(int i = n-1; i>=0; i--){

            while(!box.empty() && nums[i] >= box.top()){
                box.pop();
            }
            if(!box.empty()){
                ans[i] = box.top();
            }
            
            box.push(nums[i]);
        }
        return ans;
    }
};