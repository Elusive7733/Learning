#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int tar){
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == tar){
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }  
        }
        return {};  
    }
};


int main(){
    Solution obj;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans;
    ans = obj.twoSum(nums, 9);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}