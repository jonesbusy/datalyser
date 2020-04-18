#ifndef BENCHMARK_TCC_INCLUDED
#define BENCHMARK_TCC_INCLUDED

#include "Benchmark.h"

template <typename Key>
Benchmark<Key>::Benchmark(IProgress* iProgress) : iProgress(iProgress)
{
}

template <typename Key>
Benchmark<Key>::~Benchmark()
{
    this->clearData();
}

template <typename Key>
Result Benchmark<Key>::run(Type type)
{
    Table<Key>* table = NULL;

    switch (type)
    {
        case SEQUENTIAL:

            table = new SequentialTable<Key>(this->data.size());
            break;

        case DICHOTOMOUS:

            table = new DichotomousTable<Key>(this->data.size());
            break;
    }

    Result result;
    clock_t timeSpan    = 0;
    int percent         = 0;
    int splitting       = (this->data.size() > 200) ? this->data.size() / 200 : 1;

    random_shuffle(this->data.begin(), this->data.end());

    timeSpan = clock();

    int i = 0;

    for (typename std::vector<Row<Key>*>::iterator it = this->data.begin(); it != this->data.end(); it++)
    {
        table->insert(**it);

        if (!(i % splitting))
        {
            if (this->iProgress != NULL)

                this->iProgress->signal(percent);

            percent++;
        }

        i++;
    }

    random_shuffle(this->data.begin(), this->data.end());

    i = 0;

    for (typename std::vector<Row<Key>*>::iterator it = this->data.begin(); it != this->data.end(); it++)
    {
        table->search((*it)->getKey());

        if (!(i % splitting))
        {
            if (this->iProgress != NULL)

                this->iProgress->signal(percent);

            percent++;
        }

        i++;
    }

    if (this->iProgress != NULL)

        this->iProgress->signal(100);

    delete table;

    return result;
}

template <typename Key>
void Benchmark<Key>::addData(const Row<Key>& row)
{
    Row<Key>* dataPointer;

    row.copy(dataPointer);

    this->data.push_back(dataPointer);
}

template <typename Key>
void Benchmark<Key>::clearData()
{
    for (typename std::vector<Row<Key>*>::iterator it = this->data.begin(); it != this->data.end(); it++)

        delete *it;

    this->data.clear();
}

#endif // BENCHMARK_TCC_INCLUDED
