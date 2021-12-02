#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "functions/changeMaking.h"

int main(int argc, char const *argv[]) {
  if (argc >= 2) {
    changeMaking(atoi(argv[1]), argv[2]);
  }

  return 0;
}
