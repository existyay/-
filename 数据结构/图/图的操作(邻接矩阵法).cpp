#include <bits/stdc++.h>
using namespace std;

typedef char VertexType; // 顶点类型
typedef int EdgeType;   // 边权值类型
typedef char Status;     // 状态类型
#define OK 1
#define ERROR 0
typedef struct ArcNode { // 边结点
    int adjvex;           // 该边所指向的顶点位置
    EdgeType weight;     // 权值
    struct ArcNode *nextarc; // 指向下一条边
} ArcNode;
typedef struct VNode { // 顶点结点
    VertexType data;     // 顶点信息
    ArcNode *firstarc;   // 指向第一条边
} VNode, AdjList[100]; // 邻接表类型
typedef struct ALGraph { // 邻接表图
    AdjList vertices;     // 顶点数组
    int vexnum, arcnum;   // 顶点数和边数
} ALGraph;
Status CreateDN(ALGraph *G) { // 创建有向图
    int i, j, k;
    cout << "请输入顶点数和边数：" << endl;
    cin >> G->vexnum >> G->arcnum;
    cout << "请输入顶点信息：" << endl;
    for (i = 0; i < G->vexnum; i++) {
        cin >> G->vertices[i].data;
        G->vertices[i].firstarc = NULL; // 初始化边指针
    }
    cout << "请输入边的信息（起点 终点 权值）：" << endl;
    for (k = 0; k < G->arcnum; k++) {
        cin >> i >> j >> k; // 输入边的起点、终点和权值
        ArcNode *p = new ArcNode; // 创建新边结点
        p->adjvex = j; // 设置指向的顶点
        p->weight = k; // 设置权值
        p->nextarc = G->vertices[i].firstarc; // 插入到链表头部
        G->vertices[i].firstarc = p;
    }
    return OK;
}
Status CreateUDN(ALGraph *G) { // 创建无向图
    int i, j, k;
    cout << "请输入顶点数和边数：" << endl;
    cin >> G->vexnum >> G->arcnum;
    cout << "请输入顶点信息：" << endl;
    for (i = 0; i < G->vexnum; i++) {
        cin >> G->vertices[i].data;
        G->vertices[i].firstarc = NULL; // 初始化边指针
    }
    cout << "请输入边的信息（起点 终点 权值）：" << endl;
    for (k = 0; k < G->arcnum; k++) {
        cin >> i >> j >> k; // 输入边的起点、终点和权值
        ArcNode *p = new ArcNode; // 创建新边结点
        p->adjvex = j; // 设置指向的顶点
        p->weight = k; // 设置权值
        p->nextarc = G->vertices[i].firstarc; // 插入到链表头部
        G->vertices[i].firstarc = p;
        p = new ArcNode; // 创建新边结点
        p->adjvex = i; // 设置指向的顶点
        p->weight = k; // 设置权值
        p->nextarc = G->vertices[j].firstarc; // 插入到链表头部
        G->vertices[j].firstarc = p;
    }
    return OK;
}
Status LocateVex(ALGraph G, VertexType u) { // 定位顶点
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == u) {
            return i; // 返回顶点位置
        }
    }
    return ERROR; // 未找到顶点
}
Status InsertVex(ALGraph *G, VertexType u) { // 插入顶点
    if (G->vexnum >= 100) {
        return ERROR; // 超过最大顶点数
    }
    G->vertices[G->vexnum].data = u; // 设置顶点信息
    G->vertices[G->vexnum].firstarc = NULL; // 初始化边指针
    G->vexnum++; // 增加顶点数
    return OK;
}
Status DeleteVex(ALGraph *G, VertexType u) { // 删除顶点
    int i = LocateVex(*G, u); // 定位顶点
    if (i == ERROR) {
        return ERROR; // 未找到顶点
    }
    ArcNode *p = G->vertices[i].firstarc; // 指向第一条边
    while (p) { // 遍历所有边
        ArcNode *q = p;
        p = p->nextarc; // 指向下一条边
        delete q; // 删除边结点
    }
    for (int j = i; j < G->vexnum - 1; j++) {
        G->vertices[j] = G->vertices[j + 1]; // 移动后续顶点
    }
    G->vexnum--; // 减少顶点数
    return OK;
}
Status InsertArc(ALGraph *G, VertexType u, VertexType v, EdgeType w) { // 插入边
    int i = LocateVex(*G, u); // 定位起点
    int j = LocateVex(*G, v); // 定位终点
    if (i == ERROR || j == ERROR) {
        return ERROR; // 未找到顶点
    }
    ArcNode *p = new ArcNode; // 创建新边结点
    p->adjvex = j; // 设置指向的顶点
    p->weight = w; // 设置权值
    p->nextarc = G->vertices[i].firstarc; // 插入到链表头部
    G->vertices[i].firstarc = p;
    return OK;
}
Status DeleteArc(ALGraph *G, VertexType u, VertexType v) { // 删除边
    int i = LocateVex(*G, u); // 定位起点
    int j = LocateVex(*G, v); // 定位终点
    if (i == ERROR || j == ERROR) {
        return ERROR; // 未找到顶点
    }
    ArcNode *p = G->vertices[i].firstarc; // 指向第一条边
    ArcNode *q = NULL; // 前驱结点
    while (p && p->adjvex != j) { // 遍历所有边
        q = p;
        p = p->nextarc; // 指向下一条边
    }
    if (p) { // 找到边
        if (q) {
            q->nextarc = p->nextarc; // 删除边结点
        } else {
            G->vertices[i].firstarc = p->nextarc; // 删除边结点
        }
        delete p; // 删除边结点
    }
    return OK;
}
Status GetArc(ALGraph G, VertexType u, VertexType v, EdgeType *w) { // 获取边权值
    int i = LocateVex(G, u); // 定位起点
    int j = LocateVex(G, v); // 定位终点
    if (i == ERROR || j == ERROR) {
        return ERROR; // 未找到顶点
    }
    ArcNode *p = G.vertices[i].firstarc; // 指向第一条边
    while (p && p->adjvex != j) { // 遍历所有边
        p = p->nextarc; // 指向下一条边
    }
    if (p) {
        *w = p->weight; // 获取权值
        return OK;
    }
    return ERROR; // 未找到边
}
Status GetVex(ALGraph G, VertexType u) { // 获取顶点信息
    int i = LocateVex(G, u); // 定位顶点
    if (i == ERROR) {
        return ERROR; // 未找到顶点
    }
    cout << "顶点信息：" << G.vertices[i].data << endl; // 输出顶点信息
    return OK;
}
Status GetFirstAdjVex(ALGraph G, VertexType u) { // 获取第一个邻接顶点
    int i = LocateVex(G, u); // 定位顶点
    if (i == ERROR) {
        return ERROR; // 未找到顶点
    }
    ArcNode *p = G.vertices[i].firstarc; // 指向第一条边
    if (p) {
        cout << "第一个邻接顶点：" << G.vertices[p->adjvex].data << endl; // 输出邻接顶点信息
        return OK;
    }
    return ERROR; // 无邻接顶点
}
Status GetNextAdjVex(ALGraph G, VertexType u, VertexType v) { // 获取下一个邻接顶点
    int i = LocateVex(G, u); // 定位起点
    int j = LocateVex(G, v); // 定位终点
    if (i == ERROR || j == ERROR) {
        return ERROR; // 未找到顶点
    }
    ArcNode *p = G.vertices[i].firstarc; // 指向第一条边
    while (p && p->adjvex != j) { // 遍历所有边
        p = p->nextarc; // 指向下一条边
    }
    if (p && p->nextarc) {
        cout << "下一个邻接顶点：" << G.vertices[p->nextarc->adjvex].data << endl; // 输出邻接顶点信息
        return OK;
    }
    return ERROR; // 无邻接顶点
}
Status DestroyGraph(ALGraph *G) { // 销毁图
    for (int i = 0; i < G->vexnum; i++) {
        ArcNode *p = G->vertices[i].firstarc; // 指向第一条边
        while (p) { // 遍历所有边
            ArcNode *q = p;
            p = p->nextarc; // 指向下一条边
            delete q; // 删除边结点
        }
    }
    G->vexnum = 0; // 重置顶点数
    G->arcnum = 0; // 重置边数
    return OK;
}
Status DestroyGraph(ALGraph *G, int V) { // 销毁图
    ArcNode *p = G->vertices[V].firstarc; // 指向第一条边
    while (p) { // 遍历所有边
        ArcNode *q = p;
        p = p->nextarc; // 指向下一条边
        delete q; // 删除边结点
    }
    G->vexnum--; // 减少顶点数
    return OK;
}
Status DestroyGraph(ALGraph *G, int V, int W) { // 销毁图
    ArcNode *p = G->vertices[V].firstarc; // 指向第一条边
    while (p) { // 遍历所有边
        ArcNode *q = p;
        p = p->nextarc; // 指向下一条边
        delete q; // 删除边结点
    }
    G->vexnum--; // 减少顶点数
    return OK;
}

void PrintGraph(ALGraph G) { // 打印图
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.vertices[i].data << ": ";
        for(int j = 0; j < G.vexnum; j++) {
            cout << G.vertices[i].data << " ";
            cout << endl;
        }
        // ArcNode *p = G.vertices[i].firstarc;
        // while (p) {
        //     cout << "(" << G.vertices[p->adjvex].data << ", " << p->weight << ") ";
        //     p = p->nextarc;
        // }
        // cout << endl;
    }
}

bool visited[100]; // 访问标志数组
void DFS(ALGraph G, int v) { // 深度优先遍历
    visited[v] = true; // 标记为已访问
    cout << G.vertices[v].data << " "; // 访问顶点
    ArcNode *p = G.vertices[v].firstarc; // 指向第一条边
    while (p) { // 遍历所有边
        if (!visited[p->adjvex]) { // 如果未访问
            DFS(G, p->adjvex); // 递归访问
        }
        p = p->nextarc; // 指向下一条边
    }
}

// 仅含有传入的图
void DFSTraverse(ALGraph G) { // 遍历所有顶点
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // 初始化访问标志
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // 如果未访问
            DFS(G, i); // 深度优先遍历
        }
    }
}
//含有传入的图和顶点
void DFSTraverse(ALGraph G,int V) { // 遍历所有顶点
    cout << V ;
    visited[V] = true; // 标记为已访问
    ArcNode *p = G.vertices[V].firstarc; // 指向第一条边
    while (p) { // 遍历所有边
        if (!visited[p->adjvex]) { // 如果未访问
            DFSTraverse(G, p->adjvex); // 递归访问
        }
        p = p->nextarc; // 指向下一条边
    }
}

void DFSTraverse(ALGraph G, int V, int W) { // 遍历所有顶点
    cout << V ;
    visited[V] = true; // 标记为已访问
    ArcNode *p = G.vertices[V].firstarc; // 指向第一条边
    while (p) { // 遍历所有边
        if (!visited[p->adjvex]) { // 如果未访问
            DFSTraverse(G, p->adjvex); // 递归访问
        }
        p = p->nextarc; // 指向下一条边
    }
}

void BFSTraverse(ALGraph G) { // 广度优先遍历
    queue<int> q; // 队列
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // 初始化访问标志
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // 如果未访问
            visited[i] = true; // 标记为已访问
            cout << G.vertices[i].data << " "; // 访问顶点
            q.push(i); // 入队
            while (!q.empty()) { // 队列不为空
                int v = q.front(); // 取队头元素
                q.pop(); // 出队
                ArcNode *p = G.vertices[v].firstarc; // 指向第一条边
                while (p) { // 遍历所有边
                    if (!visited[p->adjvex]) { // 如果未访问
                        visited[p->adjvex] = true; // 标记为已访问
                        cout << G.vertices[p->adjvex].data << " "; // 访问顶点
                        q.push(p->adjvex); // 入队
                    }
                    p = p->nextarc; // 指向下一条边
                }
            }
        }
    }
}

void BFSTraverse(ALGraph G, int V) { // 广度优先遍历
    queue<int> q; // 队列
    visited[V] = true; // 标记为已访问
    cout << G.vertices[V].data << " "; // 访问顶点
    q.push(V); // 入队
    while (!q.empty()) { // 队列不为空
        int v = q.front(); // 取队头元素
        q.pop(); // 出队
        ArcNode *p = G.vertices[v].firstarc; // 指向第一条边
        while (p) { // 遍历所有边
            if (!visited[p->adjvex]) { // 如果未访问
                visited[p->adjvex] = true; // 标记为已访问
                cout << G.vertices[p->adjvex].data << " "; // 访问顶点
                q.push(p->adjvex); // 入队
            }
            p = p->nextarc; // 指向下一条边
        }
    }
}
void MiniSpanTree_Prim(ALGraph G, int v0) { // Prim算法求最小生成树
    int min, i, j, k;
    int adjvex[100]; // 存储最小边的顶点
    EdgeType lowcost[100]; // 存储最小边的权值
    for (i = 0; i < G.vexnum; i++) {
        lowcost[i] = INT_MAX; // 初始化权值为无穷大
        adjvex[i] = -1; // 初始化顶点为-1
    }
    lowcost[v0] = 0; // 设置起点权值为0
    for (i = 1; i < G.vexnum; i++) {
        min = INT_MAX;
        j = -1;
        for (k = 0; k < G.vexnum; k++) {
            if (lowcost[k] < min && adjvex[k] == -1) { // 找到最小权值
                min = lowcost[k];
                j = k;
            }
        }
        if (j == -1) {
            break; // 无法连接所有顶点
        }
        cout << "选中边：" << G.vertices[adjvex[j]].data << " - " << G.vertices[j].data << " 权值：" << lowcost[j] << endl;
        adjvex[j] = j; // 标记为已选中
        for (k = 0; k < G.vexnum; k++) {
            if (G.vertices[j].firstarc->adjvex == k && lowcost[k] > G.vertices[j].firstarc->weight) { // 更新权值
                lowcost[k] = G.vertices[j].firstarc->weight;
                adjvex[k] = j;
            }
        }
    }
}
int Find(int parent[], int i) { // 查找根节点
    if (parent[i] == -1) {
        return i; // 返回根节点
    }
    return Find(parent, parent[i]); // 递归查找
}
void Union(int parent[], int x, int y) { // 合并集合
    int xroot = Find(parent, x); // 查找x的根节点
    int yroot = Find(parent, y); // 查找y的根节点
    if (xroot != yroot) {
        parent[xroot] = yroot; // 合并集合
    }
}
void MiniSpanTree_Kruskal(ALGraph G) { // Kruskal算法求最小生成树
    int i, j, k;
    int parent[100]; // 存储顶点的父节点
    for (i = 0; i < G.vexnum; i++) {
        parent[i] = -1; // 初始化父节点为-1
    }
    vector<pair<int, pair<int, int>>> edges; // 存储边的信息
    for (i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc; // 指向第一条边
        while (p) { // 遍历所有边
            edges.push_back(make_pair(p->weight, make_pair(i, p->adjvex))); // 添加边信息
            p = p->nextarc; // 指向下一条边
        }
    }
    sort(edges.begin(), edges.end()); // 按权值排序
    for (i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first; // 起点
        int v = edges[i].second.second; // 终点
        if (Find(parent, u) != Find(parent, v)) { // 如果不在同一集合
            Union(parent, u, v); // 合并集合
            cout << "选中边：" << G.vertices[u].data << " - " << G.vertices[v].data << " 权值：" << edges[i].first << endl;
        }
    }
}
void ShortestPath_Dijkstra(ALGraph G, int v0) { // Dijkstra算法求最短路径
    int dist[100]; // 存储最短路径长度
    bool s[100]; // 标记顶点是否已确定最短路径
    for (int i = 0; i < G.vexnum; i++) {
        dist[i] = INT_MAX; // 初始化为无穷大
        s[i] = false; // 初始化为false
    }
    dist[v0] = 0; // 设置起点距离为0
    for (int i = 0; i < G.vexnum - 1; i++) {
        int min = INT_MAX;
        int u = -1;
        for (int j = 0; j < G.vexnum; j++) {
            if (!s[j] && dist[j] < min) { // 找到未确定的最小距离
                min = dist[j];
                u = j;
            }
        }
        s[u] = true; // 标记为已确定
        ArcNode *p = G.vertices[u].firstarc; // 指向第一条边
        while (p) { // 遍历所有边
            if (!s[p->adjvex] && dist[u] + p->weight < dist[p->adjvex]) { // 更新最短路径
                dist[p->adjvex] = dist[u] + p->weight;
            }
            p = p->nextarc; // 指向下一条边
        }
    }
    cout << "最短路径长度：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "从" << G.vertices[v0].data << "到" << G.vertices[i].data << "的最短路径长度为：" << dist[i] << endl;
    }
}
void ShortestPath_Bellman_Ford(ALGraph G, int v0) { // Bellman-Ford算法求最短路径
    int dist[100]; // 存储最短路径长度
    for (int i = 0; i < G.vexnum; i++) {
        dist[i] = INT_MAX; // 初始化为无穷大
    }
    dist[v0] = 0; // 设置起点距离为0
    for (int i = 1; i < G.vexnum - 1; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            ArcNode *p = G.vertices[j].firstarc; // 指向第一条边
            while (p) { // 遍历所有边
                if (dist[j] != INT_MAX && dist[j] + p->weight < dist[p->adjvex]) { // 更新最短路径
                    dist[p->adjvex] = dist[j] + p->weight;
                }
                p = p->nextarc; // 指向下一条边
            }
        }
    }
    cout << "最短路径长度：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "从" << G.vertices[v0].data << "到" << G.vertices[i].data << "的最短路径长度为：" << dist[i] << endl;
    }
}
int main(){
    ALGraph G;
    CreateDN(&G); // 创建有向图
    PrintGraph(G); // 打印图
    cout << "深度优先遍历：" << endl;
    DFSTraverse(G); // 深度优先遍历
    cout << "广度优先遍历：" << endl;
    BFSTraverse(G); // 广度优先遍历
    cout << "最小生成树（Prim算法）：" << endl;
    MiniSpanTree_Prim(G, 0); // Prim算法求最小生成树
    cout << "最小生成树（Kruskal算法）：" << endl;
    MiniSpanTree_Kruskal(G); // Kruskal算法求最小生成树
    cout << "最短路径（Dijkstra算法）：" << endl;
    ShortestPath_Dijkstra(G, 0); // Dijkstra算法求最短路径
    cout << "最短路径（Bellman-Ford算法）：" << endl;
    ShortestPath_Bellman_Ford(G, 0); // Bellman-Ford算法求最短路径
    DestroyGraph(&G); // 销毁图
    return 0;
}