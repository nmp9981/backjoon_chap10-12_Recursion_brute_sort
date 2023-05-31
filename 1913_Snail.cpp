#include <iostream>
using namespace std;

int n, search,num;
const int maxi = 999;
int A[maxi][maxi];//배열
//북동남서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//입력
void input() {
    cin >> n>>search;
    num = 1;//현재 숫자
}

//달팽이
void Snail(int start) {
    int x = start; int y = start;//시작 지점
    A[x][y] = num;
    int len = 0;//이동 거리
    int dir = 0;//방향

    while (true) {
        if (dir % 2 == 0) len++;//거리 늘림

        for (int i = 0; i < len; i++) {//이동 하기
            x += dx[dir]; y += dy[dir];//다음 지점
            A[x][y] = (++num);//배열 갱신

            if (x == 0 && y == 0) return;//종료
        }
        dir = (dir + 1) % 4;//방향 전환
    }
}
//출력
void output() {
    int row, col;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == search) {//수 찾음
                row = i;
                col = j;
            }
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << row+1 << " " << col+1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Snail(n/2);//달팽이
    output();//출력
    return 0;
}
