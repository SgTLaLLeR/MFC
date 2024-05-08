#pragma once
#include "afxdialogex.h"
#include "excelcrud.h"

// lekerdezes1 dialog

class lekerdezes1 : public CDialog
{
	DECLARE_DYNAMIC(lekerdezes1)

public:
	lekerdezes1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~lekerdezes1();

	CListCtrl lekerdezes1lista;

	void ListUsers(bool male);
	virtual BOOL OnInitDialog();
	void SetMaleUsers(bool male);

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void FillListControl(std::vector<User>& users);
	

	DECLARE_MESSAGE_MAP()

private:
	bool male;
};
