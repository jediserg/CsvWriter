//
// Created by serg on 11/18/16.
//

#ifndef CSVWRITER_CSVWRITER_H
#define CSVWRITER_CSVWRITER_H

#include <string>
#include <vector>
#include <map>
#include <stdio.h>

class CsvWriter {
public:
    CsvWriter(std::string file, std::vector<std::string>);
    ~CsvWriter();

    bool create();
    bool write(const std::map<std::string, std::string> &);
    void close();
private:
    std::string _file_name;
    std::vector<std::string> _header;

    FILE* _file;
};


#endif //CSVWRITER_CSVWRITER_H
