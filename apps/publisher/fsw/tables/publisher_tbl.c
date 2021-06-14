//
// Created by Neil Khera on 6/13/2021
//

#include "cfe.h"
#include "cfe_tbl_filedef.h"  /* Required to obtain the CFE_TBL_FILEDEF macro definition */

#include "publisher_tbl.h"

publisherTable_t publisher_TblStruct = {

};


/*
** The macro below identifies:
**    1) the data structure type to use as the table image format
**    2) the name of the table to be placed into the cFE Table File Header
**    3) a brief description of the contents of the file image
**    4) the desired name of the table image binary file that is cFE compatible
*/
CFE_TBL_FILEDEF(publisher_TblStruct, PUBLISHER.publisherTable, publisher parameters, publisher_tbl.tbl )
