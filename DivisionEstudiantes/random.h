#include <iostream>
#include <vector>
#include <time.h>
#include "group.h"
#include "file.h"

using namespace std;

vector<int> groupRest(int count){
  vector<int> groupNumber;
  for(int i = 0; i < count; i ++){
    groupNumber.push_back(i);
  }
  return groupNumber;
}

void randomGroups(vector<string> students, vector<string> topics, group groups[], int count){
  int numStudents = fileSize(students);
  for(int i = 0; i < numStudents - numStudents%count; i++){
    int random = rand();
    int select = i%count;
    groups[select].students.push_back(students[random%fileSize(students)]);
    students.erase(students.begin()+random%fileSize(students));
  }

  if(fileSize(students) > 0){
    int numStudentsRest = count;
    vector<int> num = groupRest(numStudentsRest);
    for(int i = 0; i < fileSize(students); i ++){
      int random = rand();
      int select = random%numStudentsRest;
      groups[num[select]].students.push_back(students[i]);
      num.erase(num.begin()+select);
      numStudentsRest--;
    }
  }

  //Seleccion temas
  int numTopics = fileSize(topics);
  for(int i = 0; i < numTopics - numTopics%count; i++){
    int random = rand();
    int select = i%count;
    groups[select].topics.push_back(topics[random%fileSize(topics)]);
    topics.erase(topics.begin()+random%fileSize(topics));
  }
  if(fileSize(topics) > 0){
    vector<int> num = groupRest(count);
    int numTopicsRest = count;
    for(int i = 0; i < fileSize(topics); i ++){
      int random = rand();
      int select = random%numTopicsRest;
      groups[num[select]].topics.push_back(topics[i]);
      num.erase(num.begin()+select);
      numTopicsRest--;
    }
  }
}
