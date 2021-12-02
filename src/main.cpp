#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions/changeMaking.h"
#include "functions/coinRow.h"

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    return -1;
  }

  if (strcmp(argv[1], "cm") == 0) {
    changeMaking(atoi(argv[2]), argv[3]);
  } else if (strcmp(argv[1], "cr") == 0) {
    coinRow(argv[2]);
  }

  return 0;
}
