#include <string>
using namespace std;

const int maxi = 11;
bool visit[maxi][maxi][maxi][maxi];//(a,b)->(c,d)방문 여부

//이동
int Move(string dir){
    int curX = 5;int curY = 5;//시작 지점
    int nx,ny;//다음 지점
    int cnt = 0;//길 개수
    
    //다음 지점 구하기
    for(int i=0;i<dir.size();i++){
        if(dir[i]=='L'){
            nx = curX-1;ny = curY;
        }else if(dir[i]=='R'){
            nx = curX+1;ny = curY;
        }else if(dir[i]=='U'){
            nx = curX;ny = curY-1;
        }else if(dir[i]=='D'){
            nx = curX;ny = curY+1;
        }
        if(nx<0 || nx>=maxi || ny<0 || ny>=maxi) continue;//방문 조건
        //방문 여부 확인
        if(!visit[curX][curY][nx][ny] && !visit[nx][ny][curX][curY]){
            visit[curX][curY][nx][ny] = true;
            visit[nx][ny][curX][curY] = true;
            cnt++;
        }
        curX = nx;curY = ny;//좌표 갱신
    }
    return cnt;
}
int solution(string dirs) {
    return Move(dirs);
}
