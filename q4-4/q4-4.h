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
#define  PANEL_TAB                        3       /* control type: tab, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_GRAPH_linear            2       /* control type: graph, callback function: (none) */
#define  TABPANEL_SHOW_linear             3       /* control type: command, callback function: show_linear */
#define  TABPANEL_SLOPE                   4       /* control type: numeric, callback function: (none) */
#define  TABPANEL_intercept               5       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_GRAPH_EXP             2       /* control type: graph, callback function: (none) */
#define  TABPANEL_2_SHOW_EXP              3       /* control type: command, callback function: show_exp */

     /* tab page panel controls */
#define  TABPANEL_3_GRAPH_POL             2       /* control type: graph, callback function: (none) */
#define  TABPANEL_3_SHOW_POL              3       /* control type: command, callback function: show_pol */
#define  TABPANEL_3_order                 4       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_4_SHOW                  2       /* control type: command, callback function: show */
#define  TABPANEL_4_GRAPH                 3       /* control type: graph, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK show(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK show_exp(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK show_linear(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK show_pol(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
