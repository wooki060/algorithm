#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;int main(){
    int n;
    map<char, int> word;
    scanf("%d",&n);
    set<char> tmp;
    for(int i=0;i<n;i++){
        string inp;
        cin >> inp;
        int t=1;
        for(int j=inp.size()-1;j>=0;j--,t*=10){
            word[inp[j]] += t;
            tmp.insert(inp[j]);
        }
    }
    vector<char> w(tmp.begin(),tmp.end());
    vector<int> num(w.size());
    for(int i=0;i<w.size();i++)
        num[i] = 9-i;
    
    int ans=0;
    do{
        int val=0;
        map<char, int>::iterator it;
        for(it=word.begin();it!=word.end();it++){
            val += it->second*num[find(w.begin(),w.end(),it->first) - w.begin()];
        }
        ans = max(ans,val);
    }while(prev_permutation(num.begin(),num.end()));
    printf("%d\n",ans);
    return 0;
}
