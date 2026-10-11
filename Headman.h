#pragma once
#include "Student.h"

class BayrakHeadman : public BayrakStudent
{
public:
    static const int TYPE_HEADMAN = 2;

    BayrakHeadman();
    virtual ~BayrakHeadman();

    void readFromConsole() override;
    void printToConsole() const override;
    int  getType() const override;
    void readFromFile(std::wifstream& in) override;
    void writeToFile(std::wofstream& out) const override;

private:
    std::wstring phone;
    int headmanYears;
};
