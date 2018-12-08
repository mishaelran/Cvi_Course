#include <cvirte.h>		
#include <userint.h>
#include "q5-3.h"			    

static int panelHandle;
static double x1,x2,m1,m2,k1,k2,k3,x01,x02,x03,v1,v2,a1,a2;
int H, W;
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "q5-3.uir", PANEL)) < 0)
		return -1;
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_HEIGHT, &H);
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_WIDTH, &W);
	SetCtrlVal (panelHandle, PANEL_X1, 226.0);
	SetCtrlVal (panelHandle, PANEL_X2, 453.0);
	SetCtrlVal (panelHandle, PANEL_M1, 1.0);
	SetCtrlVal (panelHandle, PANEL_M2, 1.0);
	SetCtrlVal (panelHandle, PANEL_K1, 0.05);
	SetCtrlVal (panelHandle, PANEL_K2, 0.05); 
	SetCtrlVal (panelHandle, PANEL_K3, 0.05);
	SetCtrlVal (panelHandle, PANEL_X01, 100.0);
	SetCtrlVal (panelHandle, PANEL_X02, 100.0);
	SetCtrlVal (panelHandle, PANEL_X03, 100.0);
    SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_MODE, VAL_XOR_MODE);
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

void drawredrect(Rect rect)
{
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_DRAW_POLICY, VAL_MARK_FOR_UPDATE);
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_COLOR, VAL_RED);  
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_FILL_COLOR, VAL_RED);
	CanvasDrawRect (panelHandle, PANEL_CANVAS, rect, VAL_DRAW_FRAME_AND_INTERIOR);	
}

void drawbluerect(Rect rect)
{
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_DRAW_POLICY, VAL_MARK_FOR_UPDATE);
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_COLOR, VAL_BLUE);  
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_FILL_COLOR, VAL_BLUE);
	CanvasDrawRect (panelHandle, PANEL_CANVAS, rect, VAL_DRAW_FRAME_AND_INTERIOR);	
}

void clearcanvas()
{
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_DRAW_POLICY, VAL_MARK_FOR_UPDATE);
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_COLOR, VAL_BLACK);  
	SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_FILL_COLOR, VAL_BLACK);
	CanvasClear (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
 	CanvasDrawRect (panelHandle, PANEL_CANVAS, MakeRect(H-10,0,10,700), VAL_DRAW_FRAME_AND_INTERIOR);
	CanvasDrawRect (panelHandle, PANEL_CANVAS, MakeRect(H-60,0,60,10), VAL_DRAW_FRAME_AND_INTERIOR);
	CanvasDrawRect (panelHandle, PANEL_CANVAS, MakeRect(H-60,690,690,10), VAL_DRAW_FRAME_AND_INTERIOR);	
}

int CVICALLBACK My_Go (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	static int tmp;
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PEN_MODE, VAL_COPY_MODE);
			clearcanvas();
			
			GetCtrlVal (panelHandle, PANEL_GO, &tmp);
			GetCtrlVal (panelHandle, PANEL_X1, &x1);
			GetCtrlVal (panelHandle, PANEL_X2, &x2);
			GetCtrlVal (panelHandle, PANEL_K1, &k1);
			GetCtrlVal (panelHandle, PANEL_K2, &k2);
			GetCtrlVal (panelHandle, PANEL_K3, &k3);
			GetCtrlVal (panelHandle, PANEL_X01, &x01);
			GetCtrlVal (panelHandle, PANEL_X02, &x02);
			GetCtrlVal (panelHandle, PANEL_X03, &x03);
			GetCtrlVal (panelHandle, PANEL_M1, &m1);
			GetCtrlVal (panelHandle, PANEL_M2, &m2);
			
			drawredrect(MakeRect(H-50,x1-10,40,40));
			drawbluerect(MakeRect(H-50,x2-10,40,40));
			CanvasUpdate (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
			
			SetCtrlAttribute (panelHandle, PANEL_TIMER,ATTR_ENABLED, tmp);
			
			break;
	}
	return 0;
}

int CVICALLBACK My_Timer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double dt=0.01;
	switch (event)
	{
		case EVENT_TIMER_TICK:
			
			a1=(-k1*(x1-x01)+k2*(x2-x1-x02))/m1;
			a2=(-k2*(x2-x1-x02)+k3*(W-x2-x03))/m2;
			
			x1=x1+v1*dt+a1*0.5*dt*dt;
			x2=x2+v2*dt+a2*0.5*dt*dt;
			
			v1=v1+a1*dt;
			v2=v2+a2*dt;
		
			clearcanvas();
			drawredrect(MakeRect(H-50,x1-10,40,40));
			drawbluerect(MakeRect(H-50,x2-10,40,40));
			CanvasUpdate (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
			//SetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_PICT_BGCOLOR, VAL_WHITE);
			break;
	}
	return 0;
}
