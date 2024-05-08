#pragma once

#include <afxdb.h>
#include <vector>
#include <string>

// User struct definition
struct User {
    CString name;
    CString email;
    int id;
    CString nem;
};

class excelcrud
{
public:
    void excelcrud::InsertIntoAccess(const CString& name, const CString& email, const CString& nem);
    std::vector<User> GetAllUsers();
    void excelcrud::DeleteUser(int id);
    void excelcrud::UpdateAccess(int id, const CString& name, const CString& email);
    std::vector<User> excelcrud::GetMaleUsers();
    std::vector<User> excelcrud::GetFemaleUsers();
    excelcrud();
    ~excelcrud();
private:
    CDatabase db_;

};