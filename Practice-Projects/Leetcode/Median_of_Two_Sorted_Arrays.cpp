#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        int i = 0;
        double sum = 0;
        int temp = 0;
        vector<int> combined_arrays;
        int n = nums1.size();
        int m = nums2.size();

        while(i < n+m){
            if(p1 > n-1){
                break;
            }
            if(p2 > m-1){
                break;
            }

            if (nums1[p1] > nums2[p2]){
                combined_arrays.emplace_back(nums2[p2]);
                p2++;
            }
            else{
                combined_arrays.emplace_back(nums1[p1]);
                p1++;
            }
            i++;   
        }  

        while(p2 < m){
            combined_arrays.emplace_back(nums2[p2]);
            p2++;
        }

        while(p1 < n){
            combined_arrays.emplace_back(nums1[p1]);
            p1++;
        }

        if ((n+m-1)%2 == 0){
            return combined_arrays[(n+m-1)/2];
        }
        else{
            temp = (n+m-1)/2;
            sum = combined_arrays[temp];
            sum += combined_arrays[temp + 1];
            sum /= 2;
            return sum;
        }
    }
};

int main(){
    Solution obj;
    vector<int> nums1 = {3, 4, 6, 7, 8};
    vector<int> nums2 = {1, 2, 3};
    double ans = 0;
    ans = obj.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
    return 0;
}