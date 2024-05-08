
// MFCView.cpp : implementation of the CMFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC.h"
#endif

#include "MFCDoc.h"
#include "MFCView.h"
#include "createData.h"
#include "excelcrud.h"
#include "rekordview.h"
#include "lekerdezes1.h"
#include <string>
#include <afxstr.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CView)

BEGIN_MESSAGE_MAP(CMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CRUD_CREATE, &CMFCView::OnCrudCreate)
	ON_COMMAND(ID_CRUD_REKORDOK, &CMFCView::OnCrudRekordok)
	ON_COMMAND(ID_CRUD_FERFIAKLISTAZASA, &CMFCView::OnCrudFerfiaklistazasa)
	ON_COMMAND(ID_CRUD_NOKLISTAZASA, &CMFCView::OnCrudNoklistazasa)
END_MESSAGE_MAP()

// CMFCView construction/destruction

CMFCView::CMFCView() noexcept
{
	// TODO: add construction code here

}

CMFCView::~CMFCView()
{
}

BOOL CMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCView drawing

void CMFCView::OnDraw(CDC* pDC)
{
	CMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Font létrehozása
	CFont font;
	font.CreatePointFont(120, _T("Arial"), pDC);

	// Font beállítása
	CFont* def_font = pDC->SelectObject(&font);

	pDC->SetTextColor(RGB(0,0,0));
	pDC->SetBkMode(TRANSPARENT);

	// Szöveg kiírása
	CString text = _T("A felso menusavban a CRUD menuben talalhatoak a muveletek!");
	pDC->TextOut(30, 10, text);
	CString text2 = _T("A create-el uj user-t lehet felvinni");
	pDC->TextOut(30, 40, text2);
	CString text3 = _T("A rekordokkal pedig vegig lehet menni a user listan es lehet szerkeszteni/torolni a rekordokat");
	pDC->TextOut(30, 70, text3);
	CString text4 = _T("A ferfiak listazasa csak ferfiakat listazza ki");
	pDC->TextOut(30, 100, text4);
	CString text5 = _T("A nok listazasa pedig csak a noket");
	pDC->TextOut(30, 130, text5);

	// Visszaállítás eredeti font-ra
	pDC->SelectObject(def_font);

	// TODO: add draw code for native data here
}


// CMFCView printing


void CMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCView diagnostics

#ifdef _DEBUG
void CMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDoc* CMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDoc)));
	return (CMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCView message handlers


void CMFCView::OnCrudCreate()
{
	createData dlg;
	if (dlg.DoModal() == IDOK) 
	{
		name = dlg.nameEdit;
		email = dlg.emailEdit;
		nem = dlg.nem_value; 

		excelcrud eCrud;
		eCrud.InsertIntoAccess(name, email,nem);    
	}
	// TODO: Add your command handler code here
}


void CMFCView::OnCrudRekordok()
{
	rekordview dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}





void CMFCView::OnCrudFerfiaklistazasa()
{
	lekerdezes1 dlg;
	dlg.SetMaleUsers(true);    
	dlg.DoModal();
}

void CMFCView::OnCrudNoklistazasa()
{
	lekerdezes1 dlg;
	dlg.SetMaleUsers(false);
	dlg.DoModal();
}
