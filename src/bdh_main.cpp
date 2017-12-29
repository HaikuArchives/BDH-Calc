#include <InterfaceKit.h>
#include <AppKit.h>
#include <Alert.h>
#include <Beep.h>

#include "bdh_view.h"


const char* app_signature = "application/x-vnd.Hammond-BDH";


/****************************************************/


class bdh_window : public BWindow
{
public:
	bdh_window(BRect r);
	virtual bool QuitRequested();
	virtual void MessageReceived(BMessage*);
};


bdh_window::bdh_window(BRect r)
	:
	BWindow(r, "BDH Calc", B_TITLED_WINDOW, B_NOT_ZOOMABLE | B_NOT_RESIZABLE)
{
	bdh_view* theView = new bdh_view(Bounds(), "bdh_view");
	AddChild(theView);
}


bool bdh_window::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return(true);
}


void bdh_window::MessageReceived(BMessage *msg)
{
	//if (msg->what == BDHVIEW_UINT64)
	//	beep();
	BWindow::MessageReceived(msg);
}

/****************************************************/


class bdh_app : public BApplication
{
public:
	bdh_app(const char *signature);
	virtual void AboutRequested();
};


bdh_app::bdh_app(const char *signature)
	: BApplication(signature)
{
	BRect r(187, 229, 186+584, 230+148);
	bdh_window* theWindow = new bdh_window(r);
	theWindow->Show();
}


void bdh_app::AboutRequested()
{
	(new BAlert("About", "BDH Calc 1.1\n\n"
		"Author: Scott Hammond, sehammond@mindspring.com\n\n"
		"Fully-functional 64-bit calculator that does standard arithmatic "
		"and logic on signed and unsigned integers.\n\n"
		"Features:\n"
		"  - Selectable word size from 8 to 64 bits\n"
		"  - Binary, decimal, and hexadecimal\n"
		"    conversion (its namesake)\n"
		"  - 10 memory registers\n"
		"  - Small screen footprint so it doesn't get\n"
		"    in your way.\n"
		"  - Standard keyboard shortcuts work,\n"
		"    can copy the display with Command-C.\n\n",
		"Close"))->Go();
}


/****************************************************/


int
main(void)
{
	new bdh_app(app_signature);
	be_app->Run();
	delete be_app;

	return 0;
}

