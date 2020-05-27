#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<vector<int>> num(n,vector<int>(n));
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&num[i][j]);
    for(int i=0;i<n;i++)
        pq.push(num[0][i]);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(num[i][j]);
            pq.pop();
        }
    }
    printf("%d\n",pq.top());
    return 0;
}
