//https://leetcode.com/problems/walking-robot-simulation-ii/description/?envType=daily-question&envId=2026-04-07

class Robot {
private:
    int width,height;
    int direction=0; //0east 1south 2west 3north
    vector<string> d={"East","South","West","North"};
    int x=0,y=0;
    int total;
public:
    Robot(int width, int height) {
        this->width=width;
        this->height=height;
        this->total=2*(width+height)-4;
    }
    
    void step(int num) {
        num=num%total;
        if (num == 0 && x == 0 && y == 0) {
            direction = 1;
            return;
        }
        while(num!=0){
            if(direction==0){
                if(x+num>=width){
                    num=(x+num)-(width-1);
                    x=width-1;
                    direction=3;
                }
                else{
                    x+=num;
                    num=0;
                }
            }
            else if(direction==1){
                if(y-num<0){
                    int done=y;
                    num-=done;
                    y=0;
                    direction=0;
                }
                else{
                    y-=num;
                    num=0;
                }
            }
            else if(direction==2){
                if(x-num<0){
                    int done=x;
                    num-=done;
                    x=0;
                    direction=1;
                }
                else{
                    x-=num;
                    num=0;
                }
            }
            else if(direction==3){
                if(y+num>=height){
                    num=(y+num)-(height-1);
                    y=height-1;
                    direction=2;
                }
                else{
                    y+=num;
                    num=0;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return d[direction];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
