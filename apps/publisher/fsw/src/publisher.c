//
// Created by Neil Khera on 6/13/2021.
//
#include "publisher.h"
#include "publisher_tbl.c"

CFE_EVS_BinFilter_t  publisher_EventFilters[] =
{  /* Event ID    mask */
        { PUBLISHER_STARTUP_INF_EID,       0x0000},
        { PUBLISHER_COMMAND_ERR_EID,       0x0000},
}; /// Event ID definitions

/* Application entry points */
void PUBLISHER_AppMain(void){

    int32 status;
    uint32 RunStatus = CFE_ES_APP_RUN;

    PUBLISHER_AppInit();

    while(CFE_ES_RunLoop(&RunStatus) == TRUE){
        status = CFE_SB_RcvMsg(&publisherAppData.publisher_MsgPtr, publisherAppData.publisher_Pipe, 10);

        if (status == CFE_SUCCESS)
        {
		PUBLISHER_ProcessPacket();
        }
    }

    PUBLISHER_AppCleanUp();

    CFE_ES_ExitApp(RunStatus);
}

void PUBLISHER_AppInit(void) {

    memset(&publisherAppData, 0, sizeof(publisherAppData_t));

    int32 status;

    // Register the app with executive services
    CFE_ES_RegisterApp();

    // Register the events
    CFE_EVS_Register(publisher_EventFilters,
                     sizeof(publisher_EventFilters) / sizeof(CFE_EVS_BinFilter_t),
                     CFE_EVS_BINARY_FILTER);

    // Create pipe to receive SB messages
    status = CFE_SB_CreatePipe(&publisherAppData.publisher_Pipe, /* Variable to hold Pipe ID */
		    PUBLISHER_PIPE_DEPTH,       /* Depth of Pipe */
		    PUBLISHER_PIPE_NAME);       /* Name of pipe */

    //Subscribe to plexil output messages from the SB

    // Initialize all messages that this App generates

    // Register table with table services
    status = CFE_TBL_Register(&publisherAppData.publisher_tblHandle,
                              "publisherTable",
                              sizeof(publisherTable_t),
                              CFE_TBL_OPT_DEFAULT,
                              &publisherTableValidationFunc);

    // Load app table data
    status = CFE_TBL_Load(publisherAppData.publisher_tblHandle,CFE_TBL_SRC_ADDRESS,&publisher_TblStruct);

    publisherTable_t *TblPtr;
    status = CFE_TBL_GetAddress((void**)&TblPtr, publisherAppData.publisher_tblHandle);

    // Send event indicating app initialization
    CFE_EVS_SendEvent(PUBLISHER_STARTUP_INF_EID, CFE_EVS_INFORMATION,
                      "publisher App Initialized. Version %d.%d",
                      PUBLISHER_MAJOR_VERSION,
                      PUBLISHER_MINOR_VERSION);
}

void PUBLISHER_AppCleanUp(){
    // Do clean up here
}

void PUBLISHER_ProcessPacket(){

    CFE_SB_MsgId_t  MsgId;
    MsgId = CFE_SB_GetMsgId(publisherAppData.publisher_MsgPtr);

    switch(MsgId){

    }
}

int32_t publisherTableValidationFunc(void *TblPtr){
    return 0;
}
