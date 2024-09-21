#pragma once
#include "english_verbs.h"
#include "../../include/rapidjson/filereadstream.h"
#include "../../include/rapidjson/document.h"
#include <cctype>
#include <cstdlib>


english_verbs::english_verbs()
  :score_past_simple{0},score_past_participle{0}
{
  std::cout << "Init verbs: normal verb - past simple - past participle"<<"\n";
    FILE* fp = fopen("verbs.json", "r");
    if(fp==NULL)
    {
    	std::cout << "no hay nada" << std::endl;
    }
    else
    {
    	std::cout << "alloha" << std::endl;
    // Use a FileReadStream to
      // read the data from the file
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer,sizeof(readBuffer));

    // Parse the JSON data
      // using a Document object
    rapidjson::Document doc;
    doc.ParseStream(is);
    const rapidjson::Value& verbs = doc["verbs"];
    // Access the data in the JSON document
    /*
        std::cout << doc["normal"].GetString() << std::endl;
        std::cout << doc["pass_simple"].GetString() << std::endl;
        std::cout << doc["pass_participle"].GetString() << std::endl;
    */
        for (rapidjson::SizeType i = 0; i < verbs.Size(); i++)
        {
        	Verb verb;
        	verb.normal=verbs[i]["normal"].GetString();
        	verb.past_simple=verbs[i]["past_simple"].GetString();
        	verb.past_participle=verbs[i]["past_participle"].GetString();
        	data.push_back(verb);
        	/*
        	printf("verbs[%d] = %s\n", i, verbs[i]["normal"].GetString());
        	printf("verbs[%d] = %s\n", i, verbs[i]["past_simple"].GetString());
        	printf("verbs[%d] = %s\n", i, verbs[i]["past_participle"].GetString());
        	*/
        }
    }
    // Close the file
    fclose(fp);
}
english_verbs::~english_verbs()
{
  std::cout << "score Past Simple: "<< score_past_simple <<std::endl;
  std::cout << "score Past Participle: "<< score_past_participle <<std::endl;
}
void english_verbs::past_simple_exercise()
{
	std::cout << "You should write the past simple of the verbs:" << std::endl;
	for(const Verb &verb:data)
	{
		std::cout << verb.normal << std::endl;
		std::string s;
		std::cin >> s;
    std::remove_if(s.begin(),s.end(),isspace);
		if(validate(s,verb.past_simple)) 
      {
        score_past_simple++;
      std::cout << BEGIN_GREEN <<"Good!" << END << std::endl;
      }
		else 
    {
      std::cout << BEGIN_RED <<"wrong!" << END << BEGIN_YELLOW << " correct option: " << verb.past_simple << END << std::endl;
    }
	}
}

void english_verbs::past_participle_exercise()
{
  std::cout << "You should write the past participle of the verbs:" << std::endl;
	for(const Verb &verb:data)
	{
		std::cout << verb.normal << std::endl;
		std::string s;
		std::cin >> s;
    std::remove_if(s.begin(),s.end(),isspace);
		if(validate(s,verb.past_participle)) 
      {
        score_past_participle++;
        std::cout << BEGIN_GREEN <<"Good!" << END << std::endl;
      }
		else 
      { 
        std::cout << BEGIN_RED <<"wrong!" << END << BEGIN_YELLOW << " correct option: " << verb.past_participle << END << std::endl; 
      }
	}

}

std::string english_verbs::convertToLowercase(const std::string& str)
{
	std::string result = "";

    for (char ch : str) {
        // Convert each character to lowercase using tolower
        result += std::tolower(ch);
    }

  return result;
}

bool english_verbs::validate(std::string &s,std::string verb)
{
	if(verb!=convertToLowercase(s))
  {
    return false;
  }
  return true;
}
