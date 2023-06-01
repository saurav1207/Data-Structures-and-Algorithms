#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void getMaxRacers() {
    ll n, k; cin >> n >> k;

    vector<ll> speed(n);
    for (ll i = 0; i < n; i++) cin >> speed[i];

    ll maxRacers = 0;

    for (ll i = 0; i < n; i++) {
        ll count = 1;
        ll removed = 0;

        for (ll j = i + 1; j < n; j++) {
            if (speed[j] == speed[i]) {
                count++;
            } else {
                removed++;
                if (removed > k) {
                    break;
                }        
            }
        }

        maxRacers = max(maxRacers, count);
    }
    cout << "Maximum number of racers in a contiguous segment: " << maxRacers << endl;
}

int main() {
    getMaxRacers();
    
    return 0;
}



/*

```
n = 6
k = 2
speed = [1, 4, 4, 2, 2, 4]
```
```
Maximum number of racers in a contiguous segment: 3
```

We want to find the maximum number of racers in a contiguous segment after removing at most 2 racers.

First, we initialize `maxRacers` to 0, which will keep track of the maximum number of racers in a contiguous segment.

Now, we start iterating through the array. For each racer, we count the number of racers with the same speed in a contiguous segment.

- For the first racer with speed 1, there is only one racer with the same speed in the segment. So, `count` becomes 1.

- For the second racer with speed 4, there are two racers with the same speed in the segment. `count` becomes 2.

- For the third racer with speed 4, there are three racers with the same speed in the segment. `count` becomes 3.

- For the fourth racer with speed 2, there are two racers with the same speed in the segment. `count` becomes 2.

- For the fifth racer with speed 2, there are two racers with the same speed in the segment. `count` becomes 2.

- For the sixth racer with speed 4, there are three racers with the same speed in the segment. `count` becomes 3.

At each step, we update `maxRacers` to keep track of the maximum count encountered so far.

Finally, we return `maxRacers`, which represents the maximum number of racers in a contiguous segment after removing at most 2 racers.


This means that we can have a contiguous segment of 3 racers with the same speed after removing at most 2 racers.
*/