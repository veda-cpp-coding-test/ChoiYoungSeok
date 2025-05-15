#include <iostream>
#include <algorithm>
using namespace std;

char map[10000][10000];

void unit(int sx, int sy){
    map[sx][sy] = '*';
    map[sx+1][sy-1] = '*';
    map[sx+1][sy+1] = '*';
    for(int i = sy-2; i <= sy + 2; i++) map[sx+2][i] = '*';
}

void draw(int sx, int sy, int len){
    if(len == 3){
        unit(sx,sy);
        return;
    }
    
    else if( len < 3) return;

    int halfX = len/2;
    int halfY = len/2;
    draw(sx,sy,len/2);
    draw(sx+halfX,sy-halfY,len/2); 
    draw(sx+halfX,sy+halfY,len/2); 

}
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    int sy = (2*N-1)/2;
    fill(&map[0][0],&map[9999][10000],' ');
    draw(0,sy,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2*N-1; j++) cout << map[i][j];
        cout << "\n";
    }
}