// goal is to implement binary search in cpp

#include <iostream>
#include <vector>


int main() {
  std::vector<int> testVec = {1, 5, 9, 13, 15, 99, 181};
  

  std::vector<int> current = testVec;
  int left = 0;
  int right = current.size() - 1;
  bool found = false;
  int target = 14;
  while (left < right && !found) {
    int mid = (left + right) / 2;
    if (current[mid] == target) {
      found = true;
    } else if (current[mid] > target) {
      right = mid - 1;
      
    } else {
      left = mid + 1;
    }
    

  }

  if (found) {
    std::cout << "value " << target << " is in vector \n";
  } else {
    std::cout << "value is not in vector \n";
  }



}

