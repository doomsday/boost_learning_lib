#include <boost/predef.h>
#include <boost/config.hpp>
#include <boost/version.hpp>

#include <iostream>

using std::cout;
using std::endl;

void check_os();
void build_env_info();

int main() {

  check_os();
  build_env_info();

  return EXIT_SUCCESS;
}

void check_os() {
  // Identify OS.
#if defined(BOOST_OS_WINDOWS)
  cout << "Windows ";
#elif defined(BOOST_OS_LINUX)
  cout << "Linux ";
#elif defined(BOOST_OS_MACOS)
  cout << "MacOS ";
#elif defined(BOOST_OS_UNIX)
  cout << "Anoter UNIX ";
#endif

  // Identify architecture.
#if defined(BOOST_ARCH_X86)
#if defined(BOOST_ARCH_X86_64)
  cout << "x86-64 bit" << endl;
#else
  cout << "x86-32 bit" << endl;
#endif
#elif defined(BOOST_ARCH_ARM)
  cout << "ARM" << endl;
#else
  cout << "Other architecture" << endl;
#endif

  // Identify compiler.
#if defined(BOOST_COMP_GNUC)
  cout << "GCC, Version: " << BOOST_COMP_GNUC << endl;
#elif defined(BOOST_COMP_MSVC)
  cout << "MSVC, Version: " << BOOST_COMP_MSVC << endl;
#else
  cout << "Other compiler" << endl;
#endif

}

void build_env_info() {
  cout << "Compiler: " << BOOST_COMPILER << endl
       << "Platform: " << BOOST_PLATFORM << endl
       << "Library: " << BOOST_STDLIB << endl;

  cout << "Boost version: " << BOOST_LIB_VERSION << "[" << BOOST_VERSION << "]" << endl;
}