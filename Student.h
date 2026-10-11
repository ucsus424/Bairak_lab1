#pragma once
#include <string>
#include <fstream>

class BayrakStudent
{
public:
    static const int TYPE_STUDENT = 1;

    BayrakStudent();
    virtual ~BayrakStudent();

    virtual void readFromConsole();
    virtual void printToConsole() const;
    virtual int  getType() const;
    virtual void readFromFile(std::wifstream& in);
    virtual void writeToFile(std::wofstream& out) const;

    static std::wstring inputLine(const std::wstring& prompt);
    static int inputInt(const std::wstring& prompt, int minV, int maxV);
    static double inputDouble(const std::wstring& prompt, double minV, double maxV);

protected:
    std::wstring name;
    int age;
    double averageGrade;
};
