#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<vector<int>> net;
int cal(int com){
    int val=0;
    vector<int> distance(n+1,0x07fffffff);
    for(int i=1;i<=n;i++)
        if(net[com][i] != 0)
            distance[i] = net[com][i];
    distance[com] = -1;
    
    for(int t=1;t<n;t++){
        int idx;
        int min_dis=0x7fffffff;
        for(int i=1;i<=n;i++){
            if(distance[i] > 0 && distance[i] < min_dis){
                min_dis = distance[i];
                idx = i;
            }
        }
        val += distance[idx];
        for(int i=1;i<=n;i++)
            if(net[idx][i] != 0 && distance[i] > distance[idx]+net[idx][i])
                distance[i]  = distance[idx]+net[idx][i];
        
        distance[idx] = -1;
    }
    
    return val;
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    net.assign(n+1, vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        net[a][b] = c;
        net[b][a] = c;
    }
    int min_dis=0x7fffffff;
    int ans;
    for(int i=1;i<=n;i++){
        int dis = cal(i);
        if(min_dis > dis){
            min_dis = dis;
            ans = i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
