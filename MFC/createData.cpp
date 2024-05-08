// createData.cpp : implementation file
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "createData.h"


// createData dialog

IMPLEMENT_DYNAMIC(createData, CDialog)

createData::createData(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, nameEdit(_T(""))
	, emailEdit(_T(""))
	, nem_value(_T(""))
{

}

createData::~createData()
{
}

void createData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, nameEdit);
	DDX_Text(pDX, IDC_EDIT2, emailEdit);
	DDX_CBString(pDX, IDC_COMBO1, nem_value);
}



BEGIN_MESSAGE_MAP(createData, CDialog)
	ON_BN_CLICKED(IDCANCEL, &createData::OnBnClickedCancel)
END_MESSAGE_MAP()


// createData message handlers


void createData::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL createData::OnInitDialog() 
{
	CDialog::OnInitDialog(); // Call base class implementation

	// ComboBox with the ID IDC_COMBO1
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);

	// Add items to the ComboBox control
	pCombo->AddString(_T("Ferfi"));
	pCombo->AddString(_T("No"));

	return TRUE;
}
