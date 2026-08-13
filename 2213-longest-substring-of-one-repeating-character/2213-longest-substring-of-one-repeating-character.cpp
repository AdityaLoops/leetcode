class Solution {
    struct Node{
        char first, last;
        int prefix, suffix;
        int len;
        int best;
    };
        vector<Node> tree;
    Node merge(Node left, Node right){
        Node res;
        res.len = left.len + right.len;
        res.first = left.first; 
        res.last = right.last;
        if(left.last == right.first){
            res.best = max(left.suffix+ right.prefix, max(left.best, right.best));
            if(left.prefix == left.len) res.prefix= left.prefix + right.prefix;
            else res.prefix = left.prefix;
            if(right.prefix == right.len) res.suffix = right.suffix + left.suffix;
            else res.suffix = right.suffix;
        }
        else {
            res.best = max(left.best, right.best);
            res.prefix = left.prefix;
            res.suffix = right.suffix;
        }
        return res;
    }

    void build(int node, int l, int r, string &s){
        if(l==r) {
            Node leaf;
            leaf.first = s[l];
            leaf.last = s[r];
            leaf.len=1;
            leaf.best =1;
            leaf.prefix = 1;
            leaf.suffix=1;
            tree[node] = leaf;
            return;
        }

        int mid = (l+r)/2;

        build(node*2, l, mid,s);
        build(node*2+1, mid+1, r,s);

        tree[node] = merge(tree[node*2],tree[node*2+1]);

    }

    void update(int node, int l, int r, int id, char c){
        if( l==r){
            Node leaf;
            leaf.first = c;
            leaf.last = c;
            leaf.prefix =1;
            leaf.suffix =1;
            leaf.len=1;
            leaf.best=1;
            tree[node]=leaf;
            return;
        }

        int mid = (l+r)/2;

        if(id<=mid){
            update(node*2, l, mid, id,c);
        }
        else update(node*2 + 1, mid+1, r,id, c);

        tree[node] = merge(tree[node*2], tree[node*2 + 1]);
        
    }

public:


    vector<int> longestRepeating(string s, string chars, vector<int>& index) {
        int n = chars.size();
        
        tree.resize(4*s.size());

        build(1, 0, s.size()-1, s);
        vector<int> ans(n);
        for(int i =0; i<n; i++){
            update(1,0, s.size()-1, index[i], chars[i] );
            ans[i] =  tree[1].best;
        }
        return ans;


    }
};