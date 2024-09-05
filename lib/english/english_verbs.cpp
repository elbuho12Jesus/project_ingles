#include "english_verbs.h"
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h> 
#include <iostream>

english_verbs::english_verbs()
  :score{0}
{
  std::cout << "Init verbs: normal verb - pass simple - pass participle"<<"\n";
    FILE* fp = fopen("../verbs.json", "r"); 
  
    // Use a FileReadStream to 
      // read the data from the file 
    char readBuffer[10000]; 
    rapidjson::FileReadStream is(fp, readBuffer,sizeof(readBuffer)); 
  
    // Parse the JSON data  
      // using a Document object 
    rapidjson::Document doc; 
    doc.ParseStream(is); 
  
    // Close the file 
    fclose(fp);
    if (doc.HasParseError()) { 
      switch (doc.GetParseError()) { 
        case rapidjson::kParseErrorNone: 
          std::cout << "No error" << std::endl; 
          break; 
        case rapidjson::kParseErrorDocumentEmpty: 
          std::cout << "Error: Document is empty" << std::endl; 
          break; 
        case rapidjson::kParseErrorDocumentRootNotSingular: 
          std::cout << "Error: Document root is not singular" << std::endl; 
          break;
        // ... 
      } 
    }
  
    // Access the data in the JSON document 
    std::cout << doc["normal"].GetString() << std::endl; 
    std::cout << doc["pass_simple"].GetString() << std::endl;   
    std::cout << doc["pass_participle"].GetString() << std::endl;   
}
english_verbs::~english_verbs()
{}
bool english_verbs::validate(std::string s)
{
  return true;
}
