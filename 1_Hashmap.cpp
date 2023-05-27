
// https://pastebin.com/dGwNUmCe


#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);
 
    map<int, int> apnaMap;

    // insertion - O(logn)
    apnaMap[2]=3;

    // updation - O(logn)
    apnaMap[2]=4;

    // fetch - O(logn)
    cout<<apnaMap[2]<<endl;
    cout<<(apnaMap.count(3)?apnaMap[3]:-1);
 
    // size - O(1)
    cout<<apnaMap.size()<<endl;
 
    // whether a key is present or not - O(logN)
    cout<<apnaMap.count(2)<<endl;
    cout<<apnaMap.count(3)<<endl;
 
    // erase - O(logN)
    apnaMap.erase(2); 
    cout<<apnaMap.size()<<endl;
 
    //iterate on map - O(N)
    apnaMap[3]=5;
    apnaMap[9]=4;
    apnaMap[3]=6;
    for(auto itr : apnaMap){
        cout<<itr.first<<" "<<itr.second<<endl;
    }


}