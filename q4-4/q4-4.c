#include <ansi_c.h>
#include <analysis.h>
#include <cvirte.h>		
#include <userint.h>
#include "q4-4.h"

static int panelHandle,tabHnadle,tabHnadle_1,tabHnadle_2,tabHnadle_3;
FILE *fin;
double X[50],Y[50];
int size;
int main (int argc, char *argv[])
{
	
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "q4-4.uir", PANEL)) < 0)
		return -1;
	// TODO: Get the panel handle associated with a tab page with GetPanelHandleFromTabPage
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
	return 0;					 //quit
}

int CVICALLBACK show (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i=0;
	char str[50];
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 0, &tabHnadle);  
			if (!(fin = fopen("num.txt", "r")))
		       {
	         	printf("Cannot open file \num\"\n");
	        	exit(0);
	           }
			while(!feof(fin))
			{
					fscanf (fin, "%s", &str[i]);
					X[i] = atof(&str[i]);
					fscanf (fin, "%s", &str[i]);
					Y[i] = atof(&str[i]);
					i++;
			}
			fclose(fin);
			size=i-1;
			PlotXY (tabHnadle, TABPANEL_4_GRAPH, X, Y, size, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			break;
		
	}
	return 0;
}




int CVICALLBACK show_linear (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double RES[50], Slope, intercept, mean; 
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 1, &tabHnadle_1);  
			LinFit (X, Y, size, RES, &Slope, &intercept, &mean);
			SetCtrlVal (tabHnadle_1, TABPANEL_SLOPE, Slope);
			SetCtrlVal (tabHnadle_1, TABPANEL_intercept, intercept);
			PlotXY (tabHnadle_1, TABPANEL_GRAPH_linear, X, RES, size, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			break;
		
	}
	return 0;
}

int CVICALLBACK show_exp (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double RES[50],Amplitude,Decay,Mean;
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 2, &tabHnadle_2);
			ExpFit (X, Y, size, RES,&Amplitude,&Decay,&Mean);
			PlotXY (tabHnadle_2, TABPANEL_2_GRAPH_EXP, X, RES, size, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);

			break;
	
	}
	return 0;
}

int CVICALLBACK show_pol (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double RES[50],coefficents[50],Mean;
	int Order;
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 3, &tabHnadle_3);
			GetCtrlVal (tabHnadle_3, TABPANEL_3_order, &Order);
			if(Order>size)
				Order = size-1;
			SetCtrlVal (tabHnadle_3, TABPANEL_3_order, Order);
			PolyFit (X, Y, size, Order, RES, coefficents, &Mean);
			PlotXY (tabHnadle_3, TABPANEL_3_GRAPH_POL, X, RES, size, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			break;
	
	}
	return 0;
}

