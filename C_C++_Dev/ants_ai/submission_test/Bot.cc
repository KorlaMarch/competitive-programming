#include "Bot.h"

#define MFOOD -10.0
#define MFRI 10.0
#define MEN 50.0
#define FHI 1.0
#define MHI -1000.5

using namespace std;

//constructor
Bot::Bot()
{

};

bool Bot::canMove(int x, int y){
    return state.grid[x][y].isVisible&&!state.grid[x][y].isWater&&dis[x][y]==-1;
}

void Bot::bfs(int x, int y){
    /*std::queue<std::pair<int,int>> qu;
    //reset all distance
    for(int i = 0; i < state.rows; i++){
        for(int j = 0; j < state.cols; j++){
            dis[i][j] = -1;
        }
    }
    //bfs (shorted path)
    dis[x][y] = 0;
    qu.push({x,y});
    while(!qu.empty()){
        auto pi = qu.front();
        int d = dis[pi.first][pi.second]+1;
        qu.pop();
        if(canMove((pi.first-1+state.rows)%state.rows,pi.second)){
            dis[(pi.first-1+state.rows)%state.rows][pi.second] = d;
            qu.push((pi.first-1+state.rows)%state.rows,pi.second);
        }
        if(canMove((pi.first+1)%state.rows,pi.second)){
            dis[(pi.first+1)%state.rows][pi.second] = d;
            qu.push((pi.first+1)%state.rows,pi.second);
        }
        if(canMove(pi.first,(pi.second-1+state.cols)%state.cols)){
            dis[pi.first][(pi.second-1+state.cols)%state.cols] = d;
            qu.push((pi.first-1+state.cols)%state.cols,pi.second);
        }
    }*/
}

//plays a single game of Ants.
void Bot::playGame()
{
    //reads the game parameters and sets up
    cin >> state;
    state.setup();
    endTurn();

    //continues making moves while the game is not over
    while(cin >> state)
    {
        state.updateVisionInformation();
        makeMoves();
        endTurn();
    }
};

bool Bot::checkLoc(Location loc){
    return !state.grid[loc.row][loc.col].isWater&&state.grid[loc.row][loc.col].ant==-1;
}

bool Bot::checkPath(Location a, Location b){

}

void Bot::calGra(Location ant, std::vector<Location>& locs, double m, double& fx, double& fy){
    double f,r;
    for(Location x : locs){
        r = state.distance(ant,x);
        if(r!=0.0){
            f = m/r;
            fx += f*(state.distanceX(x,ant)/r);
            fy += f*(state.distanceY(x,ant)/r);
            state.bug << "Gar with " << x.row << " " << x.col << " : " << r << " " << f << " ";
            state.bug << f*(state.distanceX(x,ant)/r) << " " << f*(state.distanceY(x,ant)/r) << "\n";
        }
    }
}

//makes the bots moves for the turn
void Bot::makeMoves()
{
    state.bug << "turn " << state.turn << ":" << endl;
    //state.bug << state << endl;

    //picks out moves for each ant
    for(int ant=0; ant<(int)state.myAnts.size(); ant++)
    {
        /*for(int d=0; d<TDIRECTIONS; d++)
        {
            Location loc = state.getLocation(state.myAnts[ant], d);

            if(!state.grid[loc.row][loc.col].isWater)
            {
                state.makeMove(state.myAnts[ant], d);
                break;
            }
        }*/
        //calulate gravity with myAnts, enemyAnts, myHills, enemyHills and food
        double fx=0.0,fy=0.0;
        Location loc = state.myAnts[ant];
        state.bug << "food\n";
        calGra(loc, state.food, MFOOD, fx, fy);
        state.bug << "friends\n";
        calGra(loc, state.myAnts, MFRI, fx, fy);
        state.bug << "enemy\n";
        calGra(loc, state.enemyAnts, MEN, fx, fy);
        state.bug << "hill\n";
        calGra(loc, state.enemyHills, MHI, fx, fy);
        state.bug << "x : " << loc.row << " y : " << loc.col << " fx " << fx << " fy " << fy << "\n";
        if(abs(fx)>=abs(fy)&&fx>=0&&checkLoc(state.getLocation(loc, 2))){
            state.makeMove(loc, 2);
        }else if(abs(fx)>=abs(fy)&&fx<0&&checkLoc(state.getLocation(loc, 0))){
            state.makeMove(loc, 0);
        }else if(fy>=0&&checkLoc(state.getLocation(loc, 1))){
            state.makeMove(loc, 1);
        }else if(fy<0&&checkLoc(state.getLocation(loc, 3))){
            state.makeMove(loc, 3);
        }else{
            for(int d=0; d<TDIRECTIONS; d++){
                if(checkLoc(state.getLocation(loc, d))){
                    state.makeMove(state.myAnts[ant], d);
                    break;
                }
            }
        }
    }
    state.bug << "time taken: " << state.timer.getTime() << "ms" << endl << endl;
};

//finishes the turn
void Bot::endTurn()
{
    if(state.turn > 0)
        state.reset();
    state.turn++;

    cout << "go" << endl;
};
