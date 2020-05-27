#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct step{
    int a;
    int b;
    int c;
};
int main(){
    int n;
    scanf("%d",&n);
    vector<step> stair(n);
    for(int i=0;i<n;i++){
        step tmp;
        scanf("%d%d%d",&tmp.a,&tmp.b,&tmp.c);
        stair[i] = tmp;
    }
    step minS = stair[0];
    step maxS = stair[0];
    for(int i=1;i<n;i++){
        step minT,  maxT;
        minT.a = stair[i].a + min(minS.a, minS.b);
        minT.b = stair[i].b + min(minS.a, min(minS.b, minS.c));
        minT.c = stair[i].c + min(minS.b, minS.c);
        
        maxT.a = stair[i].a + max(maxS.a, maxS.b);
        maxT.b = stair[i].b + max(maxS.a, max(maxS.b, maxS.c));
        maxT.c = stair[i].c + max(maxS.b, maxS.c);
        
        minS = minT;
        maxS = maxT;
    }
    
    printf("%d %d\n",max(maxS.a, max(maxS.b,maxS.c)), min(minS.a, min(minS.b, minS.c)));
    return 0;
}
