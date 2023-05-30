
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

    ll n, m; cin>>n>>m;

    vector<vector<ll>> mat(n+1, vector<ll>(m+1, 0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++) cin>>mat[i][j];
    }
   
    vector<vector<ll>> pref(n+1, vector<ll>(m+1, 0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+mat[i][j];
        }
    }

    ll q; cin>>q;
    while(q--){
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<<pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1]<<endl;
    }

}


/*
Linkedin - Margubur Rahman 
Contact Number - +91 7042263245
Snapchat - rahman1000001
Youtube - Seventh Sky 
*/