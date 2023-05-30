#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> mat(n + 1, vector<ll>(m + 1, 0));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }

    ll targetSum;
    cin >> targetSum;

    ll count = 0;

    for(ll x1 = 1; x1 <= n; x1++){
        for(ll y1 = 1; y1 <= m; y1++){
            for(ll x2 = x1; x2 <= n; x2++){
                for(ll y2 = y1; y2 <= m; y2++){
                    ll subMatrixSum = 0;
                    for(ll i = x1; i <= x2; i++){
                        for(ll j = y1; j <= y2; j++){
                            subMatrixSum += mat[i][j];
                        }
                    }

                    if(subMatrixSum == targetSum){
                        count++;
                    }
                }
            }
        }
    }

    cout << "Number of submatrices with sum equal to targetSum: " << count << endl;

    return 0;
}
