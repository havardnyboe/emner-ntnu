#pragma once

#include "AnimationWindow.h"
#include "GUI.h"
#include "interpreter.h"
#include "robot_grid.h"
#include "std_lib_facilities.h"
#include "tracing_application.h"
#include <FL/Fl_Button.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <optional>

class Application : public TracingApplication
{
public:
  Application();
  void main_loop();
  void trace_execution(string intr);
  void clear_trace();
  void enable_gui();

private:
  AnimationWindow window;
  RobotGrid grid;
  Interpreter interpreter;

  void execute_program(istringstream program);
  string load_program(string file_name);
  void save_program(string file_name, string conents);
  double get_fps(string fps);
  optional<string> choose_file(Fl_Native_File_Chooser::Type type);
  void disable_gui();

  // Window widgets
  Fl_Multiline_Input in_program;
  Fl_Button btn_run_program;
  Fl_Button btn_load_program;
  Fl_Button btn_save_program;
  Fl_Native_File_Chooser file_chooser;
  Fl_Input in_execution_speed;
  Fl_Multiline_Output out_execution_trace;

  enum Command {
    DISABLE_GUI,
    ENABLE_GUI,
    EXECUTE_SCRIPT,
    CLEAR_GRID,
    LOAD_PROGRAM,
    SAVE_PROGRAM,
    CLEAR_TRACE
  };
  void do_command(Command command);
  void execute_program();

  template <int command>
  static void callback_dispatch(Fl_Widget *, void *base_ptr)
  {
    dispatch_command<command>(base_ptr);
  }

  template <int command1, int command2>
  static void callback_dispatch(Fl_Widget *, void *base_ptr)
  {
    dispatch_command<command1, command2>(base_ptr);
  }

  template <int command1, int command2, int command3>
  static void callback_dispatch(Fl_Widget *, void *base_ptr)
  {
    dispatch_command<command1, command2, command3>(base_ptr);
  }

  template <int command1, int command2, int command3, int command4>
  static void callback_dispatch(Fl_Widget *, void *base_ptr)
  {
    dispatch_command<command1, command2, command3, command4>(base_ptr);
  }

  template <int command>
  static void dispatch_command(void *base_ptr)
  {
    try {
      reference_to<Application>(base_ptr).do_command(Command(command));
    } catch (const exception &e) {
      fl_alert("Caught exception:\n\n%s", e.what());
      reference_to<Application>(base_ptr).enable_gui();
    } catch (const string &e) {
      fl_alert("Caught exception:\n\n%s", e.c_str());
      reference_to<Application>(base_ptr).enable_gui();
    }
  }

  template <int command1, int command2>
  static void dispatch_command(Address base_ptr)
  {
    dispatch_command<command1>(base_ptr);
    Fl::add_timeout(0, &dispatch_command<command2>, base_ptr);
  }

  template <int command1, int command2, int command3>
  static void dispatch_command(Address base_ptr)
  {
    dispatch_command<command1>(base_ptr);
    Fl::add_timeout(0, &dispatch_command<command2>, base_ptr);
    Fl::add_timeout(0, &dispatch_command<command3>, base_ptr);
  }

  template <int command1, int command2, int command3, int command4>
  static void dispatch_command(Address base_ptr)
  {
    dispatch_command<command1>(base_ptr);
    Fl::add_timeout(0, &dispatch_command<command2>, base_ptr);
    Fl::add_timeout(0, &dispatch_command<command3>, base_ptr);
    Fl::add_timeout(0, &dispatch_command<command4>, base_ptr);
  }
};

