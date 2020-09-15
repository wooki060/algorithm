#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main(void){
    int N,L;
    cin >> N >> L;
    vector<vector<int>> map(N, vector<int>(N));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> map[i][j];
    
    int ans=0;
    for(int i=0;i<N;i++){
        int tmp=map[i][0];
        int cnt=1;
        for(int j=1;j<N;j++){
            if(tmp+1 < map[i][j] || tmp > map[i][j]+1)
                break;
            if(tmp == map[i][j])
                cnt++;
            if(tmp+1 == map[i][j]){
                if(cnt < L)
                    break;
                tmp++;
                cnt=1;
            }
            if(tmp-1 == map[i][j]){
                tmp--;
                if(j+L-1 >= N)
                    break;
                for(cnt=1;cnt<L;cnt++)
                    if(tmp != map[i][j+cnt])
                        break;
                if(cnt < L)
                    break;
                j+=L-1;
                cnt=0;
            }
            if(j == N-1){
                ans++;
            }
        }
        
        tmp=map[0][i];
        cnt=1;
        for(int j=1;j<N;j++){
            if(tmp+1 < map[j][i] || tmp > map[j][i]+1)
                break;
            if(tmp == map[j][i])
                cnt++;
            if(tmp+1 == map[j][i]){
                if(cnt < L)
                    break;
                tmp++;
                cnt=1;
            }
            if(tmp-1 == map[j][i]){
                tmp--;
                if(j+L-1 >= N)
                    break;
                for(cnt=1;cnt<L;cnt++)
                    if(tmp != map[j+cnt][i])
                        break;
                if(cnt < L)
                    break;
                j+=L-1;
                cnt=0;
            }
            if(j == N-1){
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}
