#ifndef IHASH_CODE_H_INCLUDED
#define IHASH_CODE_H_INCLUDED

template <typename Key>
class IHashCode
{
    public:

    virtual long generate(const Key& key, long size) = 0;
};

#endif // IHASH_CODE_H_INCLUDED
