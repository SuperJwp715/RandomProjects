#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::string get_time();
int get_date_tallys();
int main() {
  std::cout << get_time();
  std::string prompt = "tally: ";
  std::string input;

  std::ofstream MyFile("tally.txt");
  
  MyFile.close();
  int counter = 0;
  while (input != "end") {
    if (input == "show" || input == "display" || input == "disp") {
      std::cout << counter;
    } else if (input == "add" || input == "a") {
      counter++;
    } else if (input == "sub") {
      counter--;
    }
    std::cout << std::endl;
    std::cout << prompt;
    std::cin >> input;
  }
}

int get_date_tallys() {
  std::ifstream MyReadFile("tally.txt");

  std::string line;
  std::string todays_date = get_time();

  while (std::getline(MyReadFile, line)) {
    if (line.find(todays_date) != std::string::npos) {
      
      MyReadFile.close();
    }
  }
  MyReadFile.close();
  return 0;
}

std::string get_time() {
  time_t timestamp = time(&timestamp);
  struct tm datetime = *localtime(&timestamp);

  int month_offset = 1;   // months go from 0-11
  int year_offset = 1900; // year counts years after 1900

  std::string date = std::to_string(datetime.tm_mon + month_offset) + "-" +
                     std::to_string(datetime.tm_mday) + "-" +
                     std::to_string(datetime.tm_year + year_offset);
  return date;
}
