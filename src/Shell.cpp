//
// Created by Dmitry Morozov on 24/1/23.
//

#include "Shell.hpp"

#include <iostream>
#include <sstream>
#include <vector>

Shell::Shell(const std::string &path, size_t size) {

  std::cout << "Shell Constructor . Args :  Path =  " << path << " Size = " << size << std::endl;
}

//Command Example
// copy file1 path/file2
// help
// touch fileName

//FIXME: Wrong  command string
void Shell::Run() {
  std::vector<std::string> cmd_line;
  std::cout << "Command interpreter launched" << std::endl;

  std::string cmd, line;

  //Main loop
  while (cmd != "exit") {

    std::cout << "FS > ";

    std::getline(std::cin, line);


    std::cout << "User wrote : " << line << std::endl;

    std::istringstream ss(line);

    cmd_line.clear();

    //Fill cmd_line vector
    while (ss >> cmd) {
      cmd_line.push_back(cmd);
    }

    if (cmd_line.empty()) {
      continue;
    }

    cmd = cmd_line[0];

    std::cout << "Command is : " << cmd << std::endl;

    cmd_line.erase(cmd_line.begin(), cmd_line.end());

    if (cmd == "help") {
      help_cmd();
    } else if (cmd == "rename") {
      if (cmd_line.size() != 2) {
        std::cerr << " Wrong Argument number!" << std::endl;
      } else {
        rename_cmd(cmd_line[0], cmd_line[1]);
      }
    } else {
      std::cout << "Unknown command" << cmd << std::endl;
      std::cout << "Type 'help' for a list of commands " << std::endl;
    }

  }
  std::cout << "Command interpreter is stopped" << std::endl;
}

void Shell::help_cmd() {
  std::cout << " Help. Command list : \n";
  std::cout << "exit : Exit from shell \n";
  std::cout << "help : Show this screen \n";
}
void Shell::rename_cmd(const std::string &src_fName, const std::string &trg_fName) {

  std::cout << " Rename command run " << std::endl;
  std::cout << "Renaming file " << src_fName << " to file : " << trg_fName << std::endl;

}
