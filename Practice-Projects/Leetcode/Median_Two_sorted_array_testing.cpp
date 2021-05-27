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
        vector<int> combined_arrays;
        int n = nums1.size();
        int m = nums2.size();

        cout << n << endl;
        cout << m << endl;
        // merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), combined_arrays.begin());

        while(i < n+m){
            if(p1 > n-1){
                break;
            }
            if(p2 > m-1){
                break;
            }

            if (nums1[p1] > nums2[p2]){

                cout << endl;
                cout << "placing: " << nums2[p2] << " from nums2....p2 = " << p2 << endl;

                combined_arrays.emplace_back(nums2[p2]);
                p2++;

                cout << "combined array till now (in if): " << endl;
                for (int i = 0; i < combined_arrays.size(); i++) { cout << combined_arrays[i] << " "; }
                cout << endl;
                system("pause");  
            }
            else{

                cout << endl;
                cout << "placing: " << nums1[p1] << " from nums1....p1 = " << p1 << endl;

                combined_arrays.emplace_back(nums1[p1]);
                p1++;

                cout << "combined array till now (in else): " << endl;
                for (int i = 0; i < combined_arrays.size(); i++) { cout << combined_arrays[i] << " "; }
                cout << endl;
                system("pause");  
            }
            i++;   
        }

        cout << endl;
        cout << "combined array till now (first while): " << endl;
        for (int i = 0; i < combined_arrays.size(); i++) { cout << combined_arrays[i] << " "; }
        cout << endl;
        system("pause");  

        while(p2 < m){
            combined_arrays.emplace_back(nums2[p2]);
            p2++;
        }

        cout << endl;
        cout << "combined array till now (second while): " << endl;
        for (int i = 0; i < combined_arrays.size(); i++) { cout << combined_arrays[i] << " "; }
        cout << endl;
        system("pause");

        while(p1 < n){
            combined_arrays.emplace_back(nums1[p1]);
            p1++;
        }


        // fflush(stdout);
        // cout << "tf2" << endl;
        // for (int i = 0; i < nums1.size(); i++) { cout << nums1[i] << " "; } 
        // cout << endl;
        // for (int i = 0; i < nums2.size(); i++) { cout << nums2[i] << " "; }  
        // cout << endl; 
        cout << endl;
        cout << endl;
        cout << endl;
        for (int i = 0; i < combined_arrays.size(); i++) { cout << combined_arrays[i] << " "; }  
        cout << endl;
        return 0;
    }
};

int main(){
    Solution obj;
    vector<int> nums1 = {1, 2, 9, 11, 16, 33, 75, 123};
    vector<int> nums2 = {3, 6, 25, 155};
    cout << "5: " << nums1[5] << endl;
    cout << "6: " << nums1[6] << endl;
    double ans = 0;
    ans = obj.findMedianSortedArrays(nums1, nums2);
    // cout << ans << endl;
    return 0;
}