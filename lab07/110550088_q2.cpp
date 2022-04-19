#include <bits/stdc++.h>

using namespace std;

int selection_sort(vector<int> a){
    int cnt = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i], a[min]);
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << selection_sort(a) << endl;
}