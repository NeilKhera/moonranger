/**
 * @file publisher.h
 * @brief Function declaration, MACRO and data structure definitions for the publisher application
 */

#ifndef ICAROUS_CFS_PUBLISHER_H
#define ICAROUS_CFS_PUBLISHER_H

#include "cfe.h"
#include "cfe_error.h"
#include "cfe_evs.h"
#include "cfe_sb.h"
#include "cfe_es.h"
#include <string.h>

#include "publisher_tbl.h"

#define PUBLISHER_STARTUP_INF_EID 0
#define PUBLISHER_COMMAND_ERR_EID 1

#define PUBLISHER_PIPE_DEPTH 30 
#define PUBLISHER_PIPE_NAME "PUBLISHER_PIPE"
#define PUBLISHER_MAJOR_VERSION 1
#define PUBLISHER_MINOR_VERSION 0

/**
 * @defgroup PUBLISHER
 * @brief Application to monitor traffic conflicts
 * @ingroup APPLICATIONS
 *
 * @details Description of this application
 * 
 */


/**
 * @struct publisherAppData_t
 * @brief Structure to hold app data
 */
typedef struct{
    CFE_SB_PipeId_t    publisher_Pipe;       ///< Pipe variable
    CFE_SB_MsgPtr_t    publisher_MsgPtr;     ///< Msg pointer to SB message
    CFE_TBL_Handle_t   publisher_tblHandle;    ///< Traffic table handle
}publisherAppData_t;

/**
 * App entry point
 */
void PUBLISHER_AppMain(void);

/**
 * Initializes data structures and cfs related entities.
 */
void PUBLISHER_AppInit(void);

/**
 * Deallocates memory
 */
void PUBLISHER_AppCleanUp();

/**
 * Processes incoming software bus messages
 */
void PUBLISHER_ProcessPacket();

/**
 * Validates table parameters
 * @param TblPtr Pointer to table
 * @return  0 if success
 */
int32_t publisherTableValidationFunc(void *TblPtr);

/**
 * @var Global variable to store all app related data
 */
publisherAppData_t publisherAppData;

#endif //ICAROUS_CFS_PUBLISHER_H
