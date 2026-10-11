#pragma once
#include <vector>
#include <fstream>
#include "Student.h"

class BayrakGroup
{
public:
    BayrakGroup();
    ~BayrakGroup();

    void add(BayrakStudent* student);
    void print() const;
    bool load(std::wifstream& in);
    void save(std::wofstream& out) const;
    void clear();
    size_t size() const;

private:
    std::vector<BayrakStudent*> students;

    BayrakGroup(const BayrakGroup&) = delete;
    BayrakGroup& operator=(const BayrakGroup&) = delete;
};
