#include  "Shell.hpp"

#include <iostream>

// argv : char * path, char * fs_size

const std::string DEFAULT_PATH = "demo.dat";
const size_t DEFAULT_SIZE = 1000;

int main(int argc, char *argv[]) { //TODO: Think about the arguments and

  std::cout << "File System is starting ..." << std::endl;

  Shell *p_shell; // Use a pointer instead ( using std::uniq_ptr<> )

  for (int i{0}; i < argc; ++i) {
    std::cout << "Arg " << i << " :  " << argv[i] << std::endl;
  }

  if (argc == 3) {
    std::string path = argv[1];
    size_t size = std::stoi(argv[2]);

    p_shell = new Shell(path, size);

  } else {

    std::cout << "Wrong args. Using default, Path = " << DEFAULT_PATH << " Size = " << DEFAULT_SIZE << std::endl;
    p_shell = new Shell(DEFAULT_PATH, DEFAULT_SIZE);

  }

  p_shell->Run();

  return 0;
}