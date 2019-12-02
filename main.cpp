#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <fstream>
using namespace std;
ifstream f("in.txt");
int v[1000];
/*
void function2(int a, int l, int ok){
    int i;
    v[1] = a;
    v[2] = l;
    for(int i = 0;i<ok;i+=4)
        if(v[i] == 1)
            v[v[i+3]] = v[v[i+2]] + v[v[i+1]];
        else
            if(v[i] == 2)
                v[v[i+3]] = v[v[i+2]] * v[v[i+1]];
        else
            if(v[i]==99)
                i++;
}*/
int main()
{
    char b[1000], *p;
    int ok = 0, i, j, k, ii, jj, l = 0;
    cin.getline(b, sizeof(b));
    //19690720
    p = strtok(b, ",");
    while(p)
    {
        v[ok++] = atoi(p);
        p = strtok(NULL, ",");
    }
    for(k=99; k>=0; k--){
        for(j=0; j<=99; j++)
        {
            v[1] = k;
            v[2] = j;
            for(int i = 0; i<ok; i+=4)
                if(v[i] == 1)
                    v[v[i+3]] = v[v[i+2]] + v[v[i+1]];
                else if(v[i] == 2)
                    v[v[i+3]] = v[v[i+2]] * v[v[i+1]];
                else if(v[i]==99)
                    i++;
            if(v[0] == 19690720)
            {
                ii=i;
                jj = j;
                l = 1;
                break;
            }
        }
        if(l==1)
            break;
    }
    cout<<100*ii+jj;

}


