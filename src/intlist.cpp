#include "intlist.h"

IntList::IntList()
{
}

void IntList::append(const int i)
{

    m_list.append(i);

}

int IntList::count()
{
    return m_list.count();
}
void IntList::clear()
{
    return m_list.clear();
}
bool IntList::isEmpty()
{
    return m_list.isEmpty();
}
int IntList::at(int i)
{
    return m_list.at(i);
}
int IntList::size()
{
    return m_list.count();
}
