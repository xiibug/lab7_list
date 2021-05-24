#ifndef LISTELEM
#define LISTELEM
#include <iostream>
#include <fstream>

template <class T>
class TListElem
{
protected:
    T data;
    TListElem* next;
    TListElem* prev;
public:
    TListElem(T _data);
    TListElem(TListElem& _v);
    ~TListElem();

    T GetData() const;
    TListElem* GetNext() const;
    TListElem* GetPrev() const;

    bool operator==(TListElem<T>& _v) const;
    bool operator!=(TListElem<T>& _v) const;

    void SetData(T _data);
    void SetNext(TListElem* _next);
    void SetPrev(TListElem* _prev);

    template <class T1>
    friend std::ostream& operator<< (std::ostream& ostr, const TListElem<T1>& A);
    template <class T1>
    friend std::istream& operator >> (std::istream& istr, TListElem<T1>& A);
    template <class T1>
    friend std::ofstream& operator<< (std::ofstream& ostr, const TListElem<T1>& A);
    template <class T1>
    friend std::ifstream& operator >> (std::ifstream& istr, TListElem<T1>& A);
};
template<class T>
TListElem<T>::TListElem(T _data)
{
    this->data = _data;
    this->next = 0;
    this->prev = 0;
}

template<class T>
inline TListElem<T>::TListElem(TListElem& _v)
{
    this->data = _v.data;
    this->next = 0;
    this->prev = 0;
}

template<class T>
inline TListElem<T>::~TListElem()
{
    this->next = 0;
    this->prev = 0;
}

template<class T>
inline T TListElem<T>::GetData() const
{
    return this->data;
}

template<class T>
inline TListElem<T>* TListElem<T>::GetNext() const
{
    return this->next;
}

template<class T>
inline TListElem<T>* TListElem<T>::GetPrev() const
{
    return this->prev;
}

template<class T>
inline bool TListElem<T>::operator==(TListElem<T>& _v) const
{
    return (this->data == _v.data && this->next == _v.next && this->prev == _v.prev);
}

template<class T>
inline bool TListElem<T>::operator!=(TListElem<T>& _v) const
{
    return (!(*this==_v));
}

template<class T>
inline void TListElem<T>::SetData(T _data)
{
    this->data = _data;
}

template<class T>
inline void TListElem<T>::SetNext(TListElem* _next)
{
    this->next = _next;
}

template<class T>
inline void TListElem<T>::SetPrev(TListElem* _prev)
{
    this->prev = _prev;
}

template<class T1>
inline std::ostream& operator<<(std::ostream& ostr, const TListElem<T1>& A)
{
    ostr << A.GetData();
    return ostr;
}

template<class T1>
inline std::istream& operator>>(std::istream& istr, TListElem<T1>& A)
{
    T1 d;
    istr >> d;
    A.SetData(d);
    return istr;
}

template<class T1>
inline std::ofstream& operator<<(std::ofstream& ostr, const TListElem<T1>& A)
{
    ostr << A.GetData();
    return ostr;
}

template<class T1>
inline std::ifstream& operator>>(std::ifstream& istr, TListElem<T1>& A)
{
    T1 d;
    istr >> d;
    A.SetData(d);
    A.SetNext(0);
    A.SetPrev(0);
    return istr;
}


#endif
