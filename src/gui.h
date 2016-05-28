#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>

#include "create_index.h"
#include "delete_reg.h"
#include "create_reg.h"
#include "io_operations.h"
#include "merge.h"

class GUI {
  public:
    static bool RunMainMenu();
    static void ShowMainMenu();

  private:
    static void CreateNewIndexFile();

    static void AddRegistryToDataFile();
    static void RemoveRegistryFromDataFile();
    static void UpdateRegistryFromDataFile();

    static void MergeDataFilesUsingTheirIndexFiles();
};

#endif /* GUI_H */
