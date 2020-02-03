#pragma once
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <string>
#include <vector>

#define MAX_N 10000

using namespace std;


int CREATE(int, int, int, int**);

int DELETE(int, int, int**);

int dijkstra(int**, int, int,int*);

#endif // !__GRAPH_H__
