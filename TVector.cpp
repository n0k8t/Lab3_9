#include "TVector.h"

TVector::~TVector()//+
{
    delete[] Data;
}

TVector::TVector()//+
{
    Data = nullptr;
    Len = 0;
}

TVector::TVector(const TVector & rhs)//+
{
    Len = rhs.Len;
    Data = new double[Len];
    memcpy(Data, rhs.Data, Len * sizeof(double));
}

TVector::TVector(const double * const data, const size_t len)//+
{
    Len = len;
    Data = new double[Len];
    memcpy(Data, data, Len * sizeof(double));
}

TVector & TVector::operator=(const TVector & rhs)//+
{
    if (&rhs == this) return *this;

    Len = rhs.Len;
    delete[] Data;
    Data = new double[Len];
    memcpy(Data, rhs.Data, Len * sizeof(double));
    return *this;
}

TVector & TVector::operator+=(const double * const data)//+
{
    double * newData = new double[Len * 2];
    memcpy(newData, data, Len * sizeof(double));
    memcpy(newData + Len, Data, Len * sizeof(double));


    Len *= 2;
    delete[] Data;
    Data = newData;
    return *this;
}

double TVector::operator[](size_t index) const//+
{
    return Data[index];
}

double& TVector::operator[](size_t index)//+
{
    return Data[index];
}

TVector operator+(const double * const b, const TVector & a)//+
{
    TVector res = TVector(a);
    res += b;
    return res;
}