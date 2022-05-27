#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a(19, 0);
    vector<int> b(19, 0);

    int n;
    cin >> n;
    int t;
    for(int i=0;i<n;i++){
        cin >> t;
        int hash = t % 19;
        int probe = 0;
        while(probe < 19 and a[(hash+probe)%19] != 0){
            probe ++;
        }
        if(a[(hash+probe)%19] == 0)
            a[(hash+probe)%19] = t;

        hash = t % 19;
        probe = 0;
        while(probe < 19 and b[(hash+probe*probe)%19] != 0){
            probe ++;
        }
        if(b[(hash+probe*probe)%19] == 0){
            b[(hash+probe*probe)%19] = t;
        }
    }
    for(auto i: a) cout << i << " ";
    cout << endl;
    for(auto i: b) cout << i << " ";
    cout << endl;
}