/* 
Given an array of integer of length N find the longest subarray having sum k
N = 10^5
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai(vector<ll> &arr, vector<ll> &pref, ll n, ll k, ll mid){
    ll sp = 1, ep = mid;
    while(ep<=n){
        ll sum = pref[ep]-pref[sp-1];
        if(sum<=k) return true;
        sp++;
        ep++;
    }
    return false;
}

int main(){

    ll n; 
    cin>>n;

    vector<ll> arr(n+1, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    ll mid, k;
    cin>>mid>>k;
    cout<<kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai(arr, pref, n, k, mid)<<endl;

}

/*
mujhe yaha check karna hai ki kya koi aisa subarray exist karta hai jiska length ka prefixSum less than or equal to k hai.

mid bta rha hai ki kitna length ki window hai ya banegi 

r - l + 1 = mid;
l = r - mid + 1;
*/


/*
Explanation of the code:

1. The code checks whether there exists a subarray of a given length whose sum is less than or equal to a specified value.

2. The function `kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai` takes the following parameters:
   - `arr`: A vector containing the array elements.
   - `pref`: A vector containing prefix sums of the array elements.
   - `n`: The size of the array.
   - `k`: The target sum value.
   - `mid`: The length of the subarray to check.

3. The function uses a sliding window approach to iterate through the array and check subarrays of length `mid`.

4. Inside the function, the sliding window is initialized with `sp = 1` (start of the window) and `ep = mid` (end of the window).

5. The function calculates the sum of the subarray using the prefix sums `pref` to efficiently calculate subarray sums.

6. If the sum is less than or equal to `k`, the function returns `true`, indicating that such a subarray exists.

7. If the sum exceeds `k`, the sliding window is moved forward by incrementing `sp` and `ep` to consider the next subarray.

8. The process continues until all subarrays of length `mid` have been checked. If no subarray is found within the loop, the function returns `false`.

9. In the `main()` function:
   - The size of the array, `n`, is read from the input.
   - A vector `arr` is created to store the array elements.
   - The array elements are read from the input.
   - A vector `pref` is created to store the prefix sums of the array elements.
   - The prefix sums are calculated using a loop.
   - The values of `mid` and `k` are read from the input.
   - The function `kyaMlengthKiSubarrayExistKartiHaiJiskaSumLessThanEqualToKHai` is called with the appropriate arguments.
   - The result is printed, indicating whether a subarray of length `mid` with a sum less than or equal to `k` exists.
*/