#include <bits/stdc++.h>
using namespace std;

typedef char VertexType; // ��������
typedef int EdgeType;   // ��Ȩֵ����
typedef char Status;     // ״̬����
#define OK 1
#define ERROR 0
typedef struct ArcNode { // �߽��
    int adjvex;           // �ñ���ָ��Ķ���λ��
    EdgeType weight;     // Ȩֵ
    struct ArcNode *nextarc; // ָ����һ����
} ArcNode;
typedef struct VNode { // ������
    VertexType data;     // ������Ϣ
    ArcNode *firstarc;   // ָ���һ����
} VNode, AdjList[100]; // �ڽӱ�����
typedef struct ALGraph { // �ڽӱ�ͼ
    AdjList vertices;     // ��������
    int vexnum, arcnum;   // �������ͱ���
} ALGraph;
Status CreateDN(ALGraph *G) { // ��������ͼ
    int i, j, k;
    cout << "�����붥�����ͱ�����" << endl;
    cin >> G->vexnum >> G->arcnum;
    cout << "�����붥����Ϣ��" << endl;
    for (i = 0; i < G->vexnum; i++) {
        cin >> G->vertices[i].data;
        G->vertices[i].firstarc = NULL; // ��ʼ����ָ��
    }
    cout << "������ߵ���Ϣ����� �յ� Ȩֵ����" << endl;
    for (k = 0; k < G->arcnum; k++) {
        cin >> i >> j >> k; // ����ߵ���㡢�յ��Ȩֵ
        ArcNode *p = new ArcNode; // �����±߽��
        p->adjvex = j; // ����ָ��Ķ���
        p->weight = k; // ����Ȩֵ
        p->nextarc = G->vertices[i].firstarc; // ���뵽����ͷ��
        G->vertices[i].firstarc = p;
    }
    return OK;
}
Status CreateUDN(ALGraph *G) { // ��������ͼ
    int i, j, k;
    cout << "�����붥�����ͱ�����" << endl;
    cin >> G->vexnum >> G->arcnum;
    cout << "�����붥����Ϣ��" << endl;
    for (i = 0; i < G->vexnum; i++) {
        cin >> G->vertices[i].data;
        G->vertices[i].firstarc = NULL; // ��ʼ����ָ��
    }
    cout << "������ߵ���Ϣ����� �յ� Ȩֵ����" << endl;
    for (k = 0; k < G->arcnum; k++) {
        cin >> i >> j >> k; // ����ߵ���㡢�յ��Ȩֵ
        ArcNode *p = new ArcNode; // �����±߽��
        p->adjvex = j; // ����ָ��Ķ���
        p->weight = k; // ����Ȩֵ
        p->nextarc = G->vertices[i].firstarc; // ���뵽����ͷ��
        G->vertices[i].firstarc = p;
        p = new ArcNode; // �����±߽��
        p->adjvex = i; // ����ָ��Ķ���
        p->weight = k; // ����Ȩֵ
        p->nextarc = G->vertices[j].firstarc; // ���뵽����ͷ��
        G->vertices[j].firstarc = p;
    }
    return OK;
}
Status LocateVex(ALGraph G, VertexType u) { // ��λ����
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == u) {
            return i; // ���ض���λ��
        }
    }
    return ERROR; // δ�ҵ�����
}
Status InsertVex(ALGraph *G, VertexType u) { // ���붥��
    if (G->vexnum >= 100) {
        return ERROR; // ������󶥵���
    }
    G->vertices[G->vexnum].data = u; // ���ö�����Ϣ
    G->vertices[G->vexnum].firstarc = NULL; // ��ʼ����ָ��
    G->vexnum++; // ���Ӷ�����
    return OK;
}
Status DeleteVex(ALGraph *G, VertexType u) { // ɾ������
    int i = LocateVex(*G, u); // ��λ����
    if (i == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    ArcNode *p = G->vertices[i].firstarc; // ָ���һ����
    while (p) { // �������б�
        ArcNode *q = p;
        p = p->nextarc; // ָ����һ����
        delete q; // ɾ���߽��
    }
    for (int j = i; j < G->vexnum - 1; j++) {
        G->vertices[j] = G->vertices[j + 1]; // �ƶ���������
    }
    G->vexnum--; // ���ٶ�����
    return OK;
}
Status InsertArc(ALGraph *G, VertexType u, VertexType v, EdgeType w) { // �����
    int i = LocateVex(*G, u); // ��λ���
    int j = LocateVex(*G, v); // ��λ�յ�
    if (i == ERROR || j == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    ArcNode *p = new ArcNode; // �����±߽��
    p->adjvex = j; // ����ָ��Ķ���
    p->weight = w; // ����Ȩֵ
    p->nextarc = G->vertices[i].firstarc; // ���뵽����ͷ��
    G->vertices[i].firstarc = p;
    return OK;
}
Status DeleteArc(ALGraph *G, VertexType u, VertexType v) { // ɾ����
    int i = LocateVex(*G, u); // ��λ���
    int j = LocateVex(*G, v); // ��λ�յ�
    if (i == ERROR || j == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    ArcNode *p = G->vertices[i].firstarc; // ָ���һ����
    ArcNode *q = NULL; // ǰ�����
    while (p && p->adjvex != j) { // �������б�
        q = p;
        p = p->nextarc; // ָ����һ����
    }
    if (p) { // �ҵ���
        if (q) {
            q->nextarc = p->nextarc; // ɾ���߽��
        } else {
            G->vertices[i].firstarc = p->nextarc; // ɾ���߽��
        }
        delete p; // ɾ���߽��
    }
    return OK;
}
Status GetArc(ALGraph G, VertexType u, VertexType v, EdgeType *w) { // ��ȡ��Ȩֵ
    int i = LocateVex(G, u); // ��λ���
    int j = LocateVex(G, v); // ��λ�յ�
    if (i == ERROR || j == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    ArcNode *p = G.vertices[i].firstarc; // ָ���һ����
    while (p && p->adjvex != j) { // �������б�
        p = p->nextarc; // ָ����һ����
    }
    if (p) {
        *w = p->weight; // ��ȡȨֵ
        return OK;
    }
    return ERROR; // δ�ҵ���
}
Status GetVex(ALGraph G, VertexType u) { // ��ȡ������Ϣ
    int i = LocateVex(G, u); // ��λ����
    if (i == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    cout << "������Ϣ��" << G.vertices[i].data << endl; // ���������Ϣ
    return OK;
}
Status GetFirstAdjVex(ALGraph G, VertexType u) { // ��ȡ��һ���ڽӶ���
    int i = LocateVex(G, u); // ��λ����
    if (i == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    ArcNode *p = G.vertices[i].firstarc; // ָ���һ����
    if (p) {
        cout << "��һ���ڽӶ��㣺" << G.vertices[p->adjvex].data << endl; // ����ڽӶ�����Ϣ
        return OK;
    }
    return ERROR; // ���ڽӶ���
}
Status GetNextAdjVex(ALGraph G, VertexType u, VertexType v) { // ��ȡ��һ���ڽӶ���
    int i = LocateVex(G, u); // ��λ���
    int j = LocateVex(G, v); // ��λ�յ�
    if (i == ERROR || j == ERROR) {
        return ERROR; // δ�ҵ�����
    }
    ArcNode *p = G.vertices[i].firstarc; // ָ���һ����
    while (p && p->adjvex != j) { // �������б�
        p = p->nextarc; // ָ����һ����
    }
    if (p && p->nextarc) {
        cout << "��һ���ڽӶ��㣺" << G.vertices[p->nextarc->adjvex].data << endl; // ����ڽӶ�����Ϣ
        return OK;
    }
    return ERROR; // ���ڽӶ���
}
Status DestroyGraph(ALGraph *G) { // ����ͼ
    for (int i = 0; i < G->vexnum; i++) {
        ArcNode *p = G->vertices[i].firstarc; // ָ���һ����
        while (p) { // �������б�
            ArcNode *q = p;
            p = p->nextarc; // ָ����һ����
            delete q; // ɾ���߽��
        }
    }
    G->vexnum = 0; // ���ö�����
    G->arcnum = 0; // ���ñ���
    return OK;
}
Status DestroyGraph(ALGraph *G, int V) { // ����ͼ
    ArcNode *p = G->vertices[V].firstarc; // ָ���һ����
    while (p) { // �������б�
        ArcNode *q = p;
        p = p->nextarc; // ָ����һ����
        delete q; // ɾ���߽��
    }
    G->vexnum--; // ���ٶ�����
    return OK;
}
Status DestroyGraph(ALGraph *G, int V, int W) { // ����ͼ
    ArcNode *p = G->vertices[V].firstarc; // ָ���һ����
    while (p) { // �������б�
        ArcNode *q = p;
        p = p->nextarc; // ָ����һ����
        delete q; // ɾ���߽��
    }
    G->vexnum--; // ���ٶ�����
    return OK;
}

void PrintGraph(ALGraph G) { // ��ӡͼ
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

bool visited[100]; // ���ʱ�־����
void DFS(ALGraph G, int v) { // ������ȱ���
    visited[v] = true; // ���Ϊ�ѷ���
    cout << G.vertices[v].data << " "; // ���ʶ���
    ArcNode *p = G.vertices[v].firstarc; // ָ���һ����
    while (p) { // �������б�
        if (!visited[p->adjvex]) { // ���δ����
            DFS(G, p->adjvex); // �ݹ����
        }
        p = p->nextarc; // ָ����һ����
    }
}

// �����д����ͼ
void DFSTraverse(ALGraph G) { // �������ж���
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // ��ʼ�����ʱ�־
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // ���δ����
            DFS(G, i); // ������ȱ���
        }
    }
}
//���д����ͼ�Ͷ���
void DFSTraverse(ALGraph G,int V) { // �������ж���
    cout << V ;
    visited[V] = true; // ���Ϊ�ѷ���
    ArcNode *p = G.vertices[V].firstarc; // ָ���һ����
    while (p) { // �������б�
        if (!visited[p->adjvex]) { // ���δ����
            DFSTraverse(G, p->adjvex); // �ݹ����
        }
        p = p->nextarc; // ָ����һ����
    }
}

void DFSTraverse(ALGraph G, int V, int W) { // �������ж���
    cout << V ;
    visited[V] = true; // ���Ϊ�ѷ���
    ArcNode *p = G.vertices[V].firstarc; // ָ���һ����
    while (p) { // �������б�
        if (!visited[p->adjvex]) { // ���δ����
            DFSTraverse(G, p->adjvex); // �ݹ����
        }
        p = p->nextarc; // ָ����һ����
    }
}

void BFSTraverse(ALGraph G) { // ������ȱ���
    queue<int> q; // ����
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // ��ʼ�����ʱ�־
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // ���δ����
            visited[i] = true; // ���Ϊ�ѷ���
            cout << G.vertices[i].data << " "; // ���ʶ���
            q.push(i); // ���
            while (!q.empty()) { // ���в�Ϊ��
                int v = q.front(); // ȡ��ͷԪ��
                q.pop(); // ����
                ArcNode *p = G.vertices[v].firstarc; // ָ���һ����
                while (p) { // �������б�
                    if (!visited[p->adjvex]) { // ���δ����
                        visited[p->adjvex] = true; // ���Ϊ�ѷ���
                        cout << G.vertices[p->adjvex].data << " "; // ���ʶ���
                        q.push(p->adjvex); // ���
                    }
                    p = p->nextarc; // ָ����һ����
                }
            }
        }
    }
}

void BFSTraverse(ALGraph G, int V) { // ������ȱ���
    queue<int> q; // ����
    visited[V] = true; // ���Ϊ�ѷ���
    cout << G.vertices[V].data << " "; // ���ʶ���
    q.push(V); // ���
    while (!q.empty()) { // ���в�Ϊ��
        int v = q.front(); // ȡ��ͷԪ��
        q.pop(); // ����
        ArcNode *p = G.vertices[v].firstarc; // ָ���һ����
        while (p) { // �������б�
            if (!visited[p->adjvex]) { // ���δ����
                visited[p->adjvex] = true; // ���Ϊ�ѷ���
                cout << G.vertices[p->adjvex].data << " "; // ���ʶ���
                q.push(p->adjvex); // ���
            }
            p = p->nextarc; // ָ����һ����
        }
    }
}
void MiniSpanTree_Prim(ALGraph G, int v0) { // Prim�㷨����С������
    int min, i, j, k;
    int adjvex[100]; // �洢��С�ߵĶ���
    EdgeType lowcost[100]; // �洢��С�ߵ�Ȩֵ
    for (i = 0; i < G.vexnum; i++) {
        lowcost[i] = INT_MAX; // ��ʼ��ȨֵΪ�����
        adjvex[i] = -1; // ��ʼ������Ϊ-1
    }
    lowcost[v0] = 0; // �������ȨֵΪ0
    for (i = 1; i < G.vexnum; i++) {
        min = INT_MAX;
        j = -1;
        for (k = 0; k < G.vexnum; k++) {
            if (lowcost[k] < min && adjvex[k] == -1) { // �ҵ���СȨֵ
                min = lowcost[k];
                j = k;
            }
        }
        if (j == -1) {
            break; // �޷��������ж���
        }
        cout << "ѡ�бߣ�" << G.vertices[adjvex[j]].data << " - " << G.vertices[j].data << " Ȩֵ��" << lowcost[j] << endl;
        adjvex[j] = j; // ���Ϊ��ѡ��
        for (k = 0; k < G.vexnum; k++) {
            if (G.vertices[j].firstarc->adjvex == k && lowcost[k] > G.vertices[j].firstarc->weight) { // ����Ȩֵ
                lowcost[k] = G.vertices[j].firstarc->weight;
                adjvex[k] = j;
            }
        }
    }
}
int Find(int parent[], int i) { // ���Ҹ��ڵ�
    if (parent[i] == -1) {
        return i; // ���ظ��ڵ�
    }
    return Find(parent, parent[i]); // �ݹ����
}
void Union(int parent[], int x, int y) { // �ϲ�����
    int xroot = Find(parent, x); // ����x�ĸ��ڵ�
    int yroot = Find(parent, y); // ����y�ĸ��ڵ�
    if (xroot != yroot) {
        parent[xroot] = yroot; // �ϲ�����
    }
}
void MiniSpanTree_Kruskal(ALGraph G) { // Kruskal�㷨����С������
    int i, j, k;
    int parent[100]; // �洢����ĸ��ڵ�
    for (i = 0; i < G.vexnum; i++) {
        parent[i] = -1; // ��ʼ�����ڵ�Ϊ-1
    }
    vector<pair<int, pair<int, int>>> edges; // �洢�ߵ���Ϣ
    for (i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc; // ָ���һ����
        while (p) { // �������б�
            edges.push_back(make_pair(p->weight, make_pair(i, p->adjvex))); // ��ӱ���Ϣ
            p = p->nextarc; // ָ����һ����
        }
    }
    sort(edges.begin(), edges.end()); // ��Ȩֵ����
    for (i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first; // ���
        int v = edges[i].second.second; // �յ�
        if (Find(parent, u) != Find(parent, v)) { // �������ͬһ����
            Union(parent, u, v); // �ϲ�����
            cout << "ѡ�бߣ�" << G.vertices[u].data << " - " << G.vertices[v].data << " Ȩֵ��" << edges[i].first << endl;
        }
    }
}
void ShortestPath_Dijkstra(ALGraph G, int v0) { // Dijkstra�㷨�����·��
    int dist[100]; // �洢���·������
    bool s[100]; // ��Ƕ����Ƿ���ȷ�����·��
    for (int i = 0; i < G.vexnum; i++) {
        dist[i] = INT_MAX; // ��ʼ��Ϊ�����
        s[i] = false; // ��ʼ��Ϊfalse
    }
    dist[v0] = 0; // ����������Ϊ0
    for (int i = 0; i < G.vexnum - 1; i++) {
        int min = INT_MAX;
        int u = -1;
        for (int j = 0; j < G.vexnum; j++) {
            if (!s[j] && dist[j] < min) { // �ҵ�δȷ������С����
                min = dist[j];
                u = j;
            }
        }
        s[u] = true; // ���Ϊ��ȷ��
        ArcNode *p = G.vertices[u].firstarc; // ָ���һ����
        while (p) { // �������б�
            if (!s[p->adjvex] && dist[u] + p->weight < dist[p->adjvex]) { // �������·��
                dist[p->adjvex] = dist[u] + p->weight;
            }
            p = p->nextarc; // ָ����һ����
        }
    }
    cout << "���·�����ȣ�" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "��" << G.vertices[v0].data << "��" << G.vertices[i].data << "�����·������Ϊ��" << dist[i] << endl;
    }
}
void ShortestPath_Bellman_Ford(ALGraph G, int v0) { // Bellman-Ford�㷨�����·��
    int dist[100]; // �洢���·������
    for (int i = 0; i < G.vexnum; i++) {
        dist[i] = INT_MAX; // ��ʼ��Ϊ�����
    }
    dist[v0] = 0; // ����������Ϊ0
    for (int i = 1; i < G.vexnum - 1; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            ArcNode *p = G.vertices[j].firstarc; // ָ���һ����
            while (p) { // �������б�
                if (dist[j] != INT_MAX && dist[j] + p->weight < dist[p->adjvex]) { // �������·��
                    dist[p->adjvex] = dist[j] + p->weight;
                }
                p = p->nextarc; // ָ����һ����
            }
        }
    }
    cout << "���·�����ȣ�" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << "��" << G.vertices[v0].data << "��" << G.vertices[i].data << "�����·������Ϊ��" << dist[i] << endl;
    }
}
int main(){
    ALGraph G;
    CreateDN(&G); // ��������ͼ
    PrintGraph(G); // ��ӡͼ
    cout << "������ȱ�����" << endl;
    DFSTraverse(G); // ������ȱ���
    cout << "������ȱ�����" << endl;
    BFSTraverse(G); // ������ȱ���
    cout << "��С��������Prim�㷨����" << endl;
    MiniSpanTree_Prim(G, 0); // Prim�㷨����С������
    cout << "��С��������Kruskal�㷨����" << endl;
    MiniSpanTree_Kruskal(G); // Kruskal�㷨����С������
    cout << "���·����Dijkstra�㷨����" << endl;
    ShortestPath_Dijkstra(G, 0); // Dijkstra�㷨�����·��
    cout << "���·����Bellman-Ford�㷨����" << endl;
    ShortestPath_Bellman_Ford(G, 0); // Bellman-Ford�㷨�����·��
    DestroyGraph(&G); // ����ͼ
    return 0;
}