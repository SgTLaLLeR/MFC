#include "pch.h"
#include "excelcrud.h"
#include <afxdb.h> 
#include <vector>

excelcrud::excelcrud()
{
    CString sDriver = _T("Microsoft Access Driver (*.mdb, *.accdb)");
    CString sAccessFile = _T("E:\\db.accdb");
    CString sConn;

    sConn.Format(_T("DRIVER={" + sDriver + "};DBQ=" + sAccessFile));

    if (db_.OpenEx(sConn, CDatabase::noOdbcDialog))
    {
        // Connected
    }
}
excelcrud::~excelcrud()
{
    if (db_.IsOpen())
    {
        db_.Close();
    }
}

void excelcrud::InsertIntoAccess(const CString& name, const CString& email, const CString& nem)
{
    CString sSql;
    sSql.Format(_T("INSERT INTO users (Nev, Email, Nem) VALUES ('%s', '%s', '%s')"), name.GetString(), email.GetString(), nem.GetString());

    db_.ExecuteSQL(sSql);
}

std::vector<User> excelcrud::GetAllUsers()
{
    std::vector<User> users;

    CRecordset rs(&db_);
    CString sSql = _T("SELECT [Id], [Nev], [Email] FROM users");
    if (rs.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly))
    {
        while (!rs.IsEOF())
        {
            User user;
            CDBVariant varValue;

            rs.GetFieldValue((short)0, varValue);
            user.id = varValue.m_iVal;

            rs.GetFieldValue((short)1, user.name);
            rs.GetFieldValue((short)2, user.email);
            users.push_back(user);
            rs.MoveNext();
        }

        rs.Close();
    }

    return users;
}

void excelcrud::DeleteUser(int id)
{
    CString sSql;
    sSql.Format(_T("DELETE FROM users WHERE id=%d"), id);
    db_.ExecuteSQL(sSql);
}

void excelcrud::UpdateAccess(int id, const CString& name, const CString& email)
{
    CString sSql;
    sSql.Format(_T("UPDATE users SET Nev = '%s', Email = '%s' WHERE ID = %d"), name.GetString(), email.GetString(), id);
    db_.ExecuteSQL(sSql);
}


std::vector<User> excelcrud::GetMaleUsers()
{
    std::vector<User> users;

    CRecordset rs(&db_);
    CString sSql = _T("SELECT [Nev], [Email] FROM users WHERE Nem = 'Ferfi'");
    if (rs.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly))
    {
        while (!rs.IsEOF())
        {
            User user;
    
            rs.GetFieldValue((short)0, user.name);
            rs.GetFieldValue((short)1, user.email);
            users.push_back(user);
            rs.MoveNext();
        }

        rs.Close();
    }
    return users;
}

std::vector<User> excelcrud::GetFemaleUsers()
{
    std::vector<User> users;

    CRecordset rs(&db_);
    CString sSql = _T("SELECT [id], [Nev], [Email] FROM users WHERE Nem = 'No'");
    if (rs.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly))
    {
        while (!rs.IsEOF())
        {
            User user;
            CDBVariant varValue;
    
            rs.GetFieldValue((short)0, varValue);
            user.id = varValue.m_iVal;
            rs.GetFieldValue((short)1, user.name);
            rs.GetFieldValue((short)2, user.email);
            
            users.push_back(user);
            rs.MoveNext();
        }
    }
    return users;
}

