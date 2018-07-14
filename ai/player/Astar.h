//
// Created by Nam Nguyen on 13/07/2018.
//

#ifndef BOMBERMANCPP_ASTAR_H
#define BOMBERMANCPP_ASTAR_H

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

class Astar {
public:
    const int n; // vertical size of the map = width
    const int m; // horizontal size size of the map = height

    vector<vector<int>> map;
    vector<vector<int>> closed_nodes_map;
    vector<vector<int>> open_nodes_map;

    vector<vector<int>> dir_map;

    int xPlayer = 0;
    int yPlayer = 0;

    int xDest;
    int yDest;



    Astar(const int n, const int m, const int xplayer, const int yplayer);

    void searchDestination(vector<vector<int>> map_decision);
    string pathFindTmp(const int &xStart, const int &yStart, const int &xFinish, const int &yFinish);
    string findPath(const int &xEnd, const int &yEnd);


};


#endif //BOMBERMANCPP_ASTAR_H
