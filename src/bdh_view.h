#include <InterfaceKit.h>
#include <AppKit.h>

#define NUM_BUTTONS 37



class bdh_view : public BView
{
public:
	bdh_view(BRect frame, const char *name,
		uint32 resizeMask = B_FOLLOW_LEFT | B_FOLLOW_TOP, 
		uint32 flags = B_WILL_DRAW | B_NAVIGABLE);
	
	//bdh_view(BMessage *);  // archivable format
	
	//static BArchivable *Instantiate(BMessage *data);
	//virtual	status_t Archive(BMessage *data, bool deep = true) const;

	virtual void AllAttached();
	virtual void KeyDown(const char *bytes, int32 numBytes);
	virtual void MessageReceived(BMessage *);
	virtual void MouseDown(BPoint where);
	virtual void MouseMoved(BPoint where, uint32 code, const BMessage* message);
	virtual void MouseUp(BPoint where);
	//virtual	void Draw(BRect updateRect);

private:
	typedef	BView inherited;

	void InitObject(void);
	void set_text(unsigned long long);
	void insert_text(char);
	unsigned long long get_num();
	void enter();
	void switch_keys();
	
	unsigned long long pwr2(unsigned long long power);
	unsigned long long pwr10(unsigned long long power);
	
	BStringView *credits;
	BButton *button[NUM_BUTTONS];
	BRadioButton *binary;
	BRadioButton *decimal;
	BRadioButton *hex;
	BTextView *das_text;
	BMenuItem *menuitems[9];
	BPopUpMenu *popup;
	BMenuBar *popup_menu;
	
	unsigned long long first, second, storage[10];
	bool first_entered, invalidate, last_was_number, store, recall;
	long base;
	unsigned long mode;
	unsigned char data_type;

	bool mouse_down;
	BPoint mouse_offset;
};

#define BINARY	2
#define DECIMAL 10
#define HEX		16

#define SIGNED	1
#define BIT8	2
#define BIT16	4
#define BIT32	8
#define BIT64	16
#define FP		32
#define WORD_MASK BIT8+BIT16+BIT32+BIT64

#define BDHVIEW_POPUP_MENU 'PopU'

enum {
	BDHVIEW_CLEAR = 0x9169L,
	BDHVIEW_MOD = 0x170L,
	BDHVIEW_AND = 0x171L,
	BDHVIEW_OR = 0x172L,
	BDHVIEW_NOT = 0x173L,
	BDHVIEW_XOR = 0x174L,
	BDHVIEW_SHL = 0x175L,
	BDHVIEW_SHR = 0x176L,
	BDHVIEW_ROL = 0x177L,
	BDHVIEW_ROR = 0x178L,
	BDHVIEW_SIGN = 0x179L,
	BDHVIEW_POINT = 0x180L,
	BDHVIEW_STO = 0x181L,
	BDHVIEW_RCL = 0x182L,
	BDHVIEW_2X = 0x183L,
	BDHVIEW_10X = 0x184L,
	BDHVIEW_BINARY = 0x2L,
	BDHVIEW_DECIMAL = 0x6L,
	BDHVIEW_HEX = 0x9L,
	BDHVIEW_A = 0xE4L,
	BDHVIEW_B = 0x102L,
	BDHVIEW_C = 0x10AL,
	BDHVIEW_D = 0x114L,
	BDHVIEW_E = 0x11DL,
	BDHVIEW_F = 0x126L,
	BDHVIEW_PLUS = 0x12FL,
	BDHVIEW_MINUS = 0x136L,
	BDHVIEW_TIMES = 0x146L,
	BDHVIEW_DIV = 0x156L,
	BDHVIEW_ENTER = 0xE0L,
	BDHVIEW_0 = 0xB2L,
	BDHVIEW_1 = 0xB9L,
	BDHVIEW_2 = 0xBDL,
	BDHVIEW_3 = 0xC1L,
	BDHVIEW_4 = 0xCDL,
	BDHVIEW_5 = 0xD0L,
	BDHVIEW_6 = 0xD6L,
	BDHVIEW_7 = 0xD9L,
	BDHVIEW_8 = 0xDDL,
	BDHVIEW_9 = 0x62L,
	BDHVIEW_UINT64 = 0xb064L,
	BDHVIEW_UINT32 = 0xb032L,
	BDHVIEW_UINT16 = 0xb016L,
	BDHVIEW_UINT8 = 0xb008L,
	BDHVIEW_FP = 0xb111L,
	BDHVIEW_INT64 = 0xb164L,
	BDHVIEW_INT32 = 0xb132L,
	BDHVIEW_INT16 = 0xb116L,
	BDHVIEW_INT8 = 0xb108L,
};
