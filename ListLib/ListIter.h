#ifndef LISTITER
#define LISTITER
#include "ListElem.h"
#include "List.h"

template<class T>
class TListIter
{
private:
    TList<T>& list;
    TListElem<T>* i;
public:
    TListIter(TList<T>& l);
    ~TListIter();

    bool HasNext() const;
    bool GoNext();
    bool GoBack();
    bool ResetIter(int i);
    TListElem<T>* Get();
    T GetData();
};

template<class T>
inline TListIter<T>::TListIter(TList<T>& l):list(l)
{
    this->i = l.GetFirst();
}

template<class T>
inline TListIter<T>::~TListIter()
{
    this->i = 0;
}
template<class T>
inline bool TListIter<T>::HasNext() const
{
    return (this->i->GetNext()!=0);
}

template<class T>
inline bool TListIter<T>::GoNext()
{
    if (this->i->GetNext() == 0) return false;
    else this->i = this->i->GetNext();
    return true;
}

template<class T>
inline bool TListIter<T>::GoBack()
{
    if (this->i->GetPrev() == 0) return false;
    this->i = this->i->GetPrev();
    return true;
}

template<class T>
inline bool TListIter<T>::ResetIter(int ind)
{
    if (ind > this->list.GetSize() || ind < (-1) * this->list.GetSize())
        return false;
    if (ind < 0) {
        this->i = this->list->GetLast();
        for (int k = -1; k > ind; k--)
            this->i = this->i->GetPrev();
        return true;
    }
    else {
        this->i = this->list->GetFirst();
        for (int k = 0; k < ind; k++)
            this->i = this->i->GetNext();
        return true;
    }
}

template<class T>
inline TListElem<T>* TListIter<T>::Get()
{
    return this->i;
}

template<class T>
inline T TListIter<T>::GetData()
{
    return this->i->GetData();
}

#endif