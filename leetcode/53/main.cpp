#include <vector>
#include <iostream>
#include <compare>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Se em algum momento for negativo, set a soma em 0, nunca deixe ir para baixo de 0
        // Como número de elementos não importa, e sim a soma deles, deve funcionar.

        int max_value = nums[0];
        int current_value = 0;
        for (auto & num : nums) {
            
            if (current_value < 0) {
                current_value = std::max(current_value+num, num);
            }
            else {
                current_value += num;
            }
            

            if (current_value > max_value) {
                max_value = current_value;
            }

        }

        return max_value;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = sol.maxSubArray(nums);
    cout << "Max subarray sum: " << result << endl;
    return 0;
}