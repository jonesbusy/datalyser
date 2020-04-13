/*******************************************************************
|
| File         : HashCodeModulo.h
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

#ifndef HASHCODEMODULO_H_INCLUDED
#define HASHCODEMODULO_H_INCLUDED

#include "IHashCode.h"

class HashCodeModulo : public IHashCode
{

    public :

        /***************************************************************
        | Description  : Permet suivant une cle donnee de retourner le
        |                numero de ligne
        |
        | Visibility   : Public
        |
        | Parameters   : Key - La cle pour la generation du numero de
        |                      ligne
        |
        | Return value : Le numero de ligne des donnees
        ***************************************************************/
        unsigned int generate(unsigned long index);

};

#endif // HASHCODEMODULO_H_INCLUDED
