#ifndef TARRAY_H
#define TARRAY_H

class TArray {
protected:
    float* data;
    int size;

public:
    TArray();
    TArray(int length, float initialValue = 0.0f);
    virtual ~TArray();

    void resize(int newSize);
    virtual void print() const;

    int getSize() const;
    float getValue(int index) const;
    void setValue(int index, float value);
};

#endif // TARRAY_H
