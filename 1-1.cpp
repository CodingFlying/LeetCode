#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {    //暴力法
        int i, j;
        for (i = 0; i < nums.size() - 1; i++) {
            for (j = 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return { };    
    }

    vector<int> twoSum1(vector<int>& nums, int target) {   //两遍哈希表
        map<int, int> a;    //
        vector<int> b(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            a.insert(map<int, int> :: value_type(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            if(a.count(target - nums[i]) > 0 && a[target - nums[i]] != i) {
                 //判断是否找到目标元素且目标元素不能是本身
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        }
        return b;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {   //一遍哈希表
        map<int, int> a;
        vector<int> b(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i])) {
                b[0] = a[target - nums[i]];
                b[1] = i;
                break;
            }
            else {
                a[nums[i]] = i;
            }
        }
        return b;
    }

};

int main() {
    vector<int> nums = {3, 4, 5, 8};
    Solution s1;
    vector<int> b = s1.twoSum2(nums, 12);
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
}