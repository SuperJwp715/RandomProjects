#include <iostream>

int main() {
  int success = 0;
  int failure = 0;
  int percentage = 0;
  while (true) {

    if ((success + failure) > 0) {
      percentage = (double)(success) / (success + failure) * 100;
    }
    std::cout << percentage
              << "% Success rate ((s)uccess, (f)ailure, or (b)reak): ";
    char user;
    std::cin >> user;

    if (user == 's') {
      success++;
    } else if (user == 'f') {
      failure++;
    } else if (user == 'b') {
      break;
    } else {
      continue;
    }

    std::cout << " failure " << failure << " success " << success << std::endl;
  }
}
