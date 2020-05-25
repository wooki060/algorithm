#include<stdio.h>
#include<queue>
#include<math.h>
using namespace std;

int n,m;
char board[10][10];
bool visit[10][10][10][10];
int hx,hy;

struct ball{
    int rx,ry,bx,by,count;
};
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};


int main(){
    ball s;
    queue<ball> q;
    
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%s",board[i]);
        for(int j=0;j<m;j++){
            if (board[i][j] == 'R') {
                s.rx = i;
                s.ry = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                s.bx = i;
                s.by = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'O') {
                hx = i;
                hy = j;
                board[i][j] = '.';
            }
        }
    }
    
    int ans = -1;
    s.count = 0;
    q.push(s);
    while(!q.empty()){
        ball cur = q.front();
        visit[cur.rx][cur.ry][cur.bx][cur.by] = true;
        q.pop();
        
        if (cur.bx == hx && cur.by == hy)
            continue;
        
        if (cur.rx == hx && cur.ry == hy) {
            ans = cur.count;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            ball next;
            next.rx = cur.rx;
            next.ry = cur.ry;
            next.bx = cur.bx;
            next.by = cur.by;
            while (board[next.rx + dx[i]][next.ry + dy[i]] == '.') {
                next.rx += dx[i];
                next.ry += dy[i];
                if (next.rx == hx && next.ry == hy)
                    break;
            }
            while (board[next.bx + dx[i]][next.by + dy[i]] == '.') {
                next.bx += dx[i];
                next.by += dy[i];
                if (next.bx == hx && next.by == hy)
                    break;
            }
            
            if (next.bx == next.rx && next.by == next.ry && (next.rx != hx || next.ry != hy)){
                int rdis = abs(cur.rx - next.rx + cur.ry - next.ry);
                int bdis = abs(cur.bx - next.bx + cur.by - next.by);
                if(rdis < bdis){
                    next.bx -= dx[i];
                    next.by -= dy[i];
                }
                else {
                    next.rx -= dx[i];
                    next.ry -= dy[i];
                }
            }
            
            if (visit[next.rx][next.ry][next.bx][next.by] == false) {
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
