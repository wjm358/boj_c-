#include<iostream>
#include<cmath>
#include<queue>
#include<vector>

#define INF 987654321;
using namespace std;

int n, m;

vector<int> is_connect[20000];
bool v[20000];
int max_value = 0;
int vertex[20000];
void bfs() {
    queue<int> q;
    q.push(0);
    int cnt =0 ;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if(v[here] ) continue;
        v[here] = true;
        for(int i=0;i<is_connect[here].size();i++) {
            int ver=  is_connect[here][i];
            if(!v[ver]) {
                q.push(ver);
                vertex[ver] = min(vertex[ver], vertex[here]+1);
                max_value = max(max_value,vertex[ver]);
            }
        }



    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m; 

    for(int i=0; i<n;i++) {
        vertex[i] = INF;
    }
    vertex[0] = 0;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a>> b;
        is_connect[a-1].push_back(b-1);
        is_connect[b-1].push_back(a-1);
    }

    bfs();
    int idx =200001;
    int count =0;
    for(int i=0;i<n;i++) {
        if(max_value == vertex[i]) {
            count++;
            idx = min(idx,i);
        }
    }

    cout << idx+1 << " " << vertex[idx] << " " << count << endl;

}