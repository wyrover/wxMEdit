///////////////////////////////////////////////////////////////////////////////
// vim:         ts=4 sw=4
// Name:        wxm/recent_list.cpp
// Description: Recent List
// Copyright:   2013-2015  JiaYanwei   <wxmedit@gmail.com>
// License:     GPLv3
///////////////////////////////////////////////////////////////////////////////

#include "recent_list.h"
#include "case_conv.h"
#include "utils.h"
#include <wx/menu.h>
#include <wx/intl.h>

#ifdef _DEBUG
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK ,__FILE__, __LINE__)
#endif

namespace wxm
{

bool wxCaseInsensitiveRecentList::ItemEqual(const wxString& item1, const wxString& item2)
{
	return wxm::WxCaseCompare(item1, item2) == 0;
}

bool wxFilePathRecentList::ItemEqual(const wxString& item1, const wxString& item2)
{
	return wxm::FilePathEqual(item1, item2);
}

static const wxChar *s_MRUEntryFormat = wxT("&%d %s");

static inline wxChar* MYcopystring(const wxString& s)
{
	wxChar* copy = new wxChar[s.size() + 1];
	copy[s.size()] = 0;
	return (wxChar*)memcpy(copy, s.c_str(), s.size()*sizeof(wxChar));
}

// Recent List management
void wxRecentList::AddFileToHistory(const wxString& item)
{
	size_t i;

	// Check we don't already have this item
	for (i = 0; i < m_fileHistoryN; i++)
	{
		if ( m_fileHistory[i] && ItemEqual(item, m_fileHistory[i]) )
		{
			// we do have it, move it to the top of the history
			RemoveFileFromHistory (i);
			AddFileToHistory (item);
			return;
		}
	}

	// if we already have a full history, delete the one at the end
	if ( m_fileMaxFiles == m_fileHistoryN )
	{
		RemoveFileFromHistory (m_fileHistoryN - 1);
		AddFileToHistory (item);
		return;
	}

	// Add to the project item history:
	// Move existing items (if any) down so we can insert item at beginning.
	if (m_fileHistoryN < m_fileMaxFiles)
	{
		wxList::compatibility_iterator node = m_fileMenus.GetFirst();
		while (node)
		{
			wxMenu* menu = (wxMenu*) node->GetData();
			if ( m_fileHistoryN == 0 && menu->GetMenuItemCount() )
			{
				menu->AppendSeparator();
			}
			menu->Append(GetBaseId()+m_fileHistoryN, _("[EMPTY]"));
			node = node->GetNext();
		}
		m_fileHistoryN ++;
	}
	// Shuffle items down
	for (i = (m_fileHistoryN-1); i > 0; i--)
	{
		m_fileHistory[i] = m_fileHistory[i-1];
	}
	m_fileHistory[0] = MYcopystring(item);

	for (i = 0; i < m_fileHistoryN; i++)
	{
		if ( m_fileHistory[i] )
		{
			wxString itemInMenu = m_fileHistory[i];

			// we need to quote '&' characters which are used for mnemonics
			itemInMenu.Replace(_T("&"), _T("&&"));
			wxString buf;
			buf.Printf(s_MRUEntryFormat, i + 1, itemInMenu.c_str());
			wxList::compatibility_iterator node = m_fileMenus.GetFirst();
			while (node)
			{
				wxMenu* menu = (wxMenu*) node->GetData();
				menu->SetLabel(GetBaseId() + i, buf);
				node = node->GetNext();
			}
		}
	}
}

} // namespace wxm
