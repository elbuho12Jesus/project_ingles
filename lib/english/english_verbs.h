#include "english.h"
class english_verbs {
public:
  english_verbs();
  english_verbs(english_verbs &&) = default;
  english_verbs(const english_verbs &) = default;
  english_verbs &operator=(english_verbs &&) = default;
  english_verbs &operator=(const english_verbs &) = default;
  ~english_verbs();
  bool validate(std::string s);
  int score;
  std::string data;

private:
  
};
