#include <fstream>
#include <algorithm>
#include <map>
#include "WordCounter.h"

struct SortPred
{
    bool operator()(const int& intl, const int& intr) const
    {
        return(intl > intr);
    };
};

void WordCounter::Count(const std::string& infile){
    std::ifstream fin(infile);
    if (!fin.is_open())
        std::cout << infile << "could not be opened.\n";
    else {
        std::string line, word;
        while (!fin.eof()){
            getline(fin, line);
            for (size_t i = 0; i < line.length(); ++i){
                while (isalpha(line[i]) || isdigit(line[i])){
                    line[i] = tolower(line[i]);
                    word += line[i];
                    ++i;
                }
                if(!word.empty()){
                    ++mapStringToInt[word];
                    ++count;
                    word.clear();
                }
            }
        }
        fin.close();
    }
}

void WordCounter::Write(const std::string& outfile) const{
    std::ofstream fout(outfile);
    if (!fout.is_open())
        std::cout << outfile << "could not be opened.\n";
    else {
        std::multimap<int, std::string, SortPred> mmapIntToString;
        for(const auto &i : mapStringToInt){
            mmapIntToString.insert(make_pair (i.second, i.first));
        }
        for(const auto &i : mmapIntToString){
            fout << i.second + ";" << i.first << ";" << (double) 100 * i.first / count << '%' << std::endl;
        }
        fout.close();
    }
}
