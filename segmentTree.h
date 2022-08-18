#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>
using namespace std ;
template<class T>
class segmentTree{
  public:
    T buildTree(int ss,int se,int si, T data[], T tree[]);
    T getSum(int qs,int qe,int ss,int se,int si, T tree[]) ;
    void update(int ss,int se,int i,int si,T diff, T tree[]);
};

template<class T>T segmentTree<T> :: buildTree(int ss,int se,int si, T data[], T tree[]){
  if(ss == se)
	{
		tree[si] = data[ss];
		return data[ss];
	}

	int mid = (ss + se) / 2;

	tree[si] = buildTree(ss, mid, 2 * si + 1, data, tree)
		       + buildTree(mid + 1, se, 2 * si + 2, data, tree);

	return tree[si];
}

template<class T>T segmentTree<T> :: getSum(int qs,int qe,int ss,int se,int si, T tree[]){
  if(se < qs || ss > qe)
		return 0;
	if(qs <= ss &&  qe >= se)
		return tree[si];

	int mid = (ss + se) / 2;

	return getSum(qs, qe, ss, mid, 2 * si + 1, tree)
		   + getSum(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

template<class T>void segmentTree<T> :: update(int ss,int se,int i,int si,T diff, T tree[]){
  if(i < ss || i > se) 
        return;
        
  tree[si] = tree[si] + diff;
  
  if(se > ss)
  {
      int mid = (ss + se) / 2;
      
      update(ss, mid, i, 2 * si + 1, diff, tree);
      update(mid + 1, se, i, 2 * si + 2, diff, tree);
      
  }
}

#endif //SEGMENTTREE_H 