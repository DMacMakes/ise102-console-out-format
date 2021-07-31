#ifndef ISE102_H
#define ISE102_H

//#include <iostream>
//#include "scn/all.h"
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

//void newLine()
//{
  //std::cout << std::endl;
//}
#include <cstdlib>

void clearScreen()
{
#ifdef WINDOWS
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}

fmt::text_style makeStyle(fmt::color foreground, fmt::color background,fmt::emphasis emph = fmt::emphasis(0))
{
  return emph | fg(foreground) | bg (background);
}

#endif  // ISE102_H