//Maximize Area of Square Hole in Grid
//TLE 509/524

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int v=0,h=0;
        int l1=hBars.size(),l2=vBars.size();
        int prevH=1,prevV=1;
        int maxi1=1,maxi2=1;
        int nextH=hBars[h],nextV=vBars[v];
        int leftOut=0, bar,common;//bar = 0 means hBar and bar = 1 means vBar
        if(n<=m){
            common=n;
            leftOut=m-n;
            bar=1;
        }
        else{
            common=m;
            leftOut=n-m;
            bar=0;
        }
        int i=1;
        for(;i<common+3;i++){
            if(i!=nextH){
                maxi1=max(maxi1,i-prevH);
                prevH=i;
            }
            else{
                if(++h!=l1)
                nextH=hBars[h];
            }
            if(i!=nextV){
                maxi2=max(maxi2,i-prevV);
                prevV=i;
            }
            else{
                if(++v!=l2)
                nextV=vBars[v];
            }
        }
        if(bar==1){
            for(;i<m+3;i++){
                if(i!=nextV){
                    maxi2=max(maxi2,i-prevV);
                    prevV=i;
                }
                else{
                    if(++v!=l2)
                    nextV=vBars[v];
                }
            }
        }
        else{
            for(;i<n+3;i++){
                if(i!=nextH){
                    maxi1=max(maxi1,i-prevH);
                    prevH=i;
                }
                else{
                    if(++h!=l1)
                    nextH=hBars[h];
                }
            }

        }
        return min(maxi1,maxi2)*min(maxi1,maxi2);
    }
};


/////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        hBars.push_back(-1);
        vBars.push_back(-1);

        int i=0,j=1;
        int l1=hBars.size(),l2=vBars.size();
        int maxi1=1,maxi2=1;
        while(j<l1){
            if(hBars[j]-hBars[j-1]==1){
            }
            else{
                maxi1=max(maxi1,hBars[j-1]+1-(hBars[i]-1));
                i=j;
            }
            j++;
        }
        i=0,j=1;
        while(j<l2){
            if(vBars[j]-vBars[j-1]==1){
            }
            else{
                maxi2=max(maxi2,vBars[j-1]+1-(vBars[i]-1));
                i=j;
            }
            j++;
        }
        return min(maxi1,maxi2)*min(maxi1,maxi2);
    }
};
