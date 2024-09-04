add_library(english_lib english.h english_verbs.h english_verbs.cpp)
target_include_directories(english_lib PUBLIC
  ${CMAKE_CURRENT_LIST_DIR})
