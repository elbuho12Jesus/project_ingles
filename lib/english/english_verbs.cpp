#include "english_verbs.h"
#include "rapidjson/document.h"
#include <fstream>
#include <iostream>

english_verbs::english_verbs()
  :score{0}
{
  std::cout << "Init verbs: normal verb - pass simple - pass participle"<<"\n";
  ifstream file("example.json"); 
  
    // Read the entire file into a string 
    data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>()); 
  
    // Create a Document object  
      // to hold the JSON data 
    rapidjson::Document doc; 
  
    // Parse the JSON data 
    doc.Parse(data.c_str()); 
  
    // Check for parse errors 
    if (doc.HasParseError()) { 
        cerr << "Error parsing JSON: "
             << doc.GetParseError() << endl;  
    }
}
english_verbs::~english_verbs()
{}
bool english_verbs::validate(std::string s)
{
  return true;
}
