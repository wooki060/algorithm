#include<stdio.h>
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
int x[300001];
int y[300001];
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    int board[501][501];
    int ans[501][501];
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int n;
            scanf("%d",&n);
            board[i][j] = n;
            ans[i][j] = 1;
            x[n] = i;
            y[n] = j;
        }
    }
    
    for(int i=300000;i>=0;i--){
        if(x[i] == 0)
            continue;
        
        int cx=x[i];
        int cy=y[i];
        int tmp=ans[cx][cy];
        ans[cx][cy] = 0;
        for(int d=0;d<8;d++){
            int nx = x[i]+dx[d];
            int ny = y[i]+dy[d];
            if(nx<1 || nx>r || ny<1 || ny>c)
                continue;
            if(board[cx][cy] > board[nx][ny]){
                cx = nx;
                cy = ny;
            }
        }
        ans[cx][cy] += tmp;
    }
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
