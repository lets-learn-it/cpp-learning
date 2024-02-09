#include <vector>

class union_find {
  private:
    std::vector<int> link;
    std::vector<int> size;
  public:
    union_find(int nodes) {
      link.resize(nodes);
      for (int i=0; i<nodes; i++) link[i] = i;
      size.resize(nodes);
      for (int i=0; i<nodes; i++) size[i] = 1;
    }

    int find(int x) {
      while (x != link[x])
        x = link[x];
      return x;
    }

    bool same(int a, int b) {
      return find(a) == find(b);
    }

    void unite(int a, int b) {
      a = find(a);
      b = find(b);
      if (size[a] < size[b]) std::swap(a, b);
      size[a] += size[b];
      link[b] = a;
    }
};