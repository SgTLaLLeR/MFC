// lekerdezes1.cpp : implementation file
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "lekerdezes1.h"
#include <string>

// lekerdezes1 dialog

IMPLEMENT_DYNAMIC(lekerdezes1, CDialog)

lekerdezes1::lekerdezes1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
{

}

lekerdezes1::~lekerdezes1()
{
}

void lekerdezes1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, lekerdezes1lista);
}


BEGIN_MESSAGE_MAP(lekerdezes1, CDialog)

END_MESSAGE_MAP()
void lekerdezes1::SetMaleUsers(bool maleParam)
{
	male = maleParam;
}

BOOL lekerdezes1::OnInitDialog()
{
	CDialog::OnInitDialog();

	ListUsers(male);
	return TRUE;
}

// lekerdezes1 message handlers
void lekerdezes1::ListUsers(bool male)
{
	std::vector<User> users;
	excelcrud crud;
	if (male)
	{
		users = crud.GetMaleUsers();
	}
	else
	{
		users = crud.GetFemaleUsers();
	}
	FillListControl(users);
}

void lekerdezes1::FillListControl(std::vector<User>& users)
{
	lekerdezes1lista.DeleteAllItems();
	lekerdezes1lista.InsertColumn(0, _T("Nev"), LVCFMT_LEFT, 100);
	lekerdezes1lista.InsertColumn(1, _T("Email"), LVCFMT_LEFT, 150);

	for (int i = 0; i < users.size(); i++)
	{
		int index = lekerdezes1lista.InsertItem(LVIF_TEXT, i, users[i].name, 0, 0, 0, 0);
		lekerdezes1lista.SetItemText(index, 1, users[i].email);
	}
}