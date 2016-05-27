#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>

#include "create_index.h"
#include "io_operations.h"

class GUI {
  public:
    static bool RunMainMenu();
    static void ShowMainMenu();

  private:
    static void CreateNewIndexFile();
    static void AddRegistryToDataFile();

};

#endif /* GUI_H */
