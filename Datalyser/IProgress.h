#ifndef IPROGRESS_H_INCLUDED
#define IPROGRESS_H_INCLUDED

class IProgress
{
    public:

    virtual void signal(unsigned int progress) = 0;
};

#endif // IPROGRESS_H_INCLUDED
