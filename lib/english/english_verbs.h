#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

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
  bool validate(std::string &s,std::string verb);


private:
  std::string convertToLowercase(const std::string& str);
  int score_past_simple;
  int score_past_participle;
  std::vector<Verb> data;
};
