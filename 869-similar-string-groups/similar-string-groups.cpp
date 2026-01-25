class Solution {
public:
int check(string &a,string &b){
    int nott=0;
    int st=0;
    while(st<a.size()){
        if(a[st]!=b[st])nott++;
        st++;
    }
    return nott<=2;
}

string findPar(string &x,unordered_map<string,string>&par){
if(par[x]==x){
    return x;
}
return par[x]=findPar(par[x],par);
}


    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string,string>par;
        for(auto it:strs){
            par[it]=it;
        }
        int finalGrps=0;
        for(int i=0;i<strs.size();i++){
            string a=strs[i];
            for(int j=0;j<strs.size();j++){
                if(i==j)continue;
                string b=strs[j];
                string apar=findPar(a,par);
                string bpar=findPar(b,par);
                if(apar==bpar)continue;
                if(check(a,b)){
                    par[apar]=par[bpar];
                }
            }
        }
        unordered_map<string,int>m;
        for(int i=0;i<strs.size();i++){
            string parr=findPar(strs[i],par);
            if(m.find(parr)==m.end()){
                m[parr]++;
                finalGrps++;
            }
        }
        return finalGrps;
    }
};