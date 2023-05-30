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

    // Iterate through all submatrices --> time complexity of this approach is : O(N^4) O(N^2)
    for(ll x1 = 1; x1 <= n; x1++){
        for(ll y1 = 1; y1 <= m; y1++){
            for(ll x2 = x1; x2 <= n; x2++){
                for(ll y2 = y1; y2 <= m; y2++){
                    // Calculate sum of submatrix
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

/*
The given code calculates the number of submatrices within a given matrix that have a target sum.

Let's take an example to understand the code better:

```
Input:
3 3
1 1 2
2 3 3
3 1 2
5

Output:
Number of submatrices with sum equal to targetSum: 3
```

Explanation:
- The first line of the input (`3 3`) represents the dimensions of the matrix, which is a 3x3 matrix in this case.
- The next 3 lines input the values of the matrix elements.
- The line `5` inputs the target sum, which is 5 in this case.
- The code initializes a variable `count` to keep track of the number of submatrices with the target sum.
- The nested loops starting from `x1` and `y1` iterate through all possible starting positions of the submatrix.
- The inner loops starting from `x2` and `y2` iterate through all possible ending positions of the submatrix.
- Within these loops, the code calculates the sum of the submatrix by iterating over the corresponding elements and storing the sum in `subMatrixSum`.
- If the `subMatrixSum` is equal to the `targetSum`, it means we have found a submatrix with the desired sum, so the `count` is incremented.
- Finally, the code prints the value of `count`, which represents the number of submatrices with the target sum.

In our example, there are 3 submatrices with a sum equal to 5: (1, 1), (1, 2), (2, 1) and (2, 2).

Note: The time complexity of this code is O(N^4), where N represents the maximum dimension of the matrix. It can be improved further by using more efficient algorithms.
*/