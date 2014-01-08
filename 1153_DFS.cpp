#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

bool visited[64];
int road[64];
int dir[8][2] = {-1, -2, -1, 2, -2, 1, -2, -1, 1, 2, 1, -2, 2, 1, 2, -1};  //all eight direction that the horse can reach

bool legal(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7)
        return false;
    return true;
}
//要剪枝， 先走下一步克星拓展最少的
//也就是说，加入当前节点有8个可以走的拓展点，对每个克星拓展点在计算它的克星拓展书，然后排序，先走可行拓展数最小的
//也就是先走最没有前途的点，那样会更快，因为没前途，所以其他点到他就更难了，所以先走
int cal_ok(int x, int y){  //计算当前节点的克星可拓展数
    int count = 0;
    for(int i = 0; i < 8; ++i){
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        if(legal(X, Y) && !visited[X + Y * 8])
            ++count;
    }
    return count;
}

struct coord{
    int x, y;
    int cnt;
    coord(int xx, int yy){   //cnt 记录可行拓展数
        x = xx;
        y = yy;
        cnt = cal_ok(xx, yy);
    }
};


bool cmp(coord a, coord b){
    return a.cnt < b.cnt;
}

//将DFS函数定义bool型，一旦递归成功搜索到解，name直接通过if函数一层层return回来
bool dfs(int x, int y, int cur){
    vector<coord> v;
    visited[y * 8 + x] = 1;
    road[cur] = y * 8 + x + 1;
    if(cur == 63)
        return true;
    for(int i = 0; i < 8; ++i){
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        if(legal(X, Y) && !visited[X + Y * 8])
            v.push_back(coord(X, Y));  //构造器中带有计算可行拓展数
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); ++i){
        if(dfs(v[i].x, v[i].y, cur + 1))
            return true;  //拓展节点成功
    }
    visited[y * 8 + x] = 0;
    return false;  //拓展节点失败
}

int main()
{
    int n;
    while(cin>>n && n != -1){
        int row, col;
        row = (n - 1) % 8;
        col = (n - 1) / 8;
        memset(visited, 0, sizeof(visited));
        
        dfs(row, col, 0);
        cout<<road[0];
        for(int i = 1; i < 64; ++i)
            cout<<" "<<road[i];
        cout<<endl;
    }
    return 0;
}
