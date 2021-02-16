#include <gtest/gtest.h>
#include <vector>
#include "file.h"
#include "main.cpp"

using namespace std;

TEST(VerifyFile, count){
  ASSERT_LE(5,fileSize(readFile("estudiantes.txt")));
  ASSERT_LE(5,fileSize(readFile("temas.txt")));
}

TEST(Random, printRandom)

int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
