/*******************************************************************
|
| File         : HashCodeModulo.cpp
|
| Description  : Implemente un algorithme permettant de trouver le
|                numero de ligne suivant une clef, en utilisant
|                l'operateur modulo.
|
| Author       : Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 03.12.2009
|
| C++ std      : -
|
| Dependencies : IHashCode.h
|
| Version      : 1.0
|
*******************************************************************/

#include "HashCodeModulo.h"

// generate
unsigned int HashCodeModulo::generate(unsigned long index)
{
    return index % 10;
}
