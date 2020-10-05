#ifndef MAIN_CXX
#define MAIN_CXX
#include <wx/wx.h>
#include <cstring>
#include <fstream>
#include <string.h>
using namespace std;
//compile: run `g++ src/main.cxx `wx-config --cxxflags --libs` -I/mnt/c/Users/User/Downloads/wxWidgets-3.1.4 -o main`
//run: run Xming and enter the ff. commands to the command line `DISPLAY=:0 gdb ./main`

wxTextCtrl *textctrl;

class Main : public wxApp {
public:
	virtual bool OnInit();
};

class Button : public wxFrame {
public:
	Button(const wxString& title);

	void New(wxCommandEvent& event);
	void CompileBasic(wxCommandEvent& event);
	void CompileGxx(wxCommandEvent& event);
};

class Frame : public wxFrame {
public:
	Frame(const wxString& title);
};

Frame::Frame(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxPoint(-1, -1), wxSize(750, 600)) {
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	textctrl = new wxTextCtrl(this, wxID_ANY, "\x54\x65\x73\x74", wxPoint(-1, 10), wxSize(750, 750), wxTE_MULTILINE);
	wxButton *button = new wxButton(panel, wxID_ANY, "\x54\x65\x73\x74 Button", wxPoint(-1, -1), wxSize(750, 10));
	Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Button::CompileBasic));
	button->SetFocus();
	Centre();
}

void Button::CompileBasic(wxCommandEvent& event) {
	wxString *textCtrlStr;
	std::string xeOutput;
	std::ofstream outfile("a.cxx");
	std::string str = textctrl->GetValue().ToStdString();
	outfile << str;
	outfile.close();

	std::ifstream infile;
	infile.open("a.cxx");
	std::string cxxsh;
	while(!infile.eof()) {
		std::string line;
		std::getline(infile, line);

		if(line == "int main() {}") {
		}
		//printf
		if(line == "printf(\x22HELO\x22);") {
			cxxsh = cxxsh + "\x65\x63\x68\x6F \x22HELO\x22";
		}
		if(line == "printf(\x22helo\x22);") {
			cxxsh = cxxsh + "\x65\x63\x68\x6F \x22helo\x22";
		}
		//var
		if(line == "std::string a = \x22HELO\x22;") {
			cxxsh = cxxsh + "a=\x22HELO\x22";
		}
		if(line == "std::string a = \x22helo\x22;") {
			cxxsh = cxxsh + "a=\x22helo\x22";
		}
	}
	infile.close();

	std::ofstream cxxfile("a.sh");
	cxxfile << cxxsh;
	cxxfile.close();

	wxMessageBox("\x43\x6F\x6D\x70\x69\x6C\x65\x64\x21");
}

IMPLEMENT_APP(Main);

bool Main::OnInit() {
	Frame *frame = new Frame("\x54\x65\x73\x74");
	frame->Show(true);

	return true;
}
#endif //MAIN_CXX