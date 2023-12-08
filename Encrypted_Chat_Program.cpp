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

void process(int user){
    string s;

    cin.ignore();
    getline(cin, s);

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
    
    cout << endl << "Output: " << endl;
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "1.Encrypt\n";
    cout << "2.Decrypt\n\n" << flush;
    
    while(true){
        cout << "Select Operation: " << flush;
        
        int user;
        cin >> user;

        if(user != 1 && user != 2) break;

        cout << "\nInput: " << endl;
        
        process(user);
    }

    


    return 0;
}
