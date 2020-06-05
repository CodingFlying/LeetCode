#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;      //边界情况不能少
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                if (j > i) {
                    i++;
                    nums[i] = nums[j]; 
                }
            }  
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    Solution s1;
    int a = s1.removeDuplicates(nums);
    cout << a << endl;
}