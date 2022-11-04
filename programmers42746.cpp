#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> num;

//정렬 기준
bool cmp(string& a, string& b){
    return a+b>b+a;
}
//문자열로
void Change(vector<int> numbers){
    for(int i=0;i<numbers.size();i++) num.push_back(to_string(numbers[i]));//문자열로
    sort(num.begin(),num.end(),cmp);//정렬
}
string solution(vector<int> numbers) {
    string answer = "";
    Change(numbers);//문자열로
    //문자열 이어붙이기
    for(int i=0;i<num.size();i++) answer+= num[i];
    //0예외
    if(num[0]=="0") answer = "0";
    return answer;
}
