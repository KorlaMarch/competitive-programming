#ifndef BOT_H_
#define BOT_H_

#include "State.h"
#include "math.h"
#include "algorithm"

/*
    This struct represents your bot in the game of Ants
*/
struct Bot
{
    State state;
    std::vector<std::vector<int> > dis;

    Bot();

    void playGame();    //plays a single game of Ants

    void makeMoves();   //makes moves for a single turn
    void endTurn();     //indicates to the engine that it has made its moves
    void bfs(int x, int y);
    private:
        bool canMove(int x, int y);
        void calGra(Location ant, std::vector<Location>& locs, double m, double& fx, double& fy);
        bool checkLoc(Location loc);
        bool checkPath(Location a, Location b);
};

#endif //BOT_H_
