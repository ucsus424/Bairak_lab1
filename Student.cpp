#include "Student.h"
#include <iostream>
#include <algorithm>

BayrakStudent::BayrakStudent() : name(L""), age(0), averageGrade(0.0)
{
}

BayrakStudent::~BayrakStudent()
{
}

void BayrakStudent::readFromConsole()
{
    name = inputLine(L"ФИО: ");
    age = inputInt(L"Возраст: ", 14, 100);
    averageGrade = inputDouble(L"Средний балл (2-5): ", 2.0, 5.0);
}

void BayrakStudent::printToConsole() const
{
    std::wcout << L"[Студент]  " << name
               << L", возраст: " << age
               << L", средний балл: " << averageGrade << std::endl;
}

int BayrakStudent::getType() const
{
    return TYPE_STUDENT;
}

void BayrakStudent::readFromFile(std::wifstream& in)
{
    std::getline(in >> std::ws, name);
    in >> age >> averageGrade;
}

void BayrakStudent::writeToFile(std::wofstream& out) const
{
    out << name << L'\n'
        << age << L'\n'
        << averageGrade << L'\n';
}

std::wstring BayrakStudent::inputLine(const std::wstring& prompt)
{
    std::wstring s;
    while (true)
    {
        std::wcout << prompt;
        if (!std::getline(std::wcin, s))
        {
            std::wcin.clear();
            continue;
        }
        if (!s.empty())
            return s;
    }
}

int BayrakStudent::inputInt(const std::wstring& prompt, int minV, int maxV)
{
    while (true)
    {
        std::wstring s = inputLine(prompt);
        try
        {
            size_t pos = 0;
            int v = std::stoi(s, &pos);
            if (pos == s.size() && v >= minV && v <= maxV)
                return v;
        }
        catch (...) {}
        std::wcout << L"Ошибка: введите целое число от " << minV
                   << L" до " << maxV << L"." << std::endl;
    }
}

double BayrakStudent::inputDouble(const std::wstring& prompt, double minV, double maxV)
{
    while (true)
    {
        std::wstring s = inputLine(prompt);
        std::replace(s.begin(), s.end(), L',', L'.');
        try
        {
            size_t pos = 0;
            double v = std::stod(s, &pos);
            if (pos == s.size() && v >= minV && v <= maxV)
                return v;
        }
        catch (...) {}
        std::wcout << L"Ошибка: введите число от " << minV
                   << L" до " << maxV << L"." << std::endl;
    }
}
