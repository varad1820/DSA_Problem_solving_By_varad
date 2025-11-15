---
739. Daily Temperatures
Solved
Medium
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

---

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> box;

        vector<int> ans(temp.size(),0);

        for(int i = 0; i < temp.size(); i++){
            while(!box.empty() && temp[i] > temp[box.top()]){
                int idx = box.top(); 
                box.pop();
                ans[idx] = i - idx; 
            }
            box.push(i);
        }

        return ans;
    }
};