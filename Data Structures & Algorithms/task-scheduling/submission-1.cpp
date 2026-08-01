class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res=0;
        priority_queue<int> pq;
        int num=tasks.size();
        vector<int> hash(26,0);
        for(int i=0;i<num;i++){
            hash[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]>0){
                pq.push(hash[i]);
            }
        }
        queue<pair<int,int>> q;
        int cycle=1;
        while(!pq.empty() || !q.empty()){
            if(pq.empty() && q.front().second>cycle){
                cycle=q.front().second;
            }
            while(!q.empty() && q.front().second<=cycle){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int top=pq.top();
                pq.pop();
                top--;
                if(top>0){
                    q.push({top,cycle+n+1});
                }
            }
            if(pq.empty() && q.empty()){
                break;
            }
            cycle++;
        }
        return cycle;
    }
};
