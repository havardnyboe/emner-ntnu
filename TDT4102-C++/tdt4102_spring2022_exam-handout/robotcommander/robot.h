#pragma once

#include "Graph.h"
#include "std_lib_facilities.h"

struct Robot {
  Robot(string name, Point pos, Graph_lib::Color color);

  string name;
  Point pos;
  Graph_lib::Color color;
};

