#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

namespace table_t
{

    class CUniVariable
    {
    public:
        int type;
        double m_dVal;
        string m_strVal;

    public:
        CUniVariable() {}
        ~CUniVariable() {}

        void setValue(const double &val)
        {
            m_dVal = val;
        }

        void setValue(const string &val)
        {
            m_strVal = val;
        }

        void setValue(const string &val, int type);

        /* 效率高 */
        int getStringValueType(const char *val, int size)
        {
        }

        int getStringValueType(const string &val)
        {
            /* 1. 比较慢 */
            std::stringstream sin(val);
            double t;
            char p;
            if (!(sin >> t))
                return false;
            else
                return true;

            /* 2. 稍微快 */
            /*
            for (int i = 0; i < val.size(); i++)
            {
                char tmp = val[i];
                if (tmp >= '0' && tmp <= '9' || tmp == '.')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
            */

        }
    };

    class CCell
    {
    public:
        CUniVariable m_val;

    public:
        CCell() {}
        ~CCell() {}
    };

    class CRow
    {
    public:
        vector<CCell> m_vecCells;
    public:
        CRow(){}
        ~CRow(){}
    };

    class CTable
    {
    public:
        // table name
        string m_strTableName;
        // head
        bool hasHeader;
        vector<string> m_vecHead;
        // content
        vector<CRow> m_vecContent;
    public:
        CTable(){}
        ~CTable(){}
        /* 
        表格函数功能函数
        */
        // 获取表名
        string GetTableName();
        // 获取表头
        vector<string>& GetTableHeader();
        // 获取表内容
        vector<CRow>& GetTableContent();
        // 获取表头的索引
        int GetColumnIndex(const string &str);
        // 获取行
        CRow* GetRow(int row);
        // 获取列
        vector<CCell>* GetColumn(int col);
        // 获取单元格元素
        CCell* GetCell(int row, int col);
        // 获取单元格值
        CUniVariable* GetCellValue(int row, int col);
        //
        // 修改表名
        bool SetTableName(const string& tableName);
        // 修改表头字段
        bool SetTableHeaderString(int index, const string& headName);
        // 修改单元格
        bool SetTableContent(int row, int col, const CCell& val);
        // 修改单元格值
        bool SetTableContentValue(int row, int col, const CUniVariable& val);
        bool SetTableContentValue(int row, int col, double val);
        bool SetTableContentValue(int row, int col, const string& val);
        //
        // 删除指定行
        int DelTableRow(int row);
    };

} // namespace table_t

#endif