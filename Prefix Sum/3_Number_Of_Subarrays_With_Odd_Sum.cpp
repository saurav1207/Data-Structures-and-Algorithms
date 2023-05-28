#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void sumOfSubArrayEqualToK(){
    ll n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<ll> arr(n+1,0);
    cout<<"Enter the element of array: ";
    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }
    
    ll targetSum; 
    cout<<"Enter the target: ";
    cin>>targetSum;

    vector<ll>pref(n+1,0);
    for(ll i=1; i<=n; i++){
        pref[i] = pref[i-1] + arr[i];
    }

    map<ll, ll> mp;
    mp[0]=1;
    for(ll i=1; i<=n; i++){
        if(mp.count(pref[i] - targetSum)){
            cout<<"Yes"<<endl;
            return;
        }
        if(mp.count(pref[i])){
            mp[pref[i]]++;
        }
        else{
            mp[pref[i]]=1;
        }
    }
    cout<<"No"<<endl;
}
int main(){
    sumOfSubArrayEqualToK();
    return 0;
} 