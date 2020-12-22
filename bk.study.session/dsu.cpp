// As mentioned before, if we combine both optimizations -
//  path compression with union by size / rank - we will reach nearly 
// constant time queries. It turns out, that the final amortized 
// time complexity is O(α(n)) O ( α ( n ) ) , where α(n) α ( n ) 
//  is the inverse Ackermann function, which grows very slowly. 
// In fact it grows so slowly, that it doesn't exceed 4 4  for all reasonable n n 
//  (approximately n<10600 n < 10 600 ).  

// Amortized complexity is the total time per operation,
//  evaluated over a sequence of multiple operations.
//  The idea is to guarantee the total time of the entire sequence,
//  while allowing single operations to be much slower then the amortized time.
//  E.g. in our case a single call might take O(logn) O ( log ⁡ n ) 
//  in the worst case, but if we do m m  such calls back to back we will end up
//  with an average time of O(α(n)) O ( α ( n ) ) .  We will also not present a proof for this time complexity, since it is quite long and complicated.  Also, it's worth mentioning that DSU with union by size / rank, but without path compression works in O(logn) O ( log ⁡ n )  time per query.

parent = i, rank = 0
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}