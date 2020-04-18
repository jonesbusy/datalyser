#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "Row.h"
#include "IHash.h"
#include "Table.h"
#include "SequentialTable.h"
#include "DichotomousTable.h"
#include "ClosedHashTable.h"
#include "OpenHashTable.h"

/*
class Test
{
    public:

    Test() : i(0)
    {
        printf("const ");
    }

    Test(int i) : i(i)
    {
        printf("const ");
    }

    Test& operator=(const Test& test)
    {
        i = test.i;
        printf("op egalite ");

        return *this;
    }

    Test(const Test& test) : i(test.i)
    {
        printf("copy ");
    }

    int i;
};
*/

class Cle
{
    public:

    Cle(int id) : id(id)
    {
    }

    int id;
    int a;
    int b;
};

// Exemple de ligne avec pour type de clé des integer
class RowTest : public Row<Cle>
{
    public:

    RowTest(int id, int code) : Row<Cle>(Cle(id)), code(code), type(true)
    {
    }

    // Redéfinition obligatoire ! ( Pour que la magie du polymorphisme s'opère dans la table :D )
    void clone(IRow*& row) const
    {
        row = new RowTest(*this);
    }

    // Redéfinition obligatoire !
    int compare(const Cle& key1, const Cle& key2)
    {
        if (key1.id > key2.id)

            return 1;

        if (key1.id < key2.id)

            return -1;

        return 0;
    }

    int code;
    bool type;
};

class Modulo : public IHash<Cle>
{
    public:

    long generate(const Cle& cle, long size)
    {
        return cle.id % size;
    }

    long regenerate(long hash, long size)
    {
        return (hash + 1) % size;
    }
};

/*
class A
{
    public:

    virtual Row<Cle>*& test()
    {
        printf("A");
        return a;
    }

    Row<Cle>* a;
};

class B : public A
{
    public:

    RowTest*& test()
    {
        printf("B");
        return (RowTest*&)A::test();
    }

    void pascal()
    {
        RowTest* h = this->test();
    }
};
*/

int main()
{
    printf("*** SequentialTable ***\n\n");

    // Table dichotomique contenant des lignes à clé de type integer (taille : 10)
    SequentialTable<Cle> sequentialTable(10);

    try
    {
        sequentialTable.insert(RowTest(44, 1956));
        sequentialTable.insert(RowTest(34, 1922));
        sequentialTable.insert(RowTest(23, 1911));
        sequentialTable.insert(RowTest(8, 1988));
        sequentialTable.insert(RowTest(24, 1986));
        sequentialTable.insert(RowTest(0, 1989));
        sequentialTable.insert(RowTest(1, 2006));
        sequentialTable.insert(RowTest(9, 1926));
        sequentialTable.insert(RowTest(4, 1486));
        sequentialTable.insert(RowTest(5, 1666));

        // Provoque un overflow (> 10)
        sequentialTable.insert(RowTest(50, 1));
    }
    catch (TableError error)
    {
		printf("Error : %d\n", error);
    }

    for (int i = 0; i <= 50; i++)
    {
        // Recherche
        RowTest* row = (RowTest*)sequentialTable.search(i);

        // Trouvé ?
        if (row != NULL)

            printf("Id : %d trouve ==> %d\n", row->getKey().id, row->code);

        else

            printf("Id : %d pas trouve !\n", i);
    }






    printf("\n\n*** DichotomousTable ***\n\n");

    // Table dichotomique contenant des lignes à clé de type integer (taille : 10)
    DichotomousTable<Cle> dichotomousTable(10);

    try
    {
        dichotomousTable.insert(RowTest(44, 1956));
        dichotomousTable.insert(RowTest(34, 1922));
        dichotomousTable.insert(RowTest(23, 1911));
        dichotomousTable.insert(RowTest(8, 1988));
        dichotomousTable.insert(RowTest(24, 1986));
        dichotomousTable.insert(RowTest(0, 1989));
        dichotomousTable.insert(RowTest(1, 2006));
        dichotomousTable.insert(RowTest(9, 1926));
        dichotomousTable.insert(RowTest(4, 1486));
        dichotomousTable.insert(RowTest(5, 1666));

        // Provoque un overflow (> 10)
        dichotomousTable.insert(RowTest(50, 1));
    }
    catch (TableError error)
    {
		printf("Error : %d\n", error);
    }

    for (int i = 0; i <= 50; i++)
    {
        // Recherche
        RowTest* row = (RowTest*)dichotomousTable.search(i);

        // Trouvé ?
        if (row != NULL)

            printf("Id : %d trouve ==> %d\n", row->getKey().id, row->code);

        else

            printf("Id : %d pas trouve !\n", i);
    }






    printf("\n\n*** ClosedHashTable ***\n\n");

    Modulo m;

    // Table Hash Ouvert contenant des lignes à clé de type integer (taille : 10)
    ClosedHashTable<Cle> closedHashTable(10, &m);

    try
    {
        closedHashTable.insert(RowTest(44, 1956));
        closedHashTable.insert(RowTest(34, 1922));
        closedHashTable.insert(RowTest(23, 1911));
        closedHashTable.insert(RowTest(8, 1988));
        closedHashTable.insert(RowTest(24, 1986));
        closedHashTable.insert(RowTest(0, 1989));
        closedHashTable.insert(RowTest(1, 2006));
        closedHashTable.insert(RowTest(9, 1926));
        closedHashTable.insert(RowTest(4, 1486));
        closedHashTable.insert(RowTest(5, 1666));

        // Provoque un overflow (> 10)
        closedHashTable.insert(RowTest(50, 1));
    }
    catch (TableError error)
    {
		printf("Error : %d\n", error);
    }

    for (int i = 0; i <= 50; i++)
    {
        // Recherche
        RowTest* row = (RowTest*)closedHashTable.search(i);

        // Trouvé ?
        if (row != NULL)

            printf("Id : %d trouve ==> %d\n", row->getKey().id, row->code);

        else

            printf("Id : %d pas trouve !\n", i);
    }








    printf("\n\n*** OpenHashTable ***\n\n");

    // Table Hash Ouvert contenant des lignes à clé de type integer (taille : 10)
    OpenHashTable<Cle> openHashTable(10, &m);

    try
    {
        openHashTable.insert(RowTest(44, 1956));
        openHashTable.insert(RowTest(34, 1922));
        openHashTable.insert(RowTest(23, 1911));
        openHashTable.insert(RowTest(8, 1988));
        openHashTable.insert(RowTest(24, 1986));
        openHashTable.insert(RowTest(0, 1989));
        openHashTable.insert(RowTest(1, 2006));
        openHashTable.insert(RowTest(9, 1926));
        openHashTable.insert(RowTest(4, 1486));
        openHashTable.insert(RowTest(5, 1666));

        // Ne provoque pas d'overflow (normal)
        openHashTable.insert(RowTest(50, 1));
    }
    catch (TableError error)
    {
		printf("Error : %d\n", error);
    }

    for (int i = 0; i <= 50; i++)
    {
        // Recherche
        RowTest* row = (RowTest*)openHashTable.search(i);

        // Trouvé ?
        if (row != NULL)

            printf("Id : %d trouve ==> %d\n", row->getKey().id, row->code);

        else

            printf("Id : %d pas trouve !\n", i);
    }

    printf("\n\n* Le 50 est trouve, car on peut inserer plus de 10 elements !\n");


/*
    Benchmark<Cle> bench = Benchmark<Cle>(NULL);

    bench.addData(RowTest(1, 1986));
    bench.addData(RowTest(2, 1986));
    bench.addData(RowTest(3, 1986));
    bench.addData(RowTest(4, 1986));

    bench.run(Benchmark<Cle>::DICHOTOMOUS);
*/
/*
    Test t = Test(0);   printf("\n");
    Test t1 = 1;        printf("\n");
    Test t2 = 2;        printf("\n");

    printf("%d\n", t1.i);
    printf("%d\n", t2.i);

    t1 = t2;        printf("\n");
    t1 = Test(1);   printf("\n");
    t1 = Test(t2);  printf("\n");

    printf("%d\n", t1.i);
    printf("%d\n", t2.i);

    if (&t1 == &t2)
    {
        printf("==\n");
    }
    else
    {
        printf("!=\n");
    }
*/

    /*
    int myvector[10];

    // set some values:        myvector: 10 20 30 40 50 60 70 80 90
    for (int i=1; i<10; i++) myvector[i] = i * 10;

    int* p = NULL;

    p = find(myvector, myvector+10, 444);

    vector<int> v;

    for (int i=1; i<10; i++) v.push_back(i * 10);

    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)

        cout << (int)(int*)&*i << "  " << *i << "\n";

    if (p != myvector + 10)
        cout << "match1 found at position " << p << "  "  << endl;
    else
        cout << "match1 not found" << endl;
    */



    getchar();

    return EXIT_SUCCESS;
}
