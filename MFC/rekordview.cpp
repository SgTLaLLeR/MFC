// rekordview.cpp : implementation file
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "rekordview.h"
#include "excelcrud.h"


// rekordview dialog

IMPLEMENT_DYNAMIC(rekordview, CDialog)

rekordview::rekordview(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, edit_name(_T(""))
	, edit_email(_T(""))

{
	excelcrud excelCrud;
	auto users = excelCrud.GetAllUsers();
	if (!users.empty())
	{
		const auto& firstUser = users[0];
		edit_name = firstUser.name;
		edit_email = firstUser.email;
		currentUserId = firstUser.id;
	}

}

rekordview::~rekordview()
{
}

void rekordview::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_name);
	DDX_Text(pDX, IDC_EDIT2, edit_email);
	DDX_Control(pDX, IDC_BUTTON4, prev);
	DDX_Control(pDX, IDC_BUTTON3, next);
}


BEGIN_MESSAGE_MAP(rekordview, CDialog)
	ON_BN_CLICKED(IDC_BUTTON4, &rekordview::Prev)
	ON_BN_CLICKED(IDC_BUTTON3, &rekordview::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &rekordview::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &rekordview::ModifyButton)
END_MESSAGE_MAP()


// rekordview message handlers


void rekordview::LoadData(int startPosition)
{
	excelcrud excelCrud;
	auto users = excelCrud.GetAllUsers();

	if (startPosition >= users.size() || startPosition < 0)
	{
		
		return;
	}

	const auto& user = users[startPosition];
	edit_name = user.name;
	edit_email = user.email;
	currentUserId = user.id;  
	UpdateData(FALSE); 
}

void rekordview::Prev()
{
	if (currentUserIndex > 0)
	{
		--currentUserIndex;
		LoadData(currentUserIndex);
	}
}


void rekordview::OnBnClickedButton3()
{
	{
		excelcrud excelCrud;
		auto users = excelCrud.GetAllUsers();
		if (currentUserIndex < (users.size() - 1))
		{
			++currentUserIndex;
			LoadData(currentUserIndex);
		}
	}
}


//törlés
void rekordview::OnBnClickedButton1()
{
	excelcrud excelCrud;
	excelCrud.DeleteUser(this->currentUserId);
	if(currentUserIndex > 0){
		--currentUserIndex;
	}
	LoadData(currentUserIndex);
	AfxMessageBox(_T("Sikeres torles"));
}


void rekordview::ModifyButton()
{
	UpdateData(TRUE);
	excelcrud excelCrud;
	excelCrud.UpdateAccess(currentUserId, edit_name, edit_email);
	LoadData(currentUserIndex);
	AfxMessageBox(_T("Sikeres adat modositas"));
}
