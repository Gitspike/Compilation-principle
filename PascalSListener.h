
// Generated from PascalS.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PascalSParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PascalSParser.
 */
class  PascalSListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAssignop(PascalSParser::AssignopContext *ctx) = 0;
  virtual void exitAssignop(PascalSParser::AssignopContext *ctx) = 0;

  virtual void enterRelop(PascalSParser::RelopContext *ctx) = 0;
  virtual void exitRelop(PascalSParser::RelopContext *ctx) = 0;

  virtual void enterAddop(PascalSParser::AddopContext *ctx) = 0;
  virtual void exitAddop(PascalSParser::AddopContext *ctx) = 0;

  virtual void enterMulop(PascalSParser::MulopContext *ctx) = 0;
  virtual void exitMulop(PascalSParser::MulopContext *ctx) = 0;

  virtual void enterProgram(PascalSParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(PascalSParser::ProgramContext *ctx) = 0;

  virtual void enterProgram_head(PascalSParser::Program_headContext *ctx) = 0;
  virtual void exitProgram_head(PascalSParser::Program_headContext *ctx) = 0;

  virtual void enterProgram_body(PascalSParser::Program_bodyContext *ctx) = 0;
  virtual void exitProgram_body(PascalSParser::Program_bodyContext *ctx) = 0;

  virtual void enterMultiMainArg(PascalSParser::MultiMainArgContext *ctx) = 0;
  virtual void exitMultiMainArg(PascalSParser::MultiMainArgContext *ctx) = 0;

  virtual void enterMainArg(PascalSParser::MainArgContext *ctx) = 0;
  virtual void exitMainArg(PascalSParser::MainArgContext *ctx) = 0;

  virtual void enterConst_declarations(PascalSParser::Const_declarationsContext *ctx) = 0;
  virtual void exitConst_declarations(PascalSParser::Const_declarationsContext *ctx) = 0;

  virtual void enterSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext *ctx) = 0;
  virtual void exitSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext *ctx) = 0;

  virtual void enterMultiConstDeclaration(PascalSParser::MultiConstDeclarationContext *ctx) = 0;
  virtual void exitMultiConstDeclaration(PascalSParser::MultiConstDeclarationContext *ctx) = 0;

  virtual void enterPositiveId(PascalSParser::PositiveIdContext *ctx) = 0;
  virtual void exitPositiveId(PascalSParser::PositiveIdContext *ctx) = 0;

  virtual void enterNegativeId(PascalSParser::NegativeIdContext *ctx) = 0;
  virtual void exitNegativeId(PascalSParser::NegativeIdContext *ctx) = 0;

  virtual void enterPositiveNumber(PascalSParser::PositiveNumberContext *ctx) = 0;
  virtual void exitPositiveNumber(PascalSParser::PositiveNumberContext *ctx) = 0;

  virtual void enterNegativeNumber(PascalSParser::NegativeNumberContext *ctx) = 0;
  virtual void exitNegativeNumber(PascalSParser::NegativeNumberContext *ctx) = 0;

  virtual void enterConstChar(PascalSParser::ConstCharContext *ctx) = 0;
  virtual void exitConstChar(PascalSParser::ConstCharContext *ctx) = 0;

  virtual void enterType_declarations(PascalSParser::Type_declarationsContext *ctx) = 0;
  virtual void exitType_declarations(PascalSParser::Type_declarationsContext *ctx) = 0;

  virtual void enterMultiTypeDeclaration(PascalSParser::MultiTypeDeclarationContext *ctx) = 0;
  virtual void exitMultiTypeDeclaration(PascalSParser::MultiTypeDeclarationContext *ctx) = 0;

  virtual void enterSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx) = 0;
  virtual void exitSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx) = 0;

  virtual void enterType(PascalSParser::TypeContext *ctx) = 0;
  virtual void exitType(PascalSParser::TypeContext *ctx) = 0;

  virtual void enterStandard_type(PascalSParser::Standard_typeContext *ctx) = 0;
  virtual void exitStandard_type(PascalSParser::Standard_typeContext *ctx) = 0;

  virtual void enterRecord_body(PascalSParser::Record_bodyContext *ctx) = 0;
  virtual void exitRecord_body(PascalSParser::Record_bodyContext *ctx) = 0;

  virtual void enterSinglePeriod(PascalSParser::SinglePeriodContext *ctx) = 0;
  virtual void exitSinglePeriod(PascalSParser::SinglePeriodContext *ctx) = 0;

  virtual void enterMultiPeriod(PascalSParser::MultiPeriodContext *ctx) = 0;
  virtual void exitMultiPeriod(PascalSParser::MultiPeriodContext *ctx) = 0;

  virtual void enterPeriod(PascalSParser::PeriodContext *ctx) = 0;
  virtual void exitPeriod(PascalSParser::PeriodContext *ctx) = 0;

  virtual void enterVar_declarations(PascalSParser::Var_declarationsContext *ctx) = 0;
  virtual void exitVar_declarations(PascalSParser::Var_declarationsContext *ctx) = 0;

  virtual void enterSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext *ctx) = 0;
  virtual void exitSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext *ctx) = 0;

  virtual void enterMultiVarDeclaration(PascalSParser::MultiVarDeclarationContext *ctx) = 0;
  virtual void exitMultiVarDeclaration(PascalSParser::MultiVarDeclarationContext *ctx) = 0;

  virtual void enterSubprogram_declarations(PascalSParser::Subprogram_declarationsContext *ctx) = 0;
  virtual void exitSubprogram_declarations(PascalSParser::Subprogram_declarationsContext *ctx) = 0;

  virtual void enterSubprogram_declaration(PascalSParser::Subprogram_declarationContext *ctx) = 0;
  virtual void exitSubprogram_declaration(PascalSParser::Subprogram_declarationContext *ctx) = 0;

  virtual void enterFunctionDeclaration(PascalSParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(PascalSParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterProcedureDeclaration(PascalSParser::ProcedureDeclarationContext *ctx) = 0;
  virtual void exitProcedureDeclaration(PascalSParser::ProcedureDeclarationContext *ctx) = 0;

  virtual void enterFormal_parameter(PascalSParser::Formal_parameterContext *ctx) = 0;
  virtual void exitFormal_parameter(PascalSParser::Formal_parameterContext *ctx) = 0;

  virtual void enterMultiPara(PascalSParser::MultiParaContext *ctx) = 0;
  virtual void exitMultiPara(PascalSParser::MultiParaContext *ctx) = 0;

  virtual void enterSinglePara(PascalSParser::SingleParaContext *ctx) = 0;
  virtual void exitSinglePara(PascalSParser::SingleParaContext *ctx) = 0;

  virtual void enterVarPara(PascalSParser::VarParaContext *ctx) = 0;
  virtual void exitVarPara(PascalSParser::VarParaContext *ctx) = 0;

  virtual void enterValuePara(PascalSParser::ValueParaContext *ctx) = 0;
  virtual void exitValuePara(PascalSParser::ValueParaContext *ctx) = 0;

  virtual void enterVar_parameter(PascalSParser::Var_parameterContext *ctx) = 0;
  virtual void exitVar_parameter(PascalSParser::Var_parameterContext *ctx) = 0;

  virtual void enterValue_parameter(PascalSParser::Value_parameterContext *ctx) = 0;
  virtual void exitValue_parameter(PascalSParser::Value_parameterContext *ctx) = 0;

  virtual void enterCompound_statement(PascalSParser::Compound_statementContext *ctx) = 0;
  virtual void exitCompound_statement(PascalSParser::Compound_statementContext *ctx) = 0;

  virtual void enterMultiStatement(PascalSParser::MultiStatementContext *ctx) = 0;
  virtual void exitMultiStatement(PascalSParser::MultiStatementContext *ctx) = 0;

  virtual void enterSingleStatement(PascalSParser::SingleStatementContext *ctx) = 0;
  virtual void exitSingleStatement(PascalSParser::SingleStatementContext *ctx) = 0;

  virtual void enterBlock(PascalSParser::BlockContext *ctx) = 0;
  virtual void exitBlock(PascalSParser::BlockContext *ctx) = 0;

  virtual void enterAssign(PascalSParser::AssignContext *ctx) = 0;
  virtual void exitAssign(PascalSParser::AssignContext *ctx) = 0;

  virtual void enterCall(PascalSParser::CallContext *ctx) = 0;
  virtual void exitCall(PascalSParser::CallContext *ctx) = 0;

  virtual void enterIf(PascalSParser::IfContext *ctx) = 0;
  virtual void exitIf(PascalSParser::IfContext *ctx) = 0;

  virtual void enterCase(PascalSParser::CaseContext *ctx) = 0;
  virtual void exitCase(PascalSParser::CaseContext *ctx) = 0;

  virtual void enterWhile(PascalSParser::WhileContext *ctx) = 0;
  virtual void exitWhile(PascalSParser::WhileContext *ctx) = 0;

  virtual void enterRepeat(PascalSParser::RepeatContext *ctx) = 0;
  virtual void exitRepeat(PascalSParser::RepeatContext *ctx) = 0;

  virtual void enterFor(PascalSParser::ForContext *ctx) = 0;
  virtual void exitFor(PascalSParser::ForContext *ctx) = 0;

  virtual void enterNone(PascalSParser::NoneContext *ctx) = 0;
  virtual void exitNone(PascalSParser::NoneContext *ctx) = 0;

  virtual void enterWhile_condition(PascalSParser::While_conditionContext *ctx) = 0;
  virtual void exitWhile_condition(PascalSParser::While_conditionContext *ctx) = 0;

  virtual void enterWhile_body(PascalSParser::While_bodyContext *ctx) = 0;
  virtual void exitWhile_body(PascalSParser::While_bodyContext *ctx) = 0;

  virtual void enterVariable(PascalSParser::VariableContext *ctx) = 0;
  virtual void exitVariable(PascalSParser::VariableContext *ctx) = 0;

  virtual void enterId_varparts(PascalSParser::Id_varpartsContext *ctx) = 0;
  virtual void exitId_varparts(PascalSParser::Id_varpartsContext *ctx) = 0;

  virtual void enterArrayAccess(PascalSParser::ArrayAccessContext *ctx) = 0;
  virtual void exitArrayAccess(PascalSParser::ArrayAccessContext *ctx) = 0;

  virtual void enterRecordAccess(PascalSParser::RecordAccessContext *ctx) = 0;
  virtual void exitRecordAccess(PascalSParser::RecordAccessContext *ctx) = 0;

  virtual void enterElse_part(PascalSParser::Else_partContext *ctx) = 0;
  virtual void exitElse_part(PascalSParser::Else_partContext *ctx) = 0;

  virtual void enterThen_statement(PascalSParser::Then_statementContext *ctx) = 0;
  virtual void exitThen_statement(PascalSParser::Then_statementContext *ctx) = 0;

  virtual void enterIf_condition(PascalSParser::If_conditionContext *ctx) = 0;
  virtual void exitIf_condition(PascalSParser::If_conditionContext *ctx) = 0;

  virtual void enterCase_body(PascalSParser::Case_bodyContext *ctx) = 0;
  virtual void exitCase_body(PascalSParser::Case_bodyContext *ctx) = 0;

  virtual void enterBranch_list(PascalSParser::Branch_listContext *ctx) = 0;
  virtual void exitBranch_list(PascalSParser::Branch_listContext *ctx) = 0;

  virtual void enterBranch(PascalSParser::BranchContext *ctx) = 0;
  virtual void exitBranch(PascalSParser::BranchContext *ctx) = 0;

  virtual void enterSingleConstList(PascalSParser::SingleConstListContext *ctx) = 0;
  virtual void exitSingleConstList(PascalSParser::SingleConstListContext *ctx) = 0;

  virtual void enterMultiConstList(PascalSParser::MultiConstListContext *ctx) = 0;
  virtual void exitMultiConstList(PascalSParser::MultiConstListContext *ctx) = 0;

  virtual void enterUpdown(PascalSParser::UpdownContext *ctx) = 0;
  virtual void exitUpdown(PascalSParser::UpdownContext *ctx) = 0;

  virtual void enterCallWithNoPara(PascalSParser::CallWithNoParaContext *ctx) = 0;
  virtual void exitCallWithNoPara(PascalSParser::CallWithNoParaContext *ctx) = 0;

  virtual void enterCallWithPara(PascalSParser::CallWithParaContext *ctx) = 0;
  virtual void exitCallWithPara(PascalSParser::CallWithParaContext *ctx) = 0;

  virtual void enterCallWriteln(PascalSParser::CallWritelnContext *ctx) = 0;
  virtual void exitCallWriteln(PascalSParser::CallWritelnContext *ctx) = 0;

  virtual void enterCallReadln(PascalSParser::CallReadlnContext *ctx) = 0;
  virtual void exitCallReadln(PascalSParser::CallReadlnContext *ctx) = 0;

  virtual void enterExpression_list(PascalSParser::Expression_listContext *ctx) = 0;
  virtual void exitExpression_list(PascalSParser::Expression_listContext *ctx) = 0;

  virtual void enterRelationOperation(PascalSParser::RelationOperationContext *ctx) = 0;
  virtual void exitRelationOperation(PascalSParser::RelationOperationContext *ctx) = 0;

  virtual void enterNoRalationOperation(PascalSParser::NoRalationOperationContext *ctx) = 0;
  virtual void exitNoRalationOperation(PascalSParser::NoRalationOperationContext *ctx) = 0;

  virtual void enterPositiveTerm(PascalSParser::PositiveTermContext *ctx) = 0;
  virtual void exitPositiveTerm(PascalSParser::PositiveTermContext *ctx) = 0;

  virtual void enterAddOperation(PascalSParser::AddOperationContext *ctx) = 0;
  virtual void exitAddOperation(PascalSParser::AddOperationContext *ctx) = 0;

  virtual void enterNegativeTerm(PascalSParser::NegativeTermContext *ctx) = 0;
  virtual void exitNegativeTerm(PascalSParser::NegativeTermContext *ctx) = 0;

  virtual void enterNoMultiplyOperation(PascalSParser::NoMultiplyOperationContext *ctx) = 0;
  virtual void exitNoMultiplyOperation(PascalSParser::NoMultiplyOperationContext *ctx) = 0;

  virtual void enterMultiplyOperation(PascalSParser::MultiplyOperationContext *ctx) = 0;
  virtual void exitMultiplyOperation(PascalSParser::MultiplyOperationContext *ctx) = 0;

  virtual void enterUnsignConst(PascalSParser::UnsignConstContext *ctx) = 0;
  virtual void exitUnsignConst(PascalSParser::UnsignConstContext *ctx) = 0;

  virtual void enterFactorVariable(PascalSParser::FactorVariableContext *ctx) = 0;
  virtual void exitFactorVariable(PascalSParser::FactorVariableContext *ctx) = 0;

  virtual void enterFactorReturn(PascalSParser::FactorReturnContext *ctx) = 0;
  virtual void exitFactorReturn(PascalSParser::FactorReturnContext *ctx) = 0;

  virtual void enterFactorPriority(PascalSParser::FactorPriorityContext *ctx) = 0;
  virtual void exitFactorPriority(PascalSParser::FactorPriorityContext *ctx) = 0;

  virtual void enterReverseFactor(PascalSParser::ReverseFactorContext *ctx) = 0;
  virtual void exitReverseFactor(PascalSParser::ReverseFactorContext *ctx) = 0;

  virtual void enterUnsignConstId(PascalSParser::UnsignConstIdContext *ctx) = 0;
  virtual void exitUnsignConstId(PascalSParser::UnsignConstIdContext *ctx) = 0;

  virtual void enterUnsignConstNumber(PascalSParser::UnsignConstNumberContext *ctx) = 0;
  virtual void exitUnsignConstNumber(PascalSParser::UnsignConstNumberContext *ctx) = 0;

  virtual void enterUnsignConstChar(PascalSParser::UnsignConstCharContext *ctx) = 0;
  virtual void exitUnsignConstChar(PascalSParser::UnsignConstCharContext *ctx) = 0;


};

