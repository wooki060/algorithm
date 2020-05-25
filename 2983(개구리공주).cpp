#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
struct pose{
    int x;
    int y;
    bool operator<(const pose &a) const{
        if(x == a.x)
            return y < a.y;
        return x < a.x;
    }
};
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int main(){
    int N,K;
    string J;
    scanf("%d%d",&N,&K);
    cin >> J;
    unordered_map<int, set<pose>> pl_map;
    unordered_map<int, set<pose>> mi_map;
    pose now;
    for(int i=0;i<N;i++){
        pose inp;
        scanf("%d%d",&inp.x,&inp.y);
        if(i==0){
            now.x = inp.x;
            now.y = inp.y;
        }
        pl_map[inp.x+inp.y].insert(inp);
        mi_map[inp.x-inp.y].insert(inp);
    }
    
    for(int i=0;i<K;i++){
        int d = J[i] - 'A';
        int pl = now.x+now.y;
        int mi = now.x-now.y;
        if(d == 0){
            auto it = mi_map[mi].find(now);
            if(it == prev(mi_map[mi].end()))
                continue;
            it++;
            mi_map[mi].erase(now);
            pl_map[pl].erase(now);
            now.x = it->x;
            now.y = it->y;
        }
        else if(d == 1){
            auto it = pl_map[pl].find(now);
            if(it == prev(pl_map[pl].end()))
                continue;
            it++;
            pl_map[pl].erase(now);
            mi_map[mi].erase(now);
            now.x = it->x;
            now.y = it->y;
        }
        else if(d == 2){
            auto it = pl_map[pl].find(now);
            if(it == pl_map[pl].begin())
                continue;
            it--;
            pl_map[pl].erase(now);
            mi_map[mi].erase(now);
            now.x = it->x;
            now.y = it->y;
        }
        else{
            auto it = mi_map[mi].find(now);
            if(it == mi_map[mi].begin())
                continue;
            it--;
            mi_map[mi].erase(now);
            pl_map[pl].erase(now);
            now.x = it->x;
            now.y = it->y;
        }
    }
    printf("%d %d\n",now.x,now.y);
    
    return 0;
}

