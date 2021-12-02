#include <iostream>
#include <vector>
#include <limits>

int changeMakingRecursive(int change, std::vector<int>& coins) {
  if (change == 0) {

    return 0;
  } else {
    int minCoins = std::numeric_limits<int>::max();
    for (size_t i = 0; i < coins.size(); i++) {
      if(change >= coins[i]) {
        int temp = changeMakingRecursive(change - coins[i], coins);
        minCoins = (temp < minCoins) ? temp : minCoins;
      }
    }

    return minCoins + 1;
  }
}

int changeMakingDynamic(int change, std::vector<int>& coins) {
  std::vector<int> f(change + 1);
  f[0] = 0;

  for (size_t i = 1; i < f.size(); i++) {
    int minCoins = std::numeric_limits<int>::max();
    for (size_t j = 0; j < coins.size(); j++) {
      if(i >= coins[j]) {
        int temp = f[i - coins[j]];
        minCoins = (temp < minCoins) ? temp : minCoins;
      }
    }

    f[i] = minCoins + 1;
  }

  return f.back();
}

void changeMaking(int n, char const *opt) {
  std::vector<int> coins({1,3,4});

  switch (opt[0]) {
    case 'r':
      std::cout << changeMakingRecursive(n, coins) << std::endl;
      break;

    case 'd':
      std::cout << changeMakingDynamic(n, coins) << std::endl;
      break;

    default:
      std::cout << changeMakingRecursive(n, coins) << std::endl;
      std::cout << changeMakingDynamic(n, coins) << std::endl;
      break;
  }
}