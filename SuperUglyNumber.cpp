class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp{1};
        priority_queue<node*, vector<node*>, compare> pq;
        for (int i=0; i<primes.size(); i++)
            pq.push(new node(primes[i], 0, primes[i]));
        while (dp.size() < n) {
            int cur = pq.top()->val;
            dp.push_back(cur);
            while (pq.top()->val == cur) {
                node *tmp = pq.top();
                pq.pop();
                tmp->val = dp[++tmp->idx] * tmp->prime;
                pq.push(tmp);
            }
        }
        return dp.back();
    }
    
private:
    struct node {
        int val;
        int idx;
        int prime;
        
        node(int v, int i, int p) {
            val = v;
            idx = i;
            prime = p;
        }
    };
    
    struct compare{
        bool operator()(node* a, node* b) const {
            return a->val > b->val;
        }
    };
};
