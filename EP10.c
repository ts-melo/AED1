#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAXSIZE 1200

typedef unsigned uint;

uint dist[MAXSIZE];
uint grafo[MAXSIZE][MAXSIZE];

void dijkstra(int, int, uint g[MAXSIZE][MAXSIZE], uint *);

int main(int argc, char **argv)
{
    int r, e, c;
    int n, m, u, v;

    while (~scanf("%d %d", &n, &m))
    {
        // Inicializa a matriz de adjacência com INT_MAX
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                grafo[i][j] = INT_MAX;

        // Lê as rotas entre as cidades e marca as conexões na matriz de adjacência
        for (int i = 0; i < m; ++i)
            scanf("%d %d", &u, &v), grafo[u][v] = grafo[v][u] = 1;

        // Lê as cidades Curytyba, Riacho de Fevereiro e Estadunido
        scanf("%d %d %d", &c, &r, &e);

        // Marca Estadunido como inalcançável na matriz de adjacência
        for (int i = 0; i <= n; ++i)
            grafo[e][i] = grafo[i][e] = INT_MAX;

        // Chama a função dijkstra para calcular a distância mínima
        dijkstra(c, n, grafo, dist);

        // Imprime a distância mínima de Curytyba para Riacho de Fevereiro
        printf("%d\n", dist[r]);
    }

    return 0;
}

void dijkstra(int s, int n, uint g[MAXSIZE][MAXSIZE], uint *d)
{
    bool foi[n + 1];
    memset(foi, false, sizeof(foi));

    for (int i = 0; i <= n; ++i)
        d[i] = INT_MAX;

    d[s] = 0;

    for (int i = 0; i <= n; ++i)
    {
        int v = -1;
        for (int j = 0; j <= n; ++j)
            if (!foi[j] && (v == -1 || d[j] < d[v]))
                v = j;

        if (d[v] == INT_MAX)
            break;

        foi[v] = true;
        for (int j = 0; j <= n; ++j)
            if (d[v] + g[v][j] < d[j])
                d[j] = g[v][j] + d[v];
    }
}
