#include "SkillLevelPanel.h"

SkillLevelPanel::SkillLevelPanel(std::map<wxString, wxClientData*> weaponmap, std::map<wxString, wxClientData*> battalionmap, wxWindow* parent, wxWindowID id) :
	wxPanel(parent, id)
{
	const wxArrayString emptybuffer{};

	slm = new SkillLevelManager(this, (int)ID_SINGLE_CONTROL::ID_SLM);
	wm = new WeaponManager(weaponmap, this, (int)ID_MISC::ID_WM);	
	wxStaticText* lbaslaLABEL = new wxStaticText(this, wxID_ANY, "Available Abilities");
	lbasla = new ListBoxASLA(this, (int)ID_SINGLE_CONTROL::ID_LBASLA, 0, 0, 150, 260, emptybuffer, wxLB_MULTIPLE);
	wxStaticText* lbbLABEL = new wxStaticText(this, wxID_ANY, "Available Battalions");
	lbb = new ListBoxBattalions(battalionmap, this, (int)ID_SINGLE_CONTROL::ID_LBB, 150, 260, emptybuffer, wxLB_SINGLE | wxLB_SORT);

	slpSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* column2 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* column3 = new wxBoxSizer(wxVERTICAL);

	column1->Add(slm);
	column1->Add(wm);
	slpSizer->Add(column1);
	column2->Add(lbaslaLABEL);
	column2->Add(lbasla);
	slpSizer->Add(column2);
	column3->Add(lbbLABEL);
	column3->Add(lbb);
	slpSizer->Add(column3);
	SetSizerAndFit(slpSizer);
	//this->Layout();
}