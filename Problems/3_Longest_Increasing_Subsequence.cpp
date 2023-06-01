// LIS --> Longest incresing subsequence --> jo increasin

// subarray --> which is continuous element
// subsequences --> non continuous part of the array in

// 2 length ki jitni bhi increasing subsequence uski ending element minimum ho --> aisa ek array create karo
// 2->ax->x 3->aby->y
// x > y
// then 2->ay 3->ab
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> min_ending_element(n + 1, 2e9);
    min_ending_element[0] = -2e9;

    for (auto itr : nums) {
        int lo = 0, hi = n, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (min_ending_element[mid] < itr) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        min_ending_element[ans + 1] = itr;
    }

    for (int i = n; i >= 0; i--) {
        if (min_ending_element[i] != 2e9) {
            return i;
        }
    }
    return 0;
}

int main() {
    ll n;
    cin >> n;
    vector<int> arr(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = lengthOfLIS(arr);
    cout << ans;

    return 0;
}
