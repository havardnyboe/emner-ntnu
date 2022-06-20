#include "application.h"
#include <filesystem>

// Task A1: Loading a program from a file
//
// Implement the function Application::load_program() to read the
// contents of the file given in the parameter file_name and return
// its contents as a string. Make sure to include the whitespace from
// the file in the string. This makes it possible to load a program
// from a file to the Control script-window in the
// application. Some test-programs have been included in the
// handout-code. You can use these to test this function if you don't
// want/have time to make your own test cases. Make sure to handle
// potential problems with opening the file
// appropriately.
string Application::load_program(string file_name) {
    // BEGIN: A1
    //
    // Write your answer to assignment A1 here, between the // BEGIN: A1
    // and // END: A1 comments. You should remove any code that is
    // already there and replace it with your own.

    ifstream file(file_name);
    string line, output;
    while (getline(file, line)) {
        output += line;
        output += "\n";
    }
    return output;

    // END: A1
}

// Task A2: Saving a program to a file
//
// Implement the function Application::save_program() to write
// the value of the string parameter contents to the file with the
// name given as the parameter file_name. This makes it possible to
// save the current script from the Control script-window to a
// file. Make sure to handle potential problems with opening the file
// appropriately.
void Application::save_program(string file_name, string contents) {
    // BEGIN: A2
    //
    // Write your answer to assignment A2 here, between the // BEGIN: A2
    // and // END: A2 comments. You should remove any code that is
    // already there and replace it with your own.
    ofstream file(file_name);
    file << contents;
    // END: A2
}

// Task A3: Converting string to double
//
// Implement the function Application::get_fps() to return the
// string passed in the parameter fps as a double. If the value of
// fps is not a valid double, the function should throw an
// exception with a descriptive error message.
double Application::get_fps(string fps) {
    // BEGIN: A3
    //
    // Write your answer to assignment A3 here, between the // BEGIN: A3
    // and // END: A3 comments. You should remove any code that is
    // already there and replace it with your own.
    try {
        double fpsOut = static_cast<double>(fps);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // END: A3
}

// |
// | END OF ASSIGNMENTS
// |

// The main loop of the program that redraws the grid and shows the
// next frame.
void Application::main_loop() {
    while (!window.should_close()) {
        grid.draw_universe();
        window.next_frame();
    }
}

void Application::trace_execution(string instr) {
    out_execution_trace.value(
        (string(out_execution_trace.value()) + instr + "\n").c_str());
}

void Application::clear_trace() {
    out_execution_trace.value("");
}

void Application::enable_gui() {
    in_program.activate();
    in_execution_speed.activate();
    btn_run_program.activate();
    btn_save_program.activate();
    btn_load_program.activate();
}

void Application::disable_gui() {
    in_program.deactivate();
    in_execution_speed.deactivate();
    btn_run_program.deactivate();
    btn_save_program.deactivate();
    btn_load_program.deactivate();
}

// Checks if the string str ends with suffix
static bool ends_with(const std::string &str, const std::string &suffix) {
    return str.size() >= suffix.size() &&
           0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

// Wrapper function for displaying a file chooser dialog to make the
// user select a file name.
optional<string> Application::choose_file(Fl_Native_File_Chooser::Type type) {
    file_chooser.type(type);
    file_chooser.options(Fl_Native_File_Chooser::SAVEAS_CONFIRM);
    switch (file_chooser.show()) {
    case -1:
        printf("ERROR: %s\n", file_chooser.errmsg());
        return nullopt;
        break; // ERROR
    case 1:
        return nullopt;
        break;
    default:
        string file_name = string(file_chooser.filename());
        if (!ends_with(file_name, ".txt")) {
            file_name = file_name + ".txt";
        }
        return make_optional(file_name);
        break;
    }
}

// Performs the command requested as per the value of the cmd parameter
void Application::do_command(Command cmd) {
    switch (cmd) {
    case EXECUTE_SCRIPT:
        interpreter.execute_program(in_program.value(),
                                    get_fps(in_execution_speed.value()));
        break;
    case CLEAR_GRID:
        grid.clear_robots();
        break;
    case LOAD_PROGRAM: {
        auto file_name = choose_file(Fl_Native_File_Chooser::BROWSE_FILE);
        if (file_name) {
            in_program.value(load_program(file_name.value()).c_str());
        }
    } break;
    case SAVE_PROGRAM: {
        auto file_name = choose_file(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
        if (file_name) {
            save_program(file_name.value(), string(in_program.value()));
        }
    } break;
    case CLEAR_TRACE:
        clear_trace();
        break;
    case DISABLE_GUI:
        disable_gui();
        break;
    case ENABLE_GUI:
        enable_gui();
        break;
    default:
        assert(0);
    }
}

Application::Application()
    : window(50, 50, 1024, 768, "Robot commander"),
      grid(window, *this, 10, 10, 650, 650, 5, 5), interpreter(grid),
      in_program(700, 20, 300, 200, "Control script"),
      btn_run_program(700, 230, 300, 50, "Run program"),
      btn_load_program(700, 280, 300, 50, "Load program from file"),
      btn_save_program(700, 330, 300, 50, "Save program to file"),
      in_execution_speed(700, 420, 300, 30, "Frames per second"),
      out_execution_trace(700, 480, 300, 250, "Execution trace") {
    file_chooser.title("Pick a file");
    file_chooser.filter("Text\t*.txt");
    // Set default file open dialog relative to source file directory
    string dirname = (filesystem::path(string(__FILE__)).remove_filename() /
                      string("programs"))
                         .string();
    file_chooser.directory(dirname.c_str());
    btn_run_program.callback(
        &callback_dispatch<DISABLE_GUI, CLEAR_TRACE, CLEAR_GRID, EXECUTE_SCRIPT>,
        this);
    window.add(btn_run_program);
    in_program.align(FL_ALIGN_TOP_LEFT);
    in_program.textfont(Font::courier);
    in_program.value("make_grid     6     6\n"
                     "make_robot    bob   2      2 green\n"
                     "make_robot    alice 4      4 blue\n"
                     "move_robot    bob   2      3\n"
                     "move_robot    alice 4      5\n"
                     "recolor_robot alice yellow\n"
                     "rename_robot  bob   roy\n"
                     "move_robot    roy 5      5\n"
                     "delete_robot  roy\n"
                     "delete_robot  alice\n");
    window.add(in_program);
    window.add(btn_load_program);
    btn_load_program.callback(&callback_dispatch<LOAD_PROGRAM>, this);
    window.add(btn_save_program);
    btn_save_program.callback(&callback_dispatch<SAVE_PROGRAM>, this);
    in_execution_speed.align(FL_ALIGN_TOP_LEFT);
    in_execution_speed.value("2");
    window.add(in_execution_speed);
    out_execution_trace.align(FL_ALIGN_TOP_LEFT);
    out_execution_trace.textfont(Font::courier);
    window.add(out_execution_trace);
}
