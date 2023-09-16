#include <iostream>
#include <vector>
using std::vector; // allows to use vector without std::vector
#include <unordered_map>
using std::unordered_map;

/* 
https://leetcode.com/problems/two-sum/
Ref: https://www.youtube.com/watch?v=BlliTRJlsnI&list=PLPERBdDHWLi1x0ZxbnCd5t8yxEudSrxxH&index=1

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

/*
DSA algorithm
We use a hash table to store the complement.
We iterate each element in the array.
Check if the complement value exists in the hash table.
If the element and the complement add up to the target and exists, we have found a pair which sums up to the target.

Complement: Target - Current element in array
*/

class Solution {
public: // allows members to be accessed outside of class
    vector<int> twoSum(vector<int>& nums, int target) {
        // initialize a hash table
        unordered_map<int, int> hashTable; // key(element) and value(index)

        for (int i=0; i <nums.size(); i++) { // start, end, step
            int complement = target - nums[i]; // complement
            
            // if the complement exists in the hash table
            if (hashTable.count(complement)) {
                // return a vector {index of complement, current element index}
                return {hashTable[complement], i};
            }
            
            // if the complement does not exist in the hash table,
            // add key (current element) and value (current element index) to hash table.
            hashTable[nums[i]] = i;
        }
        return {}; // return empty vector if no solution
    }
};
