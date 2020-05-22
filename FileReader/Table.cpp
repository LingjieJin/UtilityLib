#include "Table.hpp"

#include <algorithm>
#include <memory>

using namespace table_t;

// 获取表名
string CTable::GetTableName()
{
    return this->m_strTableName;
}

// 获取表头
vector<string> &CTable::GetTableHeader()
{
    return this->m_vecHead;
}

// 获取表内容
vector<CRow> &CTable::GetTableContent()
{
    return this->m_vecContent;
}

// 获取表头的索引
int CTable::GetColumnIndex(const string &str)
{
    vector<string>::iterator it;
    it = std::find(m_vecHead.begin(), m_vecHead.end(), str);
    if (it != m_vecHead.end())
    {
        return std::distance(m_vecHead.begin(), it);
    }
}

// 获取行
CRow *CTable::GetRow(int row)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return NULL;

    return &this->m_vecContent[row];
}

// 获取列
vector<CCell>* CTable::GetColumn(int col)
{
    std::shared_ptr<vector<CCell>> pVec;
    
    pVec = std::make_shared<vector<CCell>>();

    if (col < 0 || col >= this->m_vecHead.size())
        return NULL;
    if(this->m_vecContent.size() <= 0)
        return NULL;



    return pVec.get();
}

// 获取单元格元素
CCell *CTable::GetCell(int row, int col)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return false;
    if (col < 0 || col >= this->m_vecHead.size())
        return false;

    return &this->m_vecContent[row].m_vecCells[col];
}

// 获取单元格值
CUniVariable *CTable::GetCellValue(int row, int col)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return false;
    if (col < 0 || col >= this->m_vecHead.size())
        return false;

    return &this->m_vecContent[row].m_vecCells[col].m_val;
}

//
// 修改表名
bool CTable::SetTableName(const string &tableName)
{
    this->m_strTableName = tableName;
    return true;
}

// 修改表头字段
bool CTable::SetTableHeaderString(int index, const string &headName)
{
    if (index < 0 || index >= this->m_vecHead.size())
        return false;
    this->m_vecHead[index] = headName;
    return true;
}

// 修改单元格
bool CTable::SetTableContent(int row, int col, const CCell &val)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return false;
    if (col < 0 || col >= this->m_vecHead.size())
        return false;

    this->m_vecContent[row].m_vecCells[col] = val;

    return true;
}

// 修改单元格值
bool CTable::SetTableContentValue(int row, int col, const CUniVariable &val)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return false;
    if (col < 0 || col >= this->m_vecHead.size())
        return false;

    this->m_vecContent[row].m_vecCells[col].m_val = val;

    return true;
}

bool CTable::SetTableContentValue(int row, int col, double val)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return false;
    if (col < 0 || col >= this->m_vecHead.size())
        return false;

    this->m_vecContent[row].m_vecCells[col].m_val.m_dVal = val;

    return true;
}

bool CTable::SetTableContentValue(int row, int col, const string &val)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return false;
    if (col < 0 || col >= this->m_vecHead.size())
        return false;

    this->m_vecContent[row].m_vecCells[col].m_val.m_strVal = val;

    return true;
}

//
// 删除指定行
int CTable::DelTableRow(int row)
{
    if (row < 0 || row >= this->m_vecContent.size())
        return NULL;

    this->m_vecContent.erase(this->m_vecContent.begin() + row);

    return true;
}