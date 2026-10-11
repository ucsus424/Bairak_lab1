#include "Group.h"
#include "Headman.h"
#include <iostream>

BayrakGroup::BayrakGroup()
{
}

BayrakGroup::~BayrakGroup()
{
    clear();
}

void BayrakGroup::add(BayrakStudent* student)
{
    if (student != nullptr)
        students.push_back(student);
}

void BayrakGroup::print() const
{
    if (students.empty())
    {
        std::wcout << L"Список пуст." << std::endl;
        return;
    }
    for (size_t i = 0; i < students.size(); ++i)
    {
        std::wcout << i + 1 << L". ";
        students[i]->printToConsole();
    }
}

bool BayrakGroup::load(std::wifstream& in)
{
    clear();

    size_t count = 0;
    if (!(in >> count))
        return false;

    for (size_t i = 0; i < count; ++i)
    {
        int type = 0;
        if (!(in >> type))
            return false;

        BayrakStudent* s = nullptr;
        if (type == BayrakStudent::TYPE_STUDENT)
            s = new BayrakStudent();
        else if (type == BayrakHeadman::TYPE_HEADMAN)
            s = new BayrakHeadman();
        else
            return false;

        s->readFromFile(in);
        if (!in)
        {
            delete s;
            return false;
        }
        students.push_back(s);
    }
    return true;
}

void BayrakGroup::save(std::wofstream& out) const
{
    out << students.size() << L'\n';
    for (size_t i = 0; i < students.size(); ++i)
    {
        out << students[i]->getType() << L'\n';
        students[i]->writeToFile(out);
    }
}

void BayrakGroup::clear()
{
    for (size_t i = 0; i < students.size(); ++i)
        delete students[i];
    students.clear();
}

size_t BayrakGroup::size() const
{
    return students.size();
}
