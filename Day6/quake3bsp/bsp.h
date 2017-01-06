#ifndef _BSP_H_
#define _BSP_H_

#include <string>
#include "lump.h"
#include "bsp_header_file.h"
#include "bsp_data.h"
#include "bsp_reader.h"
#include "bsp_writer.h"

using namespace std;

class BSP
{
private:
    BSPHeader   header;
    BSPLoader*  loader;
    BSPData     data;

public:
    BSP(string filename);
    ~BSP();
};

#endif // _BSP_H_
