#ifndef ISE102_H
#define ISE102_H

//#include <iostream>
//#include "scn/all.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include "fmt/core.h"
#include "fmt/format.h"
#include "fmt/color.h"
//using namespace std;
using fmt::print;
using fmt::format;
using fmt::emphasis;
using fmt::fg;
using fmt::bg;
//using scn::input;
//using scn::prompt;
using fmt::color;
using namespace std::literals::chrono_literals;
#include <cstdlib>


void delay(int duration_ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}

void clearScreen()
{
#ifdef WINDOWS
  std::system("cls");
  //print("\n windows clearscreen \n");
#else
  // Assume POSIX
  std::system("clear");
  //print("\n linux clearscreen \n");
#endif
}

fmt::text_style makeStyle(fmt::color foreground, fmt::color background,fmt::emphasis emph = fmt::emphasis(0))
{
  return emph | fg(foreground) | bg (background);
}

#endif  // ISE102_H