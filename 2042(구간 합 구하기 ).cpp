#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
long long ST_init(vector<long long> &num, vector<long long> &tree, int node, int s, int e){
    if(s ==  e)
        return tree[node] = num[s];
    int mid = (s+e)/2;
    return tree[node] = ST_init(num,tree,node*2,s,mid) + ST_init(num,tree,node*2+1,mid+1,e);
}
long long ST_sum(vector<long long> &tree, int node, int s, int e, int left, int right){
    if(left > e || s > right)
        return 0;
    if(left <= s && e <= right)
        return tree[node];
    int mid = (s+e)/2;
    return ST_sum(tree,node*2,s,mid,left,right) + ST_sum(tree,node*2+1,mid+1,e,left,right);
}
void ST_update(vector<long long> &tree,int node,int s,int e,int idx,long long diff){
    if(idx < s || e < idx)
        return;
    tree[node] += diff;
    if(s !=  e){
        int mid = (s+e)/2;
        ST_update(tree,node*2,s,mid,idx,diff);
        ST_update(tree,node*2+1,mid+1,e,idx,diff);
    }
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<long long> num(n);
    vector<long long> tree(1 << ((int)ceil(log2(n))+1));
    for(int i=0;i<n;i++)
        scanf("%lld",&num[i]);
    
    ST_init(num,tree,1,0,n-1);
    for(int i=0;i<m+k;i++){
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        if(a == 1){
            ST_update(tree,1,0,n-1,b-1,c-num[b-1]);
            num[b-1] = c;
        }
        else
            printf("%lld\n",ST_sum(tree,1,0,n-1,b-1,c-1));
    }
    return 0;
}
