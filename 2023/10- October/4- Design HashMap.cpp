struct node{
    int val;
    vector<int> next;
};

class MyHashMap {
public:
    vector<node> X;
    int at = 1;

    MyHashMap() : X(1, {-1, vector<int>(2, -1)}) {
        
    }
    
    void add(int node, int key, int value){
        if (!key){
            X[node].val = value;
            return;
        }

        if(X[node].next[key % 2] == -1){
            X.push_back({-1, vector<int>(2, -1)});
            X[node].next[key % 2] = at++;
        }
        
        add(X[node].next[key % 2], key / 2, value);
    }

    void put(int key, int value) {
        add(0, key, value);
    }
    
    int find(int node, int key){
        if (!key)
            return (X[node].val);

        if(X[node].next[key % 2] == -1)
            return (-1);
        
        return find(X[node].next[key % 2], key / 2);
    }

    int get(int key) {
        return find(0, key);
    }
    
    void rem(int node, int key){
       if (!key){
            X[node].val = -1;
            return;
        }

        if(X[node].next[key % 2] == -1)
            return;
        
        rem(X[node].next[key % 2], key / 2);
    }

    void remove(int key) {
        rem(0, key);
    }
};