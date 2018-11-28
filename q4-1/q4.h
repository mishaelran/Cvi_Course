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
#define  PANEL_matrix                     3       /* control type: table, callback function: (none) */
#define  PANEL_result                     4       /* control type: table, callback function: (none) */
#define  PANEL_vector                     5       /* control type: table, callback function: (none) */
#define  PANEL_TOGGLEBUTTON_2             6       /* control type: textButton, callback function: (none) */
#define  PANEL_TOGGLEBUTTON               7       /* control type: textButton, callback function: (none) */
#define  PANEL_CALCULATE                  8       /* control type: command, callback function: My_Calcuate */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK My_Calcuate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
