#include "interpreter.h"
#include "robot_grid.h"
#include <FL/fl_ask.H>
#include <exception>
#include <functional>
#include <optional>
#include <sstream>
#include <string>

// Task S1: Color name mapping
//
// This function takes the name of a color as its argument and
// returns the corresponding Graph_lib color type. This function is
// needed to convert the color names given as strings in the
// instruction code to the internal color representation used by the
// graphics library. We provide the map color_map, defined in
// interpreter.h that contains all valid mappings between color
// names and color types.
Graph_lib::Color::Color_type Interpreter::get_color(string color_name) {
    // BEGIN: S1
    //
    // Write your answer to assignment S1 here, between the // BEGIN: S1
    // and // END: S1 comments. You should remove any code that is
    // already there and replace it with your own.

    for (pair<string, Color::Color_type> c : color_map) {
        if (color_name == c.first) {
            return c.second;
        } else {
            throw invalid_argument(color_name + " is not a valid color name.");
        }
    }

    // END: S1
}

// Task S2: Instruction interpretation
//
// The interpreter function Interpreter::execute_instruction()
// reads an instruction (refer to the table in the
// assignment PDF for a description) and calls the corresponding
// function in the RobotGrid class to perform the requested action
// for changing the universe
void Interpreter::execute_instruction(istringstream instruction) {
    // BEGIN: S2
    //
    // Write your answer to assignment S2 here, between the // BEGIN: S2
    // and // END: S2 comments.
    // You may use the code below as a starting point for your
    // implementation following the structure of the implementation of
    // the make_grid command or you may start from scratch. If you use
    // this code as a starting point, replace each of the throw
    // string("Not implemented " + cmd); lines with your implementation.
    string instr;
    instruction >> instr;
    if (instr == "make_grid") {
        int rows;
        int cols;

        instruction >> rows;
        instruction >> cols;

        grid.make_grid(rows, cols);

    } else if (instr == "make_robot") {
        throw string("Instruction not implemented " + instr);
    } else if (instr == "clear_robots") {
        throw string("Instruction not implemented " + instr);
    } else if (instr == "move_robot") {
        throw string("Instruction not implemented " + instr);
    } else if (instr == "recolor_robot") {
        throw string("Instruction not implemented " + instr);
    } else if (instr == "rename_robot") {
        throw string("Instruction not implemented " + instr);
    } else if (instr == "delete_robot") {
        throw string("Instruction not implemented " + instr);
    } else {
        // Don't change this
        throw string("Invalid command " + instr);
    }

    (void)grid;
    // END: S2
}

// |
// | END OF ASSIGNMENTS
// |

// Wrapper around execute_command to deal with exception handling
bool Interpreter::do_execute_instruction(string instruction) {
    grid.get_application().trace_execution(instruction);
    try {
        execute_instruction(istringstream(instruction));
        return true;
    } catch (const exception &e) {
        fl_alert("Caught exception:\n\n%s", e.what());
        return false;
    } catch (const string &e) {
        fl_alert("Caught exception:\n\n%s", e.c_str());
        return false;
    } catch (const char *&e) {
        fl_alert("Caught exception:\n\n%s", e);
        return false;
    } catch (...) {
        fl_alert("Caught unknown exception.");
        return false;
    }
}

// Returns an optional containing the next line of a program as a
// string unless the program has no more lines.
optional<string> Interpreter::get_next_instruction(istringstream &stream) {
    for (;;) {
        if (stream.eof()) {
            return std::nullopt;
        } else {
            string res;
            getline(stream, res);
            // Trim string
            res = std::regex_replace(res, std::regex("^ +| +$|( ) +"), "$1");
            if (res == "") {
                continue;
            }
            return optional(res);
        }
    }
}

// Executes the commands of a program timed
void Interpreter::execute_steps(void *interpreter_ptr) {
    Interpreter &interpreter = *(Interpreter *)interpreter_ptr;
    auto command = interpreter.get_next_instruction(interpreter.program_stream);

    if (command.has_value()) {
        if (interpreter.do_execute_instruction(command.value())) {
            Fl::repeat_timeout(interpreter.step_delay, &execute_steps,
                               interpreter_ptr);
        }
    } else {
        interpreter.grid.get_application().enable_gui();
    }
}

// Executes a complete program
void Interpreter::execute_program(string stream, double frame_rate) {
    step_delay = 1.0 / frame_rate;
    program_stream = istringstream(stream);
    auto command = get_next_instruction(program_stream);
    if (command.has_value()) {
        if (do_execute_instruction(command.value())) {
            Fl::add_timeout(step_delay, &execute_steps, this);
        }
    } else {
        grid.get_application().enable_gui();
    }
}

Interpreter::Interpreter(RobotGrid &grid) : grid(grid) {
}
