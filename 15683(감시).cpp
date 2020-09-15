#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N,M;
vector<vector<int>> map;
struct cctv{
    int x;
    int y;
    int num;
    int dir;
};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<cctv> CCTV;
int ans=0x7fffffff;
vector<vector<int>> tmp;
vector<vector<int>> tmp1;
void sight(int dir, int x, int y){
    while(0<=x && x<N && 0<=y && y<M ){
        tmp[x][y]=0;
        if(map[x][y] == 6)
            break;
        x+=dx[dir];
        y+=dy[dir];
    }
}
int val(){
    tmp.assign(tmp1.begin(),tmp1.end());
    for(auto c : CCTV){
        if(c.num == 5){
            for(int i=0;i<4;i++)
                sight(i,c.x,c.y);
        }
        else if(c.num == 4){
            sight(c.dir,c.x,c.y);
            sight((c.dir+1)%4,c.x,c.y);
            sight((c.dir+3)%4,c.x,c.y);
        }
        else if(c.num == 3){
            sight(c.dir,c.x,c.y);
            sight((c.dir+1)%4,c.x,c.y);
        }
        else if(c.num == 2){
            sight(c.dir,c.x,c.y);
            sight(c.dir+2,c.x,c.y);
        }
        else
            sight(c.dir,c.x,c.y);
    }
    int val=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            val += tmp[i][j];
    return val;
}
void dir_set(int idx){
    if(idx == CCTV.size())
        ans = min(ans,val());
    else{
        if(CCTV[idx].num == 5)
            dir_set(idx+1);
        else if(CCTV[idx].num == 2){
            CCTV[idx].dir = 0;
            dir_set(idx+1);
            CCTV[idx].dir = 1;
            dir_set(idx+1);
        }
        else{
            for(int i=0;i<4;i++){
                CCTV[idx].dir = i;
                dir_set(idx+1);
            }
        }
    }
}
int main(void){
    cin >> N >> M;
    map.resize(N, vector<int>(M));
    tmp1.resize(N, vector<int>(M,1));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(1<=map[i][j] && map[i][j]<=5){
                cctv temp;
                temp.x = i;
                temp.y = j;
                temp.num = map[i][j];
                CCTV.push_back(temp);
            }
            else if(map[i][j] == 6)
                tmp1[i][j] = 0;
        }
    }
    dir_set(0);
    printf("%d\n",ans);
}

