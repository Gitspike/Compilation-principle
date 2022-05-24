
// Generated from PascalS.g4 by ANTLR 4.9.2


#include "PascalSListener.h"

#include "PascalSParser.h"


using namespace antlrcpp;
using namespace antlr4;

PascalSParser::PascalSParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PascalSParser::~PascalSParser() {
  delete _interpreter;
}

std::string PascalSParser::getGrammarFileName() const {
  return "PascalS.g4";
}

const std::vector<std::string>& PascalSParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PascalSParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AssignopContext ------------------------------------------------------------------

PascalSParser::AssignopContext::AssignopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::AssignopContext::getRuleIndex() const {
  return PascalSParser::RuleAssignop;
}

void PascalSParser::AssignopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignop(this);
}

void PascalSParser::AssignopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignop(this);
}

PascalSParser::AssignopContext* PascalSParser::assignop() {
  AssignopContext *_localctx = _tracker.createInstance<AssignopContext>(_ctx, getState());
  enterRule(_localctx, 0, PascalSParser::RuleAssignop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(PascalSParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

PascalSParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::RelopContext::getRuleIndex() const {
  return PascalSParser::RuleRelop;
}

void PascalSParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void PascalSParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}

PascalSParser::RelopContext* PascalSParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 2, PascalSParser::RuleRelop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalSParser::T__1)
      | (1ULL << PascalSParser::T__2)
      | (1ULL << PascalSParser::T__3)
      | (1ULL << PascalSParser::T__4)
      | (1ULL << PascalSParser::T__5)
      | (1ULL << PascalSParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddopContext ------------------------------------------------------------------

PascalSParser::AddopContext::AddopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::AddopContext::getRuleIndex() const {
  return PascalSParser::RuleAddop;
}

void PascalSParser::AddopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddop(this);
}

void PascalSParser::AddopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddop(this);
}

PascalSParser::AddopContext* PascalSParser::addop() {
  AddopContext *_localctx = _tracker.createInstance<AddopContext>(_ctx, getState());
  enterRule(_localctx, 4, PascalSParser::RuleAddop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalSParser::T__7)
      | (1ULL << PascalSParser::T__8)
      | (1ULL << PascalSParser::T__9))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulopContext ------------------------------------------------------------------

PascalSParser::MulopContext::MulopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::MulopContext::getRuleIndex() const {
  return PascalSParser::RuleMulop;
}

void PascalSParser::MulopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulop(this);
}

void PascalSParser::MulopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulop(this);
}

PascalSParser::MulopContext* PascalSParser::mulop() {
  MulopContext *_localctx = _tracker.createInstance<MulopContext>(_ctx, getState());
  enterRule(_localctx, 6, PascalSParser::RuleMulop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalSParser::T__10)
      | (1ULL << PascalSParser::T__11)
      | (1ULL << PascalSParser::T__12)
      | (1ULL << PascalSParser::T__13)
      | (1ULL << PascalSParser::T__14))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

PascalSParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Program_headContext* PascalSParser::ProgramContext::program_head() {
  return getRuleContext<PascalSParser::Program_headContext>(0);
}

PascalSParser::Program_bodyContext* PascalSParser::ProgramContext::program_body() {
  return getRuleContext<PascalSParser::Program_bodyContext>(0);
}


size_t PascalSParser::ProgramContext::getRuleIndex() const {
  return PascalSParser::RuleProgram;
}

void PascalSParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void PascalSParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

PascalSParser::ProgramContext* PascalSParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalSParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    program_head();
    setState(117);
    program_body();
    setState(118);
    match(PascalSParser::T__15);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_headContext ------------------------------------------------------------------

PascalSParser::Program_headContext::Program_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::Program_headContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Identifier_listContext* PascalSParser::Program_headContext::identifier_list() {
  return getRuleContext<PascalSParser::Identifier_listContext>(0);
}


size_t PascalSParser::Program_headContext::getRuleIndex() const {
  return PascalSParser::RuleProgram_head;
}

void PascalSParser::Program_headContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_head(this);
}

void PascalSParser::Program_headContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_head(this);
}

PascalSParser::Program_headContext* PascalSParser::program_head() {
  Program_headContext *_localctx = _tracker.createInstance<Program_headContext>(_ctx, getState());
  enterRule(_localctx, 10, PascalSParser::RuleProgram_head);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(PascalSParser::T__16);
    setState(121);
    match(PascalSParser::ID);
    setState(122);
    match(PascalSParser::T__17);
    setState(123);
    identifier_list(0);
    setState(124);
    match(PascalSParser::T__18);
    setState(125);
    match(PascalSParser::T__19);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_bodyContext ------------------------------------------------------------------

PascalSParser::Program_bodyContext::Program_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Const_declarationsContext* PascalSParser::Program_bodyContext::const_declarations() {
  return getRuleContext<PascalSParser::Const_declarationsContext>(0);
}

PascalSParser::Type_declarationsContext* PascalSParser::Program_bodyContext::type_declarations() {
  return getRuleContext<PascalSParser::Type_declarationsContext>(0);
}

PascalSParser::Var_declarationsContext* PascalSParser::Program_bodyContext::var_declarations() {
  return getRuleContext<PascalSParser::Var_declarationsContext>(0);
}

PascalSParser::Subprogram_declarationsContext* PascalSParser::Program_bodyContext::subprogram_declarations() {
  return getRuleContext<PascalSParser::Subprogram_declarationsContext>(0);
}

PascalSParser::Body_compound_statementContext* PascalSParser::Program_bodyContext::body_compound_statement() {
  return getRuleContext<PascalSParser::Body_compound_statementContext>(0);
}


size_t PascalSParser::Program_bodyContext::getRuleIndex() const {
  return PascalSParser::RuleProgram_body;
}

void PascalSParser::Program_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_body(this);
}

void PascalSParser::Program_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_body(this);
}

PascalSParser::Program_bodyContext* PascalSParser::program_body() {
  Program_bodyContext *_localctx = _tracker.createInstance<Program_bodyContext>(_ctx, getState());
  enterRule(_localctx, 12, PascalSParser::RuleProgram_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    const_declarations();
    setState(128);
    type_declarations();
    setState(129);
    var_declarations();
    setState(130);
    subprogram_declarations(0);
    setState(131);
    body_compound_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Body_compound_statementContext ------------------------------------------------------------------

PascalSParser::Body_compound_statementContext::Body_compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Compound_statementContext* PascalSParser::Body_compound_statementContext::compound_statement() {
  return getRuleContext<PascalSParser::Compound_statementContext>(0);
}


size_t PascalSParser::Body_compound_statementContext::getRuleIndex() const {
  return PascalSParser::RuleBody_compound_statement;
}

void PascalSParser::Body_compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody_compound_statement(this);
}

void PascalSParser::Body_compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody_compound_statement(this);
}

PascalSParser::Body_compound_statementContext* PascalSParser::body_compound_statement() {
  Body_compound_statementContext *_localctx = _tracker.createInstance<Body_compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 14, PascalSParser::RuleBody_compound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    compound_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_listContext ------------------------------------------------------------------

PascalSParser::Identifier_listContext::Identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Identifier_listContext::getRuleIndex() const {
  return PascalSParser::RuleIdentifier_list;
}

void PascalSParser::Identifier_listContext::copyFrom(Identifier_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultiMainArgContext ------------------------------------------------------------------

PascalSParser::Identifier_listContext* PascalSParser::MultiMainArgContext::identifier_list() {
  return getRuleContext<PascalSParser::Identifier_listContext>(0);
}

tree::TerminalNode* PascalSParser::MultiMainArgContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::MultiMainArgContext::MultiMainArgContext(Identifier_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiMainArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiMainArg(this);
}
void PascalSParser::MultiMainArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiMainArg(this);
}
//----------------- MainArgContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::MainArgContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::MainArgContext::MainArgContext(Identifier_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::MainArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMainArg(this);
}
void PascalSParser::MainArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMainArg(this);
}

PascalSParser::Identifier_listContext* PascalSParser::identifier_list() {
   return identifier_list(0);
}

PascalSParser::Identifier_listContext* PascalSParser::identifier_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Identifier_listContext *_localctx = _tracker.createInstance<Identifier_listContext>(_ctx, parentState);
  PascalSParser::Identifier_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, PascalSParser::RuleIdentifier_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MainArgContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(136);
    match(PascalSParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(143);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiMainArgContext>(_tracker.createInstance<Identifier_listContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleIdentifier_list);
        setState(138);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(139);
        match(PascalSParser::T__20);
        setState(140);
        match(PascalSParser::ID); 
      }
      setState(145);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Const_declarationsContext ------------------------------------------------------------------

PascalSParser::Const_declarationsContext::Const_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Const_declarationContext* PascalSParser::Const_declarationsContext::const_declaration() {
  return getRuleContext<PascalSParser::Const_declarationContext>(0);
}


size_t PascalSParser::Const_declarationsContext::getRuleIndex() const {
  return PascalSParser::RuleConst_declarations;
}

void PascalSParser::Const_declarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_declarations(this);
}

void PascalSParser::Const_declarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_declarations(this);
}

PascalSParser::Const_declarationsContext* PascalSParser::const_declarations() {
  Const_declarationsContext *_localctx = _tracker.createInstance<Const_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 18, PascalSParser::RuleConst_declarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(146);
      match(PascalSParser::T__21);
      setState(147);
      const_declaration(0);
      setState(148);
      match(PascalSParser::T__19);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_declarationContext ------------------------------------------------------------------

PascalSParser::Const_declarationContext::Const_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Const_declarationContext::getRuleIndex() const {
  return PascalSParser::RuleConst_declaration;
}

void PascalSParser::Const_declarationContext::copyFrom(Const_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleConstDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::SingleConstDeclarationContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Const_variableContext* PascalSParser::SingleConstDeclarationContext::const_variable() {
  return getRuleContext<PascalSParser::Const_variableContext>(0);
}

PascalSParser::SingleConstDeclarationContext::SingleConstDeclarationContext(Const_declarationContext *ctx) { copyFrom(ctx); }

void PascalSParser::SingleConstDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleConstDeclaration(this);
}
void PascalSParser::SingleConstDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleConstDeclaration(this);
}
//----------------- MultiConstDeclarationContext ------------------------------------------------------------------

std::vector<PascalSParser::Const_declarationContext *> PascalSParser::MultiConstDeclarationContext::const_declaration() {
  return getRuleContexts<PascalSParser::Const_declarationContext>();
}

PascalSParser::Const_declarationContext* PascalSParser::MultiConstDeclarationContext::const_declaration(size_t i) {
  return getRuleContext<PascalSParser::Const_declarationContext>(i);
}

PascalSParser::MultiConstDeclarationContext::MultiConstDeclarationContext(Const_declarationContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiConstDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiConstDeclaration(this);
}
void PascalSParser::MultiConstDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiConstDeclaration(this);
}

PascalSParser::Const_declarationContext* PascalSParser::const_declaration() {
   return const_declaration(0);
}

PascalSParser::Const_declarationContext* PascalSParser::const_declaration(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Const_declarationContext *_localctx = _tracker.createInstance<Const_declarationContext>(_ctx, parentState);
  PascalSParser::Const_declarationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, PascalSParser::RuleConst_declaration, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SingleConstDeclarationContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(154);
    match(PascalSParser::ID);
    setState(155);
    match(PascalSParser::T__6);
    setState(156);
    const_variable();
    _ctx->stop = _input->LT(-1);
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiConstDeclarationContext>(_tracker.createInstance<Const_declarationContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleConst_declaration);
        setState(158);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(159);
        match(PascalSParser::T__19);
        setState(160);
        const_declaration(3); 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Const_variableContext ------------------------------------------------------------------

PascalSParser::Const_variableContext::Const_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Const_variableContext::getRuleIndex() const {
  return PascalSParser::RuleConst_variable;
}

void PascalSParser::Const_variableContext::copyFrom(Const_variableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PositiveIdContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::PositiveIdContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::PositiveIdContext::PositiveIdContext(Const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::PositiveIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositiveId(this);
}
void PascalSParser::PositiveIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositiveId(this);
}
//----------------- ConstCharContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::ConstCharContext::CONST_CHAR() {
  return getToken(PascalSParser::CONST_CHAR, 0);
}

PascalSParser::ConstCharContext::ConstCharContext(Const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::ConstCharContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstChar(this);
}
void PascalSParser::ConstCharContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstChar(this);
}
//----------------- PositiveNumberContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::PositiveNumberContext::NUMBER() {
  return getToken(PascalSParser::NUMBER, 0);
}

PascalSParser::PositiveNumberContext::PositiveNumberContext(Const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::PositiveNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositiveNumber(this);
}
void PascalSParser::PositiveNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositiveNumber(this);
}
//----------------- NegativeNumberContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::NegativeNumberContext::NUMBER() {
  return getToken(PascalSParser::NUMBER, 0);
}

PascalSParser::NegativeNumberContext::NegativeNumberContext(Const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::NegativeNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegativeNumber(this);
}
void PascalSParser::NegativeNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegativeNumber(this);
}
//----------------- NegativeIdContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::NegativeIdContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::NegativeIdContext::NegativeIdContext(Const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::NegativeIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegativeId(this);
}
void PascalSParser::NegativeIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegativeId(this);
}
PascalSParser::Const_variableContext* PascalSParser::const_variable() {
  Const_variableContext *_localctx = _tracker.createInstance<Const_variableContext>(_ctx, getState());
  enterRule(_localctx, 22, PascalSParser::RuleConst_variable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(166);
      match(PascalSParser::T__7);
      setState(167);
      match(PascalSParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::NegativeIdContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(168);
      match(PascalSParser::T__8);
      setState(169);
      match(PascalSParser::ID);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveIdContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(170);
      match(PascalSParser::ID);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveNumberContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(171);
      match(PascalSParser::T__7);
      setState(172);
      match(PascalSParser::NUMBER);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::NegativeNumberContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(173);
      match(PascalSParser::T__8);
      setState(174);
      match(PascalSParser::NUMBER);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveNumberContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(175);
      match(PascalSParser::NUMBER);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::ConstCharContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(176);
      match(PascalSParser::CONST_CHAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationsContext ------------------------------------------------------------------

PascalSParser::Type_declarationsContext::Type_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Type_declarationContext* PascalSParser::Type_declarationsContext::type_declaration() {
  return getRuleContext<PascalSParser::Type_declarationContext>(0);
}


size_t PascalSParser::Type_declarationsContext::getRuleIndex() const {
  return PascalSParser::RuleType_declarations;
}

void PascalSParser::Type_declarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_declarations(this);
}

void PascalSParser::Type_declarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_declarations(this);
}

PascalSParser::Type_declarationsContext* PascalSParser::type_declarations() {
  Type_declarationsContext *_localctx = _tracker.createInstance<Type_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 24, PascalSParser::RuleType_declarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(179);
      match(PascalSParser::T__22);
      setState(180);
      type_declaration(0);
      setState(181);
      match(PascalSParser::T__19);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

PascalSParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Type_declarationContext::getRuleIndex() const {
  return PascalSParser::RuleType_declaration;
}

void PascalSParser::Type_declarationContext::copyFrom(Type_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultiTypeDeclarationContext ------------------------------------------------------------------

std::vector<PascalSParser::Type_declarationContext *> PascalSParser::MultiTypeDeclarationContext::type_declaration() {
  return getRuleContexts<PascalSParser::Type_declarationContext>();
}

PascalSParser::Type_declarationContext* PascalSParser::MultiTypeDeclarationContext::type_declaration(size_t i) {
  return getRuleContext<PascalSParser::Type_declarationContext>(i);
}

PascalSParser::MultiTypeDeclarationContext::MultiTypeDeclarationContext(Type_declarationContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiTypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiTypeDeclaration(this);
}
void PascalSParser::MultiTypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiTypeDeclaration(this);
}
//----------------- SingleTypeDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::SingleTypeDeclarationContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::TypeContext* PascalSParser::SingleTypeDeclarationContext::type() {
  return getRuleContext<PascalSParser::TypeContext>(0);
}

PascalSParser::SingleTypeDeclarationContext::SingleTypeDeclarationContext(Type_declarationContext *ctx) { copyFrom(ctx); }

void PascalSParser::SingleTypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleTypeDeclaration(this);
}
void PascalSParser::SingleTypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleTypeDeclaration(this);
}

PascalSParser::Type_declarationContext* PascalSParser::type_declaration() {
   return type_declaration(0);
}

PascalSParser::Type_declarationContext* PascalSParser::type_declaration(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, parentState);
  PascalSParser::Type_declarationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, PascalSParser::RuleType_declaration, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SingleTypeDeclarationContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(187);
    match(PascalSParser::ID);
    setState(188);
    match(PascalSParser::T__6);
    setState(189);
    type();
    _ctx->stop = _input->LT(-1);
    setState(196);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiTypeDeclarationContext>(_tracker.createInstance<Type_declarationContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleType_declaration);
        setState(191);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(192);
        match(PascalSParser::T__19);
        setState(193);
        type_declaration(3); 
      }
      setState(198);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

PascalSParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Standard_typeContext* PascalSParser::TypeContext::standard_type() {
  return getRuleContext<PascalSParser::Standard_typeContext>(0);
}

PascalSParser::Record_bodyContext* PascalSParser::TypeContext::record_body() {
  return getRuleContext<PascalSParser::Record_bodyContext>(0);
}

PascalSParser::PeriodsContext* PascalSParser::TypeContext::periods() {
  return getRuleContext<PascalSParser::PeriodsContext>(0);
}

PascalSParser::TypeContext* PascalSParser::TypeContext::type() {
  return getRuleContext<PascalSParser::TypeContext>(0);
}


size_t PascalSParser::TypeContext::getRuleIndex() const {
  return PascalSParser::RuleType;
}

void PascalSParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void PascalSParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

PascalSParser::TypeContext* PascalSParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 28, PascalSParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__29:
      case PascalSParser::T__30:
      case PascalSParser::T__31:
      case PascalSParser::T__32: {
        enterOuterAlt(_localctx, 1);
        setState(199);
        standard_type();
        break;
      }

      case PascalSParser::T__23: {
        enterOuterAlt(_localctx, 2);
        setState(200);
        match(PascalSParser::T__23);
        setState(201);
        record_body();
        setState(202);
        match(PascalSParser::T__24);
        break;
      }

      case PascalSParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(204);
        match(PascalSParser::T__25);
        setState(205);
        match(PascalSParser::T__26);
        setState(206);
        periods(0);
        setState(207);
        match(PascalSParser::T__27);
        setState(208);
        match(PascalSParser::T__28);
        setState(209);
        type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Standard_typeContext ------------------------------------------------------------------

PascalSParser::Standard_typeContext::Standard_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Standard_typeContext::getRuleIndex() const {
  return PascalSParser::RuleStandard_type;
}

void PascalSParser::Standard_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStandard_type(this);
}

void PascalSParser::Standard_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStandard_type(this);
}

PascalSParser::Standard_typeContext* PascalSParser::standard_type() {
  Standard_typeContext *_localctx = _tracker.createInstance<Standard_typeContext>(_ctx, getState());
  enterRule(_localctx, 30, PascalSParser::RuleStandard_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalSParser::T__29)
      | (1ULL << PascalSParser::T__30)
      | (1ULL << PascalSParser::T__31)
      | (1ULL << PascalSParser::T__32))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_bodyContext ------------------------------------------------------------------

PascalSParser::Record_bodyContext::Record_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Var_declarationContext* PascalSParser::Record_bodyContext::var_declaration() {
  return getRuleContext<PascalSParser::Var_declarationContext>(0);
}


size_t PascalSParser::Record_bodyContext::getRuleIndex() const {
  return PascalSParser::RuleRecord_body;
}

void PascalSParser::Record_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_body(this);
}

void PascalSParser::Record_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_body(this);
}

PascalSParser::Record_bodyContext* PascalSParser::record_body() {
  Record_bodyContext *_localctx = _tracker.createInstance<Record_bodyContext>(_ctx, getState());
  enterRule(_localctx, 32, PascalSParser::RuleRecord_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(215);
        var_declaration(0);
        break;
      }

      case PascalSParser::T__24: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PeriodsContext ------------------------------------------------------------------

PascalSParser::PeriodsContext::PeriodsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::PeriodsContext::getRuleIndex() const {
  return PascalSParser::RulePeriods;
}

void PascalSParser::PeriodsContext::copyFrom(PeriodsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SinglePeriodContext ------------------------------------------------------------------

PascalSParser::PeriodContext* PascalSParser::SinglePeriodContext::period() {
  return getRuleContext<PascalSParser::PeriodContext>(0);
}

PascalSParser::SinglePeriodContext::SinglePeriodContext(PeriodsContext *ctx) { copyFrom(ctx); }

void PascalSParser::SinglePeriodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSinglePeriod(this);
}
void PascalSParser::SinglePeriodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSinglePeriod(this);
}
//----------------- MultiPeriodContext ------------------------------------------------------------------

PascalSParser::PeriodsContext* PascalSParser::MultiPeriodContext::periods() {
  return getRuleContext<PascalSParser::PeriodsContext>(0);
}

PascalSParser::PeriodContext* PascalSParser::MultiPeriodContext::period() {
  return getRuleContext<PascalSParser::PeriodContext>(0);
}

PascalSParser::MultiPeriodContext::MultiPeriodContext(PeriodsContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiPeriodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiPeriod(this);
}
void PascalSParser::MultiPeriodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiPeriod(this);
}

PascalSParser::PeriodsContext* PascalSParser::periods() {
   return periods(0);
}

PascalSParser::PeriodsContext* PascalSParser::periods(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::PeriodsContext *_localctx = _tracker.createInstance<PeriodsContext>(_ctx, parentState);
  PascalSParser::PeriodsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, PascalSParser::RulePeriods, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SinglePeriodContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(220);
    period();
    _ctx->stop = _input->LT(-1);
    setState(227);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiPeriodContext>(_tracker.createInstance<PeriodsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RulePeriods);
        setState(222);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(223);
        match(PascalSParser::T__20);
        setState(224);
        period(); 
      }
      setState(229);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PeriodContext ------------------------------------------------------------------

PascalSParser::PeriodContext::PeriodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalSParser::Const_variableContext *> PascalSParser::PeriodContext::const_variable() {
  return getRuleContexts<PascalSParser::Const_variableContext>();
}

PascalSParser::Const_variableContext* PascalSParser::PeriodContext::const_variable(size_t i) {
  return getRuleContext<PascalSParser::Const_variableContext>(i);
}


size_t PascalSParser::PeriodContext::getRuleIndex() const {
  return PascalSParser::RulePeriod;
}

void PascalSParser::PeriodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPeriod(this);
}

void PascalSParser::PeriodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPeriod(this);
}

PascalSParser::PeriodContext* PascalSParser::period() {
  PeriodContext *_localctx = _tracker.createInstance<PeriodContext>(_ctx, getState());
  enterRule(_localctx, 36, PascalSParser::RulePeriod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    const_variable();
    setState(231);
    match(PascalSParser::T__33);
    setState(232);
    const_variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationsContext ------------------------------------------------------------------

PascalSParser::Var_declarationsContext::Var_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Var_declarationContext* PascalSParser::Var_declarationsContext::var_declaration() {
  return getRuleContext<PascalSParser::Var_declarationContext>(0);
}


size_t PascalSParser::Var_declarationsContext::getRuleIndex() const {
  return PascalSParser::RuleVar_declarations;
}

void PascalSParser::Var_declarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declarations(this);
}

void PascalSParser::Var_declarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declarations(this);
}

PascalSParser::Var_declarationsContext* PascalSParser::var_declarations() {
  Var_declarationsContext *_localctx = _tracker.createInstance<Var_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 38, PascalSParser::RuleVar_declarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(234);
      match(PascalSParser::T__34);
      setState(235);
      var_declaration(0);
      setState(236);
      match(PascalSParser::T__19);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

PascalSParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Var_declarationContext::getRuleIndex() const {
  return PascalSParser::RuleVar_declaration;
}

void PascalSParser::Var_declarationContext::copyFrom(Var_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleVarDeclarationContext ------------------------------------------------------------------

PascalSParser::Identifier_listContext* PascalSParser::SingleVarDeclarationContext::identifier_list() {
  return getRuleContext<PascalSParser::Identifier_listContext>(0);
}

PascalSParser::TypeContext* PascalSParser::SingleVarDeclarationContext::type() {
  return getRuleContext<PascalSParser::TypeContext>(0);
}

PascalSParser::SingleVarDeclarationContext::SingleVarDeclarationContext(Var_declarationContext *ctx) { copyFrom(ctx); }

void PascalSParser::SingleVarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleVarDeclaration(this);
}
void PascalSParser::SingleVarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleVarDeclaration(this);
}
//----------------- MultiVarDeclarationContext ------------------------------------------------------------------

std::vector<PascalSParser::Var_declarationContext *> PascalSParser::MultiVarDeclarationContext::var_declaration() {
  return getRuleContexts<PascalSParser::Var_declarationContext>();
}

PascalSParser::Var_declarationContext* PascalSParser::MultiVarDeclarationContext::var_declaration(size_t i) {
  return getRuleContext<PascalSParser::Var_declarationContext>(i);
}

PascalSParser::MultiVarDeclarationContext::MultiVarDeclarationContext(Var_declarationContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiVarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiVarDeclaration(this);
}
void PascalSParser::MultiVarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiVarDeclaration(this);
}

PascalSParser::Var_declarationContext* PascalSParser::var_declaration() {
   return var_declaration(0);
}

PascalSParser::Var_declarationContext* PascalSParser::var_declaration(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, parentState);
  PascalSParser::Var_declarationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, PascalSParser::RuleVar_declaration, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SingleVarDeclarationContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(242);
    identifier_list(0);
    setState(243);
    match(PascalSParser::T__35);
    setState(244);
    type();
    _ctx->stop = _input->LT(-1);
    setState(251);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiVarDeclarationContext>(_tracker.createInstance<Var_declarationContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleVar_declaration);
        setState(246);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(247);
        match(PascalSParser::T__19);
        setState(248);
        var_declaration(3); 
      }
      setState(253);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Subprogram_declarationsContext ------------------------------------------------------------------

PascalSParser::Subprogram_declarationsContext::Subprogram_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Subprogram_declarationsContext* PascalSParser::Subprogram_declarationsContext::subprogram_declarations() {
  return getRuleContext<PascalSParser::Subprogram_declarationsContext>(0);
}

PascalSParser::Subprogram_declarationContext* PascalSParser::Subprogram_declarationsContext::subprogram_declaration() {
  return getRuleContext<PascalSParser::Subprogram_declarationContext>(0);
}


size_t PascalSParser::Subprogram_declarationsContext::getRuleIndex() const {
  return PascalSParser::RuleSubprogram_declarations;
}

void PascalSParser::Subprogram_declarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_declarations(this);
}

void PascalSParser::Subprogram_declarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_declarations(this);
}


PascalSParser::Subprogram_declarationsContext* PascalSParser::subprogram_declarations() {
   return subprogram_declarations(0);
}

PascalSParser::Subprogram_declarationsContext* PascalSParser::subprogram_declarations(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Subprogram_declarationsContext *_localctx = _tracker.createInstance<Subprogram_declarationsContext>(_ctx, parentState);
  PascalSParser::Subprogram_declarationsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, PascalSParser::RuleSubprogram_declarations, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _ctx->stop = _input->LT(-1);
    setState(261);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Subprogram_declarationsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSubprogram_declarations);
        setState(255);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(256);
        subprogram_declaration();
        setState(257);
        match(PascalSParser::T__19); 
      }
      setState(263);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Subprogram_declarationContext ------------------------------------------------------------------

PascalSParser::Subprogram_declarationContext::Subprogram_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Subprogram_headContext* PascalSParser::Subprogram_declarationContext::subprogram_head() {
  return getRuleContext<PascalSParser::Subprogram_headContext>(0);
}

PascalSParser::Program_bodyContext* PascalSParser::Subprogram_declarationContext::program_body() {
  return getRuleContext<PascalSParser::Program_bodyContext>(0);
}


size_t PascalSParser::Subprogram_declarationContext::getRuleIndex() const {
  return PascalSParser::RuleSubprogram_declaration;
}

void PascalSParser::Subprogram_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_declaration(this);
}

void PascalSParser::Subprogram_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_declaration(this);
}

PascalSParser::Subprogram_declarationContext* PascalSParser::subprogram_declaration() {
  Subprogram_declarationContext *_localctx = _tracker.createInstance<Subprogram_declarationContext>(_ctx, getState());
  enterRule(_localctx, 44, PascalSParser::RuleSubprogram_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    subprogram_head();
    setState(265);
    program_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_headContext ------------------------------------------------------------------

PascalSParser::Subprogram_headContext::Subprogram_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Subprogram_headContext::getRuleIndex() const {
  return PascalSParser::RuleSubprogram_head;
}

void PascalSParser::Subprogram_headContext::copyFrom(Subprogram_headContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::FunctionDeclarationContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Formal_parameterContext* PascalSParser::FunctionDeclarationContext::formal_parameter() {
  return getRuleContext<PascalSParser::Formal_parameterContext>(0);
}

PascalSParser::Standard_typeContext* PascalSParser::FunctionDeclarationContext::standard_type() {
  return getRuleContext<PascalSParser::Standard_typeContext>(0);
}

PascalSParser::FunctionDeclarationContext::FunctionDeclarationContext(Subprogram_headContext *ctx) { copyFrom(ctx); }

void PascalSParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}
void PascalSParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}
//----------------- ProcedureDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::ProcedureDeclarationContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Formal_parameterContext* PascalSParser::ProcedureDeclarationContext::formal_parameter() {
  return getRuleContext<PascalSParser::Formal_parameterContext>(0);
}

PascalSParser::ProcedureDeclarationContext::ProcedureDeclarationContext(Subprogram_headContext *ctx) { copyFrom(ctx); }

void PascalSParser::ProcedureDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureDeclaration(this);
}
void PascalSParser::ProcedureDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureDeclaration(this);
}
PascalSParser::Subprogram_headContext* PascalSParser::subprogram_head() {
  Subprogram_headContext *_localctx = _tracker.createInstance<Subprogram_headContext>(_ctx, getState());
  enterRule(_localctx, 46, PascalSParser::RuleSubprogram_head);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__36: {
        _localctx = dynamic_cast<Subprogram_headContext *>(_tracker.createInstance<PascalSParser::FunctionDeclarationContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(267);
        match(PascalSParser::T__36);
        setState(268);
        match(PascalSParser::ID);
        setState(269);
        formal_parameter();
        setState(270);
        match(PascalSParser::T__35);
        setState(271);
        standard_type();
        setState(272);
        match(PascalSParser::T__19);
        break;
      }

      case PascalSParser::T__37: {
        _localctx = dynamic_cast<Subprogram_headContext *>(_tracker.createInstance<PascalSParser::ProcedureDeclarationContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(274);
        match(PascalSParser::T__37);
        setState(275);
        match(PascalSParser::ID);
        setState(276);
        formal_parameter();
        setState(277);
        match(PascalSParser::T__19);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_parameterContext ------------------------------------------------------------------

PascalSParser::Formal_parameterContext::Formal_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Parameter_listsContext* PascalSParser::Formal_parameterContext::parameter_lists() {
  return getRuleContext<PascalSParser::Parameter_listsContext>(0);
}


size_t PascalSParser::Formal_parameterContext::getRuleIndex() const {
  return PascalSParser::RuleFormal_parameter;
}

void PascalSParser::Formal_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormal_parameter(this);
}

void PascalSParser::Formal_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormal_parameter(this);
}

PascalSParser::Formal_parameterContext* PascalSParser::formal_parameter() {
  Formal_parameterContext *_localctx = _tracker.createInstance<Formal_parameterContext>(_ctx, getState());
  enterRule(_localctx, 48, PascalSParser::RuleFormal_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__17: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        match(PascalSParser::T__17);
        setState(282);
        parameter_lists(0);
        setState(283);
        match(PascalSParser::T__18);
        break;
      }

      case PascalSParser::T__19:
      case PascalSParser::T__35: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listsContext ------------------------------------------------------------------

PascalSParser::Parameter_listsContext::Parameter_listsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Parameter_listsContext::getRuleIndex() const {
  return PascalSParser::RuleParameter_lists;
}

void PascalSParser::Parameter_listsContext::copyFrom(Parameter_listsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultiParaContext ------------------------------------------------------------------

PascalSParser::Parameter_listsContext* PascalSParser::MultiParaContext::parameter_lists() {
  return getRuleContext<PascalSParser::Parameter_listsContext>(0);
}

PascalSParser::Parameter_listContext* PascalSParser::MultiParaContext::parameter_list() {
  return getRuleContext<PascalSParser::Parameter_listContext>(0);
}

PascalSParser::MultiParaContext::MultiParaContext(Parameter_listsContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiParaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiPara(this);
}
void PascalSParser::MultiParaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiPara(this);
}
//----------------- SingleParaContext ------------------------------------------------------------------

PascalSParser::Parameter_listContext* PascalSParser::SingleParaContext::parameter_list() {
  return getRuleContext<PascalSParser::Parameter_listContext>(0);
}

PascalSParser::SingleParaContext::SingleParaContext(Parameter_listsContext *ctx) { copyFrom(ctx); }

void PascalSParser::SingleParaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSinglePara(this);
}
void PascalSParser::SingleParaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSinglePara(this);
}

PascalSParser::Parameter_listsContext* PascalSParser::parameter_lists() {
   return parameter_lists(0);
}

PascalSParser::Parameter_listsContext* PascalSParser::parameter_lists(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Parameter_listsContext *_localctx = _tracker.createInstance<Parameter_listsContext>(_ctx, parentState);
  PascalSParser::Parameter_listsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, PascalSParser::RuleParameter_lists, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SingleParaContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(289);
    parameter_list();
    _ctx->stop = _input->LT(-1);
    setState(296);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiParaContext>(_tracker.createInstance<Parameter_listsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleParameter_lists);
        setState(291);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(292);
        match(PascalSParser::T__19);
        setState(293);
        parameter_list(); 
      }
      setState(298);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

PascalSParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Parameter_listContext::getRuleIndex() const {
  return PascalSParser::RuleParameter_list;
}

void PascalSParser::Parameter_listContext::copyFrom(Parameter_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarParaContext ------------------------------------------------------------------

PascalSParser::Var_parameterContext* PascalSParser::VarParaContext::var_parameter() {
  return getRuleContext<PascalSParser::Var_parameterContext>(0);
}

PascalSParser::VarParaContext::VarParaContext(Parameter_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::VarParaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarPara(this);
}
void PascalSParser::VarParaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarPara(this);
}
//----------------- ValueParaContext ------------------------------------------------------------------

PascalSParser::Value_parameterContext* PascalSParser::ValueParaContext::value_parameter() {
  return getRuleContext<PascalSParser::Value_parameterContext>(0);
}

PascalSParser::ValueParaContext::ValueParaContext(Parameter_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::ValueParaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValuePara(this);
}
void PascalSParser::ValueParaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValuePara(this);
}
PascalSParser::Parameter_listContext* PascalSParser::parameter_list() {
  Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 52, PascalSParser::RuleParameter_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__34: {
        _localctx = dynamic_cast<Parameter_listContext *>(_tracker.createInstance<PascalSParser::VarParaContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(299);
        var_parameter();
        break;
      }

      case PascalSParser::ID: {
        _localctx = dynamic_cast<Parameter_listContext *>(_tracker.createInstance<PascalSParser::ValueParaContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(300);
        value_parameter();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_parameterContext ------------------------------------------------------------------

PascalSParser::Var_parameterContext::Var_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Value_parameterContext* PascalSParser::Var_parameterContext::value_parameter() {
  return getRuleContext<PascalSParser::Value_parameterContext>(0);
}


size_t PascalSParser::Var_parameterContext::getRuleIndex() const {
  return PascalSParser::RuleVar_parameter;
}

void PascalSParser::Var_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_parameter(this);
}

void PascalSParser::Var_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_parameter(this);
}

PascalSParser::Var_parameterContext* PascalSParser::var_parameter() {
  Var_parameterContext *_localctx = _tracker.createInstance<Var_parameterContext>(_ctx, getState());
  enterRule(_localctx, 54, PascalSParser::RuleVar_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(PascalSParser::T__34);
    setState(304);
    value_parameter();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_parameterContext ------------------------------------------------------------------

PascalSParser::Value_parameterContext::Value_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Identifier_listContext* PascalSParser::Value_parameterContext::identifier_list() {
  return getRuleContext<PascalSParser::Identifier_listContext>(0);
}

PascalSParser::Standard_typeContext* PascalSParser::Value_parameterContext::standard_type() {
  return getRuleContext<PascalSParser::Standard_typeContext>(0);
}


size_t PascalSParser::Value_parameterContext::getRuleIndex() const {
  return PascalSParser::RuleValue_parameter;
}

void PascalSParser::Value_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_parameter(this);
}

void PascalSParser::Value_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_parameter(this);
}

PascalSParser::Value_parameterContext* PascalSParser::value_parameter() {
  Value_parameterContext *_localctx = _tracker.createInstance<Value_parameterContext>(_ctx, getState());
  enterRule(_localctx, 56, PascalSParser::RuleValue_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    identifier_list(0);
    setState(307);
    match(PascalSParser::T__35);
    setState(308);
    standard_type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

PascalSParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Statement_listContext* PascalSParser::Compound_statementContext::statement_list() {
  return getRuleContext<PascalSParser::Statement_listContext>(0);
}


size_t PascalSParser::Compound_statementContext::getRuleIndex() const {
  return PascalSParser::RuleCompound_statement;
}

void PascalSParser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void PascalSParser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

PascalSParser::Compound_statementContext* PascalSParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 58, PascalSParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(PascalSParser::T__38);
    setState(311);
    statement_list(0);
    setState(312);
    match(PascalSParser::T__24);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_listContext ------------------------------------------------------------------

PascalSParser::Statement_listContext::Statement_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Statement_listContext::getRuleIndex() const {
  return PascalSParser::RuleStatement_list;
}

void PascalSParser::Statement_listContext::copyFrom(Statement_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultiStatementContext ------------------------------------------------------------------

PascalSParser::Statement_listContext* PascalSParser::MultiStatementContext::statement_list() {
  return getRuleContext<PascalSParser::Statement_listContext>(0);
}

PascalSParser::StatementContext* PascalSParser::MultiStatementContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::MultiStatementContext::MultiStatementContext(Statement_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiStatement(this);
}
void PascalSParser::MultiStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiStatement(this);
}
//----------------- SingleStatementContext ------------------------------------------------------------------

PascalSParser::StatementContext* PascalSParser::SingleStatementContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::SingleStatementContext::SingleStatementContext(Statement_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::SingleStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleStatement(this);
}
void PascalSParser::SingleStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleStatement(this);
}

PascalSParser::Statement_listContext* PascalSParser::statement_list() {
   return statement_list(0);
}

PascalSParser::Statement_listContext* PascalSParser::statement_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Statement_listContext *_localctx = _tracker.createInstance<Statement_listContext>(_ctx, parentState);
  PascalSParser::Statement_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, PascalSParser::RuleStatement_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SingleStatementContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(315);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(322);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiStatementContext>(_tracker.createInstance<Statement_listContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatement_list);
        setState(317);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(318);
        match(PascalSParser::T__19);
        setState(319);
        statement(); 
      }
      setState(324);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PascalSParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::StatementContext::getRuleIndex() const {
  return PascalSParser::RuleStatement;
}

void PascalSParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

PascalSParser::Call_procedure_statementContext* PascalSParser::CallContext::call_procedure_statement() {
  return getRuleContext<PascalSParser::Call_procedure_statementContext>(0);
}

PascalSParser::CallContext::CallContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void PascalSParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}
//----------------- ForContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::ForContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::AssignopContext* PascalSParser::ForContext::assignop() {
  return getRuleContext<PascalSParser::AssignopContext>(0);
}

std::vector<PascalSParser::ExpressionContext *> PascalSParser::ForContext::expression() {
  return getRuleContexts<PascalSParser::ExpressionContext>();
}

PascalSParser::ExpressionContext* PascalSParser::ForContext::expression(size_t i) {
  return getRuleContext<PascalSParser::ExpressionContext>(i);
}

PascalSParser::UpdownContext* PascalSParser::ForContext::updown() {
  return getRuleContext<PascalSParser::UpdownContext>(0);
}

PascalSParser::StatementContext* PascalSParser::ForContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::ForContext::ForContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::ForContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor(this);
}
void PascalSParser::ForContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor(this);
}
//----------------- BlockContext ------------------------------------------------------------------

PascalSParser::Compound_statementContext* PascalSParser::BlockContext::compound_statement() {
  return getRuleContext<PascalSParser::Compound_statementContext>(0);
}

PascalSParser::BlockContext::BlockContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}
void PascalSParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}
//----------------- AssignContext ------------------------------------------------------------------

PascalSParser::VariableContext* PascalSParser::AssignContext::variable() {
  return getRuleContext<PascalSParser::VariableContext>(0);
}

PascalSParser::AssignopContext* PascalSParser::AssignContext::assignop() {
  return getRuleContext<PascalSParser::AssignopContext>(0);
}

PascalSParser::ExpressionContext* PascalSParser::AssignContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::AssignContext::AssignContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}
void PascalSParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}
//----------------- RepeatContext ------------------------------------------------------------------

PascalSParser::Repeat_bodyContext* PascalSParser::RepeatContext::repeat_body() {
  return getRuleContext<PascalSParser::Repeat_bodyContext>(0);
}

PascalSParser::Repeat_conditionContext* PascalSParser::RepeatContext::repeat_condition() {
  return getRuleContext<PascalSParser::Repeat_conditionContext>(0);
}

PascalSParser::RepeatContext::RepeatContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::RepeatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeat(this);
}
void PascalSParser::RepeatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeat(this);
}
//----------------- WhileContext ------------------------------------------------------------------

PascalSParser::While_conditionContext* PascalSParser::WhileContext::while_condition() {
  return getRuleContext<PascalSParser::While_conditionContext>(0);
}

PascalSParser::While_bodyContext* PascalSParser::WhileContext::while_body() {
  return getRuleContext<PascalSParser::While_bodyContext>(0);
}

PascalSParser::WhileContext::WhileContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}
void PascalSParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}
//----------------- IfContext ------------------------------------------------------------------

PascalSParser::If_conditionContext* PascalSParser::IfContext::if_condition() {
  return getRuleContext<PascalSParser::If_conditionContext>(0);
}

PascalSParser::Then_statementContext* PascalSParser::IfContext::then_statement() {
  return getRuleContext<PascalSParser::Then_statementContext>(0);
}

PascalSParser::Else_partContext* PascalSParser::IfContext::else_part() {
  return getRuleContext<PascalSParser::Else_partContext>(0);
}

PascalSParser::IfContext::IfContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}
void PascalSParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}
//----------------- NoneContext ------------------------------------------------------------------

PascalSParser::NoneContext::NoneContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::NoneContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNone(this);
}
void PascalSParser::NoneContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNone(this);
}
//----------------- CaseContext ------------------------------------------------------------------

PascalSParser::ExpressionContext* PascalSParser::CaseContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::Case_bodyContext* PascalSParser::CaseContext::case_body() {
  return getRuleContext<PascalSParser::Case_bodyContext>(0);
}

PascalSParser::CaseContext::CaseContext(StatementContext *ctx) { copyFrom(ctx); }

void PascalSParser::CaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase(this);
}
void PascalSParser::CaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase(this);
}
PascalSParser::StatementContext* PascalSParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 62, PascalSParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::BlockContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(325);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(326);
      variable();
      setState(327);
      assignop();
      setState(328);
      expression();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::CallContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(330);
      call_procedure_statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::IfContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(331);
      match(PascalSParser::T__39);
      setState(332);
      if_condition();
      setState(333);
      match(PascalSParser::T__40);
      setState(334);
      then_statement();
      setState(335);
      else_part();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::CaseContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(337);
      match(PascalSParser::T__41);
      setState(338);
      expression();
      setState(339);
      match(PascalSParser::T__28);
      setState(340);
      case_body();
      setState(341);
      match(PascalSParser::T__24);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(343);
      match(PascalSParser::T__42);
      setState(344);
      while_condition();
      setState(345);
      match(PascalSParser::T__43);
      setState(346);
      while_body();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::RepeatContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(348);
      match(PascalSParser::T__44);
      setState(349);
      repeat_body();
      setState(350);
      match(PascalSParser::T__45);
      setState(351);
      repeat_condition();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::ForContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(353);
      match(PascalSParser::T__46);
      setState(354);
      match(PascalSParser::ID);
      setState(355);
      assignop();
      setState(356);
      expression();
      setState(357);
      updown();
      setState(358);
      expression();
      setState(359);
      match(PascalSParser::T__43);
      setState(360);
      statement();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::NoneContext>(_localctx));
      enterOuterAlt(_localctx, 9);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_conditionContext ------------------------------------------------------------------

PascalSParser::While_conditionContext::While_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ExpressionContext* PascalSParser::While_conditionContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}


size_t PascalSParser::While_conditionContext::getRuleIndex() const {
  return PascalSParser::RuleWhile_condition;
}

void PascalSParser::While_conditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_condition(this);
}

void PascalSParser::While_conditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_condition(this);
}

PascalSParser::While_conditionContext* PascalSParser::while_condition() {
  While_conditionContext *_localctx = _tracker.createInstance<While_conditionContext>(_ctx, getState());
  enterRule(_localctx, 64, PascalSParser::RuleWhile_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_bodyContext ------------------------------------------------------------------

PascalSParser::While_bodyContext::While_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::StatementContext* PascalSParser::While_bodyContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}


size_t PascalSParser::While_bodyContext::getRuleIndex() const {
  return PascalSParser::RuleWhile_body;
}

void PascalSParser::While_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_body(this);
}

void PascalSParser::While_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_body(this);
}

PascalSParser::While_bodyContext* PascalSParser::while_body() {
  While_bodyContext *_localctx = _tracker.createInstance<While_bodyContext>(_ctx, getState());
  enterRule(_localctx, 66, PascalSParser::RuleWhile_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

PascalSParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::VariableContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Id_varpartsContext* PascalSParser::VariableContext::id_varparts() {
  return getRuleContext<PascalSParser::Id_varpartsContext>(0);
}


size_t PascalSParser::VariableContext::getRuleIndex() const {
  return PascalSParser::RuleVariable;
}

void PascalSParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void PascalSParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

PascalSParser::VariableContext* PascalSParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 68, PascalSParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(PascalSParser::ID);
    setState(370);
    id_varparts(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_varpartsContext ------------------------------------------------------------------

PascalSParser::Id_varpartsContext::Id_varpartsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Id_varpartsContext* PascalSParser::Id_varpartsContext::id_varparts() {
  return getRuleContext<PascalSParser::Id_varpartsContext>(0);
}

PascalSParser::Id_varpartContext* PascalSParser::Id_varpartsContext::id_varpart() {
  return getRuleContext<PascalSParser::Id_varpartContext>(0);
}


size_t PascalSParser::Id_varpartsContext::getRuleIndex() const {
  return PascalSParser::RuleId_varparts;
}

void PascalSParser::Id_varpartsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_varparts(this);
}

void PascalSParser::Id_varpartsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_varparts(this);
}


PascalSParser::Id_varpartsContext* PascalSParser::id_varparts() {
   return id_varparts(0);
}

PascalSParser::Id_varpartsContext* PascalSParser::id_varparts(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Id_varpartsContext *_localctx = _tracker.createInstance<Id_varpartsContext>(_ctx, parentState);
  PascalSParser::Id_varpartsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, PascalSParser::RuleId_varparts, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _ctx->stop = _input->LT(-1);
    setState(377);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Id_varpartsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleId_varparts);
        setState(373);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(374);
        id_varpart(); 
      }
      setState(379);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Id_varpartContext ------------------------------------------------------------------

PascalSParser::Id_varpartContext::Id_varpartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Id_varpartContext::getRuleIndex() const {
  return PascalSParser::RuleId_varpart;
}

void PascalSParser::Id_varpartContext::copyFrom(Id_varpartContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayAccessContext ------------------------------------------------------------------

PascalSParser::Expression_listContext* PascalSParser::ArrayAccessContext::expression_list() {
  return getRuleContext<PascalSParser::Expression_listContext>(0);
}

PascalSParser::ArrayAccessContext::ArrayAccessContext(Id_varpartContext *ctx) { copyFrom(ctx); }

void PascalSParser::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}
void PascalSParser::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}
//----------------- RecordAccessContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::RecordAccessContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::RecordAccessContext::RecordAccessContext(Id_varpartContext *ctx) { copyFrom(ctx); }

void PascalSParser::RecordAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecordAccess(this);
}
void PascalSParser::RecordAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecordAccess(this);
}
PascalSParser::Id_varpartContext* PascalSParser::id_varpart() {
  Id_varpartContext *_localctx = _tracker.createInstance<Id_varpartContext>(_ctx, getState());
  enterRule(_localctx, 72, PascalSParser::RuleId_varpart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__26: {
        _localctx = dynamic_cast<Id_varpartContext *>(_tracker.createInstance<PascalSParser::ArrayAccessContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(380);
        match(PascalSParser::T__26);
        setState(381);
        expression_list(0);
        setState(382);
        match(PascalSParser::T__27);
        break;
      }

      case PascalSParser::T__15: {
        _localctx = dynamic_cast<Id_varpartContext *>(_tracker.createInstance<PascalSParser::RecordAccessContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(384);
        match(PascalSParser::T__15);
        setState(385);
        match(PascalSParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_partContext ------------------------------------------------------------------

PascalSParser::Else_partContext::Else_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::StatementContext* PascalSParser::Else_partContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}


size_t PascalSParser::Else_partContext::getRuleIndex() const {
  return PascalSParser::RuleElse_part;
}

void PascalSParser::Else_partContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_part(this);
}

void PascalSParser::Else_partContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_part(this);
}

PascalSParser::Else_partContext* PascalSParser::else_part() {
  Else_partContext *_localctx = _tracker.createInstance<Else_partContext>(_ctx, getState());
  enterRule(_localctx, 74, PascalSParser::RuleElse_part);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(388);
      match(PascalSParser::T__47);
      setState(389);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Then_statementContext ------------------------------------------------------------------

PascalSParser::Then_statementContext::Then_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::StatementContext* PascalSParser::Then_statementContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}


size_t PascalSParser::Then_statementContext::getRuleIndex() const {
  return PascalSParser::RuleThen_statement;
}

void PascalSParser::Then_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThen_statement(this);
}

void PascalSParser::Then_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThen_statement(this);
}

PascalSParser::Then_statementContext* PascalSParser::then_statement() {
  Then_statementContext *_localctx = _tracker.createInstance<Then_statementContext>(_ctx, getState());
  enterRule(_localctx, 76, PascalSParser::RuleThen_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_conditionContext ------------------------------------------------------------------

PascalSParser::If_conditionContext::If_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ExpressionContext* PascalSParser::If_conditionContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}


size_t PascalSParser::If_conditionContext::getRuleIndex() const {
  return PascalSParser::RuleIf_condition;
}

void PascalSParser::If_conditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_condition(this);
}

void PascalSParser::If_conditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_condition(this);
}

PascalSParser::If_conditionContext* PascalSParser::if_condition() {
  If_conditionContext *_localctx = _tracker.createInstance<If_conditionContext>(_ctx, getState());
  enterRule(_localctx, 78, PascalSParser::RuleIf_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_bodyContext ------------------------------------------------------------------

PascalSParser::Case_bodyContext::Case_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Branch_listContext* PascalSParser::Case_bodyContext::branch_list() {
  return getRuleContext<PascalSParser::Branch_listContext>(0);
}


size_t PascalSParser::Case_bodyContext::getRuleIndex() const {
  return PascalSParser::RuleCase_body;
}

void PascalSParser::Case_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_body(this);
}

void PascalSParser::Case_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_body(this);
}

PascalSParser::Case_bodyContext* PascalSParser::case_body() {
  Case_bodyContext *_localctx = _tracker.createInstance<Case_bodyContext>(_ctx, getState());
  enterRule(_localctx, 80, PascalSParser::RuleCase_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(399);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__7:
      case PascalSParser::T__8:
      case PascalSParser::CONST_CHAR:
      case PascalSParser::ID:
      case PascalSParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(397);
        branch_list(0);
        break;
      }

      case PascalSParser::T__24: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Branch_listContext ------------------------------------------------------------------

PascalSParser::Branch_listContext::Branch_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::BranchContext* PascalSParser::Branch_listContext::branch() {
  return getRuleContext<PascalSParser::BranchContext>(0);
}

PascalSParser::Branch_listContext* PascalSParser::Branch_listContext::branch_list() {
  return getRuleContext<PascalSParser::Branch_listContext>(0);
}


size_t PascalSParser::Branch_listContext::getRuleIndex() const {
  return PascalSParser::RuleBranch_list;
}

void PascalSParser::Branch_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBranch_list(this);
}

void PascalSParser::Branch_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBranch_list(this);
}


PascalSParser::Branch_listContext* PascalSParser::branch_list() {
   return branch_list(0);
}

PascalSParser::Branch_listContext* PascalSParser::branch_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Branch_listContext *_localctx = _tracker.createInstance<Branch_listContext>(_ctx, parentState);
  PascalSParser::Branch_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, PascalSParser::RuleBranch_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(402);
    branch();
    _ctx->stop = _input->LT(-1);
    setState(409);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Branch_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBranch_list);
        setState(404);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(405);
        match(PascalSParser::T__19);
        setState(406);
        branch(); 
      }
      setState(411);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BranchContext ------------------------------------------------------------------

PascalSParser::BranchContext::BranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Const_listContext* PascalSParser::BranchContext::const_list() {
  return getRuleContext<PascalSParser::Const_listContext>(0);
}

PascalSParser::StatementContext* PascalSParser::BranchContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}


size_t PascalSParser::BranchContext::getRuleIndex() const {
  return PascalSParser::RuleBranch;
}

void PascalSParser::BranchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBranch(this);
}

void PascalSParser::BranchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBranch(this);
}

PascalSParser::BranchContext* PascalSParser::branch() {
  BranchContext *_localctx = _tracker.createInstance<BranchContext>(_ctx, getState());
  enterRule(_localctx, 84, PascalSParser::RuleBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    const_list(0);
    setState(413);
    match(PascalSParser::T__35);
    setState(414);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_listContext ------------------------------------------------------------------

PascalSParser::Const_listContext::Const_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Const_listContext::getRuleIndex() const {
  return PascalSParser::RuleConst_list;
}

void PascalSParser::Const_listContext::copyFrom(Const_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleConstListContext ------------------------------------------------------------------

PascalSParser::Const_variableContext* PascalSParser::SingleConstListContext::const_variable() {
  return getRuleContext<PascalSParser::Const_variableContext>(0);
}

PascalSParser::SingleConstListContext::SingleConstListContext(Const_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::SingleConstListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleConstList(this);
}
void PascalSParser::SingleConstListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleConstList(this);
}
//----------------- MultiConstListContext ------------------------------------------------------------------

PascalSParser::Const_listContext* PascalSParser::MultiConstListContext::const_list() {
  return getRuleContext<PascalSParser::Const_listContext>(0);
}

PascalSParser::Const_variableContext* PascalSParser::MultiConstListContext::const_variable() {
  return getRuleContext<PascalSParser::Const_variableContext>(0);
}

PascalSParser::MultiConstListContext::MultiConstListContext(Const_listContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiConstListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiConstList(this);
}
void PascalSParser::MultiConstListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiConstList(this);
}

PascalSParser::Const_listContext* PascalSParser::const_list() {
   return const_list(0);
}

PascalSParser::Const_listContext* PascalSParser::const_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Const_listContext *_localctx = _tracker.createInstance<Const_listContext>(_ctx, parentState);
  PascalSParser::Const_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, PascalSParser::RuleConst_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<SingleConstListContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(417);
    const_variable();
    _ctx->stop = _input->LT(-1);
    setState(424);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiConstListContext>(_tracker.createInstance<Const_listContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleConst_list);
        setState(419);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(420);
        match(PascalSParser::T__20);
        setState(421);
        const_variable(); 
      }
      setState(426);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UpdownContext ------------------------------------------------------------------

PascalSParser::UpdownContext::UpdownContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::UpdownContext::getRuleIndex() const {
  return PascalSParser::RuleUpdown;
}

void PascalSParser::UpdownContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdown(this);
}

void PascalSParser::UpdownContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdown(this);
}

PascalSParser::UpdownContext* PascalSParser::updown() {
  UpdownContext *_localctx = _tracker.createInstance<UpdownContext>(_ctx, getState());
  enterRule(_localctx, 88, PascalSParser::RuleUpdown);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    _la = _input->LA(1);
    if (!(_la == PascalSParser::T__48

    || _la == PascalSParser::T__49)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Repeat_conditionContext ------------------------------------------------------------------

PascalSParser::Repeat_conditionContext::Repeat_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ExpressionContext* PascalSParser::Repeat_conditionContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}


size_t PascalSParser::Repeat_conditionContext::getRuleIndex() const {
  return PascalSParser::RuleRepeat_condition;
}

void PascalSParser::Repeat_conditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeat_condition(this);
}

void PascalSParser::Repeat_conditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeat_condition(this);
}

PascalSParser::Repeat_conditionContext* PascalSParser::repeat_condition() {
  Repeat_conditionContext *_localctx = _tracker.createInstance<Repeat_conditionContext>(_ctx, getState());
  enterRule(_localctx, 90, PascalSParser::RuleRepeat_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Repeat_bodyContext ------------------------------------------------------------------

PascalSParser::Repeat_bodyContext::Repeat_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::Statement_listContext* PascalSParser::Repeat_bodyContext::statement_list() {
  return getRuleContext<PascalSParser::Statement_listContext>(0);
}


size_t PascalSParser::Repeat_bodyContext::getRuleIndex() const {
  return PascalSParser::RuleRepeat_body;
}

void PascalSParser::Repeat_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeat_body(this);
}

void PascalSParser::Repeat_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeat_body(this);
}

PascalSParser::Repeat_bodyContext* PascalSParser::repeat_body() {
  Repeat_bodyContext *_localctx = _tracker.createInstance<Repeat_bodyContext>(_ctx, getState());
  enterRule(_localctx, 92, PascalSParser::RuleRepeat_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    statement_list(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_procedure_statementContext ------------------------------------------------------------------

PascalSParser::Call_procedure_statementContext::Call_procedure_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Call_procedure_statementContext::getRuleIndex() const {
  return PascalSParser::RuleCall_procedure_statement;
}

void PascalSParser::Call_procedure_statementContext::copyFrom(Call_procedure_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallWithParaContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::CallWithParaContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Expression_listContext* PascalSParser::CallWithParaContext::expression_list() {
  return getRuleContext<PascalSParser::Expression_listContext>(0);
}

PascalSParser::CallWithParaContext::CallWithParaContext(Call_procedure_statementContext *ctx) { copyFrom(ctx); }

void PascalSParser::CallWithParaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallWithPara(this);
}
void PascalSParser::CallWithParaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallWithPara(this);
}
//----------------- CallWritelnContext ------------------------------------------------------------------

PascalSParser::Expression_listContext* PascalSParser::CallWritelnContext::expression_list() {
  return getRuleContext<PascalSParser::Expression_listContext>(0);
}

PascalSParser::CallWritelnContext::CallWritelnContext(Call_procedure_statementContext *ctx) { copyFrom(ctx); }

void PascalSParser::CallWritelnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallWriteln(this);
}
void PascalSParser::CallWritelnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallWriteln(this);
}
//----------------- CallWithNoParaContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::CallWithNoParaContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::CallWithNoParaContext::CallWithNoParaContext(Call_procedure_statementContext *ctx) { copyFrom(ctx); }

void PascalSParser::CallWithNoParaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallWithNoPara(this);
}
void PascalSParser::CallWithNoParaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallWithNoPara(this);
}
//----------------- CallReadlnContext ------------------------------------------------------------------

PascalSParser::VariableContext* PascalSParser::CallReadlnContext::variable() {
  return getRuleContext<PascalSParser::VariableContext>(0);
}

PascalSParser::CallReadlnContext::CallReadlnContext(Call_procedure_statementContext *ctx) { copyFrom(ctx); }

void PascalSParser::CallReadlnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallReadln(this);
}
void PascalSParser::CallReadlnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallReadln(this);
}
PascalSParser::Call_procedure_statementContext* PascalSParser::call_procedure_statement() {
  Call_procedure_statementContext *_localctx = _tracker.createInstance<Call_procedure_statementContext>(_ctx, getState());
  enterRule(_localctx, 94, PascalSParser::RuleCall_procedure_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(449);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallWithNoParaContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(433);
      match(PascalSParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallWithParaContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(434);
      match(PascalSParser::ID);
      setState(435);
      match(PascalSParser::T__17);
      setState(436);
      expression_list(0);
      setState(437);
      match(PascalSParser::T__18);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallWritelnContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(439);
      match(PascalSParser::T__50);
      setState(440);
      match(PascalSParser::T__17);
      setState(441);
      expression_list(0);
      setState(442);
      match(PascalSParser::T__18);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallReadlnContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(444);
      match(PascalSParser::T__51);
      setState(445);
      match(PascalSParser::T__17);
      setState(446);
      variable();
      setState(447);
      match(PascalSParser::T__18);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_listContext ------------------------------------------------------------------

PascalSParser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ExpressionContext* PascalSParser::Expression_listContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::Expression_listContext* PascalSParser::Expression_listContext::expression_list() {
  return getRuleContext<PascalSParser::Expression_listContext>(0);
}


size_t PascalSParser::Expression_listContext::getRuleIndex() const {
  return PascalSParser::RuleExpression_list;
}

void PascalSParser::Expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_list(this);
}

void PascalSParser::Expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_list(this);
}


PascalSParser::Expression_listContext* PascalSParser::expression_list() {
   return expression_list(0);
}

PascalSParser::Expression_listContext* PascalSParser::expression_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, parentState);
  PascalSParser::Expression_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 96;
  enterRecursionRule(_localctx, 96, PascalSParser::RuleExpression_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(452);
    expression();
    _ctx->stop = _input->LT(-1);
    setState(459);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expression_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression_list);
        setState(454);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(455);
        match(PascalSParser::T__20);
        setState(456);
        expression(); 
      }
      setState(461);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PascalSParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::ExpressionContext::getRuleIndex() const {
  return PascalSParser::RuleExpression;
}

void PascalSParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NoRalationOperationContext ------------------------------------------------------------------

PascalSParser::Simple_expressionContext* PascalSParser::NoRalationOperationContext::simple_expression() {
  return getRuleContext<PascalSParser::Simple_expressionContext>(0);
}

PascalSParser::NoRalationOperationContext::NoRalationOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PascalSParser::NoRalationOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoRalationOperation(this);
}
void PascalSParser::NoRalationOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoRalationOperation(this);
}
//----------------- RelationOperationContext ------------------------------------------------------------------

std::vector<PascalSParser::Simple_expressionContext *> PascalSParser::RelationOperationContext::simple_expression() {
  return getRuleContexts<PascalSParser::Simple_expressionContext>();
}

PascalSParser::Simple_expressionContext* PascalSParser::RelationOperationContext::simple_expression(size_t i) {
  return getRuleContext<PascalSParser::Simple_expressionContext>(i);
}

PascalSParser::RelopContext* PascalSParser::RelationOperationContext::relop() {
  return getRuleContext<PascalSParser::RelopContext>(0);
}

PascalSParser::RelationOperationContext::RelationOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PascalSParser::RelationOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationOperation(this);
}
void PascalSParser::RelationOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationOperation(this);
}
PascalSParser::ExpressionContext* PascalSParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 98, PascalSParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(467);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<PascalSParser::RelationOperationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(462);
      simple_expression(0);
      setState(463);
      relop();
      setState(464);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<PascalSParser::NoRalationOperationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(466);
      simple_expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

PascalSParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Simple_expressionContext::getRuleIndex() const {
  return PascalSParser::RuleSimple_expression;
}

void PascalSParser::Simple_expressionContext::copyFrom(Simple_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PositiveTermContext ------------------------------------------------------------------

PascalSParser::TermContext* PascalSParser::PositiveTermContext::term() {
  return getRuleContext<PascalSParser::TermContext>(0);
}

PascalSParser::PositiveTermContext::PositiveTermContext(Simple_expressionContext *ctx) { copyFrom(ctx); }

void PascalSParser::PositiveTermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositiveTerm(this);
}
void PascalSParser::PositiveTermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositiveTerm(this);
}
//----------------- AddOperationContext ------------------------------------------------------------------

PascalSParser::Simple_expressionContext* PascalSParser::AddOperationContext::simple_expression() {
  return getRuleContext<PascalSParser::Simple_expressionContext>(0);
}

PascalSParser::AddopContext* PascalSParser::AddOperationContext::addop() {
  return getRuleContext<PascalSParser::AddopContext>(0);
}

PascalSParser::TermContext* PascalSParser::AddOperationContext::term() {
  return getRuleContext<PascalSParser::TermContext>(0);
}

PascalSParser::AddOperationContext::AddOperationContext(Simple_expressionContext *ctx) { copyFrom(ctx); }

void PascalSParser::AddOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOperation(this);
}
void PascalSParser::AddOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOperation(this);
}
//----------------- NegativeTermContext ------------------------------------------------------------------

PascalSParser::TermContext* PascalSParser::NegativeTermContext::term() {
  return getRuleContext<PascalSParser::TermContext>(0);
}

PascalSParser::NegativeTermContext::NegativeTermContext(Simple_expressionContext *ctx) { copyFrom(ctx); }

void PascalSParser::NegativeTermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegativeTerm(this);
}
void PascalSParser::NegativeTermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegativeTerm(this);
}

PascalSParser::Simple_expressionContext* PascalSParser::simple_expression() {
   return simple_expression(0);
}

PascalSParser::Simple_expressionContext* PascalSParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  PascalSParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 100;
  enterRecursionRule(_localctx, 100, PascalSParser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(475);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__17:
      case PascalSParser::T__52:
      case PascalSParser::CONST_CHAR:
      case PascalSParser::ID:
      case PascalSParser::NUMBER: {
        _localctx = _tracker.createInstance<PositiveTermContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(470);
        term(0);
        break;
      }

      case PascalSParser::T__7: {
        _localctx = _tracker.createInstance<PositiveTermContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(471);
        match(PascalSParser::T__7);
        setState(472);
        term(0);
        break;
      }

      case PascalSParser::T__8: {
        _localctx = _tracker.createInstance<NegativeTermContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(473);
        match(PascalSParser::T__8);
        setState(474);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(483);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddOperationContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleSimple_expression);
        setState(477);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(478);
        addop();
        setState(479);
        term(0); 
      }
      setState(485);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

PascalSParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::TermContext::getRuleIndex() const {
  return PascalSParser::RuleTerm;
}

void PascalSParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NoMultiplyOperationContext ------------------------------------------------------------------

PascalSParser::FactorContext* PascalSParser::NoMultiplyOperationContext::factor() {
  return getRuleContext<PascalSParser::FactorContext>(0);
}

PascalSParser::NoMultiplyOperationContext::NoMultiplyOperationContext(TermContext *ctx) { copyFrom(ctx); }

void PascalSParser::NoMultiplyOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoMultiplyOperation(this);
}
void PascalSParser::NoMultiplyOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoMultiplyOperation(this);
}
//----------------- MultiplyOperationContext ------------------------------------------------------------------

PascalSParser::TermContext* PascalSParser::MultiplyOperationContext::term() {
  return getRuleContext<PascalSParser::TermContext>(0);
}

PascalSParser::MulopContext* PascalSParser::MultiplyOperationContext::mulop() {
  return getRuleContext<PascalSParser::MulopContext>(0);
}

PascalSParser::FactorContext* PascalSParser::MultiplyOperationContext::factor() {
  return getRuleContext<PascalSParser::FactorContext>(0);
}

PascalSParser::MultiplyOperationContext::MultiplyOperationContext(TermContext *ctx) { copyFrom(ctx); }

void PascalSParser::MultiplyOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplyOperation(this);
}
void PascalSParser::MultiplyOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplyOperation(this);
}

PascalSParser::TermContext* PascalSParser::term() {
   return term(0);
}

PascalSParser::TermContext* PascalSParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  PascalSParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 102;
  enterRecursionRule(_localctx, 102, PascalSParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<NoMultiplyOperationContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(487);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(495);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiplyOperationContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(489);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(490);
        mulop();
        setState(491);
        factor(); 
      }
      setState(497);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

PascalSParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::FactorContext::getRuleIndex() const {
  return PascalSParser::RuleFactor;
}

void PascalSParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FactorReturnContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::FactorReturnContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::Expression_listContext* PascalSParser::FactorReturnContext::expression_list() {
  return getRuleContext<PascalSParser::Expression_listContext>(0);
}

PascalSParser::FactorReturnContext::FactorReturnContext(FactorContext *ctx) { copyFrom(ctx); }

void PascalSParser::FactorReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactorReturn(this);
}
void PascalSParser::FactorReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactorReturn(this);
}
//----------------- ReverseFactorContext ------------------------------------------------------------------

PascalSParser::FactorContext* PascalSParser::ReverseFactorContext::factor() {
  return getRuleContext<PascalSParser::FactorContext>(0);
}

PascalSParser::ReverseFactorContext::ReverseFactorContext(FactorContext *ctx) { copyFrom(ctx); }

void PascalSParser::ReverseFactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReverseFactor(this);
}
void PascalSParser::ReverseFactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReverseFactor(this);
}
//----------------- FactorPriorityContext ------------------------------------------------------------------

PascalSParser::ExpressionContext* PascalSParser::FactorPriorityContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::FactorPriorityContext::FactorPriorityContext(FactorContext *ctx) { copyFrom(ctx); }

void PascalSParser::FactorPriorityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactorPriority(this);
}
void PascalSParser::FactorPriorityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactorPriority(this);
}
//----------------- FactorVariableContext ------------------------------------------------------------------

PascalSParser::VariableContext* PascalSParser::FactorVariableContext::variable() {
  return getRuleContext<PascalSParser::VariableContext>(0);
}

PascalSParser::FactorVariableContext::FactorVariableContext(FactorContext *ctx) { copyFrom(ctx); }

void PascalSParser::FactorVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactorVariable(this);
}
void PascalSParser::FactorVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactorVariable(this);
}
//----------------- UnsignConstContext ------------------------------------------------------------------

PascalSParser::Unsign_const_variableContext* PascalSParser::UnsignConstContext::unsign_const_variable() {
  return getRuleContext<PascalSParser::Unsign_const_variableContext>(0);
}

PascalSParser::UnsignConstContext::UnsignConstContext(FactorContext *ctx) { copyFrom(ctx); }

void PascalSParser::UnsignConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsignConst(this);
}
void PascalSParser::UnsignConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsignConst(this);
}
PascalSParser::FactorContext* PascalSParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 104, PascalSParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(511);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::UnsignConstContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(498);
      unsign_const_variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::FactorVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(499);
      variable();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::FactorReturnContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(500);
      match(PascalSParser::ID);
      setState(501);
      match(PascalSParser::T__17);
      setState(502);
      expression_list(0);
      setState(503);
      match(PascalSParser::T__18);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::FactorPriorityContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(505);
      match(PascalSParser::T__17);
      setState(506);
      expression();
      setState(507);
      match(PascalSParser::T__18);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::ReverseFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(509);
      match(PascalSParser::T__52);
      setState(510);
      factor();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unsign_const_variableContext ------------------------------------------------------------------

PascalSParser::Unsign_const_variableContext::Unsign_const_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::Unsign_const_variableContext::getRuleIndex() const {
  return PascalSParser::RuleUnsign_const_variable;
}

void PascalSParser::Unsign_const_variableContext::copyFrom(Unsign_const_variableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnsignConstIdContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::UnsignConstIdContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::UnsignConstIdContext::UnsignConstIdContext(Unsign_const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::UnsignConstIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsignConstId(this);
}
void PascalSParser::UnsignConstIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsignConstId(this);
}
//----------------- UnsignConstCharContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::UnsignConstCharContext::CONST_CHAR() {
  return getToken(PascalSParser::CONST_CHAR, 0);
}

PascalSParser::UnsignConstCharContext::UnsignConstCharContext(Unsign_const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::UnsignConstCharContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsignConstChar(this);
}
void PascalSParser::UnsignConstCharContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsignConstChar(this);
}
//----------------- UnsignConstNumberContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::UnsignConstNumberContext::NUMBER() {
  return getToken(PascalSParser::NUMBER, 0);
}

PascalSParser::UnsignConstNumberContext::UnsignConstNumberContext(Unsign_const_variableContext *ctx) { copyFrom(ctx); }

void PascalSParser::UnsignConstNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsignConstNumber(this);
}
void PascalSParser::UnsignConstNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PascalSListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsignConstNumber(this);
}
PascalSParser::Unsign_const_variableContext* PascalSParser::unsign_const_variable() {
  Unsign_const_variableContext *_localctx = _tracker.createInstance<Unsign_const_variableContext>(_ctx, getState());
  enterRule(_localctx, 106, PascalSParser::RuleUnsign_const_variable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(516);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::ID: {
        _localctx = dynamic_cast<Unsign_const_variableContext *>(_tracker.createInstance<PascalSParser::UnsignConstIdContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(513);
        match(PascalSParser::ID);
        break;
      }

      case PascalSParser::NUMBER: {
        _localctx = dynamic_cast<Unsign_const_variableContext *>(_tracker.createInstance<PascalSParser::UnsignConstNumberContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(514);
        match(PascalSParser::NUMBER);
        break;
      }

      case PascalSParser::CONST_CHAR: {
        _localctx = dynamic_cast<Unsign_const_variableContext *>(_tracker.createInstance<PascalSParser::UnsignConstCharContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(515);
        match(PascalSParser::CONST_CHAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PascalSParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return identifier_listSempred(dynamic_cast<Identifier_listContext *>(context), predicateIndex);
    case 10: return const_declarationSempred(dynamic_cast<Const_declarationContext *>(context), predicateIndex);
    case 13: return type_declarationSempred(dynamic_cast<Type_declarationContext *>(context), predicateIndex);
    case 17: return periodsSempred(dynamic_cast<PeriodsContext *>(context), predicateIndex);
    case 20: return var_declarationSempred(dynamic_cast<Var_declarationContext *>(context), predicateIndex);
    case 21: return subprogram_declarationsSempred(dynamic_cast<Subprogram_declarationsContext *>(context), predicateIndex);
    case 25: return parameter_listsSempred(dynamic_cast<Parameter_listsContext *>(context), predicateIndex);
    case 30: return statement_listSempred(dynamic_cast<Statement_listContext *>(context), predicateIndex);
    case 35: return id_varpartsSempred(dynamic_cast<Id_varpartsContext *>(context), predicateIndex);
    case 41: return branch_listSempred(dynamic_cast<Branch_listContext *>(context), predicateIndex);
    case 43: return const_listSempred(dynamic_cast<Const_listContext *>(context), predicateIndex);
    case 48: return expression_listSempred(dynamic_cast<Expression_listContext *>(context), predicateIndex);
    case 50: return simple_expressionSempred(dynamic_cast<Simple_expressionContext *>(context), predicateIndex);
    case 51: return termSempred(dynamic_cast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PascalSParser::identifier_listSempred(Identifier_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::const_declarationSempred(Const_declarationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::type_declarationSempred(Type_declarationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::periodsSempred(PeriodsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::var_declarationSempred(Var_declarationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::subprogram_declarationsSempred(Subprogram_declarationsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::parameter_listsSempred(Parameter_listsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::statement_listSempred(Statement_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::id_varpartsSempred(Id_varpartsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::branch_listSempred(Branch_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::const_listSempred(Const_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::expression_listSempred(Expression_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool PascalSParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> PascalSParser::_decisionToDFA;
atn::PredictionContextCache PascalSParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PascalSParser::_atn;
std::vector<uint16_t> PascalSParser::_serializedATN;

std::vector<std::string> PascalSParser::_ruleNames = {
  "assignop", "relop", "addop", "mulop", "program", "program_head", "program_body", 
  "body_compound_statement", "identifier_list", "const_declarations", "const_declaration", 
  "const_variable", "type_declarations", "type_declaration", "type", "standard_type", 
  "record_body", "periods", "period", "var_declarations", "var_declaration", 
  "subprogram_declarations", "subprogram_declaration", "subprogram_head", 
  "formal_parameter", "parameter_lists", "parameter_list", "var_parameter", 
  "value_parameter", "compound_statement", "statement_list", "statement", 
  "while_condition", "while_body", "variable", "id_varparts", "id_varpart", 
  "else_part", "then_statement", "if_condition", "case_body", "branch_list", 
  "branch", "const_list", "updown", "repeat_condition", "repeat_body", "call_procedure_statement", 
  "expression_list", "expression", "simple_expression", "term", "factor", 
  "unsign_const_variable"
};

std::vector<std::string> PascalSParser::_literalNames = {
  "", "':='", "'<'", "'>'", "'<='", "'>='", "'<>'", "'='", "'+'", "'-'", 
  "'or'", "'*'", "'/'", "'div'", "'mod'", "'and'", "'.'", "'program'", "'('", 
  "')'", "';'", "','", "'const'", "'type'", "'record'", "'end'", "'array'", 
  "'['", "']'", "'of'", "'integer'", "'real'", "'boolean'", "'char'", "'..'", 
  "'var'", "':'", "'function'", "'procedure'", "'begin'", "'if'", "'then'", 
  "'case'", "'while'", "'do'", "'repeat'", "'until'", "'for'", "'else'", 
  "'to'", "'downto'", "'write'", "'read'", "'not'"
};

std::vector<std::string> PascalSParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "CONST_CHAR", "ID", "LETTER", "COMMENT", "MUL_COMMENT", "WS", "NUMBER", 
  "DIGITS", "DIGIT"
};

dfa::Vocabulary PascalSParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PascalSParser::_tokenNames;

PascalSParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x40, 0x209, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
       0xa, 0x90, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x93, 0xb, 0xa, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9a, 0xa, 0xb, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x7, 0xc, 0xa4, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xa7, 
       0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
       0xb4, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x5, 0xe, 0xbb, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xc5, 0xa, 0xf, 
       0xc, 0xf, 0xe, 0xf, 0xc8, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xd6, 0xa, 0x10, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xdc, 0xa, 0x12, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x7, 0x13, 0xe4, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xe7, 0xb, 0x13, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xf2, 0xa, 0x15, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x7, 0x16, 0xfc, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
       0xff, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x7, 0x17, 0x106, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x109, 0xb, 
       0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x11a, 0xa, 0x19, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
       0x121, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x129, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
       0x12c, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x130, 0xa, 0x1c, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 
       0x143, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x146, 0xb, 0x20, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x5, 0x21, 0x16e, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x7, 0x25, 0x17a, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
       0x17d, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x5, 0x26, 0x185, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x5, 0x27, 0x18a, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x192, 0xa, 0x2a, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x7, 0x2b, 0x19a, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x19d, 0xb, 0x2b, 
       0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1a9, 0xa, 
       0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x1ac, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
       0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1c4, 0xa, 0x31, 0x3, 0x32, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x1cc, 
       0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x1cf, 0xb, 0x32, 0x3, 0x33, 0x3, 
       0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x1d6, 0xa, 0x33, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x5, 0x34, 0x1de, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x7, 0x34, 0x1e4, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x1e7, 0xb, 
       0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x7, 0x35, 0x1f0, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 
       0x1f3, 0xb, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x202, 0xa, 0x36, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x207, 0xa, 0x37, 0x3, 0x37, 0x2, 
       0x10, 0x12, 0x16, 0x1c, 0x24, 0x2a, 0x2c, 0x34, 0x3e, 0x48, 0x54, 
       0x58, 0x62, 0x66, 0x68, 0x38, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
       0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
       0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
       0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 
       0x68, 0x6a, 0x6c, 0x2, 0x7, 0x3, 0x2, 0x4, 0x9, 0x3, 0x2, 0xa, 0xc, 
       0x3, 0x2, 0xd, 0x11, 0x3, 0x2, 0x20, 0x23, 0x3, 0x2, 0x33, 0x34, 
       0x2, 0x206, 0x2, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x70, 0x3, 0x2, 0x2, 
       0x2, 0x6, 0x72, 0x3, 0x2, 0x2, 0x2, 0x8, 0x74, 0x3, 0x2, 0x2, 0x2, 
       0xa, 0x76, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7a, 0x3, 0x2, 0x2, 0x2, 0xe, 
       0x81, 0x3, 0x2, 0x2, 0x2, 0x10, 0x87, 0x3, 0x2, 0x2, 0x2, 0x12, 0x89, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x99, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9b, 0x3, 
       0x2, 0x2, 0x2, 0x18, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xba, 0x3, 0x2, 
       0x2, 0x2, 0x1c, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xd5, 0x3, 0x2, 0x2, 
       0x2, 0x20, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x22, 0xdb, 0x3, 0x2, 0x2, 0x2, 
       0x24, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x28, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x100, 
       0x3, 0x2, 0x2, 0x2, 0x2e, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x32, 0x120, 0x3, 0x2, 0x2, 0x2, 0x34, 0x122, 
       0x3, 0x2, 0x2, 0x2, 0x36, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x3a, 0x134, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x3e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x40, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x42, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x171, 
       0x3, 0x2, 0x2, 0x2, 0x46, 0x173, 0x3, 0x2, 0x2, 0x2, 0x48, 0x176, 
       0x3, 0x2, 0x2, 0x2, 0x4a, 0x184, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x189, 
       0x3, 0x2, 0x2, 0x2, 0x4e, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x52, 0x191, 0x3, 0x2, 0x2, 0x2, 0x54, 0x193, 
       0x3, 0x2, 0x2, 0x2, 0x56, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1a2, 
       0x3, 0x2, 0x2, 0x2, 0x5a, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1af, 
       0x3, 0x2, 0x2, 0x2, 0x5e, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1d5, 
       0x3, 0x2, 0x2, 0x2, 0x66, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1e8, 
       0x3, 0x2, 0x2, 0x2, 0x6a, 0x201, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x206, 
       0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x3, 0x2, 0x2, 0x6f, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x70, 0x71, 0x9, 0x2, 0x2, 0x2, 0x71, 0x5, 0x3, 0x2, 
       0x2, 0x2, 0x72, 0x73, 0x9, 0x3, 0x2, 0x2, 0x73, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x74, 0x75, 0x9, 0x4, 0x2, 0x2, 0x75, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x76, 0x77, 0x5, 0xc, 0x7, 0x2, 0x77, 0x78, 0x5, 0xe, 0x8, 0x2, 0x78, 
       0x79, 0x7, 0x12, 0x2, 0x2, 0x79, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
       0x7, 0x13, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x39, 0x2, 0x2, 0x7c, 0x7d, 
       0x7, 0x14, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x12, 0xa, 0x2, 0x7e, 0x7f, 
       0x7, 0x15, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x16, 0x2, 0x2, 0x80, 0xd, 
       0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x5, 0x14, 0xb, 0x2, 0x82, 0x83, 
       0x5, 0x1a, 0xe, 0x2, 0x83, 0x84, 0x5, 0x28, 0x15, 0x2, 0x84, 0x85, 
       0x5, 0x2c, 0x17, 0x2, 0x85, 0x86, 0x5, 0x10, 0x9, 0x2, 0x86, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x5, 0x3c, 0x1f, 0x2, 0x88, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x8, 0xa, 0x1, 0x2, 0x8a, 0x8b, 0x7, 
       0x39, 0x2, 0x2, 0x8b, 0x91, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0xc, 
       0x4, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x17, 0x2, 0x2, 0x8e, 0x90, 0x7, 
       0x39, 0x2, 0x2, 0x8f, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 
       0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x13, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 
       0x2, 0x94, 0x95, 0x7, 0x18, 0x2, 0x2, 0x95, 0x96, 0x5, 0x16, 0xc, 
       0x2, 0x96, 0x97, 0x7, 0x16, 0x2, 0x2, 0x97, 0x9a, 0x3, 0x2, 0x2, 
       0x2, 0x98, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x99, 0x94, 0x3, 0x2, 0x2, 0x2, 
       0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9b, 
       0x9c, 0x8, 0xc, 0x1, 0x2, 0x9c, 0x9d, 0x7, 0x39, 0x2, 0x2, 0x9d, 
       0x9e, 0x7, 0x9, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x18, 0xd, 0x2, 0x9f, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0xc, 0x4, 0x2, 0x2, 0xa1, 0xa2, 
       0x7, 0x16, 0x2, 0x2, 0xa2, 0xa4, 0x5, 0x16, 0xc, 0x5, 0xa3, 0xa0, 
       0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 
       0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x17, 0x3, 0x2, 
       0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0xa, 0x2, 
       0x2, 0xa9, 0xb4, 0x7, 0x39, 0x2, 0x2, 0xaa, 0xab, 0x7, 0xb, 0x2, 
       0x2, 0xab, 0xb4, 0x7, 0x39, 0x2, 0x2, 0xac, 0xb4, 0x7, 0x39, 0x2, 
       0x2, 0xad, 0xae, 0x7, 0xa, 0x2, 0x2, 0xae, 0xb4, 0x7, 0x3e, 0x2, 
       0x2, 0xaf, 0xb0, 0x7, 0xb, 0x2, 0x2, 0xb0, 0xb4, 0x7, 0x3e, 0x2, 
       0x2, 0xb1, 0xb4, 0x7, 0x3e, 0x2, 0x2, 0xb2, 0xb4, 0x7, 0x38, 0x2, 
       0x2, 0xb3, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xaa, 0x3, 0x2, 0x2, 0x2, 
       0xb3, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb3, 
       0xaf, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb2, 
       0x3, 0x2, 0x2, 0x2, 0xb4, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 
       0x19, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x1c, 0xf, 0x2, 0xb7, 0xb8, 0x7, 
       0x16, 0x2, 0x2, 0xb8, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbb, 0x3, 
       0x2, 0x2, 0x2, 0xba, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb9, 0x3, 0x2, 
       0x2, 0x2, 0xbb, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x8, 0xf, 0x1, 
       0x2, 0xbd, 0xbe, 0x7, 0x39, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x9, 0x2, 
       0x2, 0xbf, 0xc0, 0x5, 0x1e, 0x10, 0x2, 0xc0, 0xc6, 0x3, 0x2, 0x2, 
       0x2, 0xc1, 0xc2, 0xc, 0x4, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x16, 0x2, 
       0x2, 0xc3, 0xc5, 0x5, 0x1c, 0xf, 0x5, 0xc4, 0xc1, 0x3, 0x2, 0x2, 
       0x2, 0xc5, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 
       0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc8, 
       0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xd6, 0x5, 0x20, 0x11, 0x2, 0xca, 
       0xcb, 0x7, 0x1a, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x22, 0x12, 0x2, 0xcc, 
       0xcd, 0x7, 0x1b, 0x2, 0x2, 0xcd, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xce, 
       0xcf, 0x7, 0x1c, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x1d, 0x2, 0x2, 0xd0, 
       0xd1, 0x5, 0x24, 0x13, 0x2, 0xd1, 0xd2, 0x7, 0x1e, 0x2, 0x2, 0xd2, 
       0xd3, 0x7, 0x1f, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x1e, 0x10, 0x2, 0xd4, 
       0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xca, 
       0x3, 0x2, 0x2, 0x2, 0xd5, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x1f, 0x3, 
       0x2, 0x2, 0x2, 0xd7, 0xd8, 0x9, 0x5, 0x2, 0x2, 0xd8, 0x21, 0x3, 0x2, 
       0x2, 0x2, 0xd9, 0xdc, 0x5, 0x2a, 0x16, 0x2, 0xda, 0xdc, 0x3, 0x2, 
       0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xda, 0x3, 0x2, 0x2, 
       0x2, 0xdc, 0x23, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x8, 0x13, 0x1, 
       0x2, 0xde, 0xdf, 0x5, 0x26, 0x14, 0x2, 0xdf, 0xe5, 0x3, 0x2, 0x2, 
       0x2, 0xe0, 0xe1, 0xc, 0x4, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x17, 0x2, 
       0x2, 0xe2, 0xe4, 0x5, 0x26, 0x14, 0x2, 0xe3, 0xe0, 0x3, 0x2, 0x2, 
       0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 
       0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe7, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x18, 0xd, 0x2, 0xe9, 
       0xea, 0x7, 0x24, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x18, 0xd, 0x2, 0xeb, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x25, 0x2, 0x2, 0xed, 
       0xee, 0x5, 0x2a, 0x16, 0x2, 0xee, 0xef, 0x7, 0x16, 0x2, 0x2, 0xef, 
       0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xec, 
       0x3, 0x2, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x29, 0x3, 
       0x2, 0x2, 0x2, 0xf3, 0xf4, 0x8, 0x16, 0x1, 0x2, 0xf4, 0xf5, 0x5, 
       0x12, 0xa, 0x2, 0xf5, 0xf6, 0x7, 0x26, 0x2, 0x2, 0xf6, 0xf7, 0x5, 
       0x1e, 0x10, 0x2, 0xf7, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0xc, 
       0x4, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x16, 0x2, 0x2, 0xfa, 0xfc, 0x5, 
       0x2a, 0x16, 0x5, 0xfb, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xff, 0x3, 
       0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 
       0x2, 0x2, 0xfe, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 
       0x2, 0x100, 0x107, 0x8, 0x17, 0x1, 0x2, 0x101, 0x102, 0xc, 0x4, 0x2, 
       0x2, 0x102, 0x103, 0x5, 0x2e, 0x18, 0x2, 0x103, 0x104, 0x7, 0x16, 
       0x2, 0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 0x105, 0x101, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x109, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 
       0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x2d, 0x3, 0x2, 
       0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0x30, 
       0x19, 0x2, 0x10b, 0x10c, 0x5, 0xe, 0x8, 0x2, 0x10c, 0x2f, 0x3, 0x2, 
       0x2, 0x2, 0x10d, 0x10e, 0x7, 0x27, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x39, 
       0x2, 0x2, 0x10f, 0x110, 0x5, 0x32, 0x1a, 0x2, 0x110, 0x111, 0x7, 
       0x26, 0x2, 0x2, 0x111, 0x112, 0x5, 0x20, 0x11, 0x2, 0x112, 0x113, 
       0x7, 0x16, 0x2, 0x2, 0x113, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 
       0x7, 0x28, 0x2, 0x2, 0x115, 0x116, 0x7, 0x39, 0x2, 0x2, 0x116, 0x117, 
       0x5, 0x32, 0x1a, 0x2, 0x117, 0x118, 0x7, 0x16, 0x2, 0x2, 0x118, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x119, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
       0x7, 0x14, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x34, 0x1b, 0x2, 0x11d, 0x11e, 
       0x7, 0x15, 0x2, 0x2, 0x11e, 0x121, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x121, 0x33, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
       0x8, 0x1b, 0x1, 0x2, 0x123, 0x124, 0x5, 0x36, 0x1c, 0x2, 0x124, 0x12a, 
       0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0xc, 0x4, 0x2, 0x2, 0x126, 0x127, 
       0x7, 0x16, 0x2, 0x2, 0x127, 0x129, 0x5, 0x36, 0x1c, 0x2, 0x128, 0x125, 
       0x3, 0x2, 0x2, 0x2, 0x129, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x35, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x130, 
       0x5, 0x38, 0x1d, 0x2, 0x12e, 0x130, 0x5, 0x3a, 0x1e, 0x2, 0x12f, 
       0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0x25, 0x2, 0x2, 0x132, 
       0x133, 0x5, 0x3a, 0x1e, 0x2, 0x133, 0x39, 0x3, 0x2, 0x2, 0x2, 0x134, 
       0x135, 0x5, 0x12, 0xa, 0x2, 0x135, 0x136, 0x7, 0x26, 0x2, 0x2, 0x136, 
       0x137, 0x5, 0x20, 0x11, 0x2, 0x137, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x138, 
       0x139, 0x7, 0x29, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x3e, 0x20, 0x2, 0x13a, 
       0x13b, 0x7, 0x1b, 0x2, 0x2, 0x13b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x13c, 
       0x13d, 0x8, 0x20, 0x1, 0x2, 0x13d, 0x13e, 0x5, 0x40, 0x21, 0x2, 0x13e, 
       0x144, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0xc, 0x4, 0x2, 0x2, 0x140, 
       0x141, 0x7, 0x16, 0x2, 0x2, 0x141, 0x143, 0x5, 0x40, 0x21, 0x2, 0x142, 
       0x13f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 
       0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 
       0x16e, 0x5, 0x3c, 0x1f, 0x2, 0x148, 0x149, 0x5, 0x46, 0x24, 0x2, 
       0x149, 0x14a, 0x5, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x5, 0x64, 0x33, 
       0x2, 0x14b, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x16e, 0x5, 0x60, 0x31, 
       0x2, 0x14d, 0x14e, 0x7, 0x2a, 0x2, 0x2, 0x14e, 0x14f, 0x5, 0x50, 
       0x29, 0x2, 0x14f, 0x150, 0x7, 0x2b, 0x2, 0x2, 0x150, 0x151, 0x5, 
       0x4e, 0x28, 0x2, 0x151, 0x152, 0x5, 0x4c, 0x27, 0x2, 0x152, 0x16e, 
       0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x7, 0x2c, 0x2, 0x2, 0x154, 0x155, 
       0x5, 0x64, 0x33, 0x2, 0x155, 0x156, 0x7, 0x1f, 0x2, 0x2, 0x156, 0x157, 
       0x5, 0x52, 0x2a, 0x2, 0x157, 0x158, 0x7, 0x1b, 0x2, 0x2, 0x158, 0x16e, 
       0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x2d, 0x2, 0x2, 0x15a, 0x15b, 
       0x5, 0x42, 0x22, 0x2, 0x15b, 0x15c, 0x7, 0x2e, 0x2, 0x2, 0x15c, 0x15d, 
       0x5, 0x44, 0x23, 0x2, 0x15d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 
       0x7, 0x2f, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x5e, 0x30, 0x2, 0x160, 0x161, 
       0x7, 0x30, 0x2, 0x2, 0x161, 0x162, 0x5, 0x5c, 0x2f, 0x2, 0x162, 0x16e, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0x31, 0x2, 0x2, 0x164, 0x165, 
       0x7, 0x39, 0x2, 0x2, 0x165, 0x166, 0x5, 0x2, 0x2, 0x2, 0x166, 0x167, 
       0x5, 0x64, 0x33, 0x2, 0x167, 0x168, 0x5, 0x5a, 0x2e, 0x2, 0x168, 
       0x169, 0x5, 0x64, 0x33, 0x2, 0x169, 0x16a, 0x7, 0x2e, 0x2, 0x2, 0x16a, 
       0x16b, 0x5, 0x40, 0x21, 0x2, 0x16b, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16c, 
       0x16e, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x147, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x148, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x14d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x153, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x163, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x5, 0x64, 0x33, 0x2, 0x170, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x5, 0x40, 0x21, 0x2, 0x172, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0x39, 0x2, 0x2, 0x174, 
       0x175, 0x5, 0x48, 0x25, 0x2, 0x175, 0x47, 0x3, 0x2, 0x2, 0x2, 0x176, 
       0x17b, 0x8, 0x25, 0x1, 0x2, 0x177, 0x178, 0xc, 0x4, 0x2, 0x2, 0x178, 
       0x17a, 0x5, 0x4a, 0x26, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 0x2, 0x17a, 
       0x17d, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 
       0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x49, 0x3, 0x2, 0x2, 0x2, 0x17d, 
       0x17b, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x1d, 0x2, 0x2, 0x17f, 
       0x180, 0x5, 0x62, 0x32, 0x2, 0x180, 0x181, 0x7, 0x1e, 0x2, 0x2, 0x181, 
       0x185, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x7, 0x12, 0x2, 0x2, 0x183, 
       0x185, 0x7, 0x39, 0x2, 0x2, 0x184, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x184, 
       0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x186, 
       0x187, 0x7, 0x32, 0x2, 0x2, 0x187, 0x18a, 0x5, 0x40, 0x21, 0x2, 0x188, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x189, 0x186, 0x3, 0x2, 0x2, 0x2, 0x189, 
       0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x18b, 
       0x18c, 0x5, 0x40, 0x21, 0x2, 0x18c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x18d, 
       0x18e, 0x5, 0x64, 0x33, 0x2, 0x18e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x18f, 
       0x192, 0x5, 0x54, 0x2b, 0x2, 0x190, 0x192, 0x3, 0x2, 0x2, 0x2, 0x191, 
       0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x8, 0x2b, 0x1, 0x2, 0x194, 
       0x195, 0x5, 0x56, 0x2c, 0x2, 0x195, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x196, 
       0x197, 0xc, 0x4, 0x2, 0x2, 0x197, 0x198, 0x7, 0x16, 0x2, 0x2, 0x198, 
       0x19a, 0x5, 0x56, 0x2c, 0x2, 0x199, 0x196, 0x3, 0x2, 0x2, 0x2, 0x19a, 
       0x19d, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 
       0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x55, 0x3, 0x2, 0x2, 0x2, 0x19d, 
       0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x5, 0x58, 0x2d, 0x2, 0x19f, 
       0x1a0, 0x7, 0x26, 0x2, 0x2, 0x1a0, 0x1a1, 0x5, 0x40, 0x21, 0x2, 0x1a1, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x8, 0x2d, 0x1, 0x2, 0x1a3, 
       0x1a4, 0x5, 0x18, 0xd, 0x2, 0x1a4, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a5, 
       0x1a6, 0xc, 0x4, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x17, 0x2, 0x2, 0x1a7, 
       0x1a9, 0x5, 0x18, 0xd, 0x2, 0x1a8, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
       0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1ac, 
       0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x9, 0x6, 0x2, 0x2, 0x1ae, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x5, 0x64, 0x33, 0x2, 0x1b0, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x5, 0x3e, 0x20, 0x2, 0x1b2, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1c4, 0x7, 0x39, 0x2, 0x2, 0x1b4, 
       0x1b5, 0x7, 0x39, 0x2, 0x2, 0x1b5, 0x1b6, 0x7, 0x14, 0x2, 0x2, 0x1b6, 
       0x1b7, 0x5, 0x62, 0x32, 0x2, 0x1b7, 0x1b8, 0x7, 0x15, 0x2, 0x2, 0x1b8, 
       0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x35, 0x2, 0x2, 0x1ba, 
       0x1bb, 0x7, 0x14, 0x2, 0x2, 0x1bb, 0x1bc, 0x5, 0x62, 0x32, 0x2, 0x1bc, 
       0x1bd, 0x7, 0x15, 0x2, 0x2, 0x1bd, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1be, 
       0x1bf, 0x7, 0x36, 0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x14, 0x2, 0x2, 0x1c0, 
       0x1c1, 0x5, 0x46, 0x24, 0x2, 0x1c1, 0x1c2, 0x7, 0x15, 0x2, 0x2, 0x1c2, 
       0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
       0x1c6, 0x8, 0x32, 0x1, 0x2, 0x1c6, 0x1c7, 0x5, 0x64, 0x33, 0x2, 0x1c7, 
       0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0xc, 0x4, 0x2, 0x2, 0x1c9, 
       0x1ca, 0x7, 0x17, 0x2, 0x2, 0x1ca, 0x1cc, 0x5, 0x64, 0x33, 0x2, 0x1cb, 
       0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
       0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
       0x63, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d0, 
       0x1d1, 0x5, 0x66, 0x34, 0x2, 0x1d1, 0x1d2, 0x5, 0x4, 0x3, 0x2, 0x1d2, 
       0x1d3, 0x5, 0x66, 0x34, 0x2, 0x1d3, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
       0x1d6, 0x5, 0x66, 0x34, 0x2, 0x1d5, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
       0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
       0x1d8, 0x8, 0x34, 0x1, 0x2, 0x1d8, 0x1de, 0x5, 0x68, 0x35, 0x2, 0x1d9, 
       0x1da, 0x7, 0xa, 0x2, 0x2, 0x1da, 0x1de, 0x5, 0x68, 0x35, 0x2, 0x1db, 
       0x1dc, 0x7, 0xb, 0x2, 0x2, 0x1dc, 0x1de, 0x5, 0x68, 0x35, 0x2, 0x1dd, 
       0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1dd, 
       0x1db, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1df, 
       0x1e0, 0xc, 0x3, 0x2, 0x2, 0x1e0, 0x1e1, 0x5, 0x6, 0x4, 0x2, 0x1e1, 
       0x1e2, 0x5, 0x68, 0x35, 0x2, 0x1e2, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e3, 
       0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
       0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x67, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
       0x1e9, 0x8, 0x35, 0x1, 0x2, 0x1e9, 0x1ea, 0x5, 0x6a, 0x36, 0x2, 0x1ea, 
       0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0xc, 0x4, 0x2, 0x2, 0x1ec, 
       0x1ed, 0x5, 0x8, 0x5, 0x2, 0x1ed, 0x1ee, 0x5, 0x6a, 0x36, 0x2, 0x1ee, 
       0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
       0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
       0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f3, 
       0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x202, 0x5, 0x6c, 0x37, 0x2, 0x1f5, 
       0x202, 0x5, 0x46, 0x24, 0x2, 0x1f6, 0x1f7, 0x7, 0x39, 0x2, 0x2, 0x1f7, 
       0x1f8, 0x7, 0x14, 0x2, 0x2, 0x1f8, 0x1f9, 0x5, 0x62, 0x32, 0x2, 0x1f9, 
       0x1fa, 0x7, 0x15, 0x2, 0x2, 0x1fa, 0x202, 0x3, 0x2, 0x2, 0x2, 0x1fb, 
       0x1fc, 0x7, 0x14, 0x2, 0x2, 0x1fc, 0x1fd, 0x5, 0x64, 0x33, 0x2, 0x1fd, 
       0x1fe, 0x7, 0x15, 0x2, 0x2, 0x1fe, 0x202, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
       0x200, 0x7, 0x37, 0x2, 0x2, 0x200, 0x202, 0x5, 0x6a, 0x36, 0x2, 0x201, 
       0x1f4, 0x3, 0x2, 0x2, 0x2, 0x201, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x201, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x1ff, 0x3, 0x2, 0x2, 0x2, 0x202, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x203, 
       0x207, 0x7, 0x39, 0x2, 0x2, 0x204, 0x207, 0x7, 0x3e, 0x2, 0x2, 0x205, 
       0x207, 0x7, 0x38, 0x2, 0x2, 0x206, 0x203, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x204, 0x3, 0x2, 0x2, 0x2, 0x206, 0x205, 0x3, 0x2, 0x2, 0x2, 0x207, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x22, 0x91, 0x99, 0xa5, 0xb3, 0xba, 0xc6, 
       0xd5, 0xdb, 0xe5, 0xf1, 0xfd, 0x107, 0x119, 0x120, 0x12a, 0x12f, 
       0x144, 0x16d, 0x17b, 0x184, 0x189, 0x191, 0x19b, 0x1aa, 0x1c3, 0x1cd, 
       0x1d5, 0x1dd, 0x1e5, 0x1f1, 0x201, 0x206, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PascalSParser::Initializer PascalSParser::_init;
