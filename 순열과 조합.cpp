#include <iostream>
#include <vector>
using namespace std;

int n,m;
const int maxi = 9;
vector<int> v;
bool visit[maxi] = { false, };

//입력
void input() {
    cin >> n>>m;
}
//순열(n P m, n <= 8)
void Permunitation(int cnt) {
    //출력
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << v[i] << " ";
        cout << "\n";
        return;
    }
    //다음 숫자
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;

        v.push_back(i);
        visit[i] = true;
        Permunitation(cnt + 1);
        visit[i] = false;
        v.pop_back();
    }
}
//조합(n C m, n <= 8)
void Combination(int idx,int cnt) {
    //출력
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << v[i] << " ";
        cout << "\n";
        return;
    }
    //다음 숫자
    for (int i = idx; i <= n; i++) {
        if (visit[i]) continue;

        v.push_back(i);
        visit[i] = true;
        Combination(i+1,cnt + 1);
        visit[i] = false;
        v.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Permunitation(0);//순열
    cout << "\n";
    v.clear();
    Combination(1,0);//조합
    return 0;
}
