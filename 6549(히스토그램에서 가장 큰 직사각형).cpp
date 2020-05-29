#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define ll long long
int n;
vector<int> height;
vector<int> tree;
void ST_init(int node,int s,int e){
    if(s == e){
        tree[node] = s;
        return;
    }
    int mid=(s+e)/2;
    ST_init(node*2,s,mid);
    ST_init(node*2+1,mid+1,e);
    if(height[tree[node*2]] < height[tree[node*2+1]])
        tree[node] =  tree[node*2];
    else
        tree[node] =  tree[node*2+1];
}
int get_minIdx(int node,int s,int e,int left,int right){
    if(right < s || e < left)
        return -1;
    if(left <= s && e <= right)
        return tree[node];
    
    int mid=(s+e)/2;
    int l,r;
    l = get_minIdx(node*2,s,mid,left,right);
    r = get_minIdx(node*2+1,mid+1,e,left,right);
    if(l == -1)
        return  r;
    if(r == -1)
        return l;
    return  height[l] < height[r] ? l : r;
}
ll max_area(int s,int e){
    if(s == e)
        return height[s];
    
    int idx = get_minIdx(1,0,n-1,s,e);
    ll area = ((ll)e-s+1)*height[idx];
    if(s < idx)
        area = max(area,max_area(s,idx-1));
    if(idx < e)
        area = max(area,max_area(idx+1,e));
    return area;
}
int main(){
    while(1){
        scanf("%d",&n);
        if(n == 0)
            break;
        height.resize(n);
        tree.resize(1 << ((int)ceil(log2(n))+1));
        for(int i=0;i<n;i++)
            scanf("%d",&height[i]);
        ST_init(1,0,n-1);
        
        printf("%lld\n",max_area(0,n-1));
    }
    return 0;
}
