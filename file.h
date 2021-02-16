#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> readFile(string path){
  string line;
  vector <string> lines;
  ifstream file (path);
  if(file.is_open()){
    while(getline(file, line)){
      lines.push_back(line);
    }
    file.close();
  }
  return lines;
}

int fileSize(vector<string> lines){
  return lines.size();
}
