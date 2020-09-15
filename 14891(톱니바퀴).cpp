#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct gear{
    vector<int> wheel;
    int check;
}gear[4];
void rotation(int i){
    int tmp = gear[i].wheel[7];
    gear[i].wheel.pop_back();
    gear[i].wheel.insert(gear[i].wheel.begin(), tmp);
}
void Rrotation(int i){
    int tmp = gear[i].wheel[0];
    gear[i].wheel.erase(gear[i].wheel.begin());
    gear[i].wheel.push_back(tmp);
}
void pro(int num, int dir){
    gear[num].check = 1;
    if(num > 0 && !gear[num-1].check && gear[num-1].wheel[2]^gear[num].wheel[6])
        pro(num-1, dir*-1);
    if(num < 3 && !gear[num+1].check && gear[num+1].wheel[6]^gear[num].wheel[2])
        pro(num+1, dir*-1);
    
    if(dir == 1)
        rotation(num);
    else
        Rrotation(num);
}
int main(void){
    for(int i=0;i<4;i++){
        string tmp;
        cin >> tmp;
        for(auto t : tmp){
            gear[i].wheel.push_back(t-'0');
        }
    }
    int K;
    cin >> K;
    while(K-->0){
        int num, dir;
        for(int i=0;i<4;i++)
            gear[i].check = 0;
        cin >> num >> dir;
        pro(num-1, dir);
    }
    
    int ans=0;
    for(int i=0,j=1;i<4;i++,j*=2)
        ans += gear[i].wheel[0]*j;
    
    printf("%d\n",ans);
}

