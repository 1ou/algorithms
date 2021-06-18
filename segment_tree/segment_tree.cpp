#include <bits/stdc++.h>

#define ll long long

using namespace std;

class SegmentTree {
public:
  int size;
  vector<int> elements;
  SegmentTree(int size) {
    this->size = size * 4;
    this->elements = std::vector<int>(size * 4, 0);
  }

  void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
      elements[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(a, v*2, tl, tm);
      build(a, v*2 + 1, tm + 1, tr);
      elements[v] = elements[v*2] + elements[v*2 + 1];
    }
  }

  ll sum(int v, int tl, int tr, int l, int r) {
  	if (l > r)
  		return 0;
  	if (l == tl && r == tr)
  		return elements[v];
  	int tm = (tl + tr) / 2;
  	return sum (v*2, tl, tm, l, min(r,tm))	+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << elements[i] << " ";
    }
    cout << endl;
  }
private:
};

int main() {
  vector<int> el = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sum = 550 150 400 ..
  SegmentTree segmentTree = SegmentTree(el.size());
  segmentTree.build(el, 1, 0, el.size() - 1);
  segmentTree.print();

  int r = segmentTree.sum(1, 0, el.size() - 1, 2, 7);
  cout << "Find from [3, 8] " << r << endl;
  assert(33 == r);

  r = segmentTree.sum(1, 0, el.size() - 1, 2, 2);
  cout << "Find from [3, 3] " << r << endl;
  assert(3 == r);

  r = segmentTree.sum(1, 0, el.size() - 1, 4, 4);
  cout << "Find from [4, 4] " << r << endl;
  assert(5 == r);

  r = segmentTree.sum(1, 0, el.size() - 1, 7, 9);
  cout << "Find from [8, 10] " << r << endl;
  assert(27 == r);
}
