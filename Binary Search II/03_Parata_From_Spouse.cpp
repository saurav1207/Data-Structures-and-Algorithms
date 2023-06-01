// search space --> time 
// agar t time main p paratha bna sakta hu toh t+1 tmie main bhi p paratha bna sakta hu

// 3 5 1 2 3 --> 5 cheff with thier rank 

// lo, ho --> time ka binary search 
// mid second pe company --> p paratha bana paya
        // --> Yes ans = mid hc = mid-1
        // --> No lo = mid + 1

// Here nested binary search use 
// first for time search space 
// second for parath search space 
 
//  x paratha bana --> x * ((x+1)/2)*R



#include<bits/stdc++.h>
#define ll long long int 
using namespace std;


ll bhaiKitneParatheBanalegaTSecondsMe(ll rank, ll t, ll p){
    ll lo=1, hi=p, ans =0;
    while(lo<=hi){
        ll mid = (lo + hi)/2;
        ll totalTimeTaken = (mid * (mid+1)/2)*rank;
        if(totalTimeTaken <= t){
            ans = mid;
            lo = mid + 1;
        }
        else{
             hi = mid - 1;
        }
    }
    return ans;
}

void parathFromSpouce(){
    ll p; cin>>p;
    int n; cin>>n;
    vector<ll>rank(n,0);
    for(ll i = 0; i<n; i++) cin>>rank[i];

    ll lo=1, hi = 1e15, ans = 0;
    while(lo<=hi){
        ll mid = (lo + hi)/2;
        
        ll companyKitneParatheBanaegi = 0;

        for(auto itr: rank){
            companyKitneParatheBanaegi += bhaiKitneParatheBanalegaTSecondsMe(itr, mid, p);
        }
         if(companyKitneParatheBanaegi>=p){
                ans = mid;
                hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    parathFromSpouce();
    return 0;
}
