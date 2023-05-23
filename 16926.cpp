#include <iostream>
#include <vector>
using namespace std;

int n,m,r;
const int maxi = 301;
int A[maxi][maxi];//배열

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> A[i][j];
    }
}
//반시계로 1칸 회전하기
void Rotation() {
    int boxCount = min(n, m) / 2;//상자 개수
    int newA[maxi][maxi];
    for (int k = 1; k <= boxCount; k++) {
        //시작점(k,k), 끝점(n-k+1,m-k+1)
        int r1 = k; int c1 = k; int r2 = n - k + 1; int c2 = m - k + 1;
        for(int j=c1+1;j<=c2;j++) {//왼쪽으로
            newA[r1][j-1] = A[r1][j];
        }
        for(int j=c1;j<=c2-1;j++) {//오른쪽으로
            newA[r2][j + 1] = A[r2][j];
        }
        for(int i=r1+1;i<=r2;i++){//위쪽으로
            newA[i - 1][c2] = A[i][c2];
        }
        for(int i=r1;i<=r2-1;i++) {//아래쪽으로
            newA[i + 1][c1] = A[i][c1];
        }
    }
    //갱신
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) A[i][j] = newA[i][j];
    }
}
//출력
void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout<<A[i][j]<<" ";
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    for(int i=0;i<r;i++) Rotation();//회전
    output();//출력
    return 0;
}
