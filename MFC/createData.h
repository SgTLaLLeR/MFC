#pragma once
#include "afxdialogex.h"


// createData dialog

class createData : public CDialog
{
	DECLARE_DYNAMIC(createData)

public:
	createData(CWnd* pParent = nullptr);   // standard constructor
	virtual ~createData();
	BOOL createData::OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString nameEdit;
	CString emailEdit;
	afx_msg void OnBnClickedCancel();
	CString nem_value;
};
