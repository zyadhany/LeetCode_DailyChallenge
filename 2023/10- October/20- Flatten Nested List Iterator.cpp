/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        at = 0;
        irerateOverList(nestedList);
    }
    
    int next() {
        return (X[at++]);
    }
    
    bool hasNext() {
        return (at < X.size());
    }


private:
    int at = 0;
    vector<int> X;

    void irerateOverList(vector<NestedInteger> &nestedList){
        for (int i = 0; i < nestedList.size(); i++){
            if (nestedList[i].isInteger()) X.push_back(nestedList[i].getInteger());
            else irerateOverList(nestedList[i].getList());
        }
    }

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
