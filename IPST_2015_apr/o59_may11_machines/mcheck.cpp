#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MAX_N 110
#define MAX_M 310

char rmap[MAX_N][MAX_M];
int n,m,k;

vector<int> adj[MAX_N*MAX_M];
int deg[MAX_N*MAX_M];
bool visited[MAX_N*MAX_M];

int nid(int r, int c)
{
  return (c-1) + (r-1)*m;
}

void read_input(FILE* fin)
{
  fscanf(fin,"%d %d",&n,&m);
  for(int i=0; i<n; i++)
    fscanf(fin,"%s",rmap[i]);
}

void dead(char* msg)
{
  printf("%s\n",msg);
  exit(0);
}

void read_output(FILE* fout)
{
  for(int i=0; i<n*m; i++)
    deg[i] = 0;

  fscanf(fout,"%d",&k);
  for(int i=0; i<k; i++) {
    int a,b,c,d;
    fscanf(fout,"%d %d %d %d",&a,&b,&c,&d);

    bool ok = false;
    if(((a==c) && (abs(b-d)==1)) ||
       ((b==d) && (abs(a-c)==1)))
      ok = true;

    if((a < 1) || (a > n) || (b < 1) || (b > m) ||
       (c < 1) || (c > n) || (d < 1) || (d > m))
      ok = false;

    if(!ok)
      dead("Connection error.");

    if((rmap[a-1][b-1] != '.') ||
       (rmap[c-1][d-1] != '.'))
      dead("Connection error.");

    int u = nid(a,b);
    int v = nid(c,d);
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

void dfs(int u)
{
  visited[u] = true;
  for(int i=0; i<deg[u]; i++) {
    int v = adj[u][i];

    if(!visited[v]) {
      dfs(v);
    }
  }
}

main(int argc, char* argv[])
{
  FILE* fin = fopen(argv[1],"r");
  FILE* fout = fopen(argv[2],"r");

  read_input(fin);
  read_output(fout);

  int conn_count = 0;
  int com_count = 0;
  int empty_count = 0;

  for(int i=0; i<n*m; i++)
    visited[i] = false;

  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
      int u = nid(i+1,j+1);
      if((deg[u] != 0) && (!visited[u])) {
        conn_count++;
        dfs(u);
      }
      if(deg[u]>=4) printf("%d:%d\n",u,deg[u]);

      if(deg[u] == 1)
        com_count++;
      if(rmap[i][j] == '.')
        empty_count++;
    }

  if(conn_count > 1)
    dead("Not connected");

  double score = 10.0 * exp(log(((double)com_count)/(empty_count*2/3))*1.5);

  //printf("%d %d\n",com_count,empty_count);

  if(com_count*3 >= empty_count*2)
    score = 10;

  printf("Score: %d (%.3f,%d,%d)\n",int(score),score,com_count,2*empty_count/3);
}
