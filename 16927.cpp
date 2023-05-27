#include <iostream>
using namespace std;

int n, m, R;
const int maxi = 301;
int A[maxi][maxi];//배열
//남동북서
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m>>R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> A[i][j];
    }
}
//회전
void Rotation() {
    int EdgeCount = min(n, m) / 2;//돌리는 모서리 개수
    for (int k = 0; k < EdgeCount; k++) {//각 테두리별
        //시작, 끝지점
        int startX = k; int startY = k; 
        int endX = n - 1 - k; int endY = m - 1 - k;
        
        int RouteLen = (n+m-4*k-2)*2;//테두리 길이
        int RotateCount = R%RouteLen;//회전횟수
       
        while (RotateCount--) {
            int temp = A[startX][startY];//시작지점
            for (int j = startY + 1; j <= endY; j++) A[startX][j-1] = A[startX][j];//서
            for (int i = startX + 1; i <= endX; i++) A[i - 1][endY] = A[i][endY];//북
            for (int j = endY - 1; j >= startY; j--) A[endX][j + 1] = A[endX][j];//동
            for (int i = endX - 1; i >= startX; i--) A[i + 1][startY] = A[i][startY];//남
            A[startX + 1][startY] = temp;
        }
    }
}
//출력
void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << A[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Rotation();//회전
    output();//출력
    return 0;
}
