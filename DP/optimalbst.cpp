#include<bits/stdc++.h>
using namespace std;
int optimalbst_rec(vector<int> &keys, vector<int> freq, int start, int end, int level){

    if(start == end)
    {
        return freq[start] * level;
    }
    int min_ = 1e8;
    for(int i = start ; i < end ; i++)
    {
        int left = optimalbst_rec(keys,freq, start, i, level+1);
        int right = optimalbst_rec(keys, freq, i+1,end, level+1);
        min_= min(min_ , left + right + level*freq[i]); 
    }
    cout<<start<<" " << end<<" "<< min_<<endl;
    return min_;
}
int main()
{
    vector<int> keys{10,12,20}, freq{34, 8, 50};
    cout<<optimalbst_rec(keys,freq,0,3,1);
}