/*******************************************************************
|
| File         : TableError.h
|
| Description  : Enumération d'erreur.
|
| Author       : Valentin Delaye
|
| Created      : 06.01.2010
|
| Modified     : 06.01.2010
|
| C++ std      : -
|
| Dependencies : -
|
| Version      : 1.0
|
*******************************************************************/

#ifndef TABLE_ERROR_H_INCLUDED
#define TABLE_ERROR_H_INCLUDED

/***************************************************************
| Enumeration  : Erreurs de table
***************************************************************/
enum TableError { TABLE_SIZE_UNDER_ZERO,
                  TABLE_OUT_OF_RANGE,
                  TABLE_DUPLICATE_KEY,
                  TABLE_OVERFLOW         };

#endif // TABLE_ERROR_H_INCLUDED
