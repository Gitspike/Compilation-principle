#ifndef SymbolTable_HPP
#define SymbolTable_HPP

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "antlr4-runtime.h"
#include "PascalSParser.h"
#include <string>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;
// using namespace llvm;
struct Argument
{
    Argument(string name, string type, bool pass_value)
    {
        this->name = name;
        this->type = type;
        this->pass_value = pass_value;
    }
    string name;
    string type;
    string value;
    bool pass_value = false; //区分是传值还是引用，false为传值
    Argument(){};
};
struct record_elments //存放结构体元素
{
    string type = "";
    string value = "";
    llvm::AllocaInst *all = NULL;        //存放由LLVMAPI生成的变量地址
    int dimension = 0;                   //数组大小
    vector<string> array_item;           //如果变量是数组，则将其元素放入其中
    vector<llvm::AllocaInst *> all_item; //同上
};

typedef struct Table
{
    string name = "";
    string type = "";
    string value = "";
    // string parent = "";
    llvm::AllocaInst *all = NULL;        //存放由LLVMAPI生成的变量地址
    int dimension = 0;                   //数组大小
    vector<string> array_item;           //如果变量是数组，则将其元素放入其中
    vector<llvm::AllocaInst *> all_item; //同上

    PascalSParser::Program_bodyContext *ctx = NULL; //保存子程序的语义动作
    bool is_func = false;
    bool is_proc = false;
    bool is_const = false; // 判断该符号是否是常量
    bool is_type = false;  // 判断该符号是否是类型的别称
    bool is_record = false;

    map<string, record_elments> records; //保存结构体的内容
    int arguments_num = 0;
    string return_value = "";
    llvm::FunctionType *functiontype = NULL;
    llvm::Function *function = NULL;
    llvm::BasicBlock *block = NULL;
    // istd::unique_ptr<llvm::IRBuilder<>> builder;	// 符号的构造器指针
    // llvm::IRBuilder* build = NULL;
    vector<Argument> arguments; //存放子程序的参数

    Table() {}
    /* 变量 */
    Table(string name, string type, string value)
    {
        this->name = name;
        this->type = type;
        this->value = value;
    }
    Table(string name, string type)
    {
        this->name = name;
        this->type = type;
    }

    /* 函数或非变量 */
    Table(string name, string type, bool is_func, bool is_proc)
    {
        this->name = name;
        this->type = type;
        this->is_func = is_func;
        this->is_proc = is_proc;
    }
    void push_argument(Argument arg) //将参数加入符号表时调用
    {
        this->arguments.push_back(arg);
        this->arguments_num++;
    }
    bool push_record_elments(string name, record_elments re)//将结构体元素插入时使用
    {
        if (this->records.find(name) != this->records.end())
        {
            cout << "redeclaration of" << name << endl;
            return false;
        }
        else
        {
            this->records.insert(pair<string, record_elments>(name, re));
            return true;
        }
    }

} table;
class SymbolTable
{
private:
    vector<table> s_table; //充当符号表的栈
    vector<int> top_table; //存放函数块结束的位置
    int top = 0;           //索引表最上方的位置

public:
    table &get_top_table();                //参数表加入到子程序的符号表时使用，返回该子程序的结构体
    table &locate_table(string n);         //查找某个ID的结构体，需要检查返回的结构体中type是否为"err"，如果是则表示没有找到，该变量未声明
    void update_top_table();               //更新索引表
    void pop_table();                      //将一个子程序的符号退栈，退出函数时使用
    bool insert_table(table in_table);     //将符号入栈
    bool check_duplicates(table in_table); //被上面调用
    bool is_func(table in_table) { return in_table.is_func; };
    bool is_proc(table in_table) { return in_table.is_proc; };
    // void set_new_top();
    void pint_table();
    // records get_records_elment(string name);
};

#endif

// version 1.1
