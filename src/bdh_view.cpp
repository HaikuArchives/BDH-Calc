#include <stdio.h>

#include <InterfaceKit.h>
#include <InterfaceDefs.h>
#include <AppKit.h>
#include <Beep.h>


#include "bdh_view.h"


extern const char *app_signature;


bdh_view::bdh_view(BRect frame, const char *name, uint32 resizeMask, uint32 flags)
	: BView(frame, name, resizeMask, flags )
{
	InitObject();
	
	//AddChild(new BDragger(Bounds(), this, B_FOLLOW_RIGHT | B_FOLLOW_BOTTOM));
}


/*bdh_view::bdh_view(BMessage *message)
	: BView(message)
{	
	InitObject();
} */

#define LEFT 1
#define HEIGHT 23
#define WIDTH 51
#define HTAB 53
#define VTAB 30
#define TOP 32


void bdh_view::InitObject(void)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

	BRect r(3, 2, 3+285, 2+8);
	
/*	credits = new BStringView(r, "credits",
		"BDH v0.1            A simple 64bit programmer's calculator            by Scott Hammond");
	credits->SetHighColor(125,125,155);
	credits->SetFontSize(7);
	AddChild(credits);
*/	

	// 0 - 9
	r.Set(LEFT+HTAB*7, TOP+VTAB*3, LEFT+HTAB*7+WIDTH, TOP+VTAB*3+HEIGHT);
	button[0] = new BButton(r, "0", "0", new BMessage(BDHVIEW_0),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*7, TOP+VTAB*2, LEFT+HTAB*7+WIDTH, TOP+VTAB*2+HEIGHT);
	button[1] = new BButton(r, "1", "1", new BMessage(BDHVIEW_1),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*8, TOP+VTAB*2, LEFT+HTAB*8+WIDTH, TOP+VTAB*2+HEIGHT);
	button[2] = new BButton(r, "2", "2", new BMessage(BDHVIEW_2),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*9, TOP+VTAB*2, LEFT+HTAB*9+WIDTH, TOP+VTAB*2+HEIGHT);
	button[3] = new BButton(r, "3", "3", new BMessage(BDHVIEW_3),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*7, TOP+VTAB, LEFT+HTAB*7+WIDTH, TOP+VTAB+HEIGHT);
	button[4] = new BButton(r, "4", "4", new BMessage(BDHVIEW_4),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*8, TOP+VTAB, LEFT+HTAB*8+WIDTH, TOP+VTAB+HEIGHT);
	button[5] = new BButton(r, "5", "5", new BMessage(BDHVIEW_5),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*9, TOP+VTAB, LEFT+HTAB*9+WIDTH, TOP+VTAB+HEIGHT);
	button[6] = new BButton(r, "6", "6", new BMessage(BDHVIEW_6),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*7, TOP, LEFT+HTAB*7+WIDTH, TOP+HEIGHT);
	button[7] = new BButton(r, "7", "7", new BMessage(BDHVIEW_7),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*8, TOP, LEFT+HTAB*8+WIDTH, TOP+HEIGHT);
	button[8] = new BButton(r, "8", "8", new BMessage(BDHVIEW_8),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);

	r.Set(LEFT+HTAB*9, TOP, LEFT+HTAB*9+WIDTH, TOP+HEIGHT);
	button[9] = new BButton(r, "9", "9", new BMessage(BDHVIEW_9),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);	
	
	// A - F
	r.Set(LEFT+HTAB*0, TOP+VTAB*3, LEFT+HTAB*0+WIDTH, TOP+VTAB*3+HEIGHT);
	button[10] = new BButton(r, "A", "A", new BMessage(BDHVIEW_A),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[10]->SetEnabled(false);
	
	r.Set(LEFT+HTAB*1, TOP+VTAB*3, LEFT+HTAB*1+WIDTH, TOP+VTAB*3+HEIGHT);
	button[11] = new BButton(r, "B", "B", new BMessage(BDHVIEW_B),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[11]->SetEnabled(false);
	
	r.Set(LEFT+HTAB*2, TOP+VTAB*3, LEFT+HTAB*2+WIDTH, TOP+VTAB*3+HEIGHT);
	button[12] = new BButton(r, "C", "C", new BMessage(BDHVIEW_C),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[12]->SetEnabled(false);
	
	r.Set(LEFT+HTAB*3, TOP+VTAB*3, LEFT+HTAB*3+WIDTH, TOP+VTAB*3+HEIGHT);
	button[13] = new BButton(r, "D", "D", new BMessage(BDHVIEW_D),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[13]->SetEnabled(false);
	
	r.Set(LEFT+HTAB*4, TOP+VTAB*3, LEFT+HTAB*4+WIDTH, TOP+VTAB*3+HEIGHT);
	button[14] = new BButton(r, "E", "E", new BMessage(BDHVIEW_E),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[14]->SetEnabled(false);
	
	r.Set(LEFT+HTAB*5, TOP+VTAB*3, LEFT+HTAB*5+WIDTH, TOP+VTAB*3+HEIGHT);
	button[15] = new BButton(r, "F", "F", new BMessage(BDHVIEW_F),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[15]->SetEnabled(false);
	
	// arithmatic
	r.Set(LEFT+HTAB*10, TOP+VTAB*3, LEFT+HTAB*10+WIDTH, TOP+VTAB*3+HEIGHT);
	button[16] = new BButton(r, "plus", "+", new BMessage(BDHVIEW_PLUS),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);

	r.Set(LEFT+HTAB*10, TOP+VTAB*2, LEFT+HTAB*10+WIDTH, TOP+VTAB*2+HEIGHT);
	button[17] = new BButton(r, "minus", "−", new BMessage(BDHVIEW_MINUS),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*10, TOP+VTAB, LEFT+HTAB*10+WIDTH, TOP+VTAB+HEIGHT);
	button[18] = new BButton(r, "times", "×", new BMessage(BDHVIEW_TIMES),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*10, TOP, LEFT+HTAB*10+WIDTH, TOP+HEIGHT);
	button[19] = new BButton(r, "div", "÷", new BMessage(BDHVIEW_DIV),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);

	// enter
	r.Set(LEFT+HTAB*8, TOP+VTAB*3, LEFT+HTAB*8+WIDTH+HTAB, TOP+VTAB*3+HEIGHT);
	button[20] = new BButton(r, "enter", "=", new BMessage(BDHVIEW_ENTER),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	// logical
	r.Set(LEFT+HTAB*1, TOP+VTAB*1, LEFT+HTAB*1+WIDTH, TOP+VTAB*1+HEIGHT);
	button[21] = new BButton(r, "and", "and", new BMessage(BDHVIEW_AND),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*2, TOP+VTAB*1, LEFT+HTAB*2+WIDTH, TOP+VTAB*1+HEIGHT);
	button[22] = new BButton(r, "or", "or", new BMessage(BDHVIEW_OR),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*3, TOP+VTAB*1, LEFT+HTAB*3+WIDTH, TOP+VTAB*1+HEIGHT);
	button[23] = new BButton(r, "not", "not", new BMessage(BDHVIEW_NOT),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);

	r.Set(LEFT+HTAB*4, TOP+VTAB*1, LEFT+HTAB*4+WIDTH, TOP+VTAB*1+HEIGHT);
	button[24] = new BButton(r, "xor", "xor", new BMessage(BDHVIEW_XOR),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	// other
	r.Set(LEFT+HTAB*1, TOP+VTAB*2, LEFT+HTAB*1+WIDTH, TOP+VTAB*2+HEIGHT);
	button[25] = new BButton(r, "shl", "shl", new BMessage(BDHVIEW_SHL),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*2, TOP+VTAB*2, LEFT+HTAB*2+WIDTH, TOP+VTAB*2+HEIGHT);
	button[26] = new BButton(r, "shr", "shr", new BMessage(BDHVIEW_SHR),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*3, TOP+VTAB*2, LEFT+HTAB*3+WIDTH, TOP+VTAB*2+HEIGHT);
	button[27] = new BButton(r, "rol", "rol", new BMessage(BDHVIEW_ROL),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*4, TOP+VTAB*2, LEFT+HTAB*4+WIDTH, TOP+VTAB*2+HEIGHT);
	button[28] = new BButton(r, "ror", "ror", new BMessage(BDHVIEW_ROR),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*5, TOP+VTAB*2, LEFT+HTAB*5+WIDTH, TOP+VTAB*2+HEIGHT);
	button[29] = new BButton(r, "mod", "mod", new BMessage(BDHVIEW_MOD),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
		
	r.Set(LEFT+HTAB*6, TOP+VTAB*2, LEFT+HTAB*6+WIDTH, TOP+VTAB*2+HEIGHT);
	button[30] = new BButton(r, "±", "±", new BMessage(BDHVIEW_SIGN),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[30]->SetEnabled(false);
	
	r.Set(LEFT+HTAB*6, TOP+VTAB*3, LEFT+HTAB*6+WIDTH, TOP+VTAB*3+HEIGHT);
	button[31] = new BButton(r, ".", ".", new BMessage(BDHVIEW_POINT),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	button[31]->SetEnabled(false);

	// Memory
	r.Set(LEFT+HTAB*5, TOP+VTAB*1, LEFT+HTAB*5+WIDTH, TOP+VTAB*1+HEIGHT);
	button[32] = new BButton(r, "sto", "STO", new BMessage(BDHVIEW_STO),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*6, TOP+VTAB*1, LEFT+HTAB*6+WIDTH, TOP+VTAB*1+HEIGHT);
	button[33] = new BButton(r, "rcl", "RCL", new BMessage(BDHVIEW_RCL),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	
	// Extras
	r.Set(LEFT+HTAB*0, TOP+VTAB*1, LEFT+HTAB*0+WIDTH, TOP+VTAB*1+HEIGHT);
	button[34] = new BButton(r, "2X", "2X", new BMessage(BDHVIEW_2X),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
	r.Set(LEFT+HTAB*0, TOP+VTAB*2, LEFT+HTAB*0+WIDTH, TOP+VTAB*2+HEIGHT);
	button[35] = new BButton(r, "10X", "10X", new BMessage(BDHVIEW_10X),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);


	// Clear
	r.Set(LEFT+HTAB*10, TOP-VTAB, LEFT+HTAB*10+WIDTH, TOP-VTAB+HEIGHT);
	button[36] = new BButton(r, "clear", "C", new BMessage(BDHVIEW_CLEAR),
		B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	
		
	// Bases
	r.Set(3, HEIGHT*1.5, 3+66, HEIGHT*2);
	binary = new BRadioButton(r, "binary", "Bin",
		new BMessage(BDHVIEW_BINARY), B_FOLLOW_LEFT | B_FOLLOW_TOP,
		B_WILL_DRAW | B_NAVIGABLE);
	
	r.Set(3+66, HEIGHT*1.5, 3+66*2, HEIGHT*2);
	decimal = new BRadioButton(r, "decimal", "Dec",
		new BMessage(BDHVIEW_DECIMAL), B_FOLLOW_LEFT | B_FOLLOW_TOP,
		B_WILL_DRAW | B_NAVIGABLE);
	decimal->SetValue(B_CONTROL_ON);
	
	r.Set(3+66*2, HEIGHT*1.5, 3+66*3, HEIGHT*2);
	hex = new BRadioButton(r, "hex", "Hex",
		new BMessage(BDHVIEW_HEX), B_FOLLOW_LEFT | B_FOLLOW_TOP,
		B_WILL_DRAW | B_NAVIGABLE);
	
	
	// TextView
	BFont *textfont = new BFont(be_fixed_font);
	textfont->SetSize(14);
		
	r.Set(3, 3, 12+512+3, 3+HEIGHT);
	BRect r2(10, 2, 9+512, 20);
	das_text = new BTextView(r, "text", r2, B_FOLLOW_LEFT | B_FOLLOW_TOP,
		B_WILL_DRAW | B_NAVIGABLE);
	
	das_text->SetFontAndColor(textfont);
	das_text->SetAlignment(B_ALIGN_RIGHT);
	das_text->SetStylable(false);
	das_text->SetMaxBytes(65);
	das_text->SetWordWrap(false);
	das_text->SetText("0");
	das_text->MakeEditable(false);
	das_text->MakeSelectable(false);
	
	// PopUp Menu
	popup = new BPopUpMenu("uint64", true, true, B_ITEMS_IN_COLUMN);
	popup->AddItem(menuitems[0] = new BMenuItem("uint64", new BMessage(BDHVIEW_UINT64)));
	popup->AddItem(menuitems[1] = new BMenuItem("uint32", new BMessage(BDHVIEW_UINT32)));
	popup->AddItem(menuitems[2] = new BMenuItem("uint16", new BMessage(BDHVIEW_UINT16)));
	popup->AddItem(menuitems[3] = new BMenuItem("uint8", new BMessage(BDHVIEW_UINT8)));
	popup->AddItem(menuitems[4] = new BMenuItem("FP", new BMessage(BDHVIEW_FP)));
	menuitems[4]->SetEnabled(false);
	popup->AddItem(menuitems[5] = new BMenuItem("int64", new BMessage(BDHVIEW_INT64)));
	popup->AddItem(menuitems[6] = new BMenuItem("int32", new BMessage(BDHVIEW_INT32)));
	popup->AddItem(menuitems[7] = new BMenuItem("int16", new BMessage(BDHVIEW_INT16)));
	popup->AddItem(menuitems[8] = new BMenuItem("int8", new BMessage(BDHVIEW_INT8)));
	r.Set(HTAB*5-11, TOP+2, HTAB*5+80, TOP+HEIGHT);
	popup_menu = new BMenuBar(r, "popup menu",
		B_FOLLOW_LEFT_RIGHT | B_FOLLOW_TOP, B_ITEMS_IN_COLUMN, false);
	popup_menu->AddItem(popup);
	
	AddChild(popup_menu);
		
	AddChild(das_text);
	AddChild(binary);
	AddChild(decimal);
	AddChild(hex);

	for (int i=0; i<NUM_BUTTONS; i++)
		AddChild(button[i]);

	first = 0;
	second = 0;
	first_entered = false;
	invalidate = false;
	base = 10;
	first = 0;

	mouse_down = false;
	mouse_offset = BPoint(0, 0);
}


void bdh_view::AllAttached()
{
	int i;
	
	for (i=0; i<NUM_BUTTONS; i++)
		button[i]->SetTarget(this);
	
	binary->SetTarget(this);
	decimal->SetTarget(this);
	hex->SetTarget(this);
	
	for (i=0; i<9; i++)
		menuitems[i]->SetTarget(this);
	
	// Sets the calculator to default state
	decimal->Invoke();
	
	inherited::AllAttached();
}


/*BArchivable *bdh_view::Instantiate(BMessage *data)
{	
	if (!validate_instantiation(data, "bdh_view"))
		return NULL;
	return new bdh_view(data);
}*/



/*status_t bdh_view::Archive(BMessage *data, bool deep) const
{
	beep();
	inherited::Archive(data, deep);
	
	data->AddString("add_on", app_signature);
	return 0;
} */

void bdh_view::KeyDown(const char* bytes, int32 numBytes)
{
	char c = (bytes[0] >= 'a' && bytes[0] <= 'f' )
		? bytes[0] - 0x20 : bytes[0];

	if (numBytes == 1) {
		if (store) {
			if (c >= '0' && c <= '9') {
				c -= '0';
				storage[c] = get_num();
			}
		} else if (recall) {
			if (c >= '0' && c <= '9') {
				c -= '0';
				set_text(storage[c]);
			}
		} else {
			switch (c) {
				case B_DELETE:
					first = 0;
					first_entered = false;
					set_text(first);
					break;
				case B_BACKSPACE:
					if (das_text->TextLength() > 1) {
						char buffer[65];
						das_text->GetText(0, das_text->TextLength() - 1, buffer);
						das_text->SetText(buffer);
						first_entered = true;
					} else {
						das_text->SetText("0");
						first_entered = false;
					}
					first = get_num();
					break;

		 		case '%':
		 			enter();
					first = get_num();
					mode = BDHVIEW_MOD;
					first_entered = true;
					invalidate = true;
					break;
				case '&':
		 			enter();
					first = get_num();
					mode = BDHVIEW_AND;
					first_entered = true;
					invalidate = true;
					break;
				case '|':
		 			enter();
					first = get_num();
					mode = BDHVIEW_OR;
					first_entered = true;
					invalidate = true;
					break;
				case '!':
					set_text(get_num()^-1);
					break;
				case '^':
		 			enter();
					first = get_num();
					mode = BDHVIEW_XOR;
					first_entered = true;
					invalidate = true;
					break;
				
				case '+':
		 			enter();
					first = get_num();
					mode = BDHVIEW_PLUS;
					first_entered = true;
					invalidate = true;
					break;		
				case '-':
		 			enter();
					first = get_num();
					mode = BDHVIEW_MINUS;
					first_entered = true;
					invalidate = true;
					break;
				case '*':
		 			enter();
					first = get_num();
					mode = BDHVIEW_TIMES;
					first_entered = true;
					invalidate = true;
					break;
				case '/':
		 			enter();
					first = get_num();
					mode = BDHVIEW_DIV;
					first_entered = true;
					invalidate = true;
					break;
				
				case '0':
				case '1':
					insert_text(c);
					break;
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					if (base == 10 || base == 16)
						insert_text(c);
					break;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
					if (base == 16)
						insert_text(c);
					break;
					
				case B_ENTER:
				case '=':
					enter();
					break;
					
				default:
					BView::KeyDown(bytes, numBytes);
			}
		}
	}
	store = recall = false;

	BView::KeyDown(bytes, numBytes);
}


void bdh_view::MessageReceived(BMessage *msg)
{
	unsigned long long scratch, rotate_mask;

	switch(msg->what) {
		case BDHVIEW_POPUP_MENU:
		{
			BPoint where;
			if (msg->FindPoint("where", &where) != B_OK)
				return;

			BPopUpMenu *menu = new BPopUpMenu("", false, false);
			BMenuItem *item[1];

			item[0] = new BMenuItem("About BDH Calc", NULL);
			menu->AddItem(item[0]);

			menu->ResizeToPreferred();

			BMenuItem* selected_item = menu->Go(where);

			if (selected_item == item[0])
				be_app->AboutRequested();

			delete menu;
			break;
		}

		case B_COPY:
		{
			if (be_clipboard->Lock()) {
				be_clipboard->Clear();
       			BMessage *clipper = be_clipboard->Data();
       			clipper->what = B_ANY_TYPE;
        		clipper->AddData("text/plain", B_MIME_TYPE, das_text->Text(),
        			das_text->TextLength());
        		be_clipboard->Commit();
        		be_clipboard->Unlock();
        	}
			break;
		}
		
		case BDHVIEW_STO:
			store = true;
			recall = false;
			break;
		case BDHVIEW_RCL:
			recall = true;
			store = false;
			break;
			
		case BDHVIEW_UINT64:
			scratch = get_num();
			data_type = BIT64;
			switch_keys();
			set_text(scratch);
			store = recall = false;
			break;
		case BDHVIEW_UINT32:
			scratch = get_num();
			data_type = BIT32;
			switch_keys();
			set_text(scratch);
			store = recall = false;
			break;
		case BDHVIEW_UINT16:
			scratch = get_num();
			data_type = BIT16;
			switch_keys();
			set_text(scratch);
			store = recall = false;
			break;
		case BDHVIEW_UINT8:
			scratch = get_num();
			data_type = BIT8;
			switch_keys();
			set_text(scratch);
			store = recall = false;
			break;
		case BDHVIEW_FP:
			data_type = FP;
			switch_keys();
			set_text(get_num());
			store = recall = false;
			break;
		case BDHVIEW_INT64:
			data_type = BIT64 | SIGNED;
			switch_keys();
			set_text(get_num());
			store = recall = false;
			break;
		case BDHVIEW_INT32:
			data_type = BIT32 | SIGNED;
			switch_keys();
			set_text(get_num());
			store = recall = false;
			break;
		case BDHVIEW_INT16:
			data_type = BIT16 | SIGNED;
			switch_keys();
			set_text(get_num());
			store = recall = false;
			break;
		case BDHVIEW_INT8:
			data_type = BIT8 | SIGNED;
			switch_keys();
			set_text(get_num());
			store = recall = false;
			break;
		
		case BDHVIEW_CLEAR:
			first = 0;
			first_entered = false;
			set_text(first);
			store = recall = false;
			break;
			
			
		case BDHVIEW_BINARY:
			scratch = get_num();
			base = BINARY;
			set_text(scratch);
			switch_keys();
			store = recall = false;
			MakeFocus(true);
			break;
		case BDHVIEW_DECIMAL:
			scratch = get_num();
			base = DECIMAL;
			set_text(scratch);
			switch_keys();
			store = recall = false;
			MakeFocus(true);
			break;
		case BDHVIEW_HEX:
			scratch = get_num();
			base = HEX;
			set_text(scratch);
			switch_keys();
			store = recall = false;
			MakeFocus(true);
			break;
			
			
		case BDHVIEW_AND:
	 		enter();
			first = get_num();
			mode = BDHVIEW_AND;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		case BDHVIEW_OR:
	 		enter();
			first = get_num();
			mode = BDHVIEW_OR;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		case BDHVIEW_NOT:
			set_text(get_num()^-1);
			store = recall = false;
			break;
		case BDHVIEW_XOR:
	 		enter();
			first = get_num();
			mode = BDHVIEW_XOR;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		
		case BDHVIEW_PLUS:
	 		enter();
			first = get_num();
			mode = BDHVIEW_PLUS;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;		
		case BDHVIEW_MINUS:
	 		enter();
			first = get_num();
			mode = BDHVIEW_MINUS;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		case BDHVIEW_TIMES:
	 		enter();
			first = get_num();
			mode = BDHVIEW_TIMES;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		case BDHVIEW_DIV:
	 		enter();
			first = get_num();
			mode = BDHVIEW_DIV;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
			
		
		case BDHVIEW_2X:
			set_text(pwr2(get_num()));	
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		case BDHVIEW_10X:
			set_text(pwr10(get_num()));	
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;		
		case BDHVIEW_SHL:
			set_text(get_num()<<1);
			store = recall = false;
			break;
		case BDHVIEW_SHR:
			set_text(get_num()>>1);
			store = recall = false;
			break;
		case BDHVIEW_ROL:
			switch (data_type & WORD_MASK) {
				case BIT64:
					rotate_mask = 0x8000000000000000LL;
					break;
				case BIT32:
					rotate_mask = 0x80000000LL;
					break;
				case BIT16:
					rotate_mask = 0x8000LL;
					break;
				case BIT8:
					rotate_mask = 0x80LL;
					break;
				}
			scratch = get_num();
			if (scratch & rotate_mask) {
				scratch <<= 1;
				scratch |= 1;
				set_text(scratch);
			} else
				set_text(scratch<<1);

			store = recall = false;
			break;
		case BDHVIEW_ROR:
			switch (data_type & WORD_MASK) {
				case BIT64:
					rotate_mask = 0x8000000000000000LL;
					break;
				case BIT32:
					rotate_mask = 0x80000000LL;
					break;
				case BIT16:
					rotate_mask = 0x8000LL;
					break;
				case BIT8:
					rotate_mask = 0x80LL;
					break;
			}
			scratch = get_num();
			if (scratch & 1)
				{
				scratch >>= 1;
				scratch |= rotate_mask;
				set_text(scratch);
			} else
				set_text(scratch>>1);

			store = recall = false;
			break;
			
		case BDHVIEW_MOD:
	 		enter();
			first = get_num();
			mode = BDHVIEW_MOD;
			first_entered = true;
			invalidate = true;
			store = recall = false;
			break;
		case BDHVIEW_SIGN:
			set_text(0-get_num());
			invalidate = false;
			store = recall = false;
			break;
		
		case BDHVIEW_ENTER:
			enter();
			store = recall = false;
			break;
		
			
		case BDHVIEW_0:
			if (store)
				storage[0] = get_num();
			else if (recall)
				set_text(storage[0]);
			else
				insert_text('0');
			store = recall = false;
			break;		
		case BDHVIEW_1:
			if (store)
				storage[1] = get_num();
			else if (recall)
				set_text(storage[1]);
			else
				insert_text('1');
			store = recall = false;
			break;
		case BDHVIEW_2:
			if (store)
				storage[2] = get_num();
			else if (recall)
				set_text(storage[2]);
			else if (base == DECIMAL || base == HEX)
				insert_text('2');
			store = recall = false;
			break;
		case BDHVIEW_3:
			if (store)
				storage[3] = get_num();
			else if (recall)
				set_text(storage[3]);
			else if (base == DECIMAL || base == HEX)
				insert_text('3');
			store = recall = false;
			break;
		case BDHVIEW_4:
			if (store)
				storage[4] = get_num();
			else if (recall)
				set_text(storage[4]);
			else if (base == DECIMAL || base == HEX)
				insert_text('4');
			store = recall = false;
			break;
		case BDHVIEW_5:
			if (store)
				storage[5] = get_num();
			else if (recall)
				set_text(storage[5]);
			else if (base == DECIMAL || base == HEX)
				insert_text('5');
			store = recall = false;
			break;
		case BDHVIEW_6:
			if (store)
				storage[6] = get_num();
			else if (recall)
				set_text(storage[6]);
			else if (base == DECIMAL || base == HEX)
				insert_text('6');
			store = recall = false;
			break;
		case BDHVIEW_7:
			if (store)
				storage[7] = get_num();
			else if (recall)
				set_text(storage[7]);
			else if (base == DECIMAL || base == HEX)
				insert_text('7');
			store = recall = false;
			break;
		case BDHVIEW_8:
			if (store)
				storage[8] = get_num();
			else if (recall)
				set_text(storage[8]);
			else if (base == DECIMAL || base == HEX)
				insert_text('8');
			store = recall = false;
			break;
		case BDHVIEW_9:
			if (store)
				storage[9] = get_num();
			else if (recall)
				set_text(storage[9]);
			else if (base == DECIMAL || base == HEX)
				insert_text('9');
			store = recall = false;
			break;
		case BDHVIEW_A:
			if (base == HEX)
				insert_text('A');
			store = recall = false;
			break;
		case BDHVIEW_B:
			if (base == HEX)
				insert_text('B');
			store = recall = false;
			break;
		case BDHVIEW_C:
			if (base == HEX)
				insert_text('C');
			store = recall = false;
			break;
		case BDHVIEW_D:
			if (base == HEX)
				insert_text('D');
			store = recall = false;
			break;
		case BDHVIEW_E:
			if (base == HEX)
				insert_text('E');
			store = recall = false;
			break;
		case BDHVIEW_F:
			if (base == HEX)
				insert_text('F');
			store = recall = false;
			break;
		default:
			inherited::MessageReceived(msg);
	}
}


void bdh_view::MouseDown(BPoint where)
{
	Window()->Activate();

	if (Window()->CurrentMessage()->FindInt32("buttons")
			== B_SECONDARY_MOUSE_BUTTON) {
		BPoint point;
		Window()->CurrentMessage()->FindPoint("where", &point);
		ConvertToScreen(&point);

		BMessage message(BDHVIEW_POPUP_MENU);
		message.AddPoint("where", point);
		MessageReceived(&message);
	} else {
		mouse_down = true;
		mouse_offset = where;

		SetMouseEventMask(B_POINTER_EVENTS, B_NO_POINTER_HISTORY
			| B_SUSPEND_VIEW_FOCUS | B_LOCK_WINDOW_FOCUS);

		BView::MouseDown(where);
	}
}


void bdh_view::MouseMoved(BPoint where, uint32 code, const BMessage* message)
{
	if (mouse_down) {
		BPoint win_pos = Window()->Frame().LeftTop();
		Window()->MoveTo(win_pos.x + where.x - mouse_offset.x,
			win_pos.y + where.y - mouse_offset.y );
	} else
		BView::MouseMoved(where, code, message);
}


void bdh_view::MouseUp(BPoint where)
{
	mouse_down = false;
	BView::MouseUp(where);
}


/*
 * SET TEXT ()
 */
void bdh_view::set_text(unsigned long long number)
{
	char buffer[65], final[65];
	unsigned int i, n;
	long long signed_num = (long long)number;
	bool negative=false;
	char s_8;
	short s_16;
	long s_32;

	if (number == 0) {
		das_text->SetText("0");
		das_text->Invalidate();
		return;
	}

	for (i=0; i<65; i++)
		final[i] = 0;
	
	i=0;
	
	if (data_type & SIGNED) {
		switch (data_type & WORD_MASK) {
			case BIT8:
			    s_8 = signed_num;
			    number = (unsigned char)s_8;
			    if (s_8==0)
					final[0] = '0';
				else if (base == DECIMAL && s_8 < 0)
					{
					negative = true;
					number = (unsigned char)abs(s_8);
					}
			    break;
				
			case BIT16:
				s_16 = signed_num;
				number = (unsigned short)s_16;
				if (s_16==0)
					final[0] = '0';
				else if (base == DECIMAL && s_16 < 0)
					{
					negative = true;
					number = (unsigned short)abs(s_16);
					}
				break;
				
			case BIT32:
				s_32 = signed_num;
				number = (unsigned long)s_32;
				if (s_32==0)
					final[0] = '0';
				else if (base == DECIMAL && s_32 < 0)
					{
					negative = true;
					number = (unsigned long)abs(s_32);
					}
				break;
				
			case BIT64:
				number = (unsigned long long)signed_num;
				if (signed_num==0)
					final[0] = '0';
				else if (base == DECIMAL && signed_num < 0)
					{
					negative = true;
					number = (unsigned long long)abs(signed_num);
					}
				break;
		}
			
		while (number) {
			buffer[i] = number % base;
			number /= base;
			i++;
		}
	} else {
		// UNSIGNED
		switch (data_type & WORD_MASK) {
			case BIT8:
				number &= 0xFF;
				break;
			case BIT16:
				number &= 0xFFFF;
				break;
			case BIT32:
				number &= 0xFFFFFFFFL;
				break;
			}
		if (!number)
			final[0] = '0';
		while (number)
			{
			buffer[i] = number % base;
			number /= base;
			i++;
			}
		}
	
	for (n=0; n<i; n++) {
		final[n] = buffer[i-n-1];
		final[n] += (final[n] > 9) ? 'A' - 10 : '0';
	}
	
	if (negative) {	
		for (n=0; n<i; n++)
			final[i-n] = final[i-n-1];
		final[0] = '-';
	}
	
	das_text->SetText(final);
	das_text->Invalidate();
}


/*
 * INSERT TEXT ()
 */
void bdh_view::insert_text(char digit)
{
	int len, hex_max, dec_max, bin_max;

	len = das_text->TextLength();

	if (invalidate) {
		das_text->Delete(0,len);
		len = 0;
		das_text->Invalidate();
		invalidate = false;
	}

	switch (data_type & WORD_MASK) {
		case BIT64:
			hex_max=16;
			dec_max=20;
			bin_max=64;
			break;
		case BIT32:
			hex_max=8;
			dec_max=10;
			bin_max=32;
			break;
		case BIT16:
			hex_max=4;
			dec_max=5;
			bin_max=16;
			break;
		case BIT8:
			hex_max=2;
			dec_max=3;
			bin_max=8;
			break;
	}

	if ((len != hex_max && base == HEX)
		|| (len != dec_max && base == DECIMAL)
		|| (len != bin_max && base == BINARY)) {
		if (len == 1) {
			if (*das_text->Text() == '0') {
				das_text->Delete(0, len);
				len = 0;
			}
		}

		das_text->Insert(len, &digit, 1);
	}
}


/*
 * GET NUMBER ()
 */
unsigned long long bdh_view::get_num()
{
	char buffer[65], *text;
	unsigned long long number, base_digit;
	int i, n, len;
	bool negative=false;
	
	text = (char*)das_text->Text();
	len = das_text->TextLength();
	memcpy(buffer, text, len);

	number=0;
	base_digit=1;
	
	if (data_type & SIGNED) {
		if (buffer[0] == '-') {
			negative=true;
			for (i=1; i<len; i++)
				buffer[i-1] = buffer[i];
			buffer[len]=0;
			len--;
		}
	}
	
	for (i=0; i < len; i++) {
		buffer[i] -= (buffer[i] > '9') ? 'A' - 10 : '0' ;
		for (n=0; n<len-i-1; n++)
			base_digit *= base;
		number += base_digit * buffer[i];
		base_digit=1;
	}
	
	if (negative)
		return ((unsigned long long)(0-(long long)number));
		
	return number;
}


/*
 * ENTER ()
 */
void bdh_view::enter()
{
	long long signed_first, signed_second;
	
	if (mode) {
		first_entered = false;
		invalidate = true;	
		second = get_num();
		
		if (data_type & SIGNED) {
			signed_first = (long long) first;
			signed_second = (long long) second;
			//printf("%lld %lld\n",signed_first,signed_second);
			switch (mode) {
				case BDHVIEW_MOD:
					if (signed_second != 0)
						signed_first %= signed_second;
					else
						signed_first = 0;
					break;
				case BDHVIEW_AND:
					signed_first &= signed_second;
					break;
				case BDHVIEW_OR:
					signed_first |= signed_second;
					break;
				case BDHVIEW_XOR:
					signed_first ^= signed_second;
					break;
				case BDHVIEW_PLUS:
					signed_first += signed_second;
					break;
				case BDHVIEW_MINUS:
					signed_first -= signed_second;
					break;
				case BDHVIEW_TIMES:
					signed_first *= signed_second;
					break;
				case BDHVIEW_DIV:
					if (signed_second != 0)
						signed_first /= signed_second;
					else
						signed_first = 0;
					break;
			}
			set_text(signed_first);
		} else {
			switch (mode) {
				case BDHVIEW_MOD:
					if (second)
						first %= second;
					else
						first = 0;
					break;
				case BDHVIEW_AND:
					first &= second;
					break;
				case BDHVIEW_OR:
					first |= second;
					break;
				case BDHVIEW_XOR:
					first ^= second;
					break;
				case BDHVIEW_PLUS:
					first += second;
					break;
				case BDHVIEW_MINUS:
					first -= second;
					break;
				case BDHVIEW_TIMES:
					first *= second;
					break;
				case BDHVIEW_DIV:
					if (second)
						first /= second;
					else
						first = 0;
					break;
			}
			set_text(first);
		}
		
		mode = 0;
	}
}


/*
 * SWITCH KEYS ()
 */
void bdh_view::switch_keys()
{
	if (data_type == FP) {
		button[21]->SetLabel("eX");
		button[25]->SetLabel("lnX");
		button[22]->SetLabel("inv");
		button[26]->SetLabel("logX");
		button[23]->SetLabel("pwr");
		button[27]->SetLabel("sqrt");
		button[24]->SetLabel("pi");
		button[28]->SetLabel("");
		button[28]->SetEnabled(false);
		button[29]->SetLabel("");
		button[29]->SetEnabled(false);
			
		button[10]->SetLabel("asin");
		button[11]->SetLabel("acos");
		button[12]->SetLabel("atan");
		button[13]->SetLabel("sin");
		button[14]->SetLabel("cos");
		button[15]->SetLabel("tan");
			
		button[30]->SetEnabled(true);
		button[31]->SetEnabled(true);
	} else {
		button[21]->SetLabel("and");
		button[25]->SetLabel("shl");
		button[22]->SetLabel("or");
		button[26]->SetLabel("shr");
		button[23]->SetLabel("not");
		button[27]->SetLabel("rol");
		button[24]->SetLabel("xor");
		button[28]->SetLabel("ror");
		button[28]->SetEnabled(true);
		button[29]->SetLabel("mod");
		button[29]->SetEnabled(true);
			
		button[10]->SetLabel("A");
		button[11]->SetLabel("B");
		button[12]->SetLabel("C");
		button[13]->SetLabel("D");
		button[14]->SetLabel("E");
		button[15]->SetLabel("F");
			
		button[31]->SetEnabled(false);
		
		if (data_type & SIGNED)
			button[30]->SetEnabled(true);
		else
			button[30]->SetEnabled(false);
		
		switch (base) {
			case BINARY:
				// 2 - F disabled
				button[2]->SetEnabled(false);
				button[3]->SetEnabled(false);
				button[4]->SetEnabled(false);
				button[5]->SetEnabled(false);
				button[6]->SetEnabled(false);
				button[7]->SetEnabled(false);
				button[8]->SetEnabled(false);
				button[9]->SetEnabled(false);
				button[10]->SetEnabled(false);
				button[11]->SetEnabled(false);
				button[12]->SetEnabled(false);
				button[13]->SetEnabled(false);
				button[14]->SetEnabled(false);
				button[15]->SetEnabled(false);
				break;

			case DECIMAL:
				button[2]->SetEnabled(true);
				button[3]->SetEnabled(true);
				button[4]->SetEnabled(true);
				button[5]->SetEnabled(true);
				button[6]->SetEnabled(true);
				button[7]->SetEnabled(true);
				button[8]->SetEnabled(true);
				button[9]->SetEnabled(true);
				// A - F disabled
				button[10]->SetEnabled(false);
				button[11]->SetEnabled(false);
				button[12]->SetEnabled(false);
				button[13]->SetEnabled(false);
				button[14]->SetEnabled(false);
				button[15]->SetEnabled(false);
				break;
				
			case HEX:
				button[2]->SetEnabled(true);
				button[3]->SetEnabled(true);
				button[4]->SetEnabled(true);
				button[5]->SetEnabled(true);
				button[6]->SetEnabled(true);
				button[7]->SetEnabled(true);
				button[8]->SetEnabled(true);
				button[9]->SetEnabled(true);
				button[10]->SetEnabled(true);
				button[11]->SetEnabled(true);
				button[12]->SetEnabled(true);
				button[13]->SetEnabled(true);
				button[14]->SetEnabled(true);
				button[15]->SetEnabled(true);
				break;
		}
	}
}


unsigned long long bdh_view::pwr2(unsigned long long power)
{
	if (power < 64)
		return ((1LL)<<power);

	return 0;
}


unsigned long long bdh_view::pwr10(unsigned long long power)
{
	unsigned int i;
	unsigned long long n=1;
	
	if (power < 20) {
		for (i=0; i<power; i++)
			n *= 10;

		return n;
	}

	return 0;
}
