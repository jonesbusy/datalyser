/*******************************************************************
|
| File         : ClosedHashRow.cpp
|
| Description  : Represente les attributs supplementaires pour gerer
|                une table de hachage fermee
|
| Author       :  Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 24.12.2009
|
| C++ std      :
|
| Dependencies : -
|
| Version      : 1.0
|
*******************************************************************/

#include "ClosedHashRow.h"

ClosedHashRow::ClosedHashRow()
{
    this->size = 0;
    this->hash = 0;
    this->reset();
}

ClosedHashRow::ClosedHashRow(long hash) : hash(hash)
{
    this->reset();
}

void ClosedHashRow::increment()
{
    this->size++;
}

void ClosedHashRow::reset()
{
    this->busy = false;
    this->size = 0;
}

void ClosedHashRow::setHash(long hash)
{
    this->hash = hash;
}

long ClosedHashRow::getHash() const
{
    return this->hash;
}

void ClosedHashRow::setBusy(bool busy)
{
    this->busy = busy;
}

bool ClosedHashRow::isBusy() const
{
    return this->busy;
}

int ClosedHashRow::getSize() const
{
    return this->size;
}
