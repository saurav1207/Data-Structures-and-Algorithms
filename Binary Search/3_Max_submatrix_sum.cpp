// HackerRank Intern Laterview Problem - Round - 1;
// Hame Find karna hai --> Maximum square matrix
// Square submatrix jiska sum <= k 
// (x,y) length = 2 --> end point --> fix
// (x-l+1, y-l+1)  --> start point 
// iska prefixSum nikalwnenge


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool kyaKoiSubmatrixJiskiLengthAndBreadthMidHoAndUskaSumLessThanEqualToKHai(vector<vector<ll>> &pref, ll n, ll m, ll mid, ll k){
    for(ll x2=1;x2<=n;x2++){
        for(ll y2=1;y2<=m;y2++){
            ll x1 = x2-mid+1;
            ll y1 = y2-mid+1;
            if(x1<=0 or y1<=0) continue;
            ll sum = pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
            if(sum<=k) return true;
        }
    }
    return false;
}

int main(){

    ll n, m, k; cin>>n>>m>>k;
    vector<vector<ll>> arr(n+1, vector<ll>(m+1, 0));
    vector<vector<ll>> pref(n+1, vector<ll>(m+1, 0));

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>arr[i][j];
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
        }
    }

    ll lo = 0, hi = min(n, m), ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(kyaKoiSubmatrixJiskiLengthAndBreadthMidHoAndUskaSumLessThanEqualToKHai(pref, n, m, mid, k)){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout<<ans*ans<<endl;
}

/*
4 4 10
1 2 1 2 1 2 1 2 1 1 1 1 2 2 3 2
4
*/


/*
Input:
4 4 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Output:
4


Explanation:
In this example, we have a matrix of size 4x4 with the given elements. The target sum is 15.

The code first calculates the prefix sums of the matrix using the 2D vector `pref`.

Next, it performs a binary search to find the maximum size of a submatrix whose sum is less than or equal to 15.

The binary search iterates as follows:
- Initial `lo` = 0 and `hi` = min(n, m) = 4.
- The mid-point is calculated as (0 + 4) / 2 = 2.
- The function `kyaKoiSubmatrixJiskiLengthAndBreadthMidHoAndUskaSumLessThanEqualToKHai` is called with the current `mid` value of 2. It checks if there exists a submatrix of size 2x2 with a sum less than or equal to 15.
- The function loops through all possible submatrices of size 2x2 and calculates their sum.
- If the sum of any submatrix is less than or equal to 15, the function returns `true`.
- In this case, the submatrix with elements `6 7 10 11` has a sum of 34, which is greater than 15.
- `hi` is updated to 1 (mid - 1).
- The next iteration sets `lo` = 0 and `hi` = 1.
- The mid-point is calculated as (0 + 1) / 2 = 0.
- The function is called again with `mid` = 0, and it returns false since there is no submatrix of size 0x0 with a sum less than or equal to 15.
- `lo` is updated to 1 (mid + 1).
- Since `lo` is now greater than `hi`, the binary search ends.

The final value of `ans` is 1, which represents the maximum size of a submatrix satisfying the condition. However, since we need the area (size * size) of the submatrix, we output the value of `ans` squared, which is `4`.

Thus, the output of the code is `4`, indicating the area of the maximum submatrix with a sum less than or equal to 15.
*/