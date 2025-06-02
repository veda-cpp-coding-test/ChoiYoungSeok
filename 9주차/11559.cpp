#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

char map[12][6];
bool visited[12][6];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

struct position
{
    int y;
    int x;
};

void print(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
}

bool smash_blocks(){
    bool result = false;

    for(int i = 0; i < 12; i++)
        memset(visited[i], false, sizeof(bool) * sizeof(visited[i]));

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(map[i][j] != '.' && !visited[i][j]){
                char color = map[i][j];
                queue<position> q;
                queue<position> blocks;
                
                q.push({i, j});
                blocks.push({i, j});
                while(!q.empty()){
                    position now = q.front();
                    visited[now.y][now.x] = true;
                    q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        position next = {now.y+dy[dir], now.x+dx[dir]};
                        
                        if(next.y > -1 && next.y < 12 
                            && next.x > -1 && next.x < 6){
                            if(!visited[next.y][next.x] && map[next.y][next.x] == color){
                                q.push(next);
                                blocks.push(next);
                                visited[now.y][now.x] = true;
                            }
                        }
                    }
                }

                if(blocks.size() > 3){
                    while (!blocks.empty())
                    {
                        position block = blocks.front();
                        map[block.y][block.x] = '.';
                        blocks.pop();
                    }

                    result = true;
                }
            }
        }
    }

    return result;
}

void blocks_fall() {
    for (int j = 0; j < 6; j++) {  // 열 기준으로 반복
        int empty_row = 11;        // 가장 아래쪽 빈 칸 위치

        for (int i = 11; i >= 0; i--) {  // 아래에서 위로 탐색
            if (map[i][j] != '.') {
                if (i != empty_row) {
                    map[empty_row][j] = map[i][j];  // 블록을 아래로 이동
                    map[i][j] = '.';                // 원래 자리는 비움
                }
                empty_row--;  // 아래로 채웠으니 한 칸 올라감
            }
        }
    }
}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    for(int i =0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> map[i][j];
        }
    }

    int payoyen = 0;

    while(smash_blocks()){
        //update screen
        blocks_fall();
        payoyen++;

        //cout << '\n';
        //print();
        //cout << '\n';
    }

    cout << payoyen;

    return 0;
}