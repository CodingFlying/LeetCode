#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n-1];
                n--;
            }
            else {
                i++;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    Solution s1;
    int a = s1.removeElement(nums, 3);
    cout << a << endl;
}