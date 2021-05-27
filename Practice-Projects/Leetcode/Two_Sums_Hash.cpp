// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]
 
// Constraints:

// 2 <= nums.length <= 103
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.


#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class node{
public:
    int value, index;
    node *next;
    node(int val = 0, int in = 0){
		next = NULL;
        value = val;
        index = in;
	}

};

class Solution{
public:
    node* hash_table[10] = {NULL};
    int hash(int key){
        return (abs(key)%10);
    }
    vector<int> twoSum(vector<int> &nums, int tar){
        int key;
        vector<int> temp;
        node* ptr;
        node* ptr1;

        //loop for storing value and index pairs in the hash_table.
        for(int i = 0; i < nums.size(); i++){
            key = hash(nums[i]);
            if(hash_table[key] == NULL){
                hash_table[key] = new node(nums[i], i);
            }
            else{
                ptr = hash_table[key];
                while(ptr->next != NULL){ //Used Chaining
                    ptr = ptr->next; 
                }
                ptr->next = new node(nums[i], i); //Places in the next available spot
            }
        }    

        //loop used for calculation  
        for(int i = 0; i < nums.size(); i++){
            key = hash(tar-nums[i]);
            if(hash_table[key] != NULL){
                if(hash_table[key]->value == nums[i] && hash_table[key]->next == NULL){
                    continue; //so no same values are used
                }
                else{
                    if(hash_table[key]->next == NULL){
                        if(nums[i] + hash_table[key]->value == tar){
                            temp.push_back(i);
                            temp.push_back(hash_table[key]->index);
                            return temp;
                        }
                    }
                    else{
                        ptr = hash_table[key];
                        while(ptr != NULL){
                            ptr1 = ptr->next;
                            while(ptr1 != NULL){
                                if(ptr->value + ptr1->value == tar){
                                    temp.push_back(ptr->index);
                                    temp.push_back(ptr1->index);
                                    return temp;
                                }

                                ptr1 = ptr1->next;
                            }
                            ptr = ptr->next;
                        }
                    }
                }
            }
        }
        throw invalid_argument("No solution");
    }
};


int main(){
    Solution obj;
    // vector<int> nums = {591,955,829,805,312,83,764,841,12,744,104,773,627,306,731,539,349,811,662,341,465,300,491,423,569,405,508,802,500,747,689,506,129,325,918,606,918,370,623,905,321,670,879,607,140,543,997,530,356,446,444,184,787,199,614,685,778,929,819,612,737,344,471,645,726};
    vector<int> nums = {3,3};
    // vector<int> nums = {3,2,4};
    // vector<int> nums = {2,7,11,15};
    vector<int> ans;
    ans = obj.twoSum(nums, 6);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}