#ifndef _LUMPARRAY_H_
#define _LUMPARRAY_H_

#include <vector>

using namespace std;

template <class T>
class LumpArray
{
public:
    vector<T*>  elements;
    void        insertElement(T* t);
    void        deleteElement(int index);
    int         getTotalOfElements();
    T*          getElementByIndex(int index);
};

template <class T>
void LumpArray<T>::insertElement(T* t)
{
    printf("oi");
    elements.push_back(t);
}

template <class T>
void LumpArray<T>::deleteElement(int index)
{
    elements.erase(elements.begin() + index);
}

template <class T>
int LumpArray<T>::getTotalOfElements()
{
    return elements.size();
}

template <class T>
T* LumpArray<T>::getElementByIndex(int index)
{
    return elements[index];
}

#endif // _LUMPARRAY_H_
