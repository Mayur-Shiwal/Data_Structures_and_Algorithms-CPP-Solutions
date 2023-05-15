class CarAttributes{
private:
    int position, speed;
public:
    CarAttributes(int position, int speed){
        this->position = position;
        this->speed = speed;
    }
    void setPosition(int position){
        this->position = position;
    }
    void setSpeed(int speed){
        this->speed = speed;
    }
    int getPosition(){
        return position;
    }
    int getSpeed(){
        return speed;
    }
};

class Solution {
private:
    int target;
    int getMinimumNumberOfInstruction(){
        int minimumNumberOfInstruction = 0;
        queue<CarAttributes> q;
        unordered_set<string> vis;
        string key = to_string(0) + "," + to_string(1);
        q.push(CarAttributes(0, 1));
        vis.insert(key);
        while(!q.empty()){
            int size = (int)q.size();
            while(size--){
                CarAttributes frontEle = q.front();
                q.pop();
                int currPosition = frontEle.getPosition();
                int currSpeed = frontEle.getSpeed();
                if(currPosition == target) return minimumNumberOfInstruction; //check if reached the target then return
                //exploring option A:
                int nextPosition = currPosition + currSpeed;
                int nextSpeed = currSpeed * 2;
                key = to_string(nextPosition) + "," + to_string(nextSpeed);
                if(vis.find(key) == vis.end()){ //check if already visited
                    if(abs(target - nextPosition) < target){
                        vis.insert(key);
                        q.push(CarAttributes(nextPosition, nextSpeed));
                    }
                }
                //exploring option R:
                //for reverse the car 
                nextPosition = currPosition;
                nextSpeed = currSpeed < 0 ? 1 : -1;
                key = to_string(nextPosition) + "," + to_string(nextSpeed);
                if(vis.find(key) == vis.end()){ //check if already visited
                    if(abs(target - nextPosition) < target){
                        vis.insert(key);
                        q.push(CarAttributes(nextPosition, nextSpeed));
                    }
                }
            }
            minimumNumberOfInstruction++;
        }
        return -1;
    }
public:
    int racecar(int target) {
        this->target = target;
        return getMinimumNumberOfInstruction();
    }
};

/*

1. infinite line
2. start = [0, 1] -> [position, speed]
3. "A" "R"
4. "A" -> nextPos = currPos + currSpeed
       -> nextSpeed = currSpeed*2;
5. "R" -> currSpeed < 0 ? 1 : -1;
    nextPos = currPos

eg.
target = 3;
operations = "AA"
initialy we are at 0 ind;
where currPos = 0, currSpeed = 1;
1st iteration = currPos = 1, currSpeed = 2;
2nd iteration = currPos = 3, currSpeed = 4;
currPos == target then we reached our destination;

*/
