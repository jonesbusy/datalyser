#ifndef BENCHMARK_H_INCLUDED
#define BENCHMARK_H_INCLUDED

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Table.h"
#include "Row.h"
#include "SequentialTable.h"
#include "DichotomousTable.h"
#include "IProgress.h"
#include "Result.h"

template <typename Key>
class Benchmark
{
    public:

    enum Type { SEQUENTIAL,
                DICHOTOMOUS,
                OPEN_HASH,
                CLOSED_HASH  };

    Benchmark(IProgress* iProgress = NULL);

    ~Benchmark();

    Result run(Type type);

    void addData(const Row<Key>& row);

    void clearData();



    private:

    IProgress* iProgress;
    std::vector<Row<Key>*> data;
};

#include "Benchmark.cpp"

#endif // BENCHMARK_H_INCLUDED
