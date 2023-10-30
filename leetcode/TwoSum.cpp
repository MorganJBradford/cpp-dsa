#include <iostream>
#include <unordered_map>
#include <vector>
#include "../Timer.cpp"

class Solution {
    public:
        std::vector<int> twoSumBrute(std::vector<int>& nums, int target) {
            // std::vector<int> testCase = {2, 7, 11, 15};
            std::cout << "Brute: " << std::endl;
            Timer timer;
            for (int i = 0; i < nums.size() - 1; ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (nums[i] + nums[j] == target) {
                        std::cout << "i: " << i << " j: " << j << std::endl;
                        return {i, j};
                    }
                }
            }

            return {};
        }

        std::vector<int> twoSumTwoPassHash(std::vector<int>& nums, int target) {
            // std::vector<int> testCase = {2, 7, 11, 15};
            std::cout << "Two Pass: " << std::endl;
            Timer timer;
            std::unordered_map<int, int> numMap;

            for (int i = 0; i < nums.size(); ++i) {
                numMap[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];

                if (numMap.count(complement) && numMap[complement] != i) {
                    std::cout << "i: " << i << " numMap[complement]: " << numMap[complement] << std::endl;
                    return {i, numMap[complement]};
                }
            }
            return {};
        }


        std::vector<int> twoSumOnePassHash(std::vector<int>& nums, int target) {
            // std::vector<int> testCase = {2, 7, 11, 15};
            std::cout << "One Pass: " << std::endl;
            Timer timer;
            std::unordered_map<int, int> numMap;

            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];

                if (numMap.find(complement) != numMap.end()) {
                    std::cout << "numMap[comlement]: " << numMap[complement] << " i : " << i << std::endl;
                    return {numMap[complement], i};
                }

                numMap[nums[i]] = i;
            }
            return {};
        }
};


int main()
{
    std::vector<int> testCase = {2, 7, 11, 15};
    int target = 13;
    Solution solution;
    solution.twoSumBrute(testCase, target);
    solution.twoSumTwoPassHash(testCase, target);
    solution.twoSumOnePassHash(testCase, target);
    std::cin.get();
    return 0;
}
