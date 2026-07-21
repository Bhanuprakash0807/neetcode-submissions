class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        int ind=-1;
        for(auto& opr: operations){
            if(opr=="+"){
                int val1=v[ind];
                int val2=v[ind-1];
                ind++;
                v.push_back(val1+val2);
            }
            else if(opr=="D"){
                int val=v[ind];
                ind++;
                v.push_back(val*2);
            }
            else if(opr=="C"){
                v.pop_back();
                ind--;
            }
            else{
                ind++;
                v.push_back(stoi(opr));
            }
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        return sum;
    }
};