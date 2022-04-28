#include "SymbolTable.hpp"

void SymbolTable::update_top_table()
{
    this->top_table.push_back(this->s_table.size());
    this->top++;
}
bool SymbolTable::insert_table(table in_table)
{
    if (this->check_duplicates(in_table))
    {
        this->s_table.push_back(in_table);
        return true;
    }

    /* if (this->check_duplicates(in_table))
    {
        this->s_table.push_back(in_table);
        string p1 =in_table.parent;
        string p2=this->s_table[this->s_table.size()-2].parent;
        /* 进入新的子程序块 */
    /* if(p1!=p2)
    {
        this->top_table.push_back(this->s_table.size()-1);
        this->top++;
    }
    return true;

}*/
    else
    {
        cout << "redeclaration of " << in_table.name << endl;
        return false;
    }
}

bool SymbolTable::check_duplicates(table in_table)
{
    string id_name = in_table.name;
    if (0 == this->s_table.size())
    {
        this->top_table.push_back(0);
        return true;
    }
    int stack_top = this->s_table.size() - 1;
    int stack_bot = this->top_table[this->top];
    for (int i = stack_top; i >= stack_bot; i--)
    {
        if (this->s_table[i].name == id_name)
            return false;
    }
    return true;
}

/* void SymbolTable::set_new_top()
{
    int stack_top=this->s_table.size()-1;
    this->top++;
} */
void SymbolTable::pop_table()
{
    int end = this->top_table[this->top];
    int start = this->s_table.size() - 1;
    for (int i = start; i >= end; i--)
    {
        this->s_table.pop_back();
    }
    this->top--;
    this->top_table.pop_back();
}
table &SymbolTable::locate_table(string n)
{
    int start = this->s_table.size() - 1;
    for (int i = start; i >= 0; i--)
    {
        if (this->s_table[i].is_func || this->s_table[i].is_proc)
        {
            if(n==this->s_table[i].name)
                return s_table[i];
            for (int j = 0; j < this->s_table[i].arguments_num; j++)
            {
                if (this->s_table[i].arguments[j].name == n && this->s_table[i].arguments[j].pass_value)
                {
                    this->s_table[i].is_arg=true;
                    return this->s_table[i];
                }
            }
        }
        else if (this->s_table[i].name == n)
            return s_table[i];
    }
    string err = "err";
    this->s_table[0].type = err;
    return s_table[0];
}
void SymbolTable::pint_table()
{

    int start = this->s_table.size() - 1;
    for (int i = 0; i <= start; i++)
    {
        cout << "name: " << this->s_table[i].name
             << "  type: " << this->s_table[i].type
             <<"   value: "<<this->s_table[i].value
             << endl;
    }
}
table &SymbolTable::get_top_table()
{
    return this->s_table[this->s_table.size() - 1];
}
table &SymbolTable::get_var_table(int l)
{
    return this->s_table[l];
}

/* record_elments SymbolTable::get_records_elment(string name)
{
    if(this->s_table[this->s_table.size()-1].records.size()==0)
    {
        cout<<"err"<<endl;
    }
    if(this->s_table[this->s_table.size()-1].records.find(name)!=this->s_table[this->s_table.size()-1].records.end())
    {
        return (this->s_table[this->s_table.size()-1].records[name];
    }
} */
