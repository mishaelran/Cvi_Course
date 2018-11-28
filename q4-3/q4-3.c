#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "q4-3.h"
#define g -9.8
#define pi 3.14

static int panelHandle,h,w;
static double a_x,a_y,vis,mass,vel_y,vel_x,loc[2],alpha;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "q4-3.uir", PANEL)) < 0)
		return -1;
	SetCtrlVal (panelHandle, PANEL_MASS, 5.0);
	SetCtrlVal (panelHandle, PANEL_velocity, 5.0);
	SetCtrlVal (panelHandle, PANEL_angle, 45.0);
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_HEIGHT, &h);
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_WIDTH, &w);
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
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK My_Go (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	static int tmp;
	double vel;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (panelHandle, PANEL_GO, &tmp);
			if(!tmp)
			{		 //clear canvas
			CanvasClear (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
			CanvasSetPenPosition (panelHandle, PANEL_CANVAS, MakePoint(0,0));
			DeleteGraphPlot (panelHandle, PANEL_GRAPH, -1, VAL_IMMEDIATE_DRAW);
			}	
			GetCtrlVal (panelHandle, PANEL_MASS, &mass);
			GetCtrlVal (panelHandle, PANEL_viscosity, &vis);
			GetCtrlVal (panelHandle, PANEL_velocity, &vel);
			GetTableCellRangeVals (panelHandle, PANEL_location, MakeRect(1,1,1,2), loc, VAL_ROW_MAJOR);
			GetCtrlVal (panelHandle, PANEL_angle, &alpha);
			vel_x=vel*cos((pi*alpha)/180);
			vel_y=vel*sin((pi*alpha)/180);
			SetCtrlAttribute (panelHandle, PANEL_TIMER,ATTR_ENABLED, tmp);  
			break;
	}
	return 0;
}

int CVICALLBACK My_Time (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double dt=0.001;
	switch (event)
	{
		case EVENT_TIMER_TICK:
			SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_MODE, VAL_XOR_MODE);
			CanvasDrawOval (panelHandle, PANEL_CANVAS, MakeRect (h-loc[1]*100, loc[0]*100, 10, 10), VAL_DRAW_INTERIOR); 
			
			a_x=(vis/mass)*vel_x;
			a_y=g+(vis/mass)*vel_y;
			loc[0]=loc[0]+vel_x*dt+0.5*a_x*dt*dt;
			loc[1]=loc[1]+vel_y*dt+0.5*a_y*dt*dt;
		    vel_y=vel_y+a_y*dt;	
			vel_x=vel_x+a_x*dt;
	
			if(loc[1]>=0)
			{
			SetTableCellRangeVals (panelHandle, PANEL_location,MakeRect(1,1,1,2) , loc, VAL_ROW_MAJOR);
			//SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_MODE, VAL_XOR_MODE);
			
			//CanvasDrawPoint(panelHandle, PANEL_CANVAS, MakePoint(loc[0]*0.3*w,h-loc[1]*90));
			CanvasDrawOval (panelHandle, PANEL_CANVAS, MakeRect (h-loc[1]*100, loc[0]*100, 10, 10), VAL_DRAW_INTERIOR);
			
			PlotPoint (panelHandle, PANEL_GRAPH, loc[0], loc[1], VAL_EMPTY_SQUARE, VAL_RED);
			}
			break;
	}
	return 0;
																   
}
