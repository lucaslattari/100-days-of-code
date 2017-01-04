#ifndef _LUMP_H_
#define _LUMP_H_

class lump
{
private:
    int offset; //offset to start of a lump
    int length; //always a multiple of 4
public:
    int getOffset()
    {
        return offset;
    }

    int getLength()
    {
        return length;
    }
};

#endif // _LUMP_H_
