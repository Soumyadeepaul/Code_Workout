//https://leetcode.com/problems/moving-stones-until-consecutive/description/?envType=problem-list-v2&envId=brainteaser



class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int summ=a+b+c;
        int temp=min(a,min(b,c));
        c=max(a,max(b,c));
        a=temp;
        b=summ-a-c;
        int mini=0, maxx=INT_MIN;
        int gap1=(b-1)-a;
        int gap2=c-(b+1);
        if(gap1==0 && gap2==0) mini=0;
        else if(gap1==0 || gap2==0) mini=1;
        else mini=min(2,min(gap2,gap1));
        maxx=((b-1)-a)+(c-(b+1));

        return {mini,maxx};
    }
};
