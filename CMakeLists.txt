cmake_minimum_required(VERSION 3.20)
set(PROJECT load)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(${PROJECT})

add_subdirectory(lib)

add_executable(main ${PROJECT}.cpp)

target_link_libraries(main english_lib)

add_custom_command(TARGET main POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_LIST_DIR}/data/verbs.json
  ${CMAKE_CURRENT_BINARY_DIR})

if(${CMAKE_BUILD_TYPE}==Debug)
  if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    message("${CMAKE_CURRENT_BINARY_DIR}/Debug dosen't exist.")
  else()
    message("${CMAKE_CURRENT_BINARY_DIR}/Debug exist.")
    add_custom_command(TARGET main POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
      ${CMAKE_CURRENT_LIST_DIR}/data/verbs.json
      ${CMAKE_CURRENT_BINARY_DIR}/Debug)
  endif()
endif()
if(${CMAKE_BUILD_TYPE}==Release)
  if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/Release)
    message("${CMAKE_CURRENT_BINARY_DIR}/Release dosen't exist.")
  else()
    message("${CMAKE_CURRENT_BINARY_DIR}/Release exist.")
    add_custom_command(TARGET main POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
      ${CMAKE_CURRENT_LIST_DIR}/data/verbs.json
      ${CMAKE_CURRENT_BINARY_DIR}/Release)
  endif()
endif()



