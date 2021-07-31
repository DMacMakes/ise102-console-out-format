#include <iostream>
#include <string>
#include "include/ise102.h"
using namespace std;

int main() {
  print("Does clear work?");
  clearScreen();
  // Regular std::cout
  cout << "cout says: Hello World!\n";
  // Function style with fmtlib
  print("fmt says: Hello, world\n");
  //print(titleStyle, "Hello world!\n");
  
  std::string name = "Mitcho";
  int age = 64;
  // Joining vars and literals with cout
  //std::cout << "My Name is " << name << " and I am " << age << " years old.\n";
  // Using fmt's print. 
  print("My name is {0} and I am {1} years old.\n", name, age);
  // You can leave the numbers out of the curlies. For single values it's 
  // easy to read. With multiples I prefer the numbers.
  print("In 5 years he'll be {}.\n\n", age+5);
  
  // fmt::format() gives you the same substitution and merging types
  // as print() but returns a string you can use later instead of outputting.
  // Useful for any string you want to format and reuse.
  std::string knight_words = format("\tYou're a Knight of Bidwill at age {0} Ser {1}, just {0}!\t\n", age, name);

  // Use makeStyle to create a text appearance (style) you can use in print()
  // Foreground and background colours plus, if you're on linus, emphasise with bold/underline etc.
  auto title_style = makeStyle( color::dark_violet,
                                color::powder_blue,
                                emphasis::bold ); 
  auto error_style = makeStyle( color::beige,
                                color::crimson,
                                emphasis::bold);

  print(title_style, knight_words);
  print("\n");
  print(error_style, "\t\t\t_BLOWING UP NOW_");
  print("\n");
}