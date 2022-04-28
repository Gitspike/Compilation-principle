#include "PascalSBaseListener.h"
#include "SymbolTable.hpp"

class  semanticsListener: public PascalSBaseListener {
public:
   //bool Assign(table &t);//赋值的函数
   void enterAssignop(PascalSParser::AssignopContext * ctx) override{};
   void exitAssignop(PascalSParser::AssignopContext * ctx) override{};

   void enterRelop(PascalSParser::RelopContext * ctx) override{};
   void exitRelop(PascalSParser::RelopContext * ctx) override{};

   void enterAddop(PascalSParser::AddopContext * ctx) override{};
   void exitAddop(PascalSParser::AddopContext * ctx) override{};

   void enterMulop(PascalSParser::MulopContext * ctx) override{};
   void exitMulop(PascalSParser::MulopContext * ctx) override{};

   void enterProgram(PascalSParser::ProgramContext * ctx) override;
   void exitProgram(PascalSParser::ProgramContext * ctx) override{};

   void enterProgram_head(PascalSParser::Program_headContext * ctx) override;
   void exitProgram_head(PascalSParser::Program_headContext * ctx) override{};

   void enterProgram_body(PascalSParser::Program_bodyContext * ctx) override;
   void exitProgram_body(PascalSParser::Program_bodyContext * ctx) override;

   void enterMultiMainArg(PascalSParser::MultiMainArgContext * ctx) override{};
   void exitMultiMainArg(PascalSParser::MultiMainArgContext * ctx) override{};

   void enterMainArg(PascalSParser::MainArgContext * ctx) override{};
   void exitMainArg(PascalSParser::MainArgContext * ctx) override{};

   void enterConst_declarations(PascalSParser::Const_declarationsContext * ctx) override{};
   void exitConst_declarations(PascalSParser::Const_declarationsContext * ctx) override{};

   void enterSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext * ctx) override;
   void exitSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext * ctx) override{};

   void enterMultiConstDeclaration(PascalSParser::MultiConstDeclarationContext * ctx) override{};
   void exitMultiConstDeclaration(PascalSParser::MultiConstDeclarationContext * ctx) override{};

   void enterPositiveId(PascalSParser::PositiveIdContext * ctx) override{};
   void exitPositiveId(PascalSParser::PositiveIdContext * ctx) override{};

   void enterNegativeId(PascalSParser::NegativeIdContext * ctx) override{};
   void exitNegativeId(PascalSParser::NegativeIdContext * ctx) override{};

   void enterPositiveNumber(PascalSParser::PositiveNumberContext * ctx) override{};
   void exitPositiveNumber(PascalSParser::PositiveNumberContext * ctx) override{};

   void enterNegativeNumber(PascalSParser::NegativeNumberContext * ctx) override{};
   void exitNegativeNumber(PascalSParser::NegativeNumberContext * ctx) override{};

   void enterConstChar(PascalSParser::ConstCharContext * ctx) override{};
   void exitConstChar(PascalSParser::ConstCharContext * ctx) override{};

   void enterType_declarations(PascalSParser::Type_declarationsContext * ctx) override{};
   void exitType_declarations(PascalSParser::Type_declarationsContext * ctx) override{};

   void enterMultiTypeDeclaration(PascalSParser::MultiTypeDeclarationContext * ctx) override{};
   void exitMultiTypeDeclaration(PascalSParser::MultiTypeDeclarationContext * ctx) override{};

   void enterSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext * ctx) override;
   void exitSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext * ctx) override;

   void enterType(PascalSParser::TypeContext * ctx) override{};
   void exitType(PascalSParser::TypeContext * ctx) override{};

   void enterStandard_type(PascalSParser::Standard_typeContext * ctx) override{};
   void exitStandard_type(PascalSParser::Standard_typeContext * ctx) override{};

   void enterRecord_body(PascalSParser::Record_bodyContext * ctx) override;
   void exitRecord_body(PascalSParser::Record_bodyContext * ctx) override;

   void enterSinglePeriod(PascalSParser::SinglePeriodContext * ctx) override{};
   void exitSinglePeriod(PascalSParser::SinglePeriodContext * ctx) override{};

   void enterMultiPeriod(PascalSParser::MultiPeriodContext * ctx) override{};
   void exitMultiPeriod(PascalSParser::MultiPeriodContext * ctx) override{};

   void enterPeriod(PascalSParser::PeriodContext * ctx) override{};
   void exitPeriod(PascalSParser::PeriodContext * ctx) override{};

   void enterVar_declarations(PascalSParser::Var_declarationsContext * ctx) override{};
   void exitVar_declarations(PascalSParser::Var_declarationsContext * ctx) override{};

   void enterSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext * ctx) override;
   void exitSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext * ctx) override{};

   void enterMultiVarDeclaration(PascalSParser::MultiVarDeclarationContext * ctx) override{};
   void exitMultiVarDeclaration(PascalSParser::MultiVarDeclarationContext * ctx) override{};

   void enterSubprogram_declarations(PascalSParser::Subprogram_declarationsContext * ctx) override{};
   void exitSubprogram_declarations(PascalSParser::Subprogram_declarationsContext * ctx) override{};

   void enterSubprogram_declaration(PascalSParser::Subprogram_declarationContext * ctx) override;
   void exitSubprogram_declaration(PascalSParser::Subprogram_declarationContext * ctx) override;

   void enterFunctionDeclaration(PascalSParser::FunctionDeclarationContext * ctx) override;
   void exitFunctionDeclaration(PascalSParser::FunctionDeclarationContext * ctx) override;

   void enterProcedureDeclaration(PascalSParser::ProcedureDeclarationContext * ctx) override;
   void exitProcedureDeclaration(PascalSParser::ProcedureDeclarationContext * ctx) override;

   void enterFormal_parameter(PascalSParser::Formal_parameterContext * ctx) override{};
   void exitFormal_parameter(PascalSParser::Formal_parameterContext * ctx) override{};

   void enterMultiPara(PascalSParser::MultiParaContext * ctx) override{};
   void exitMultiPara(PascalSParser::MultiParaContext * ctx) override{};

   void enterSinglePara(PascalSParser::SingleParaContext * ctx) override{};
   void exitSinglePara(PascalSParser::SingleParaContext * ctx) override{};

   void enterVarPara(PascalSParser::VarParaContext * ctx) override;
   void exitVarPara(PascalSParser::VarParaContext * ctx) override{};

   void enterValuePara(PascalSParser::ValueParaContext * ctx) override;
   void exitValuePara(PascalSParser::ValueParaContext * ctx) override{};

   void enterVar_parameter(PascalSParser::Var_parameterContext * ctx) override{};
   void exitVar_parameter(PascalSParser::Var_parameterContext * ctx) override{};

   void enterValue_parameter(PascalSParser::Value_parameterContext * ctx) override{};
   void exitValue_parameter(PascalSParser::Value_parameterContext * ctx) override{};

   void enterCompound_statement(PascalSParser::Compound_statementContext * ctx) override{};
   void exitCompound_statement(PascalSParser::Compound_statementContext * ctx) override{};

   void enterMultiStatement(PascalSParser::MultiStatementContext * ctx) override{};
   void exitMultiStatement(PascalSParser::MultiStatementContext * ctx) override{};

   void enterSingleStatement(PascalSParser::SingleStatementContext * ctx) override{};
   void exitSingleStatement(PascalSParser::SingleStatementContext * ctx) override{};

   void enterBlock(PascalSParser::BlockContext * ctx) override{};
   void exitBlock(PascalSParser::BlockContext * ctx) override{};

   void enterAssign(PascalSParser::AssignContext * ctx) override;
   void exitAssign(PascalSParser::AssignContext * ctx) override;

   void enterCall(PascalSParser::CallContext * ctx) override{};
   void exitCall(PascalSParser::CallContext * ctx) override{};

   void enterIf(PascalSParser::IfContext * ctx) override{};
   void exitIf(PascalSParser::IfContext * ctx) override{};

   void enterCase(PascalSParser::CaseContext * ctx) override{};
   void exitCase(PascalSParser::CaseContext * ctx) override{};

   void enterWhile(PascalSParser::WhileContext * ctx) override{};
   void exitWhile(PascalSParser::WhileContext * ctx) override{};

   void enterRepeat(PascalSParser::RepeatContext * ctx) override{};
   void exitRepeat(PascalSParser::RepeatContext * ctx) override{};

   void enterFor(PascalSParser::ForContext * ctx) override{};
   void exitFor(PascalSParser::ForContext * ctx) override{};

   void enterNone(PascalSParser::NoneContext * ctx) override{};
   void exitNone(PascalSParser::NoneContext * ctx) override{};

   void enterVariable(PascalSParser::VariableContext * ctx) override;
   void exitVariable(PascalSParser::VariableContext * ctx) override;

   void enterId_varparts(PascalSParser::Id_varpartsContext * ctx) override;
   void exitId_varparts(PascalSParser::Id_varpartsContext * ctx) override;

   void enterArrayAccess(PascalSParser::ArrayAccessContext * ctx) override;
   void exitArrayAccess(PascalSParser::ArrayAccessContext * ctx) override{};

   void enterRecordAccess(PascalSParser::RecordAccessContext * ctx) override;
   void exitRecordAccess(PascalSParser::RecordAccessContext * ctx) override{};

   void enterElse_part(PascalSParser::Else_partContext * ctx) override{};
   void exitElse_part(PascalSParser::Else_partContext * ctx) override{};

   void enterCase_body(PascalSParser::Case_bodyContext * ctx) override{};
   void exitCase_body(PascalSParser::Case_bodyContext * ctx) override{};

   void enterBranch_list(PascalSParser::Branch_listContext * ctx) override{};
   void exitBranch_list(PascalSParser::Branch_listContext * ctx) override{};

   void enterBranch(PascalSParser::BranchContext * ctx) override{};
   void exitBranch(PascalSParser::BranchContext * ctx) override{};

   void enterSingleConstList(PascalSParser::SingleConstListContext * ctx) override{};
   void exitSingleConstList(PascalSParser::SingleConstListContext * ctx) override{};

   void enterMultiConstList(PascalSParser::MultiConstListContext * ctx) override{};
   void exitMultiConstList(PascalSParser::MultiConstListContext * ctx) override{};

   void enterUpdown(PascalSParser::UpdownContext * ctx) override{};
   void exitUpdown(PascalSParser::UpdownContext * ctx) override{};

   void enterCallWithNoPara(PascalSParser::CallWithNoParaContext * ctx) override{};
   void exitCallWithNoPara(PascalSParser::CallWithNoParaContext * ctx) override{};

   void enterCallWithPara(PascalSParser::CallWithParaContext * ctx) override{};
   void exitCallWithPara(PascalSParser::CallWithParaContext * ctx) override{};

   void enterCallWriteln(PascalSParser::CallWritelnContext * ctx) override{};
   void exitCallWriteln(PascalSParser::CallWritelnContext * ctx) override{};

   void enterCallReadln(PascalSParser::CallReadlnContext * ctx) override{};
   void exitCallReadln(PascalSParser::CallReadlnContext * ctx) override{};

   void enterExpression_list(PascalSParser::Expression_listContext * ctx) override{};
   void exitExpression_list(PascalSParser::Expression_listContext * ctx) override{};

   void enterRelationOperation(PascalSParser::RelationOperationContext * ctx) override{};
   void exitRelationOperation(PascalSParser::RelationOperationContext * ctx) override{};

   void enterNoRalationOperation(PascalSParser::NoRalationOperationContext * ctx) override{};
   void exitNoRalationOperation(PascalSParser::NoRalationOperationContext * ctx) override{};

   void enterPositiveTerm(PascalSParser::PositiveTermContext * ctx) override{};
   void exitPositiveTerm(PascalSParser::PositiveTermContext * ctx) override{};

   void enterAddOperation(PascalSParser::AddOperationContext * ctx) override;
   void exitAddOperation(PascalSParser::AddOperationContext * ctx) override;

   void enterNegativeTerm(PascalSParser::NegativeTermContext * ctx) override{};
   void exitNegativeTerm(PascalSParser::NegativeTermContext * ctx) override{};

   void enterNoMultiplyOperation(PascalSParser::NoMultiplyOperationContext * ctx) override{};
   void exitNoMultiplyOperation(PascalSParser::NoMultiplyOperationContext * ctx) override{};

   void enterMultiplyOperation(PascalSParser::MultiplyOperationContext * ctx) override;
   void exitMultiplyOperation(PascalSParser::MultiplyOperationContext * ctx) override;

   void enterUnsignConst(PascalSParser::UnsignConstContext * ctx) override{};
   void exitUnsignConst(PascalSParser::UnsignConstContext * ctx) override{};

   void enterFactorVariable(PascalSParser::FactorVariableContext * ctx) override;
   void exitFactorVariable(PascalSParser::FactorVariableContext * ctx) override;

   void enterFactorReturn(PascalSParser::FactorReturnContext * ctx) override{};
   void exitFactorReturn(PascalSParser::FactorReturnContext * ctx) override{};

   void enterFactorPriority(PascalSParser::FactorPriorityContext * ctx) override{};
   void exitFactorPriority(PascalSParser::FactorPriorityContext * ctx) override{};

   void enterReverseFactor(PascalSParser::ReverseFactorContext * ctx) override{};
   void exitReverseFactor(PascalSParser::ReverseFactorContext * ctx) override;

   void enterUnsignConstId(PascalSParser::UnsignConstIdContext * ctx) override;
   void exitUnsignConstId(PascalSParser::UnsignConstIdContext * ctx) override{};

   void enterUnsignConstNumber(PascalSParser::UnsignConstNumberContext * ctx) override;
   void exitUnsignConstNumber(PascalSParser::UnsignConstNumberContext * ctx) override{};

   void enterUnsignConstChar(PascalSParser::UnsignConstCharContext * ctx) override;
   void exitUnsignConstChar(PascalSParser::UnsignConstCharContext * ctx) override{};


   void enterEveryRule(antlr4::ParserRuleContext * ctx) override{};
   void exitEveryRule(antlr4::ParserRuleContext * ctx) override{};
   void visitTerminal(antlr4::tree::TerminalNode * node) override{};
   void visitErrorNode(antlr4::tree::ErrorNode * node) override{};

   

};

