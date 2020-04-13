#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

template <typename Key>
class Head : public Row<long>
{
    public:

    void copy(Row<long>*& row) const
    {
        row = new Head<Key>(0);
    }

    List<Key> list;


    protected:

    int compare(const long& key1, const long& key2)
    {
        return 0;
    }
};

#endif // HEAD_H_INCLUDED
