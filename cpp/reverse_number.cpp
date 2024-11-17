#include <iostream>
#include <string>

using namespace std;


void reverse(string& s,int l,int r){
    int n=s.size();
    char c;
    while(l<r){
        c=s[l];
        s[l]=s[r];
        s[r]=c;
        l++;
        r--;
    }
}

int main(void){
    string s;
    cin >> s;

    int n=s.size();
    int flag=0;
    int ptr=-1;


    //脑子抽了将就看吧
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            flag=1;
            ptr=i;
        }
        else if(s[i]=='/'){
            flag=2;
            ptr=i;
        }
        else if(s[i]=='%'){
            flag=3;
        }
    }

    if(flag==0){
        reverse(s,0,n-1);
    }
    else{
        reverse(s,0,ptr-1);
        reverse(s,ptr+1,n-1);
    }

    cout << s << endl;

    return 0;

}