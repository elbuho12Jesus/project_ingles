#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>


#define BEGIN_RED "\033[31m"
#define BEGIN_YELLOW "\033[33m"
#define BEGIN_GREEN "\033[92m"
#define END "\033[0m"


struct Verb
{
	std::string normal;
	std::string past_simple;
	std::string past_participle;
};

class english_verbs{
public:
  english_verbs();
  english_verbs(english_verbs &&) = default;
  english_verbs(const english_verbs &) = default;
  english_verbs &operator=(english_verbs &&) = default;
  english_verbs &operator=(const english_verbs &) = default;
  ~english_verbs();
  void past_simple_exercise();
  void past_participle_exercise();

  bool validate(std::string &s,std::string verb);


private:
  std::string convertToLowercase(const std::string& str);
  int score_past_simple;
  int score_past_participle;
  std::vector<Verb> data;
};
