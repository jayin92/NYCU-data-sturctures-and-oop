#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    private:
        vector<long long> heap;
    public:
        int size;
        MinHeap(){
            size = 0;
            heap.push_back(-1);
        }
        void insert(long long val){
            heap.push_back(val);
            size++;
            int i = size;
            while(i > 1 && heap[i] < heap[i/2]){
                swap(heap[i], heap[i/2]);
                i = i/2;
            }
        }

        long long remove(){
            if(size == 0) return -1;
            long long res = heap[1];
            heap[1] = heap[size];
            heap.pop_back();
            size --;
            int i = 1;
            while(i <= size){
                int l = 2*i;
                int r = 2*i + 1;
                if(l > size) break;
                if(r > size){
                    if(heap[l] < heap[i]){
                        swap(heap[l], heap[i]);
                        i = l;
                    } else {
                        break;
                    }
                } else {
                    if(heap[l] < heap[i] || heap[r] < heap[i]){
                        if(heap[l] < heap[r]){ // l is the smallest
                            swap(heap[l], heap[i]);
                            i = l;
                        } else { // r is the smallest
                            swap(heap[r], heap[i]);
                            i = r;
                        }
                    } else {
                        break;
                    }
                }
            }
            return res;
        }
};



int main(){
    int n;
    while(cin >> n){
        if(n == 0)  return 0;
        vector<int> a(n);
        for(auto &i: a){
            cin >> i;
        }
        MinHeap heap;
        for(auto i: a){
            heap.insert(i);
        }
        long long ans = 0;
        while(heap.size != 0){
            long long x = heap.remove();
            long long y = heap.remove();
            ans += x + y;
            if(heap.size == 0) break;
            else heap.insert(x + y);
        }
        cout << ans << endl;
    }
}