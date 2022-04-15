
// Generated from PascalS.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PascalSListener.h"


/**
 * This class provides an empty implementation of PascalSListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PascalSBaseListener : public PascalSListener {
public:

  virtual void enterAssignop(PascalSParser::AssignopContext * /*ctx*/) override { }
  virtual void exitAssignop(PascalSParser::AssignopContext * /*ctx*/) override { }

  virtual void enterRelop(PascalSParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(PascalSParser::RelopContext * /*ctx*/) override { }

  virtual void enterAddop(PascalSParser::AddopContext * /*ctx*/) override { }
  virtual void exitAddop(PascalSParser::AddopContext * /*ctx*/) override { }

  virtual void enterMulop(PascalSParser::MulopContext * /*ctx*/) override { }
  virtual void exitMulop(PascalSParser::MulopContext * /*ctx*/) override { }

  virtual void enterProgram(PascalSParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(PascalSParser::ProgramContext * /*ctx*/) override { }

  virtual void enterProgram_head(PascalSParser::Program_headContext * /*ctx*/) override { }
  virtual void exitProgram_head(PascalSParser::Program_headContext * /*ctx*/) override { }

  virtual void enterProgram_body(PascalSParser::Program_bodyContext * /*ctx*/) override { }
  virtual void exitProgram_body(PascalSParser::Program_bodyContext * /*ctx*/) override { }

  virtual void enterMultiMainArg(PascalSParser::MultiMainArgContext * /*ctx*/) override { }
  virtual void exitMultiMainArg(PascalSParser::MultiMainArgContext * /*ctx*/) override { }

  virtual void enterMainArg(PascalSParser::MainArgContext * /*ctx*/) override { }
  virtual void exitMainArg(PascalSParser::MainArgContext * /*ctx*/) override { }

  virtual void enterConst_declarations(PascalSParser::Const_declarationsContext * /*ctx*/) override { }
  virtual void exitConst_declarations(PascalSParser::Const_declarationsContext * /*ctx*/) override { }

  virtual void enterSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext * /*ctx*/) override { }
  virtual void exitSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext * /*ctx*/) override { }

  virtual void enterMultiConstDeclaration(PascalSParser::MultiConstDeclarationContext * /*ctx*/) override { }
  virtual void exitMultiConstDeclaration(PascalSParser::MultiConstDeclarationContext * /*ctx*/) override { }

  virtual void enterPositiveId(PascalSParser::PositiveIdContext * /*ctx*/) override { }
  virtual void exitPositiveId(PascalSParser::PositiveIdContext * /*ctx*/) override { }

  virtual void enterNegativeId(PascalSParser::NegativeIdContext * /*ctx*/) override { }
  virtual void exitNegativeId(PascalSParser::NegativeIdContext * /*ctx*/) override { }

  virtual void enterPositiveNumber(PascalSParser::PositiveNumberContext * /*ctx*/) override { }
  virtual void exitPositiveNumber(PascalSParser::PositiveNumberContext * /*ctx*/) override { }

  virtual void enterNegativeNumber(PascalSParser::NegativeNumberContext * /*ctx*/) override { }
  virtual void exitNegativeNumber(PascalSParser::NegativeNumberContext * /*ctx*/) override { }

  virtual void enterConstChar(PascalSParser::ConstCharContext * /*ctx*/) override { }
  virtual void exitConstChar(PascalSParser::ConstCharContext * /*ctx*/) override { }

  virtual void enterType_declarations(PascalSParser::Type_declarationsContext * /*ctx*/) override { }
  virtual void exitType_declarations(PascalSParser::Type_declarationsContext * /*ctx*/) override { }

  virtual void enterMultiTypeDeclaration(PascalSParser::MultiTypeDeclarationContext * /*ctx*/) override { }
  virtual void exitMultiTypeDeclaration(PascalSParser::MultiTypeDeclarationContext * /*ctx*/) override { }

  virtual void enterSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext * /*ctx*/) override { }
  virtual void exitSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext * /*ctx*/) override { }

  virtual void enterType(PascalSParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(PascalSParser::TypeContext * /*ctx*/) override { }

  virtual void enterStandard_type(PascalSParser::Standard_typeContext * /*ctx*/) override { }
  virtual void exitStandard_type(PascalSParser::Standard_typeContext * /*ctx*/) override { }

  virtual void enterRecord_body(PascalSParser::Record_bodyContext * /*ctx*/) override { }
  virtual void exitRecord_body(PascalSParser::Record_bodyContext * /*ctx*/) override { }

  virtual void enterSinglePeriod(PascalSParser::SinglePeriodContext * /*ctx*/) override { }
  virtual void exitSinglePeriod(PascalSParser::SinglePeriodContext * /*ctx*/) override { }

  virtual void enterMultiPeriod(PascalSParser::MultiPeriodContext * /*ctx*/) override { }
  virtual void exitMultiPeriod(PascalSParser::MultiPeriodContext * /*ctx*/) override { }

  virtual void enterPeriod(PascalSParser::PeriodContext * /*ctx*/) override { }
  virtual void exitPeriod(PascalSParser::PeriodContext * /*ctx*/) override { }

  virtual void enterVar_declarations(PascalSParser::Var_declarationsContext * /*ctx*/) override { }
  virtual void exitVar_declarations(PascalSParser::Var_declarationsContext * /*ctx*/) override { }

  virtual void enterSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext * /*ctx*/) override { }
  virtual void exitSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext * /*ctx*/) override { }

  virtual void enterMultiVarDeclaration(PascalSParser::MultiVarDeclarationContext * /*ctx*/) override { }
  virtual void exitMultiVarDeclaration(PascalSParser::MultiVarDeclarationContext * /*ctx*/) override { }

  virtual void enterSubprogram_declarations(PascalSParser::Subprogram_declarationsContext * /*ctx*/) override { }
  virtual void exitSubprogram_declarations(PascalSParser::Subprogram_declarationsContext * /*ctx*/) override { }

  virtual void enterSubprogram_declaration(PascalSParser::Subprogram_declarationContext * /*ctx*/) override { }
  virtual void exitSubprogram_declaration(PascalSParser::Subprogram_declarationContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(PascalSParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(PascalSParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterProcedureDeclaration(PascalSParser::ProcedureDeclarationContext * /*ctx*/) override { }
  virtual void exitProcedureDeclaration(PascalSParser::ProcedureDeclarationContext * /*ctx*/) override { }

  virtual void enterFormal_parameter(PascalSParser::Formal_parameterContext * /*ctx*/) override { }
  virtual void exitFormal_parameter(PascalSParser::Formal_parameterContext * /*ctx*/) override { }

  virtual void enterMultiPara(PascalSParser::MultiParaContext * /*ctx*/) override { }
  virtual void exitMultiPara(PascalSParser::MultiParaContext * /*ctx*/) override { }

  virtual void enterSinglePara(PascalSParser::SingleParaContext * /*ctx*/) override { }
  virtual void exitSinglePara(PascalSParser::SingleParaContext * /*ctx*/) override { }

  virtual void enterVarPara(PascalSParser::VarParaContext * /*ctx*/) override { }
  virtual void exitVarPara(PascalSParser::VarParaContext * /*ctx*/) override { }

  virtual void enterValuePara(PascalSParser::ValueParaContext * /*ctx*/) override { }
  virtual void exitValuePara(PascalSParser::ValueParaContext * /*ctx*/) override { }

  virtual void enterVar_parameter(PascalSParser::Var_parameterContext * /*ctx*/) override { }
  virtual void exitVar_parameter(PascalSParser::Var_parameterContext * /*ctx*/) override { }

  virtual void enterValue_parameter(PascalSParser::Value_parameterContext * /*ctx*/) override { }
  virtual void exitValue_parameter(PascalSParser::Value_parameterContext * /*ctx*/) override { }

  virtual void enterCompound_statement(PascalSParser::Compound_statementContext * /*ctx*/) override { }
  virtual void exitCompound_statement(PascalSParser::Compound_statementContext * /*ctx*/) override { }

  virtual void enterMultiStatement(PascalSParser::MultiStatementContext * /*ctx*/) override { }
  virtual void exitMultiStatement(PascalSParser::MultiStatementContext * /*ctx*/) override { }

  virtual void enterSingleStatement(PascalSParser::SingleStatementContext * /*ctx*/) override { }
  virtual void exitSingleStatement(PascalSParser::SingleStatementContext * /*ctx*/) override { }

  virtual void enterBlock(PascalSParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(PascalSParser::BlockContext * /*ctx*/) override { }

  virtual void enterAssign(PascalSParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(PascalSParser::AssignContext * /*ctx*/) override { }

  virtual void enterCall(PascalSParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(PascalSParser::CallContext * /*ctx*/) override { }

  virtual void enterIf(PascalSParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(PascalSParser::IfContext * /*ctx*/) override { }

  virtual void enterCase(PascalSParser::CaseContext * /*ctx*/) override { }
  virtual void exitCase(PascalSParser::CaseContext * /*ctx*/) override { }

  virtual void enterWhile(PascalSParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(PascalSParser::WhileContext * /*ctx*/) override { }

  virtual void enterRepeat(PascalSParser::RepeatContext * /*ctx*/) override { }
  virtual void exitRepeat(PascalSParser::RepeatContext * /*ctx*/) override { }

  virtual void enterFor(PascalSParser::ForContext * /*ctx*/) override { }
  virtual void exitFor(PascalSParser::ForContext * /*ctx*/) override { }

  virtual void enterNone(PascalSParser::NoneContext * /*ctx*/) override { }
  virtual void exitNone(PascalSParser::NoneContext * /*ctx*/) override { }

  virtual void enterVariable(PascalSParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(PascalSParser::VariableContext * /*ctx*/) override { }

  virtual void enterId_varparts(PascalSParser::Id_varpartsContext * /*ctx*/) override { }
  virtual void exitId_varparts(PascalSParser::Id_varpartsContext * /*ctx*/) override { }

  virtual void enterArrayAccess(PascalSParser::ArrayAccessContext * /*ctx*/) override { }
  virtual void exitArrayAccess(PascalSParser::ArrayAccessContext * /*ctx*/) override { }

  virtual void enterRecordAccess(PascalSParser::RecordAccessContext * /*ctx*/) override { }
  virtual void exitRecordAccess(PascalSParser::RecordAccessContext * /*ctx*/) override { }

  virtual void enterElse_part(PascalSParser::Else_partContext * /*ctx*/) override { }
  virtual void exitElse_part(PascalSParser::Else_partContext * /*ctx*/) override { }

  virtual void enterCase_body(PascalSParser::Case_bodyContext * /*ctx*/) override { }
  virtual void exitCase_body(PascalSParser::Case_bodyContext * /*ctx*/) override { }

  virtual void enterBranch_list(PascalSParser::Branch_listContext * /*ctx*/) override { }
  virtual void exitBranch_list(PascalSParser::Branch_listContext * /*ctx*/) override { }

  virtual void enterBranch(PascalSParser::BranchContext * /*ctx*/) override { }
  virtual void exitBranch(PascalSParser::BranchContext * /*ctx*/) override { }

  virtual void enterSingleConstList(PascalSParser::SingleConstListContext * /*ctx*/) override { }
  virtual void exitSingleConstList(PascalSParser::SingleConstListContext * /*ctx*/) override { }

  virtual void enterMultiConstList(PascalSParser::MultiConstListContext * /*ctx*/) override { }
  virtual void exitMultiConstList(PascalSParser::MultiConstListContext * /*ctx*/) override { }

  virtual void enterUpdown(PascalSParser::UpdownContext * /*ctx*/) override { }
  virtual void exitUpdown(PascalSParser::UpdownContext * /*ctx*/) override { }

  virtual void enterCallWithNoPara(PascalSParser::CallWithNoParaContext * /*ctx*/) override { }
  virtual void exitCallWithNoPara(PascalSParser::CallWithNoParaContext * /*ctx*/) override { }

  virtual void enterCallWithPara(PascalSParser::CallWithParaContext * /*ctx*/) override { }
  virtual void exitCallWithPara(PascalSParser::CallWithParaContext * /*ctx*/) override { }

  virtual void enterCallWriteln(PascalSParser::CallWritelnContext * /*ctx*/) override { }
  virtual void exitCallWriteln(PascalSParser::CallWritelnContext * /*ctx*/) override { }

  virtual void enterCallReadln(PascalSParser::CallReadlnContext * /*ctx*/) override { }
  virtual void exitCallReadln(PascalSParser::CallReadlnContext * /*ctx*/) override { }

  virtual void enterExpression_list(PascalSParser::Expression_listContext * /*ctx*/) override { }
  virtual void exitExpression_list(PascalSParser::Expression_listContext * /*ctx*/) override { }

  virtual void enterRelationOperation(PascalSParser::RelationOperationContext * /*ctx*/) override { }
  virtual void exitRelationOperation(PascalSParser::RelationOperationContext * /*ctx*/) override { }

  virtual void enterNoRalationOperation(PascalSParser::NoRalationOperationContext * /*ctx*/) override { }
  virtual void exitNoRalationOperation(PascalSParser::NoRalationOperationContext * /*ctx*/) override { }

  virtual void enterPositiveTerm(PascalSParser::PositiveTermContext * /*ctx*/) override { }
  virtual void exitPositiveTerm(PascalSParser::PositiveTermContext * /*ctx*/) override { }

  virtual void enterAddOperation(PascalSParser::AddOperationContext * /*ctx*/) override { }
  virtual void exitAddOperation(PascalSParser::AddOperationContext * /*ctx*/) override { }

  virtual void enterNegativeTerm(PascalSParser::NegativeTermContext * /*ctx*/) override { }
  virtual void exitNegativeTerm(PascalSParser::NegativeTermContext * /*ctx*/) override { }

  virtual void enterNoMultiplyOperation(PascalSParser::NoMultiplyOperationContext * /*ctx*/) override { }
  virtual void exitNoMultiplyOperation(PascalSParser::NoMultiplyOperationContext * /*ctx*/) override { }

  virtual void enterMultiplyOperation(PascalSParser::MultiplyOperationContext * /*ctx*/) override { }
  virtual void exitMultiplyOperation(PascalSParser::MultiplyOperationContext * /*ctx*/) override { }

  virtual void enterUnsignConst(PascalSParser::UnsignConstContext * /*ctx*/) override { }
  virtual void exitUnsignConst(PascalSParser::UnsignConstContext * /*ctx*/) override { }

  virtual void enterFactorVariable(PascalSParser::FactorVariableContext * /*ctx*/) override { }
  virtual void exitFactorVariable(PascalSParser::FactorVariableContext * /*ctx*/) override { }

  virtual void enterFactorReturn(PascalSParser::FactorReturnContext * /*ctx*/) override { }
  virtual void exitFactorReturn(PascalSParser::FactorReturnContext * /*ctx*/) override { }

  virtual void enterFactorPriority(PascalSParser::FactorPriorityContext * /*ctx*/) override { }
  virtual void exitFactorPriority(PascalSParser::FactorPriorityContext * /*ctx*/) override { }

  virtual void enterReverseFactor(PascalSParser::ReverseFactorContext * /*ctx*/) override { }
  virtual void exitReverseFactor(PascalSParser::ReverseFactorContext * /*ctx*/) override { }

  virtual void enterUnsignConstId(PascalSParser::UnsignConstIdContext * /*ctx*/) override { }
  virtual void exitUnsignConstId(PascalSParser::UnsignConstIdContext * /*ctx*/) override { }

  virtual void enterUnsignConstNumber(PascalSParser::UnsignConstNumberContext * /*ctx*/) override { }
  virtual void exitUnsignConstNumber(PascalSParser::UnsignConstNumberContext * /*ctx*/) override { }

  virtual void enterUnsignConstChar(PascalSParser::UnsignConstCharContext * /*ctx*/) override { }
  virtual void exitUnsignConstChar(PascalSParser::UnsignConstCharContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

