#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

void ArrayRangeOccurrence(){
    ll n; cin >> n;

    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll q; cin >> q;
    while(q--){
        ll l, r, x; cin >> l >> r >> x;
        ll count = 0;
        for(ll i = l - 1; i < r; i++){
            if(arr[i] == x){
                count++;
            }
        }
        cout << count << endl;
    }
}

int main(){
    ArrayRangeOccurrence();
    return 0;
}

/*

Input:
```
6
1 2 3 2 4 2
3
1 4 2
2 5 3
3 6 1
```

Output:
```
2
1
0
```

Explanation:
- In the first query, the range [1, 4] contains the value 2 twice.
- In the second query, the range [2, 5] contains the value 3 once.
- In the third query, the range [3, 6] does not contain the value 1.

*/