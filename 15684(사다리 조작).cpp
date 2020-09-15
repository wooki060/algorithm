#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int N,M,H,ans=0x7fffffff;
vector<vector<int>> column;
int check(int n,int h){
    for(int i=h;i<=H;i++){
        if(column[n][i] == 1)
            return check(n+1,i+1);
        else if(column[n][i] == 2)
            return check(n-1,i+1);
    }
    return n;
}
bool result(){
    for(int i=1;i<=N;i++)
        if(i != check(i,1))
            return false;
    return true;
}
void dfs(int num){
    if(result())
        ans = min(ans,num);
    if(num > 2)
        return;
    for(int i=1;i<N;i++){
        for(int j=1;j<=H;j++){
            if(column[i][j]==0 && column[i+1][j]==0){
                column[i][j] = 1;
                column[i+1][j] = 2;
                dfs(num+1);
                column[i][j] = 0;
                column[i+1][j] = 0;
            }
        }
    }
}
int main(void){
    cin >> N >> M >> H;
    column.resize(N+1, vector<int>(H+1,0));
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        column[b][a]=1;
        column[b+1][a]=2;
    }
    dfs(0);
    if(ans == 0x7fffffff)
        ans=-1;
    printf("%d\n",ans);
}
