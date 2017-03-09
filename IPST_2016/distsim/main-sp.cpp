#include "node.h"
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

#define MAX_N 5000
#define MAX_ROUND 100000

class MyNode : public Node
{
private:
  int source_id;
  int dest_id;
  int num_nodes;

  int counter;
  
public:
  MyNode(int id, int degree)
    : Node(id, degree)
  {}

  virtual bool work();
  virtual void init();

  void set_source(int s) { source_id = s; }
  void set_destination(int t) { dest_id = t; }
  void set_num_nodes(int n) { num_nodes = n; }
};

void MyNode::init()
{
  // put your code here
  counter = 0;
}

bool MyNode::work()
{
  // put your code here
  int num;
  int s;
  
  for(int i=0; i<get_degree(); i++) {
    if(has_data(get_adj_nid(i))) {
      receive(get_adj_nid(i), &num, &s);
      printf("[%d] from %d get %d (%d)\n",get_id(),get_adj_nid(i),num,get_adj_weight(i));
    }
  }

  counter++;
  num = get_id() + counter * 100;
  for(int i=0; i<get_degree(); i++) {
    send(get_adj_nid(i), &num, sizeof(int));
  }
  
  if(counter == 5) {
    return false;
  }
  return true;
}

int n;
int m;
MyNode* nodes[MAX_N];
vector<int> adj[MAX_N];
vector<int> wt[MAX_N];
int idmap[MAX_N];

void read_network(bool random_id=false)
{
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    u--; v--;
    adj[u].push_back(v);
    wt[u].push_back(w);
    adj[v].push_back(u);
    wt[v].push_back(w);
  }

  if(random_id) {
    set<int> usedid;
    
    for(int i=0; i<n; i++) {
      int nid = 0;
      while((nid==0) || (usedid.find(nid) == usedid.end())) {
        nid = 1 + (rand() % 10000000);
      }
      usedid.insert(nid);
      idmap[i] = nid;
    }
  } else {
    for(int i=0; i<n; i++)
      idmap[i] = i+1;
  }
  
  for(int i=0; i<n; i++) {
    nodes[i] = new MyNode(idmap[i], adj[i].size());
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<adj[i].size(); j++) {
      int vid = idmap[adj[i][j]];
      nodes[i]->add_adj_node(vid, nodes[adj[i][j]], wt[i][j]);
    }
  }
}

main()
{
  read_network();

  bool* running = new bool[n];
  for(int i=0; i<n; i++) {
    nodes[i]->set_source(1);
    nodes[i]->set_destination(n);
    nodes[i]->set_num_nodes(n);
    
    nodes[i]->init();
    running[i] = true;
  }

  int r = 0;
  bool done = true;
  while(true) {
    if(r > MAX_ROUND) {
      printf("too many rounds\n");
      throw "too many rounds.";
    }
    r++;

    done = true;

    for(int i=0; i<n; i++) {
      nodes[i]->init_round_buffers();
    }

    for(int i=0; i<n; i++) {
      if(running[i]) {
        running[i] = nodes[i]->work();
        if(running[i]) {
          done = false;
        }
      }
    }
    
    for(int i=0; i<n; i++) {
      nodes[i]->copy_in_buffers();
    }

    if(done) {
      break;
    }
  }
}
