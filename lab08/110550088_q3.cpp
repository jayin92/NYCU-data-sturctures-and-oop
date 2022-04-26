#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b, int n){
    vector<int> c;
    int i = 0, j = 0;
    
    while(i < n && j < n){
        if(a[i] < b[j]){
            c.push_back(a[i]);
            i++;
        }else{
            c.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        c.push_back(a[i]);
        i++;
    }
    while(j < n){
        c.push_back(b[j]);
        j++;
    }
    return c;
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n/2);
    vector<int> b(n/2);
    for(int i=0;i<n/2;i++){
        cin >> a[i];
    }
    for(int i=0;i<n/2;i++){
        cin >> b[i];
    }
    auto c = merge(a, b, n/2);
    for(auto i: c){
        cout << i << " ";
    }
    cout << endl;
}