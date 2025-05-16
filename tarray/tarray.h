#ifndef TARRAY_H
#define TARRAY_H

class TArray
{
public:
    TArray( int size = 100 );
    TArray( int size, int init );
    ~TArray();

    void   setCount( int cnt );
    int    Count(void);
    void   setData( int index, float value );
    float  Data( int index );

    void   print(void);

protected:
    float  *data;
    int    count;
};
#endif // TARRAY_H
