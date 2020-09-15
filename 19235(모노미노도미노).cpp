#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int score, num;
vector<vector<int>> block;
void block11(int x){
    num++;
    int i=2;
    while(i<6 && block[i][x] == 0){i++;}
    block[--i][x]=1;
}
void block12(int x){
    num+=2;
    int i=2;
    while(i<6 && block[i][x]==0 && block[i][x+1]==0){i++;}
    block[--i][x]=2;
    block[i][x+1]=2;
}
void block21(int x){
    num+=2;
    int i=2;
    while(i<6 && block[i][x] == 0){i++;}
    block[--i][x]=1;
    block[--i][x]=1;
}
void scoreCheck(){
    int tmp=-1;
    for(int i=2;i<6;i++){
        int j=0;
        while(j<4 && block[i][j]!=0){j++;}
        if(j==4){
            block.erase(block.begin()+i);
            block.insert(block.begin(), vector<int>(4,0));
            tmp=i;
            num-=4;
            score++;
        }
    }
    if(tmp == -1)
        return;
    for(int x=tmp;x>=0;x--){
        for(int y=0;y<4;y++){
            if(block[x][y] == 1){
                int t=x+1;
                while(t<6 && block[t][y]==0){t++;}
                block[x][y]=0;
                block[--t][y]=1;
            }
            else if(block[x][y] == 2){
                int t=x+1;
                while(t<6 && block[t][y]==0 && block[t][y+1]==0){t++;}
                block[x][y]=0;
                block[x][y+1]=0;
                block[--t][y]=2;
                block[t][y+1]=2;
                y++;
            }
        }
    }
    scoreCheck();
}
void eraseTile(){
    int cnt=0;
    for(int i=0;i<4;i++){
        if(block[0][i] != 0)
            cnt++;
        if(block[1][i] != 0)
            cnt++;
        if(cnt != 0)
            break;
    }
    for(int i=cnt;i>0;i--){
        for(int j=0;j<4;j++){
            if(block[5][j] != 0)
                num--;
        }
        block.pop_back();
        block.insert(block.begin(), vector<int>(4,0));
    }
}
int main(void){
    int N;
    vector<vector<int>> blue(6, vector<int>(4,0));
    vector<vector<int>> green(6, vector<int>(4,0));
    cin >> N;
    while(N-->0){
        int t,x,y;
        cin >> t >> x >> y;
        if(t == 1){
            block.clear();
            block.assign(blue.begin(), blue.end());
            block11(x);
            blue.clear();
            blue.assign(block.begin(), block.end());
            block.clear();
            block.assign(green.begin(), green.end());
            block11(y);
            green.clear();
            green.assign(block.begin(), block.end());
        }
        else if(t == 2){
            block.clear();
            block.assign(blue.begin(), blue.end());
            block21(x);
            blue.clear();
            blue.assign(block.begin(), block.end());
            block.clear();
            block.assign(green.begin(), green.end());
            block12(y);
            green.clear();
            green.assign(block.begin(), block.end());
        }
        else{
            block.clear();
            block.assign(blue.begin(), blue.end());
            block12(x);
            blue.clear();
            blue.assign(block.begin(), block.end());
            block.clear();
            block.assign(green.begin(), green.end());
            block21(y);
            green.clear();
            green.assign(block.begin(), block.end());
        }
        block.clear();
        block.assign(blue.begin(), blue.end());
        scoreCheck();
        blue.clear();
        blue.assign(block.begin(), block.end());
        block.clear();
        block.assign(green.begin(), green.end());
        scoreCheck();
        green.clear();
        green.assign(block.begin(), block.end());
        
        block.clear();
        block.assign(blue.begin(), blue.end());
        eraseTile();
        blue.clear();
        blue.assign(block.begin(), block.end());
        block.clear();
        block.assign(green.begin(), green.end());
        eraseTile();
        green.clear();
        green.assign(block.begin(), block.end());
        
        printf("%d %d\n",score,num);
    }
    printf("%d\n%d\n",score,num);
}
