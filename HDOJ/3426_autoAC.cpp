#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<string> st;
int tag_type(const string& s) {
    int cnt=0;    
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='/') { cnt++; continue; }
        if(!((s[i]<='z' && s[i]>='a') || (s[i]>='0' && s[i]<='9'))) return 0;
    }
    if(s.size()-cnt==0) return 0;
    if(s[0]=='/' && cnt == 1) return 2;
    if(s[s.size()-1]=='/' && cnt == 1) return 3;
    if(cnt == 0) return 1;
    return 0;
}
bool hex(const string& s) {
    if(s.size() <= 1 || s.size()%2==0) return false;
    if(s[0] != 'x') return false;
    for(int i=1; i<s.size(); ++i)
        if( !((s[i]<='F' && s[i] >='A') || (s[i]<='9' && s[i]>='0') || (s[i]<='f' && s[i]>='a')) ) return false;
    return true;
}
bool bad_qoute(const string& s) {
    return !(s=="lt" || s=="gt" || s=="amp" || hex(s));
}
bool bad_txt(const string& s) {
    string qoute;
    for(int i=0; i<s.size(); ++i)
        if(s[i]=='&') {
            for(int j=i+1; j<s.size() && s[j] != ';'; ++j) qoute += s[j];
            if(bad_qoute(qoute)) return true;
            qoute="";
        } 
        else if(s[i]=='<' || s[i] =='>') return true;
        else if(s[i]>127 || s[i]<32) return true;
    return false;
}
void get_l(stringstream& os, string& s, char del) {
    char t;
    while(!os.eof()) {
        os >> t;
        if(t==del) return;
        s += t;
    }    
}
int main() {
    string ln;
    while(getline(cin, ln)) {
        stringstream ss(ln);
        st.clear();
        string s;
        int inv=0;
        while(!ss.eof()) {
            s="";
            getline(ss,s,'<');
            if(bad_txt(s)) {
                inv=1;
                break;
            }
            if(ss.eof()) break;
            s="";
            getline(ss,s,'>');
            if(ss.eof()) {
                inv=4;
                break;
            }
            int tty = tag_type(s);
            if(tty==0) {
                inv=2;
                break;
            } 
            else if(tty==1) st.push_back(s);
            else if(tty==2) {                
                if(st.size()==0 || st.back() != s.substr(1)) {
                    inv=3;
                    break;
                }
                else st.pop_back();
            }
        }
        if(inv || st.size() > 0) puts("invalid");
        else puts("valid");
    }
    return 0;
}
