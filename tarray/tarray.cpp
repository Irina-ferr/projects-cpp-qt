#include "tarray.h"
#include <stdio.h>

TArray::TArray( int size )
{
    count = size ;
    data = new float[size];
}

TArray::TArray( int size, int init )
{
    count = size;
    data = new float[size];

    for (int i = 0; i < count; i++) setData(i, init);
}

TArray::~TArray()
{
    if (data != nullptr) delete[] data;
}

void   TArray::setCount( int cnt )
{
    if ( cnt > 0 )
        count = cnt;
    else
        printf("Wrong count value!\n");
}

int    TArray::Count(void) { return count; }

void   TArray::setData( int index, float value )
{
    if ( ( index >= 0 ) && ( index < count ) )
        data[index] = value;
    else
        printf("Indexing error!");
}

float  TArray::Data( int index )
{
    if ( ( index >= 0 ) && ( index < count ) )
        return data[index];
    else
        printf("Indexing error!");

    return -1;
}

void   TArray::print(void)
{
    for ( int i = 0; i < Count(); i++ )
        printf( "%5.2f ", Data(i) );
    printf("\n");
}
