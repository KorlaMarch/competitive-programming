#include "node.h"

Node::Node(int id, int degree)
  : id(id), degree(degree)
{
  for(int i=0; i<degree; i++) {
    buffers.push_back(new unsigned char[MAX_LINK_BUFFER_SIZE+1]);
    with_data.push_back(false);
    data_size.push_back(0);
    in_buffers.push_back(new unsigned char[MAX_LINK_BUFFER_SIZE+1]);
    in_with_data.push_back(false);
    in_data_size.push_back(0);
  }
}

Node::~Node()
{
  for(int i=0; i<degree; i++) {
    delete [] buffers[i];
    delete [] in_buffers[i];
  }
}

void Node::init_round_buffers()
{
  for(int i=0; i<degree; i++) {
    in_data_size[i] = 0;
    in_with_data[i] = false;
  }
}
  
void Node::copy_in_buffers()
{
  for(int i=0; i<degree; i++) {
    data_size[i] = in_data_size[i];
    with_data[i] = in_with_data[i];
    if(with_data[i]) {
      for(int j=0; j<data_size[i]; j++) {
        buffers[i][j] = in_buffers[i][j];
      }
    }
  }
}
  
void Node::add_adj_node(int nid, Node* node, int w)
{
  int nnum = adj_nids.size();
  
  adj_nids.push_back(nid);
  adj_nodes.push_back(node);
  adj_weights.push_back(w);
  nidmap[nid] = nnum;
}

void Node::send(int nid, void* data, int size)
{
  if(size > MAX_LINK_BUFFER_SIZE) {
    throw "buffer size exceeded.";
  }

  int nnum = nidmap[nid];
  
  Node* target = adj_nodes[nnum];
  unsigned char* p = (unsigned char*) data;

  int mynnum = target->nidmap[get_id()];
  unsigned char* pbuffer = target->in_buffers[mynnum];
  
  for(int i=0; i<size; i++) {
    *pbuffer = *p;
    pbuffer++;
    p++;
  }

  target->in_with_data[mynnum] = true;
  target->in_data_size[mynnum] = size;
}

void Node::receive(int nid, void* data, int* size)
{
  int nnum = nidmap[nid];
  *size = data_size[nnum];

  unsigned char* p = (unsigned char*) data;
  unsigned char* pbuffer = buffers[nnum];
  for(int i=0; i<data_size[nnum]; i++) {
    *p = *pbuffer;
    p++;
    pbuffer++;
  }
}

void Node::init()
{
}

bool Node::work()
{
  return true;
}
