#pragma once
#include "afxdialogex.h"


// rekordview dialog

class rekordview : public CDialog
{
	DECLARE_DYNAMIC(rekordview)
	int currentUserIndex = 0;
	CButton prev; // Add this line
	CButton next; // Add this line

public:
	rekordview(CWnd* pParent = nullptr);   // standard constructor
	virtual ~rekordview();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void rekordview::LoadData(int startPosition);

	DECLARE_MESSAGE_MAP()
public:
	CString edit_name;
	CString edit_email;
	afx_msg void Prev();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void ModifyButton();
	int currentUserId;
};
