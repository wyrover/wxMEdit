///////////////////////////////////////////////////////////////////////////////
// vim:         ts=4 sw=4
// Name:        xm/inframe_wxmedit.cpp
// Description: Embedded wxMEdit in Main Frame
// Copyright:   2014-2015  JiaYanwei   <wxmedit@gmail.com>
// Licence:     GPLv3
///////////////////////////////////////////////////////////////////////////////

#include "inframe_wxmedit.h"
#include "../wxmedit_frame.h"
#include "../dialog/wxm_search_replace_dialog.h"
#include "xm_utils.hpp"

#include <wx/aui/auibook.h>
#include <wx/filename.h>

#include <boost/assign/list_of.hpp>

#ifdef _DEBUG
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK ,__FILE__, __LINE__)
#endif

extern MadEdit* g_ActiveMadEdit;
extern wxMenu *g_Menu_Edit;

namespace wxm
{

InFrameWXMEdit::InFrameWXMEdit(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
	: MadEdit(parent, id, pos, size, style)
{
	SetWindowStyleFlag(GetWindowStyleFlag() & ~wxTAB_TRAVERSAL);
	//SetDropTarget(new DnDFile());

	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MadEditFrame::MadEditFrameKeyDown));
}

wxString InserModeText(bool insertmode)
{
	static wxString insstr(_("INS"));
	static wxString ovrstr(_("OVR"));
	return insertmode? insstr: ovrstr;
}

wxString ReadOnlyText(bool readonly)
{
	static wxString rostr(_("ReadOnly"));
	return readonly ? rostr : wxString();
}

wxString BOMText(bool hasbom)
{
	static wxString bom(wxT(".BOM"));
	return hasbom ? bom : wxString();
}

wxString NewLineTypeText(MadNewLineType nlty)
{
	static std::map<int, wxString> nltytxts = boost::assign::map_list_of
			(nltDOS,  wxString(wxT(".DOS")))
			(nltUNIX, wxString(wxT(".UNIX")))
			(nltMAC,  wxString(wxT(".MAC")))
		;
	return xm::wrap_map(nltytxts).get((int)nlty, wxEmptyString);
}

void InFrameWXMEdit::DoSelectionChanged()
{
	g_MainFrame->m_Notebook->ConnectMouseClick();

	if (this != g_ActiveMadEdit)
		return;

	int line, subrow;
	wxFileOffset col;
	GetCaretPosition(line, subrow, col);
	if (GetEditMode() != emHexMode)
	{
		++line;
		++col;
	}

	wxString s1 = FormatThousands(wxString::Format(wxT("%d"), line));
	wxString s2 = FormatThousands(wxString::Format(wxT("%u"), GetLineCount()));
	wxString s4 = FormatThousands(wxLongLong(col).ToString());

	static wxString lnstr(_("Ln:"));
	static wxString sepstr(wxT(" /"));
	static wxString sepstr1(wxT(" ("));
	static wxString substr(_("Sub:"));
	static wxString sepstr2(wxT(')'));
	static wxString sepstr3(wxT(' '));
	static wxString colstr(_("Col:"));
	static wxString fpstr(_("CharPos:"));
	static wxString ssstr(_("SelSize:"));

	wxString text = lnstr + s1 + sepstr + s2;
	if (subrow>0)
	{
		wxString s3 = FormatThousands(wxString::Format(wxT("%d"), subrow + 1));
		text += (sepstr1 + substr + s3 + sepstr2);
	}
	text += (sepstr3 + colstr + s4);
	wxm::GetFrameStatusBar().SetField(wxm::STBF_ROWCOL, text);

	s1 = FormatThousands(wxLongLong(GetCaretPosition()).ToString());
	s2 = FormatThousands(wxLongLong(GetFileSize()).ToString());
	wxm::GetFrameStatusBar().SetField(wxm::STBF_CHARPOS, fpstr + s1 + sepstr + s2);

	s1 = FormatThousands(wxLongLong(GetSelectionSize()).ToString());
	wxm::GetFrameStatusBar().SetField(wxm::STBF_SELECTION, ssstr + s1);

	wxm::GetFrameStatusBar().Update(); // repaint immediately
}

void InFrameWXMEdit::DoStatusChanged()
{
	g_MainFrame->m_Notebook->ConnectMouseClick();

	// check the title is changed or not
	int selid = GetIdByEdit(this);

	wxString oldtitle = g_MainFrame->m_Notebook->GetPageText(selid);

	wxString filename = GetFileName(), title;
	if (!filename.IsEmpty())
	{
		wxFileName fn(filename);
		title = fn.GetFullName();
	}
	else
	{
		title = oldtitle;
	}

	if (IsModified())
	{
		if (title[title.Len() - 1] != wxT('*'))
			title += wxT('*');

		if (filename.IsEmpty())
			filename = title;
		else
			filename += wxT('*');
	}
	else
	{
		if (title[title.Len() - 1] == wxT('*'))
			title.Truncate(title.Len() - 1);
	}

	if (title != oldtitle)
	{
		g_MainFrame->m_Notebook->SetPageText(selid, title);
	}

	if (this != g_ActiveMadEdit)
		return;

	if (filename.IsEmpty())
		filename = title;
	g_MainFrame->SetTitle(wxString(wxT("wxMEdit - [")) + filename + wxString(wxT("] ")));

	wxString encfmt = GetEncodingName();

	encfmt += BOMText(HasBOM());

	encfmt += NewLineTypeText(GetNewLineType());

	wxm::GetFrameStatusBar().SetField(wxm::STBF_ENCFMT, encfmt);

	wxm::GetFrameStatusBar().SetField(wxm::STBF_READONLY, ReadOnlyText(IsReadOnly()));

	wxm::GetFrameStatusBar().SetField(wxm::STBF_INSOVR, InserModeText(IsInsertMode()));

	wxm::GetFrameStatusBar().Update(); // repaint immediately

	if (g_SearchReplaceDialog != NULL)
	{
		g_SearchReplaceDialog->UpdateCheckBoxByCBHex(g_SearchReplaceDialog->WxCheckBoxFindHex->GetValue());
	}
}

void InFrameWXMEdit::DoToggleWindow()
{
	wxCommandEvent e(0, 0);
	g_MainFrame->OnWindowToggleWindow(e);
}

void InFrameWXMEdit::DoMouseRightUp()
{
	g_MainFrame->PopupMenu(g_Menu_Edit);
}

} //namespace wxm
