#include <MyApp.h>

bool MyApp::OnInit() {
	::wxInitAllImageHandlers();
	MyFrame* frame = new MyFrame((int)ID_MISC::ID_FRAME, wxT("feBuilder"));

	frame->InitDialog();
	frame->Show(true);
	return true;
}

IMPLEMENT_APP(MyApp);