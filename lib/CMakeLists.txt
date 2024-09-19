set(english_lib_dir "${CMAKE_CURRENT_LIST_DIR}/english/")

#file (GLOB english_file_h "${english_lib_dir}/*.h")
file (GLOB english_file_cpp "${english_lib_dir}/*.cpp")

add_library(english_lib ${english_file_cpp})
target_include_directories(english_lib PUBLIC
  ${CMAKE_CURRENT_LIST_DIR})
