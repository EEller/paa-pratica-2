#include <iostream>
#include <vector>

int coinRowRecursive(std::vector<int>& coins, int n) {
  if(n == 0) {

    return 0;
  } else if(n == 1) {

    return coins[1];
  } else {

    return std::max(coinRowRecursive(coins, n - 1), coins[n] + coinRowRecursive(coins, n -2));
  }
}

int coinRowDynamic(std::vector<int>& C) {
  std::vector<int> F(C.size(), -1);
  F[0] = 0;
  F[1] = C[1];

  for(int i=2; i < C.size(); i++ ) {
    F[i] = std::max(F[i-1], C[i] + F[i-2]);
  }

  return F.back();
};


void coinRow(char const *opt) {
  std::vector<int> coins({ 0,5,1,2,10,6,2 });

  switch (opt[0]) {
    case 'r':
      std::cout << coinRowRecursive(coins, coins.size()-1) << std::endl;
      break;

    case 'd':
      std::cout << coinRowDynamic(coins) << std::endl;
      break;

    default:
      std::cout << coinRowRecursive(coins, coins.size()-1)  << std::endl;
      std::cout << coinRowDynamic(coins) << std::endl;
      break;
  }
}