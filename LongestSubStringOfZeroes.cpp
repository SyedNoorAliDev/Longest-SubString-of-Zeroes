#include <iostream>
#include <vector>
using namespace std;
bool ZeroSubstring(string str){
    bool t = true;
    for (int i=0;i<str.size();i++){
        if (str[i] == '0'){
            t=true;
            return true;
        }
    }
    return false;
}
int LargestZeroSubString(string n){
    if (!ZeroSubstring(n)){
        return 0;
    } else {
    vector<int> v;
    int count = 0;
    for (int i=0;i<n.length();i++){
        if (n[i]=='0'){
            count +=1;
            if ((i==n.length()-1)){
                v.push_back(count);
            }
        } else if ((n[i] != '0') && (n[i-1] == '0')){
            v.push_back(count);
            count = 0;
        }
    }
        vector<int>::iterator maximum = max_element(v.begin(), v.end());
        return *maximum;
    }

}
int main(){
    int a = LargestZeroSubString("0011000110000000000");
    int b = LargestZeroSubString("1111111111111111");
    cout<<"Maximum Sub Array of Zero A: "<<a<<endl;
    cout<<"Maximum Sub Array of Zero B: "<<b<<endl;

}