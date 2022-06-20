// Defines a base class for Application with exported functionality
// to avoid problems with circular references in includes

#pragma once

#include "std_lib_facilities.h"

class TracingApplication
{
public:
  virtual void trace_execution(string intr)
  {
    (void)intr;
  };
  virtual void clear_trace(){};
  virtual void enable_gui(){};
};

