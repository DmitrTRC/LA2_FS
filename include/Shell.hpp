//
// Created by Dmitry Morozov on 24/1/23.
//

#ifndef LA2_FS_MAIN_SRC_SHELL_HPP_
#define LA2_FS_MAIN_SRC_SHELL_HPP_

#include <string>

class Shell {
 public:
  Shell(const std::string &, size_t);
  void Run();

 private:
  void help_cmd();
  void rename_cmd();

};

#endif //LA2_FS_MAIN_SRC_SHELL_HPP_
