#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<int > vd;
    vector<char > vr;
    int i,j,count=0,x,y,z;
    cout << "Enter value of x,y,z : ";
    cin >>x >>y >>z;
    cout << endl;
    cout << "Enter the expression : ";
    cin>> s;
    int l=s.length();
    for(i=0;i<l;i++){
        if(s[i]=='x'){
            vd.push_back(x);
        }
        else if(s[i]=='y'){
            vd.push_back(y);
        }
        else if(s[i]=='z'){
            vd.push_back(z);
        }
        else{
            vr.push_back(s[i]);
        }
    }

    ///for operator * and /
    int size=vr.size();
    vector<char> copyvr;
    copyvr=vr;
    for(i=0;i<=size;i++){
        if(copyvr[i]=='*'||copyvr[i]=='/'){
            int mul,l1;
            if(copyvr[i]=='*'){
                auto low1 = std::find(vr.begin(), vr.end(), '*');
                l1=low1-vr.begin();
                mul=vd[l1]*vd[l1+1];
            }
            else if(copyvr[i]=='/'){
                auto low1 = std::find(vr.begin(), vr.end(), '/');
                l1=low1-vr.begin();
                mul=vd[l1]/vd[l1+1];
            }
            vd.erase(vd.begin()+l1+1);
            vd.erase(vd.begin()+l1);
            vd.insert(vd.begin()+l1,mul);
            vr.erase(vr.begin()+l1);
        }
    }

    ///for operator + and -
    if(!vr.empty()){
        int size2=vr.size();
        vector<char> copyvr2;
        copyvr2=vr;
        for(i=0;i<=size2;i++){
            if(copyvr2[i]=='+'||copyvr2[i]=='-'){
                int mul,l1;
                if(copyvr2[i]=='+'){
                    auto low1 = std::find(vr.begin(), vr.end(), '+');
                    l1=low1-vr.begin();
                    mul=vd[l1]+vd[l1+1];
                }
                else if(copyvr2[i]=='-'){
                    auto low1 = std::find(vr.begin(), vr.end(), '-');
                    l1=low1-vr.begin();
                    mul=vd[l1]-vd[l1+1];
                }
                vd.erase(vd.begin()+l1+1);
                vd.erase(vd.begin()+l1);
                vd.insert(vd.begin()+l1,mul);
                vr.erase(vr.begin()+l1);
            }
        }
    }
    cout << endl;
    cout << "final result of \"" <<s << "\" = ";
    for(auto ir=vd.begin();ir!=vd.end();++ir){
        cout << *ir <<" ";
    }
    cout << endl;

    return 0;
}
