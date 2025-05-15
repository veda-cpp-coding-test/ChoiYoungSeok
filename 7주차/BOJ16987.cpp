#include <iostream>
using namespace std;

struct Egg{
    int hp; 
    int w; 
};
int N;
Egg egg[10];
int ans; 


void backTracking(int x){
    if(x > N+1) return;

    for(int i = 1; i <= N; i++){
        if(egg[x].hp <= 0) backTracking(x+1);
        else if(x == i || egg[i].hp <= 0) continue;
        else{
            
            egg[x].hp -= egg[i].w;
            egg[i].hp -= egg[x].w;
            backTracking(x+1); 
            
            egg[x].hp += egg[i].w;
            egg[i].hp += egg[x].w;
        }
    }

    int tmp = 0;
   
    for(int i = 1; i<= N; i++){
        if(egg[i].hp <= 0) tmp++;
    }
    
    ans = max(ans,tmp);
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        egg[i] = {v1,v2};
    }
    backTracking(1);
    cout << ans;
}