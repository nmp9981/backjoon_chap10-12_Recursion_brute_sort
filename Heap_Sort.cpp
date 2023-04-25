#include <iostream>
#include <algorithm>
using namespace std;

int n = 5;
int A[] = {8,4,1,7,2};

//힙 생성
void MakeHeap(int A[], int n,int i) {
    int parentNode = i;//부모노드
    int leftNode = 2 * i + 1;//왼쪽 자식
    int rightNode = 2 * i + 2;//오른쪽 자식

    //왼쪽 자식 노드(더 크면 갱신)
    if (leftNode < n && A[parentNode] < A[leftNode]) parentNode = leftNode;

    //오른쪽 자식 노드(더 크면 갱신)
    if (rightNode < n && A[parentNode] < A[rightNode]) parentNode = rightNode;

    //자식노드가 더 큰가?
    if (i != parentNode) {
        swap(A[parentNode], A[i]);//자리교환
        MakeHeap(A, n, parentNode);//부모노드가 제자리 찾을때까지 진행
    }
}
//힙 정렬
void HeapSort(int A[],int n) {
    //최대 힙 구성
    for (int i = (n / 2) - 1; i >= 0; i--) MakeHeap(A, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);//Root와 마지막 노드를 바꾼다.
        MakeHeap(A, i, 0);//힙 재구조화
    }
}
int main()
{
    HeapSort(A, n);//힙 정렬
    for (int i = 0; i < n; i++) cout << A[i] << " ";//출력
    return 0;
}
