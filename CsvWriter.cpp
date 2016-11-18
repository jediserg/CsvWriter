//
// Created by serg on 11/18/16.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "CsvWriter.h"

CsvWriter::CsvWriter(std::string file, std::vector<std::string> header) :
        _file_name(std::move(file)), _header(std::move(header)), _file(nullptr){

}

bool CsvWriter::write(const std::map<std::string, std::string> &data) {
    if(_file == nullptr)
        return  false;

    std::stringstream ss;

    for(int i = 0; i < _header.size(); ++i){
        if(i != 0)
            ss << ";";

        auto it = data.find(_header[i]);

        if(it != data.end())
            ss << it->second;
    }
    ss << "\r\n";

    std::string line(ss.str());
    return fwrite(line.c_str(), line.size(), 1, _file) == line.size();
}

bool CsvWriter::create() {
    if(!_file)
        _file = fopen(_file_name.c_str(), "w");

    if(!_file)
        return false;

    std::stringstream ss;

    for(int i = 0; i < _header.size(); ++i)
    {
        if(i != 0)
            ss << ";";

        ss << _header[i];
    }
    ss << std::endl;

    std::string _header_line = ss.str();

    return fwrite(_header_line.c_str(), _header_line.size(), 1, _file) == _header_line.size();

}

CsvWriter::~CsvWriter() {
    if(_file)
        fclose(_file);
}

void CsvWriter::close() {
    if(_file) {
        fclose(_file);
        _file = nullptr;
    }
}
