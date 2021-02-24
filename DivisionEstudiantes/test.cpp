#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "random.h"
#include <time.h>
#include <map>

using namespace std;

TEST(VerifyRandom, Random){
  vector <string> studentS = {"Juan","Paula","Ramon","Arturo","Matias"};
  vector <string> topics = {"math","Language","Civic","Programming","Tech"};
  srand(time(NULL));
  int juan[750], paula[750],ramon[750],arturo[750],matias[750];
  for(int i = 0; i < 750;i++){
    group groups[5];
    randomGroups(studentS,topics,groups,5);
    for(int j = 0; j < 5;j++){
      for(string student : groups[j].students){
        if(student == studentS[0])
          juan[i] = j;
        else if(student == studentS[1])
          paula[i] = j;
        else if(student == studentS[2])
          ramon[i] = j;
        else if(student == studentS[3])
          arturo[i] = j;
        else if(student == studentS[4])
          matias[i] = j;
        }
    }
  }

  //TEST Improved
  for(int i = 0; i < 5;i++){
    double num = count(juan,juan+750,i);
    double val = (abs(num-150.0)/150.0)*100.0;
    ASSERT_LE(val,20);
    double num1 = count(paula,paula+750,i);
    double val1 = (abs(num1-150.0)/150.0)*100.0;
    ASSERT_LE(val1,20);
    double num2 = count(ramon,ramon+750,i);
    double val2 = (abs(num2-150.0)/150.0)*100.0;
    ASSERT_LE(val2,20);
    double num3 = count(arturo,arturo+750,i);
    double val3 = (abs(num3-150.0)/150.0)*100.0;
    ASSERT_LE(val3,20);
    double num4 = count(matias,matias+750,i);
    double val4 = (abs(num4-150.0)/150.0)*100.0;
    ASSERT_LE(val4,20);
    ASSERT_EQ(num+num1+num2+num3+num4,750);
  }
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
