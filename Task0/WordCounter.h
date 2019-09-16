#ifndef INTRO_WORDCOUNTER_H
#define INTRO_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <map>

class WordCounter
{
public:
    void Count(const std::string& infile);
    void Write(const std::string& outfile) const;
private:
    int count = 0;
    std::map<std::string, int> mapStringToInt;
};

#endif //INTRO_WORDCOUNTER_H
