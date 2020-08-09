//
//  main.cpp
//  Prim's Minimum Cost Spanning Tree
//
//  Created by Kevinn on 2020/6/2.
//  Copyright © 2020 Kevinn. All rights reserved.
//

#include <iostream>
#define I INT_MAX
using namespace std;

int cost[8][8] = {
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}
};

int near[8] = {I,I,I,I,I,I,I,I};      // mark those points with order already confirmed as 0, compare the rest of points' distance to those points with 0, record the nearer element in each point
int t[2][6];         // record the order of the later tree



int main(int argc, const char * argv[]) {
    
    int i,j,k,u,v,n=7,min=I;
    for (i=1; i<=n; i++) {          // find minimum cost in the upper matrix;
        for (j=i; j<=n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i; v = j;
            }
        }
    }
    t[0][0] = u; t[1][0] = v;       // two elements' order have been set up
    near[u] = near[v] = 0;
    
    for (i=1; i<=n; i++) {          // find nearer point for each element, except those already order-determined
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    
    for (i=1; i<n-1; i++) {      // loop through the rest of t, and determine the order
        min = I;
        for (j=1; j<=n; j++) {
            if (near[j]!=0 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;          // k is the index for the element with minimum cost
            }
        }
        t[0][i] = k; t[1][i] = near[k];
        near[k] = 0;
        
        for (j=1; j<=n; j++) {
            if (near[j]!=0 && cost[j][k] < cost[j][near[j]])        // if newly order determined k's cost to j is smaller than j's previous cost, update the new minimun cost for each element
                near[j] = k;
        }
    }
    
    for (i=0; i<n-1; i++) {         // print the final order
        cout << "(" << t[0][i] << "," << t[1][i] << ")\n";
    }
    
    
    return 0;
}
