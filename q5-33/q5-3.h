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
#define  PANEL_CANVAS                     3       /* control type: canvas, callback function: (none) */
#define  PANEL_X1                         4       /* control type: numeric, callback function: (none) */
#define  PANEL_X03                        5       /* control type: numeric, callback function: (none) */
#define  PANEL_X2                         6       /* control type: numeric, callback function: (none) */
#define  PANEL_X02                        7       /* control type: numeric, callback function: (none) */
#define  PANEL_X01                        8       /* control type: numeric, callback function: (none) */
#define  PANEL_K2                         9       /* control type: numeric, callback function: (none) */
#define  PANEL_K3                         10      /* control type: numeric, callback function: (none) */
#define  PANEL_M2                         11      /* control type: numeric, callback function: (none) */
#define  PANEL_M1                         12      /* control type: numeric, callback function: (none) */
#define  PANEL_K1                         13      /* control type: numeric, callback function: (none) */
#define  PANEL_GO                         14      /* control type: binary, callback function: My_Go */
#define  PANEL_TIMER                      15      /* control type: timer, callback function: My_Timer */
#define  PANEL_PICTURE                    16      /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK My_Go(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK My_Timer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
