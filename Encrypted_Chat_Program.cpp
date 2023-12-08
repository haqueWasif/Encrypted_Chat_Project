#include<bits/stdc++.h>
using namespace std;

void encrypt(string &s){
    for(auto &ch : s){
        if(ch >= 'A' && ch <= 'Z'){
            ch = 'Z' - (ch - 'A');
        }
        else if(ch >= 'a' && ch <= 'z'){
            ch = 'z' - (ch - 'a');
        }
        ch++;
    }
}

void decrypt(string &s){
    for(auto &ch : s){
        ch--;
        if(ch >= 'A' && ch <= 'Z'){
            ch = 'A' + ('Z' - ch);
        }
        else if(ch >= 'a' && ch <= 'z'){
            ch = 'a' + ('z' - ch);
        } 
        
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cout << "Select Operation: " << endl;
    cout << "1.Encrypt" << endl;
    cout << "2.Decrypt" << endl;

    int user;
    cin >> user;

    while(getline(cin, s)){
        stringstream ss(s);

        vector<string> v;

        string word;
        while(ss >> word){
            v.push_back(word);
        }

        for(auto &val : v){
            reverse(val.begin(), val.end());
            if(user == 1) encrypt(val);
            else decrypt(val);
        }

        for(int i=v.size()-1; i>=0; i--){
            cout << v[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
