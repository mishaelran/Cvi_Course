/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_QUITBUTTON                 2       /* control type: command, callback function: QuitCallback */
#define  PANEL_GRAPH                      3       /* control type: graph, callback function: (none) */
#define  PANEL_Common                     4       /* control type: numeric, callback function: (none) */
#define  PANEL_StandardDeviation          5       /* control type: numeric, callback function: (none) */
#define  PANEL_Mean                       6       /* control type: numeric, callback function: (none) */
#define  PANEL_Median                     7       /* control type: numeric, callback function: (none) */
#define  PANEL_GO                         8       /* control type: command, callback function: My_Go */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK My_Go(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
