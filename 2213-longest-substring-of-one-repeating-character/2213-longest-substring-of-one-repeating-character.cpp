class Solution {
public:
    struct nd { char lc=0,rc=0; int pre=0,suf=0,best=0,len=0; };
    vector<nd> t;
    string s;
    nd mg(nd& a,nd& b){
        if(a.len==0) return b;
        if(b.len==0) return a;
        nd r;
        r.lc=a.lc; r.rc=b.rc; r.len=a.len+b.len;
        r.pre=a.pre; r.suf=b.suf;
        r.best=max(a.best,b.best);
        if(a.rc==b.lc){
            r.best=max(r.best,a.suf+b.pre);
            if(a.pre==a.len) r.pre=a.len+b.pre;
            if(b.suf==b.len) r.suf=b.len+a.suf;
        }
        return r;
    }
    void bld(int i,int l,int h){
        if(l==h){ t[i].lc=t[i].rc=s[l]; t[i].pre=t[i].suf=t[i].best=t[i].len=1; return; }
        int m=(l+h)/2;
        bld(i*2+1,l,m); bld(i*2+2,m+1,h);
        t[i]=mg(t[i*2+1],t[i*2+2]);
    }
    void upd(int i,int l,int h,int p,char c){
        if(l==h){ t[i].lc=t[i].rc=c; return; }
        int m=(l+h)/2;
        if(p<=m) upd(i*2+1,l,m,p,c);
        else upd(i*2+2,m+1,h,p,c);
        t[i]=mg(t[i*2+1],t[i*2+2]);
    }
    vector<int> longestRepeating(string str, string qc, vector<int>& qi) {
        s=str;
        int n=s.size();
        t.assign(4*n,nd());
        bld(0,0,n-1);
        vector<int> ans;
        for(int i=0;i<qi.size();i++){
            upd(0,0,n-1,qi[i],qc[i]);
            ans.push_back(t[0].best);
        }
        return ans;
    }
};