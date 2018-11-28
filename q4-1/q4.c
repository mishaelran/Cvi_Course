#include <analysis.h>
#include <cvirte.h>		
#include <userint.h>
#include "q4.h"

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "q4.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK My_Calcuate (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double mat[9],vec[3],res[3];
	switch (event)
	{
			//calculate
		case EVENT_COMMIT:
			GetTableCellRangeVals (panelHandle, PANEL_matrix, MakeRect(1,1,3,3), mat, VAL_ROW_MAJOR);
			GetTableCellRangeVals (panelHandle, PANEL_vector, MakeRect(1,1,3,1), vec, VAL_ROW_MAJOR);
			MatrixVectorMul (mat, vec, 3, 3, res);
			SetTableCellRangeVals (panelHandle, PANEL_result, MakeRect(1,1,3,1), res, VAL_ROW_MAJOR);
			break;
	}
	return 0;
}
