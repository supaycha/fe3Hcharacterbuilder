#include <CollPaneEquipment.h>

CollPaneEquipment::CollPaneEquipment(wxWindow* parent, wxWindowID id, const wxString& label) :
	wxCollapsiblePane(parent, id, label, wxDefaultPosition, wxSize(-1, -1))
{
	wxWindow* equipmentwindow = this->GetPane();
	ges = new GridEquipmentStats(equipmentwindow, (int)ID_SINGLE_CONTROL::ID_GES);

	wxBoxSizer* equipmentsizer = new wxBoxSizer(wxVERTICAL);
	equipmentsizer->Add(ges, 0, wxEXPAND, 0);

	equipmentwindow->SetSizer(equipmentsizer);
	equipmentsizer->SetSizeHints(equipmentwindow);
}

void CollPaneEquipment::ReceiveLBESelection(Stats stats) {
	ges->ReceiveLBESelection(stats);
}

void CollPaneEquipment::OnCollPaneChange(wxCollapsiblePaneEvent& event) {
	event.Skip();
}

wxBEGIN_EVENT_TABLE(CollPaneEquipment, wxCollapsiblePane)
	//EVT_COLLAPSIBLEPANE_CHANGED((int)ID_SINGLE_CONTROL::ID_CPE, CollPaneEquipment::OnCollPaneChange)
wxEND_EVENT_TABLE()