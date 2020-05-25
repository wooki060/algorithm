#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct relate{
    int b;
    int d;
};
int n,m,r;
vector<int> K;
vector<vector<relate>> algo;
bool isPossible(int x){
    vector<int> k=K;
    vector<bool> visit(n+1,false);
    queue<int> algorithm;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(k[i] <= x){
            algorithm.push(i);
            visit[i] = true;
            cnt++;
        }
    }
    if(cnt >= m)
        return true;
    
    while(!algorithm.empty()){
        int now = algorithm.front();
        algorithm.pop();
        for(int i=0;i<algo[now].size();i++){
            k[algo[now][i].b] -= algo[now][i].d;
            if(visit[algo[now][i].b] == false && k[algo[now][i].b] <= x){
                visit[algo[now][i].b] = true;
                algorithm.push(algo[now][i].b);
                cnt++;
            }
        }
        if(cnt >= m)
            return true;
    }
    return false;
}
int main(){
    int s=0x7fffffff,e=0;
    scanf("%d%d",&n,&m);
    K.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&K[i]);
        e = max(e,K[i]);
        s = min(s,K[i]);
    }
    scanf("%d",&r);
    algo.resize(n);
    for(int i=0;i<r;i++){
        int a;
        relate re;
        scanf("%d%d%d",&a,&re.b,&re.d);
        algo[a].push_back(re);
    }
    int ans=0x7fffffff;
    while(s <= e){
        int mid = (s+e)/2;
        if(isPossible(mid)){
            ans = min(ans,mid);
            e = mid-1;
        }
        else
            s = mid+1;
    }
    
    printf("%d\n",ans);
    return 0;
}

