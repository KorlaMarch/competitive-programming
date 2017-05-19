#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>
#include <map>

using namespace std;

#define MAX_LINK_BUFFER_SIZE 100

class Node
{
private:
  int id;
  int degree;
  vector<int> adj_nids;
  vector<int> adj_weights;
  vector<Node*> adj_nodes;
  
  vector<unsigned char*> buffers;
  vector<bool> with_data;
  vector<int> data_size;

  vector<unsigned char*> in_buffers;
  vector<bool> in_with_data;
  vector<int> in_data_size;

  map<int,int> nidmap;

 public:
  Node(int id, int degree);
  ~Node();

  void add_adj_node(int nid, Node* node, int w);
  int get_id() { return id; }
  int get_degree() { return degree; }
  int get_adj_nid(int i) { return adj_nids[i]; }
  int get_adj_weight(int i) { return adj_weights[i]; }

  void send(int nid, void* data, int size);
  bool has_data(int nid) { return with_data[nidmap[nid]]; }
  void receive(int nid, void* data, int* size);

  virtual void init();
  virtual bool work();

  void init_round_buffers();
  void copy_in_buffers();
};
#endif
