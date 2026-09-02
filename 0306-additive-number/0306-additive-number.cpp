class Solution {
public:
    using ll = long long ;
    bool isAdditiveNumber(string num) {
        int N = num.length();
        for(int fl =1; fl<=N/2 ; fl++){
            if(num[0]=='0' && fl>1) break;
            for(int sl=1 ; N-fl-sl>=max(fl,sl);sl++){
                if(num[fl]=='0' && sl>1) break;
                string fstr = num.substr(0,fl);
                string sstr = num.substr(fl,sl);

                ll fnum = stoll(fstr); ll snum = stoll(sstr);
                string balstr = num.substr(fl+sl);
                while(balstr.length()>0){
                    ll tnum = fnum + snum;
                    string tstr = to_string(tnum);
                    if(balstr.find(tstr)==0){
                        fnum = snum;
                        snum = tnum;
                        balstr = balstr.substr(tstr.length());
                    }
                    else break;
                }
            if(balstr.length()==0) return true;
            }
        }
        return false;
    }
};