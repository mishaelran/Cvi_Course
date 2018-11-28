#include <ansi_c.h>
#include <analysis.h>
#include <cvirte.h>		
#include <userint.h>
#include "q4-5.h"

static int panelHandle;
FILE *fin;
int i=0,size;
char str[100];
double Grade[100];
int main (int argc, char *argv[])
{
	if (!(fin = fopen("Grade.txt", "r")))
		{
		printf("Cannot open file \\Grade\"\n");
		exit(0);
		}
	while(!feof(fin))
			{
					fscanf (fin, "%s", &str[i]);
					Grade[i] = atof(&str[i]);
					i++;
			}
	size=i+1;
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "q4-5.uir", PANEL)) < 0)
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

int CVICALLBACK My_Go (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double median,mean,Common,StandardDeviation,axis[100];
	int RES[100];
	switch (event)
	{
		case EVENT_COMMIT:
			Median (Grade, size, &median);
			Mean (Grade, size, &mean);
			Mode (Grade, size, 0.0, 100.0, 1, &Common);
			StdDev (Grade, size, &mean, &StandardDeviation);
			Histogram (Grade, size, 0.0, 100.0, RES, axis, 10);
			SetCtrlVal (panelHandle, PANEL_Mean, mean);
			SetCtrlVal (panelHandle, PANEL_Common, Common);
			SetCtrlVal (panelHandle, PANEL_StandardDeviation, StandardDeviation);
			SetCtrlVal (panelHandle, PANEL_Median, median);
			PlotXY (panelHandle, PANEL_GRAPH, axis, RES, 10, VAL_DOUBLE, VAL_INTEGER,VAL_VERTICAL_BAR, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_CYAN);
			break;
	
	}
	return 0;
}
