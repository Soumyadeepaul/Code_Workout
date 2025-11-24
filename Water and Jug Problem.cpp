//https://leetcode.com/problems/water-and-jug-problem/description/?envType=problem-list-v2&envId=math

class Solution {
private:
    vector<pair<int,int>> possibles;   // visited states

    bool helper(int x, int y, int i, int j, int target){
        // if visited already → stop
        if(find(possibles.begin(), possibles.end(), make_pair(x,y)) != possibles.end())
            return false;

        // mark current state visited
        possibles.push_back({x,y});

        if(x + y == target) return true;

        // ---- fill i ----
        if(x != i){
            if(helper(i, y, i, j, target)) return true;
        }

        // ---- fill j ----
        if(y != j){
            if(helper(x, j, i, j, target)) return true;
        }

        // ---- pour i → j ----
        int can = min(x, j - y);
        if(helper(x - can, y + can, i, j, target)) return true;

        // ---- pour j → i ----
        can = min(y, i - x);
        if(helper(x + can, y - can, i, j, target)) return true;

        // ---- empty i ----
        if(x != 0){
            if(helper(0, y, i, j, target)) return true;
        }

        // ---- empty j ----
        if(y != 0){
            if(helper(x, 0, i, j, target)) return true;
        }

        return false;
    }

public:
    bool canMeasureWater(int x, int y, int target) {
        possibles.clear();
        return helper(0, 0, x, y, target);
    }
};
