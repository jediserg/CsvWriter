#include <iostream>
#include "CsvWriter.h"

int main() {
    CsvWriter writer("/tmp/test.csv", {"column1", "column2", "column3", "column4"});

    writer.create();

    writer.write({
                         {"column1", "value11"},
                         {"column2", "value21"},
                         {"column4", "value41"},
                         {"column3", "value31"},
                 });

    writer.write({
                         {"column1", "value12"},
                         {"column2", "value22"},
                         {"column3", "value32"},
                         {"column4", "value42"},
                 });

    writer.write({{}});

    writer.write({
                         {"column1", "value12"},
                         {"column2", "value22"},
                         {"column3", "value32"},
                         {"column4", "value42"},
                 });

    writer.write({
                         {"column2", "value25"}
                 });

    writer.close();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}