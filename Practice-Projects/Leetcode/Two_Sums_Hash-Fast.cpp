#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int tar){
        
        vector<int> temp;
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
           umap[nums[i]] = i; 
        }    

        for(int i = 0; i < nums.size(); i++){
            if(umap[tar-nums[i]] != 0x0 && umap[tar-nums[i]] != i){
                cout << "in here at: " << i << endl;
                temp.push_back(i);
                temp.push_back(umap[tar-nums[i]]);
                return temp;
            }
        }
        throw invalid_argument("No solution");
    }
};


int main(){
    Solution obj;
    vector<int> nums = {591,955,829,805,312,83,764,841,12,744,104,773,627,306,731,539,349,811,662,341,465,300,491,423,569,405,508,802,500,747,689,506,129,325,918,606,918,370,623,905,321,670,879,607,140,543,997,530,356,446,444,184,787,199,614,685,778,929,819,612,737,344,471,645,726};
    vector<int> ans;
    ans = obj.twoSum(nums, 789);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}