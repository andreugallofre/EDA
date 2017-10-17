
static void buscar_i(node_arbreGen *n, const T&x, bool&ret){
    for(int i = ret = n != NULL and n -> info == x; not ret and n != NULL and i<int(n->seg.size()); buscar_i(n->seg[i++], x, ret)); 
}

bool buscar(const T& x) const{
  bool b;
  buscar_i(primer_node, x, b);
  return b; 
}
