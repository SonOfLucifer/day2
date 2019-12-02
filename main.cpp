#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("in.txt");

int func(vector<long> v, long a, long b, long ok){
    long i;
    v[1] = a;
    v[2] = b;
    for(i=0;i<v.size();i+=4){
        if(v[i] == 1)
            v[v[i+3]] = v[v[i+2]] + v[v[i+1]];
        else
            if(v[i] == 2)
                v[v[i+3]] = v[v[i+2]] * v[v[i+1]];
        else
            if(v[i]==99)
                i++;
    }
    return v[0];
    
}
int main(){
    vector<long> v;
    char b[10000], *p;
    int i, j, ok = 0;
    cin.getline(b, sizeof(b));
    p = strtok(b, ",");
    while(p){
        v.push_back(atol(p));
        p = strtok(NULL, ",");
    }
    for(i=99;i>=0;i--)
        for(j=0;j<=99;j++)
            if(func(v, i, j, ok) == 19690720)
                cout<<100*i+j;
}
