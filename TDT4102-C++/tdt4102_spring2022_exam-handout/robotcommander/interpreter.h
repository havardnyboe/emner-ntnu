#pragma once

#include "robot_grid.h"
#include "std_lib_facilities.h"
#include <optional>
#include <sstream>

struct color_map_def : public map<std::string, Graph_lib::Color::Color_type> {
  color_map_def()
  {
    this->operator[]("red") = Color::red;
    this->operator[]("blue") = Color::blue;
    this->operator[]("green") = Color::green;
    this->operator[]("yellow") = Color::yellow;
    this->operator[]("white") = Color::white;
    this->operator[]("black") = Color::black;
    this->operator[]("magenta") = Color::magenta;
    this->operator[]("cyan") = Color::cyan;
    this->operator[]("dark_red") = Color::dark_red;
    this->operator[]("dark_green") = Color::dark_green;
    this->operator[]("dark_yellow") = Color::dark_yellow;
    this->operator[]("dark_blue") = Color::dark_blue;
    this->operator[]("dark_magenta") = Color::dark_magenta;
    this->operator[]("dark_cyan") = Color::dark_cyan;
    this->operator[]("gray") = Color::gray;
    this->operator[]("mid_gray") = Color::mid_gray;
    this->operator[]("dark_gray") = Color::dark_gray;
    this->operator[]("light_gray") = Color::light_gray;
  }
  ~color_map_def()
  {
  }
};

class Interpreter
{

public:
  Interpreter(RobotGrid &grid);
  void execute_program(string program_stream, double frame_rate);

private:
  RobotGrid &grid;
  color_map_def color_map;
  istringstream program_stream;
  double step_delay;
  bool do_execute_instruction(string command);
  void execute_instruction(istringstream command);
  static optional<string> get_next_instruction(istringstream &stream);
  static void execute_steps(void *interpreter);
  Graph_lib::Color::Color_type get_color(string color_name);
};

