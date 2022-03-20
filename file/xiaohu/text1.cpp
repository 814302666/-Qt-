#include <iostream>
#include <vector>
#include <string>

using namespace std;

//题目 https://leetcode-cn.com/problems/reformat-the-string/

string reformat(string s) {
    string s1 = "",s2 = "";
    for(char c : s){
        if(isdigit(c)) s1 += c;
        else s2 += c;
    }
    int n1 = s1.length(),n2 = s2.length();
    if(abs(n1 - n2) > 2) return "";
    string result = "";
    if(n1 > n2){
        int i = 0;
        while(i < n1 + n2){
            if(i % 2) result += s1[i % 2];
            else result += s2[i % 2];
        }
    }
    else{
        int i = 0;
        while(i < n1 + n2){
            if(i % 2) result += s2[i % 2];
            else result += s1[i % 2];
        }
    }
    return result;
}

int main(){
    string s = "a0b1c2";
    cout << reformat(s) << endl;
    system("pause");
}