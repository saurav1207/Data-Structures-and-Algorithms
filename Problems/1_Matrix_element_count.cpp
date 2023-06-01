// (i,j) = (i + j)^2
// n, m --> row, col 
// find how many element is less than K after visulazation an matrix
// N = M = 10^5 ( this is because we can not use)

// Here one thing is we can see is every row it shift the values 
// have to fing Maxi col no having value less than k


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);

    ll n, m, k; cin>>n>>m>>k;
    ll lo = 1, hi = n, maximumRow = 0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if((mid+m)*(mid+m)<=k){
            maximumRow = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    ll choteElements = maximumRow*m;

    if(maximumRow+1<=n){
        ll lo = 1, hi = m, maximumColumn = 0;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if((maximumRow+1+mid)*(maximumRow+1+mid)<=k){
                maximumColumn = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        ll L = maximumColumn - (n - maximumRow) + 1;
        ll R = maximumColumn;
        if(L<0) L = 0;
        choteElements += (R*(R+1))/2 - (L*(L-1))/2;
    }
    cout<<choteElements<<endl;


    // ll iMax = min(n, sqrt(k)-m);
    // imax = max(1, imax);
    // ll choteElements = iMax*m;
    // ll agliRowMeKitneChoteHai = sqrt(k)-imax-1;
    // ll L = agliRowMeKitneChoteHai-(n-imax)+1;
    // ll R = agliRowMeKitneChoteHai;
    // if(L<0) L = 0;
    // choteElements += (R*(R+1))/2 - (L*(L-1))/2;
    // cout<<choteElements<<endl;
}

/*
5 5 40
14
*/