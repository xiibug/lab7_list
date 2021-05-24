
#include "ListIter.h"
#ifndef TLIST
#define TLIST

#include <iostream>
#include <fstream>
#include <math.h>
#include "ListElem.h"

template <class T>
class TList
{
protected:
    TListElem<T>* root;
    TListElem<T>* end;
    int count;
public:
    TList();
    TList(const TList<T>& _v);
    ~TList();

    TList<T>& operator =(const TList<T>& _v);
    bool operator==(const TList<T>& _v) const;
    bool operator!=(const TList<T>& _v) const;

    TListElem<T>* GetFirst() const;
    TListElem<T>* GetLast() const;
    int GetSize() const;

    void InsFirst(T d);
    void InsLast(T d);
    void Ins(TListElem<T>* e, T d);

    bool IsEmpty(void) const;

    void DelFirst();
    void DelLast();
    void Del(TListElem<T>* e);

    TList<int> DividedByK(int k);

    template <class T1>
    friend std::ostream& operator<< (std::ostream& ostr, const TList<T1>& A);
    template <class T1>
    friend std::istream& operator >> (std::istream& istr, TList<T1>& A);
    template <class T1>
    friend std::ofstream& operator<< (std::ofstream& ostr, const TList<T1>& A);
    template <class T1>
    friend std::ifstream& operator >> (std::ifstream& istr, TList<T1>& A);
};

template<class T1>
inline std::ostream& operator<<(std::ostream& ostr, const TList<T1>& A)
{
    TListElem<T1>* i(A.GetFirst());
    while (i != 0) {
        ostr << i->GetData() << ' ';
        i = i->GetNext();
    }
    return ostr;
}

template<class T1>
inline std::istream& operator>>(std::istream& istr, TList<T1>& A)
{
    for (int i = 0; i < A.GetSize(); i++)
        A.DelFirst();
    int count;
    istr >> count;
    T1 d;
    for (int i = 0; i < count; i++) {
        istr >> d;
        A.InsLast(d);
    }
    return istr;
}

template<class T1>
inline std::ofstream& operator<<(std::ofstream& ostr, const TList<T1>& A)
{
    TListElem<T1>* i(A.GetFirst());
    ostr << A.GetSize() << std::endl;
    while (i != 0) {
        ostr << i->GetData() << ' ';
        i = i->GetNext();
    }
    return ostr;
}

template<class T1>
inline std::ifstream& operator>>(std::ifstream& istr, TList<T1>& A)
{
    int count;
    istr >> count;
    if (count == 0) return istr;
    T1 d;
    for (int i = 0; i < count; i++) {
        istr >> d;
        A.InsLast(d);
    }
    return istr;
}

template <class T>
TList<T>::TList() {
    this->root = nullptr;
    this->end = 0;
    this->count = 0;
}

template <class T>
TList<T>::TList(const TList<T>& _v)
{
    if (_v.root == 0)
    {
        this->root = 0;
        this->end = 0;
        this->count = 0;
    }
    else
    {
        this->count = 0;
        this->root = new TListElem<T>(*_v.root);
        TListElem<T>* g = _v.root;
        while (g != 0)
        {
            InsLast(g->GetData());
            g = g->GetNext();
        }
    }
}

template <class T>
TList<T>::~TList<T>() {
    if (this->root != nullptr) {
        this->count = 0;
        TListElem<T>* i = this->root;
        while (i != 0) {
            TListElem<T>* j = i;
            i = i->GetNext();
            delete j;
        }
        this->root = 0;
        this->end = 0;
    }
}

template<class T>
TList<T>& TList<T>::operator = (const TList<T>& _v) {
    if (this == &_v) {
        return *this;
    }
    if (this->root != nullptr) {
        this->count = 0;
        TListElem<T>* i = root;
        while (i != 0) {
            TListElem<T>* j = i;
            i = i->GetNext();
            delete j;
        }
        this->root = 0;
        this->end = 0;
    }
    if (_v.root == 0)
    {
        this->root = 0;
        this->end = 0;
        this->count = 0;
    }
    else
    {
        this->root = new TListElem<T>(*_v.root);
        TListElem<T>* g = _v.root;
        while (g != 0)
        {
            InsLast(g->GetData());
            g = g->GetNext();
        }
    }
    return *this;
}

template<class T>
inline bool TList<T>::operator==(const TList<T>& _v) const
{
    if (this == &_v) return true;
    if (this->count != _v.count) return false;
    TListElem<T>* i(this->root);
    TListElem<T>* j(_v.root);
    while (i != 0 && j != 0) {
        if (i->GetData() != j->GetData())
            return false;
        i = i->GetNext();
        j = j->GetNext();
    };
    return true;
}

template<class T>
inline bool TList<T>::operator!=(const TList<T>& _v) const
{
    return (!(*this==_v));
}


template<class T>
void TList<T>::InsFirst(T d)
{
    if (this->root == 0) {
        TListElem<T>* i = new TListElem<T>(d);
        this->root = i;
        this->end = i;
    }
    else {
        TListElem<T>* j = new TListElem<T>(d);
        j->SetNext(this->root);
        this->root->SetPrev(j);
        this->root = j;
    }
    this->count++;
}

template<class T>
void TList<T>::DelFirst()
{
    TListElem<T>* i = this->root;
    if (i != 0) {
        this->root = this->root->GetNext();
        this->root->SetPrev(0);
        delete i;
        this->count--;
    }
    else throw - 1;
}

template<class T>
void TList<T>::InsLast(T d) {
    TListElem<T>* i = this->root;
    if (this->count == 0) {
        i = new TListElem<T>(d);
        this->root = i;
        this->end = i;
    }
    else {
        TListElem<T>* j=new TListElem<T>(d);
        j->SetPrev(this->end);
        this->end->SetNext(j);
        this->end = j;
    }
    this->count++;
}

template<class T>
inline void TList<T>::Ins(TListElem<T>* e, T d)
{
    TListElem<T>* i = this->root;
    while (i != 0 && i != e)
        i = i->GetNext();
    if (i == 0) throw - 1;
    TListElem<T>* dat=new TListElem<T>(d);
    i->GetNext()->SetPrev(dat);
    dat->SetNext(i->GetNext());
    dat->SetPrev(i);
    i->SetNext(dat);
    this->count++;
}

template<class T>
inline bool TList<T>::IsEmpty(void) const
{
    return (this->count == 0);
}

template<class T>
inline TListElem<T>* TList<T>::GetFirst() const
{
    return this->root;
}

template<class T>
inline TListElem<T>* TList<T>::GetLast() const
{
    return this->end;
}

template<class T>
inline int TList<T>::GetSize() const
{
    return count;
}

template<class T>
void TList<T>::DelLast() {
    TListElem<T>* i = this->end;
    if (this->count == 0) {
        throw - 1;
    }
    else {
        this->end = i->GetPrev();
        this->end->SetNext(0);
        delete i;
    }
    this->count--;
}

template<class T>
inline void TList<T>::Del(TListElem<T>* e)
{
    TListElem<T>* i = this->root;
    while (i != 0 && i != e)
        i = i->GetNext();
    if (i == 0) throw - 1;
    if (i->GetNext() != 0)
        i->GetNext()->SetPrev(i->GetPrev());
    if (i->GetPrev() != 0)
        i->GetPrev()->SetNext(i->GetNext());
    delete i;
    this->count--;
}


inline TList<int> TList<int>::DividedByK(int k)
{
    TList<int> res;
    TListElem<int>* i = this->root;
    while (i != 0) {
        if (i->GetData() % k == 0)
            res.InsLast(i->GetData());
        i = i->GetNext();
    }
    return res;
}

#endif