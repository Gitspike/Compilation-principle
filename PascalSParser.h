
// Generated from PascalS.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  PascalSParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, CONST_CHAR = 54, ID = 55, LETTER = 56, 
    COMMENT = 57, MUL_COMMENT = 58, WS = 59, NUMBER = 60, DIGITS = 61, DIGIT = 62
  };

  enum {
    RuleAssignop = 0, RuleRelop = 1, RuleAddop = 2, RuleMulop = 3, RuleProgram = 4, 
    RuleProgram_head = 5, RuleProgram_body = 6, RuleIdentifier_list = 7, 
    RuleConst_declarations = 8, RuleConst_declaration = 9, RuleConst_variable = 10, 
    RuleType_declarations = 11, RuleType_declaration = 12, RuleType = 13, 
    RuleStandard_type = 14, RuleRecord_body = 15, RulePeriods = 16, RulePeriod = 17, 
    RuleVar_declarations = 18, RuleVar_declaration = 19, RuleSubprogram_declarations = 20, 
    RuleSubprogram_declaration = 21, RuleSubprogram_head = 22, RuleFormal_parameter = 23, 
    RuleParameter_lists = 24, RuleParameter_list = 25, RuleVar_parameter = 26, 
    RuleValue_parameter = 27, RuleCompound_statement = 28, RuleStatement_list = 29, 
    RuleStatement = 30, RuleWhile_condition = 31, RuleWhile_body = 32, RuleVariable = 33, 
    RuleId_varparts = 34, RuleId_varpart = 35, RuleElse_part = 36, RuleThen_statement = 37, 
    RuleIf_condition = 38, RuleCase_body = 39, RuleBranch_list = 40, RuleBranch = 41, 
    RuleConst_list = 42, RuleUpdown = 43, RuleCall_procedure_statement = 44, 
    RuleExpression_list = 45, RuleExpression = 46, RuleSimple_expression = 47, 
    RuleTerm = 48, RuleFactor = 49, RuleUnsign_const_variable = 50
  };

  explicit PascalSParser(antlr4::TokenStream *input);
  ~PascalSParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class AssignopContext;
  class RelopContext;
  class AddopContext;
  class MulopContext;
  class ProgramContext;
  class Program_headContext;
  class Program_bodyContext;
  class Identifier_listContext;
  class Const_declarationsContext;
  class Const_declarationContext;
  class Const_variableContext;
  class Type_declarationsContext;
  class Type_declarationContext;
  class TypeContext;
  class Standard_typeContext;
  class Record_bodyContext;
  class PeriodsContext;
  class PeriodContext;
  class Var_declarationsContext;
  class Var_declarationContext;
  class Subprogram_declarationsContext;
  class Subprogram_declarationContext;
  class Subprogram_headContext;
  class Formal_parameterContext;
  class Parameter_listsContext;
  class Parameter_listContext;
  class Var_parameterContext;
  class Value_parameterContext;
  class Compound_statementContext;
  class Statement_listContext;
  class StatementContext;
  class While_conditionContext;
  class While_bodyContext;
  class VariableContext;
  class Id_varpartsContext;
  class Id_varpartContext;
  class Else_partContext;
  class Then_statementContext;
  class If_conditionContext;
  class Case_bodyContext;
  class Branch_listContext;
  class BranchContext;
  class Const_listContext;
  class UpdownContext;
  class Call_procedure_statementContext;
  class Expression_listContext;
  class ExpressionContext;
  class Simple_expressionContext;
  class TermContext;
  class FactorContext;
  class Unsign_const_variableContext; 

  class  AssignopContext : public antlr4::ParserRuleContext {
  public:
    AssignopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignopContext* assignop();

  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelopContext* relop();

  class  AddopContext : public antlr4::ParserRuleContext {
  public:
    AddopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddopContext* addop();

  class  MulopContext : public antlr4::ParserRuleContext {
  public:
    MulopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MulopContext* mulop();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_headContext *program_head();
    Program_bodyContext *program_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  Program_headContext : public antlr4::ParserRuleContext {
  public:
    Program_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Identifier_listContext *identifier_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Program_headContext* program_head();

  class  Program_bodyContext : public antlr4::ParserRuleContext {
  public:
    Program_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_declarationsContext *const_declarations();
    Type_declarationsContext *type_declarations();
    Var_declarationsContext *var_declarations();
    Subprogram_declarationsContext *subprogram_declarations();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Program_bodyContext* program_body();

  class  Identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Identifier_listContext() = default;
    void copyFrom(Identifier_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultiMainArgContext : public Identifier_listContext {
  public:
    MultiMainArgContext(Identifier_listContext *ctx);

    Identifier_listContext *identifier_list();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MainArgContext : public Identifier_listContext {
  public:
    MainArgContext(Identifier_listContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Identifier_listContext* identifier_list();
  Identifier_listContext* identifier_list(int precedence);
  class  Const_declarationsContext : public antlr4::ParserRuleContext {
  public:
    Const_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_declarationContext *const_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Const_declarationsContext* const_declarations();

  class  Const_declarationContext : public antlr4::ParserRuleContext {
  public:
    Const_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Const_declarationContext() = default;
    void copyFrom(Const_declarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleConstDeclarationContext : public Const_declarationContext {
  public:
    SingleConstDeclarationContext(Const_declarationContext *ctx);

    antlr4::tree::TerminalNode *ID();
    Const_variableContext *const_variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultiConstDeclarationContext : public Const_declarationContext {
  public:
    MultiConstDeclarationContext(Const_declarationContext *ctx);

    std::vector<Const_declarationContext *> const_declaration();
    Const_declarationContext* const_declaration(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Const_declarationContext* const_declaration();
  Const_declarationContext* const_declaration(int precedence);
  class  Const_variableContext : public antlr4::ParserRuleContext {
  public:
    Const_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Const_variableContext() = default;
    void copyFrom(Const_variableContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PositiveIdContext : public Const_variableContext {
  public:
    PositiveIdContext(Const_variableContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ConstCharContext : public Const_variableContext {
  public:
    ConstCharContext(Const_variableContext *ctx);

    antlr4::tree::TerminalNode *CONST_CHAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PositiveNumberContext : public Const_variableContext {
  public:
    PositiveNumberContext(Const_variableContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NegativeNumberContext : public Const_variableContext {
  public:
    NegativeNumberContext(Const_variableContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NegativeIdContext : public Const_variableContext {
  public:
    NegativeIdContext(Const_variableContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Const_variableContext* const_variable();

  class  Type_declarationsContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_declarationContext *type_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_declarationsContext* type_declarations();

  class  Type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Type_declarationContext() = default;
    void copyFrom(Type_declarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultiTypeDeclarationContext : public Type_declarationContext {
  public:
    MultiTypeDeclarationContext(Type_declarationContext *ctx);

    std::vector<Type_declarationContext *> type_declaration();
    Type_declarationContext* type_declaration(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SingleTypeDeclarationContext : public Type_declarationContext {
  public:
    SingleTypeDeclarationContext(Type_declarationContext *ctx);

    antlr4::tree::TerminalNode *ID();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Type_declarationContext* type_declaration();
  Type_declarationContext* type_declaration(int precedence);
  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Standard_typeContext *standard_type();
    Record_bodyContext *record_body();
    PeriodsContext *periods();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  Standard_typeContext : public antlr4::ParserRuleContext {
  public:
    Standard_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Standard_typeContext* standard_type();

  class  Record_bodyContext : public antlr4::ParserRuleContext {
  public:
    Record_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_bodyContext* record_body();

  class  PeriodsContext : public antlr4::ParserRuleContext {
  public:
    PeriodsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PeriodsContext() = default;
    void copyFrom(PeriodsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SinglePeriodContext : public PeriodsContext {
  public:
    SinglePeriodContext(PeriodsContext *ctx);

    PeriodContext *period();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultiPeriodContext : public PeriodsContext {
  public:
    MultiPeriodContext(PeriodsContext *ctx);

    PeriodsContext *periods();
    PeriodContext *period();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PeriodsContext* periods();
  PeriodsContext* periods(int precedence);
  class  PeriodContext : public antlr4::ParserRuleContext {
  public:
    PeriodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Const_variableContext *> const_variable();
    Const_variableContext* const_variable(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PeriodContext* period();

  class  Var_declarationsContext : public antlr4::ParserRuleContext {
  public:
    Var_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationsContext* var_declarations();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Var_declarationContext() = default;
    void copyFrom(Var_declarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleVarDeclarationContext : public Var_declarationContext {
  public:
    SingleVarDeclarationContext(Var_declarationContext *ctx);

    Identifier_listContext *identifier_list();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultiVarDeclarationContext : public Var_declarationContext {
  public:
    MultiVarDeclarationContext(Var_declarationContext *ctx);

    std::vector<Var_declarationContext *> var_declaration();
    Var_declarationContext* var_declaration(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Var_declarationContext* var_declaration();
  Var_declarationContext* var_declaration(int precedence);
  class  Subprogram_declarationsContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_declarationsContext *subprogram_declarations();
    Subprogram_declarationContext *subprogram_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_declarationsContext* subprogram_declarations();
  Subprogram_declarationsContext* subprogram_declarations(int precedence);
  class  Subprogram_declarationContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_headContext *subprogram_head();
    Program_bodyContext *program_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_declarationContext* subprogram_declaration();

  class  Subprogram_headContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Subprogram_headContext() = default;
    void copyFrom(Subprogram_headContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionDeclarationContext : public Subprogram_headContext {
  public:
    FunctionDeclarationContext(Subprogram_headContext *ctx);

    antlr4::tree::TerminalNode *ID();
    Formal_parameterContext *formal_parameter();
    Standard_typeContext *standard_type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ProcedureDeclarationContext : public Subprogram_headContext {
  public:
    ProcedureDeclarationContext(Subprogram_headContext *ctx);

    antlr4::tree::TerminalNode *ID();
    Formal_parameterContext *formal_parameter();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Subprogram_headContext* subprogram_head();

  class  Formal_parameterContext : public antlr4::ParserRuleContext {
  public:
    Formal_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_listsContext *parameter_lists();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_parameterContext* formal_parameter();

  class  Parameter_listsContext : public antlr4::ParserRuleContext {
  public:
    Parameter_listsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Parameter_listsContext() = default;
    void copyFrom(Parameter_listsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultiParaContext : public Parameter_listsContext {
  public:
    MultiParaContext(Parameter_listsContext *ctx);

    Parameter_listsContext *parameter_lists();
    Parameter_listContext *parameter_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SingleParaContext : public Parameter_listsContext {
  public:
    SingleParaContext(Parameter_listsContext *ctx);

    Parameter_listContext *parameter_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Parameter_listsContext* parameter_lists();
  Parameter_listsContext* parameter_lists(int precedence);
  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Parameter_listContext() = default;
    void copyFrom(Parameter_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarParaContext : public Parameter_listContext {
  public:
    VarParaContext(Parameter_listContext *ctx);

    Var_parameterContext *var_parameter();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ValueParaContext : public Parameter_listContext {
  public:
    ValueParaContext(Parameter_listContext *ctx);

    Value_parameterContext *value_parameter();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Parameter_listContext* parameter_list();

  class  Var_parameterContext : public antlr4::ParserRuleContext {
  public:
    Var_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_parameterContext *value_parameter();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_parameterContext* var_parameter();

  class  Value_parameterContext : public antlr4::ParserRuleContext {
  public:
    Value_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_listContext *identifier_list();
    Standard_typeContext *standard_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Value_parameterContext* value_parameter();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_listContext *statement_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Statement_listContext : public antlr4::ParserRuleContext {
  public:
    Statement_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Statement_listContext() = default;
    void copyFrom(Statement_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultiStatementContext : public Statement_listContext {
  public:
    MultiStatementContext(Statement_listContext *ctx);

    Statement_listContext *statement_list();
    StatementContext *statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SingleStatementContext : public Statement_listContext {
  public:
    SingleStatementContext(Statement_listContext *ctx);

    StatementContext *statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Statement_listContext* statement_list();
  Statement_listContext* statement_list(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallContext : public StatementContext {
  public:
    CallContext(StatementContext *ctx);

    Call_procedure_statementContext *call_procedure_statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ForContext : public StatementContext {
  public:
    ForContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *ID();
    AssignopContext *assignop();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    UpdownContext *updown();
    StatementContext *statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BlockContext : public StatementContext {
  public:
    BlockContext(StatementContext *ctx);

    Compound_statementContext *compound_statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AssignContext : public StatementContext {
  public:
    AssignContext(StatementContext *ctx);

    VariableContext *variable();
    AssignopContext *assignop();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RepeatContext : public StatementContext {
  public:
    RepeatContext(StatementContext *ctx);

    Statement_listContext *statement_list();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  WhileContext : public StatementContext {
  public:
    WhileContext(StatementContext *ctx);

    While_conditionContext *while_condition();
    While_bodyContext *while_body();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  IfContext : public StatementContext {
  public:
    IfContext(StatementContext *ctx);

    If_conditionContext *if_condition();
    Then_statementContext *then_statement();
    Else_partContext *else_part();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NoneContext : public StatementContext {
  public:
    NoneContext(StatementContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CaseContext : public StatementContext {
  public:
    CaseContext(StatementContext *ctx);

    ExpressionContext *expression();
    Case_bodyContext *case_body();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StatementContext* statement();

  class  While_conditionContext : public antlr4::ParserRuleContext {
  public:
    While_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  While_conditionContext* while_condition();

  class  While_bodyContext : public antlr4::ParserRuleContext {
  public:
    While_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  While_bodyContext* while_body();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Id_varpartsContext *id_varparts();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  Id_varpartsContext : public antlr4::ParserRuleContext {
  public:
    Id_varpartsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Id_varpartsContext *id_varparts();
    Id_varpartContext *id_varpart();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Id_varpartsContext* id_varparts();
  Id_varpartsContext* id_varparts(int precedence);
  class  Id_varpartContext : public antlr4::ParserRuleContext {
  public:
    Id_varpartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Id_varpartContext() = default;
    void copyFrom(Id_varpartContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayAccessContext : public Id_varpartContext {
  public:
    ArrayAccessContext(Id_varpartContext *ctx);

    Expression_listContext *expression_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RecordAccessContext : public Id_varpartContext {
  public:
    RecordAccessContext(Id_varpartContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Id_varpartContext* id_varpart();

  class  Else_partContext : public antlr4::ParserRuleContext {
  public:
    Else_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Else_partContext* else_part();

  class  Then_statementContext : public antlr4::ParserRuleContext {
  public:
    Then_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Then_statementContext* then_statement();

  class  If_conditionContext : public antlr4::ParserRuleContext {
  public:
    If_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_conditionContext* if_condition();

  class  Case_bodyContext : public antlr4::ParserRuleContext {
  public:
    Case_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Branch_listContext *branch_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Case_bodyContext* case_body();

  class  Branch_listContext : public antlr4::ParserRuleContext {
  public:
    Branch_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BranchContext *branch();
    Branch_listContext *branch_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Branch_listContext* branch_list();
  Branch_listContext* branch_list(int precedence);
  class  BranchContext : public antlr4::ParserRuleContext {
  public:
    BranchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_listContext *const_list();
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BranchContext* branch();

  class  Const_listContext : public antlr4::ParserRuleContext {
  public:
    Const_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Const_listContext() = default;
    void copyFrom(Const_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleConstListContext : public Const_listContext {
  public:
    SingleConstListContext(Const_listContext *ctx);

    Const_variableContext *const_variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultiConstListContext : public Const_listContext {
  public:
    MultiConstListContext(Const_listContext *ctx);

    Const_listContext *const_list();
    Const_variableContext *const_variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Const_listContext* const_list();
  Const_listContext* const_list(int precedence);
  class  UpdownContext : public antlr4::ParserRuleContext {
  public:
    UpdownContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UpdownContext* updown();

  class  Call_procedure_statementContext : public antlr4::ParserRuleContext {
  public:
    Call_procedure_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Call_procedure_statementContext() = default;
    void copyFrom(Call_procedure_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallWithParaContext : public Call_procedure_statementContext {
  public:
    CallWithParaContext(Call_procedure_statementContext *ctx);

    antlr4::tree::TerminalNode *ID();
    Expression_listContext *expression_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CallWritelnContext : public Call_procedure_statementContext {
  public:
    CallWritelnContext(Call_procedure_statementContext *ctx);

    Expression_listContext *expression_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CallWithNoParaContext : public Call_procedure_statementContext {
  public:
    CallWithNoParaContext(Call_procedure_statementContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CallReadlnContext : public Call_procedure_statementContext {
  public:
    CallReadlnContext(Call_procedure_statementContext *ctx);

    VariableContext *variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Call_procedure_statementContext* call_procedure_statement();

  class  Expression_listContext : public antlr4::ParserRuleContext {
  public:
    Expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Expression_listContext *expression_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_listContext* expression_list();
  Expression_listContext* expression_list(int precedence);
  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NoRalationOperationContext : public ExpressionContext {
  public:
    NoRalationOperationContext(ExpressionContext *ctx);

    Simple_expressionContext *simple_expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RelationOperationContext : public ExpressionContext {
  public:
    RelationOperationContext(ExpressionContext *ctx);

    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    RelopContext *relop();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExpressionContext* expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Simple_expressionContext() = default;
    void copyFrom(Simple_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PositiveTermContext : public Simple_expressionContext {
  public:
    PositiveTermContext(Simple_expressionContext *ctx);

    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AddOperationContext : public Simple_expressionContext {
  public:
    AddOperationContext(Simple_expressionContext *ctx);

    Simple_expressionContext *simple_expression();
    AddopContext *addop();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NegativeTermContext : public Simple_expressionContext {
  public:
    NegativeTermContext(Simple_expressionContext *ctx);

    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NoMultiplyOperationContext : public TermContext {
  public:
    NoMultiplyOperationContext(TermContext *ctx);

    FactorContext *factor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultiplyOperationContext : public TermContext {
  public:
    MultiplyOperationContext(TermContext *ctx);

    TermContext *term();
    MulopContext *mulop();
    FactorContext *factor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FactorContext() = default;
    void copyFrom(FactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FactorReturnContext : public FactorContext {
  public:
    FactorReturnContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *ID();
    Expression_listContext *expression_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ReverseFactorContext : public FactorContext {
  public:
    ReverseFactorContext(FactorContext *ctx);

    FactorContext *factor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FactorPriorityContext : public FactorContext {
  public:
    FactorPriorityContext(FactorContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FactorVariableContext : public FactorContext {
  public:
    FactorVariableContext(FactorContext *ctx);

    VariableContext *variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnsignConstContext : public FactorContext {
  public:
    UnsignConstContext(FactorContext *ctx);

    Unsign_const_variableContext *unsign_const_variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  FactorContext* factor();

  class  Unsign_const_variableContext : public antlr4::ParserRuleContext {
  public:
    Unsign_const_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Unsign_const_variableContext() = default;
    void copyFrom(Unsign_const_variableContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnsignConstIdContext : public Unsign_const_variableContext {
  public:
    UnsignConstIdContext(Unsign_const_variableContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnsignConstCharContext : public Unsign_const_variableContext {
  public:
    UnsignConstCharContext(Unsign_const_variableContext *ctx);

    antlr4::tree::TerminalNode *CONST_CHAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnsignConstNumberContext : public Unsign_const_variableContext {
  public:
    UnsignConstNumberContext(Unsign_const_variableContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Unsign_const_variableContext* unsign_const_variable();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool identifier_listSempred(Identifier_listContext *_localctx, size_t predicateIndex);
  bool const_declarationSempred(Const_declarationContext *_localctx, size_t predicateIndex);
  bool type_declarationSempred(Type_declarationContext *_localctx, size_t predicateIndex);
  bool periodsSempred(PeriodsContext *_localctx, size_t predicateIndex);
  bool var_declarationSempred(Var_declarationContext *_localctx, size_t predicateIndex);
  bool subprogram_declarationsSempred(Subprogram_declarationsContext *_localctx, size_t predicateIndex);
  bool parameter_listsSempred(Parameter_listsContext *_localctx, size_t predicateIndex);
  bool statement_listSempred(Statement_listContext *_localctx, size_t predicateIndex);
  bool id_varpartsSempred(Id_varpartsContext *_localctx, size_t predicateIndex);
  bool branch_listSempred(Branch_listContext *_localctx, size_t predicateIndex);
  bool const_listSempred(Const_listContext *_localctx, size_t predicateIndex);
  bool expression_listSempred(Expression_listContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

