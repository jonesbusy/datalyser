#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <cstdlib>
#include <vector>

class Result
{
    public:

    enum Analyse { INSERT,
                   SEARCH  };

    private:

    std::vector<int> timeSpans;
};

#endif // RESULT_H_INCLUDED
