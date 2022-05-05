
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
    setState(94);
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
    setState(96);
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
    setState(98);
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
    setState(100);
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
    setState(102);
    program_head();
    setState(103);
    program_body();
    setState(104);
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
    setState(106);
    match(PascalSParser::T__16);
    setState(107);
    match(PascalSParser::ID);
    setState(108);
    match(PascalSParser::T__17);
    setState(109);
    identifier_list(0);
    setState(110);
    match(PascalSParser::T__18);
    setState(111);
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

PascalSParser::Compound_statementContext* PascalSParser::Program_bodyContext::compound_statement() {
  return getRuleContext<PascalSParser::Compound_statementContext>(0);
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
    setState(113);
    const_declarations();
    setState(114);
    type_declarations();
    setState(115);
    var_declarations();
    setState(116);
    subprogram_declarations(0);
    setState(117);
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
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, PascalSParser::RuleIdentifier_list, precedence);

    

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

    setState(120);
    match(PascalSParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(127);
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
        setState(122);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(123);
        match(PascalSParser::T__20);
        setState(124);
        match(PascalSParser::ID); 
      }
      setState(129);
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
  enterRule(_localctx, 16, PascalSParser::RuleConst_declarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(130);
      match(PascalSParser::T__21);
      setState(131);
      const_declaration(0);
      setState(132);
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
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, PascalSParser::RuleConst_declaration, precedence);

    

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

    setState(138);
    match(PascalSParser::ID);
    setState(139);
    match(PascalSParser::T__6);
    setState(140);
    const_variable();
    _ctx->stop = _input->LT(-1);
    setState(147);
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
        setState(142);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(143);
        match(PascalSParser::T__19);
        setState(144);
        const_declaration(3); 
      }
      setState(149);
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
  enterRule(_localctx, 20, PascalSParser::RuleConst_variable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(150);
      match(PascalSParser::T__7);
      setState(151);
      match(PascalSParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::NegativeIdContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(152);
      match(PascalSParser::T__8);
      setState(153);
      match(PascalSParser::ID);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveIdContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(154);
      match(PascalSParser::ID);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveNumberContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(155);
      match(PascalSParser::T__7);
      setState(156);
      match(PascalSParser::NUMBER);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::NegativeNumberContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(157);
      match(PascalSParser::T__8);
      setState(158);
      match(PascalSParser::NUMBER);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::PositiveNumberContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(159);
      match(PascalSParser::NUMBER);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<Const_variableContext *>(_tracker.createInstance<PascalSParser::ConstCharContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(160);
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
  enterRule(_localctx, 22, PascalSParser::RuleType_declarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      match(PascalSParser::T__22);
      setState(164);
      type_declaration(0);
      setState(165);
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
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, PascalSParser::RuleType_declaration, precedence);

    

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

    setState(171);
    match(PascalSParser::ID);
    setState(172);
    match(PascalSParser::T__6);
    setState(173);
    type();
    _ctx->stop = _input->LT(-1);
    setState(180);
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
        setState(175);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(176);
        match(PascalSParser::T__19);
        setState(177);
        type_declaration(3); 
      }
      setState(182);
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
  enterRule(_localctx, 26, PascalSParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__29:
      case PascalSParser::T__30:
      case PascalSParser::T__31:
      case PascalSParser::T__32: {
        enterOuterAlt(_localctx, 1);
        setState(183);
        standard_type();
        break;
      }

      case PascalSParser::T__23: {
        enterOuterAlt(_localctx, 2);
        setState(184);
        match(PascalSParser::T__23);
        setState(185);
        record_body();
        setState(186);
        match(PascalSParser::T__24);
        break;
      }

      case PascalSParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(188);
        match(PascalSParser::T__25);
        setState(189);
        match(PascalSParser::T__26);
        setState(190);
        periods(0);
        setState(191);
        match(PascalSParser::T__27);
        setState(192);
        match(PascalSParser::T__28);
        setState(193);
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
  enterRule(_localctx, 28, PascalSParser::RuleStandard_type);
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
    setState(197);
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
  enterRule(_localctx, 30, PascalSParser::RuleRecord_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(199);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, PascalSParser::RulePeriods, precedence);

    

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

    setState(204);
    period();
    _ctx->stop = _input->LT(-1);
    setState(211);
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
        setState(206);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(207);
        match(PascalSParser::T__20);
        setState(208);
        period(); 
      }
      setState(213);
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
  enterRule(_localctx, 34, PascalSParser::RulePeriod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    const_variable();
    setState(215);
    match(PascalSParser::T__33);
    setState(216);
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
  enterRule(_localctx, 36, PascalSParser::RuleVar_declarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(218);
      match(PascalSParser::T__34);
      setState(219);
      var_declaration(0);
      setState(220);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, PascalSParser::RuleVar_declaration, precedence);

    

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

    setState(226);
    identifier_list(0);
    setState(227);
    match(PascalSParser::T__35);
    setState(228);
    type();
    _ctx->stop = _input->LT(-1);
    setState(235);
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
        setState(230);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(231);
        match(PascalSParser::T__19);
        setState(232);
        var_declaration(3); 
      }
      setState(237);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, PascalSParser::RuleSubprogram_declarations, precedence);

    

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
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Subprogram_declarationsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSubprogram_declarations);
        setState(239);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(240);
        subprogram_declaration();
        setState(241);
        match(PascalSParser::T__19); 
      }
      setState(247);
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
  enterRule(_localctx, 42, PascalSParser::RuleSubprogram_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    subprogram_head();
    setState(249);
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
  enterRule(_localctx, 44, PascalSParser::RuleSubprogram_head);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__36: {
        _localctx = dynamic_cast<Subprogram_headContext *>(_tracker.createInstance<PascalSParser::FunctionDeclarationContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(251);
        match(PascalSParser::T__36);
        setState(252);
        match(PascalSParser::ID);
        setState(253);
        formal_parameter();
        setState(254);
        match(PascalSParser::T__35);
        setState(255);
        standard_type();
        setState(256);
        match(PascalSParser::T__19);
        break;
      }

      case PascalSParser::T__37: {
        _localctx = dynamic_cast<Subprogram_headContext *>(_tracker.createInstance<PascalSParser::ProcedureDeclarationContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(258);
        match(PascalSParser::T__37);
        setState(259);
        match(PascalSParser::ID);
        setState(260);
        formal_parameter();
        setState(261);
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
  enterRule(_localctx, 46, PascalSParser::RuleFormal_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__17: {
        enterOuterAlt(_localctx, 1);
        setState(265);
        match(PascalSParser::T__17);
        setState(266);
        parameter_lists(0);
        setState(267);
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
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, PascalSParser::RuleParameter_lists, precedence);

    

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

    setState(273);
    parameter_list();
    _ctx->stop = _input->LT(-1);
    setState(280);
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
        setState(275);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(276);
        match(PascalSParser::T__19);
        setState(277);
        parameter_list(); 
      }
      setState(282);
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
  enterRule(_localctx, 50, PascalSParser::RuleParameter_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__34: {
        _localctx = dynamic_cast<Parameter_listContext *>(_tracker.createInstance<PascalSParser::VarParaContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(283);
        var_parameter();
        break;
      }

      case PascalSParser::ID: {
        _localctx = dynamic_cast<Parameter_listContext *>(_tracker.createInstance<PascalSParser::ValueParaContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(284);
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
  enterRule(_localctx, 52, PascalSParser::RuleVar_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(PascalSParser::T__34);
    setState(288);
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
  enterRule(_localctx, 54, PascalSParser::RuleValue_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    identifier_list(0);
    setState(291);
    match(PascalSParser::T__35);
    setState(292);
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
  enterRule(_localctx, 56, PascalSParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(PascalSParser::T__38);
    setState(295);
    statement_list(0);
    setState(296);
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
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, PascalSParser::RuleStatement_list, precedence);

    

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

    setState(299);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(306);
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
        setState(301);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(302);
        match(PascalSParser::T__19);
        setState(303);
        statement(); 
      }
      setState(308);
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

PascalSParser::Statement_listContext* PascalSParser::RepeatContext::statement_list() {
  return getRuleContext<PascalSParser::Statement_listContext>(0);
}

PascalSParser::ExpressionContext* PascalSParser::RepeatContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
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

PascalSParser::ExpressionContext* PascalSParser::WhileContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::StatementContext* PascalSParser::WhileContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
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

PascalSParser::ExpressionContext* PascalSParser::IfContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::StatementContext* PascalSParser::IfContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
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
  enterRule(_localctx, 60, PascalSParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(347);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::BlockContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(309);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(310);
      variable();
      setState(311);
      assignop();
      setState(312);
      expression();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::CallContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(314);
      call_procedure_statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::IfContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(315);
      match(PascalSParser::T__39);
      setState(316);
      expression();
      setState(317);
      match(PascalSParser::T__40);
      setState(318);
      statement();
      setState(319);
      else_part();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::CaseContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(321);
      match(PascalSParser::T__41);
      setState(322);
      expression();
      setState(323);
      match(PascalSParser::T__28);
      setState(324);
      case_body();
      setState(325);
      match(PascalSParser::T__24);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(327);
      match(PascalSParser::T__42);
      setState(328);
      expression();
      setState(329);
      match(PascalSParser::T__43);
      setState(330);
      statement();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::RepeatContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(332);
      match(PascalSParser::T__44);
      setState(333);
      statement_list(0);
      setState(334);
      match(PascalSParser::T__45);
      setState(335);
      expression();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PascalSParser::ForContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(337);
      match(PascalSParser::T__46);
      setState(338);
      match(PascalSParser::ID);
      setState(339);
      assignop();
      setState(340);
      expression();
      setState(341);
      updown();
      setState(342);
      expression();
      setState(343);
      match(PascalSParser::T__43);
      setState(344);
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
  enterRule(_localctx, 62, PascalSParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    match(PascalSParser::ID);
    setState(350);
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
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, PascalSParser::RuleId_varparts, precedence);

    

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
    setState(357);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Id_varpartsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleId_varparts);
        setState(353);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(354);
        id_varpart(); 
      }
      setState(359);
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
  enterRule(_localctx, 66, PascalSParser::RuleId_varpart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__26: {
        _localctx = dynamic_cast<Id_varpartContext *>(_tracker.createInstance<PascalSParser::ArrayAccessContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(360);
        match(PascalSParser::T__26);
        setState(361);
        expression_list(0);
        setState(362);
        match(PascalSParser::T__27);
        break;
      }

      case PascalSParser::T__15: {
        _localctx = dynamic_cast<Id_varpartContext *>(_tracker.createInstance<PascalSParser::RecordAccessContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(364);
        match(PascalSParser::T__15);
        setState(365);
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
  enterRule(_localctx, 68, PascalSParser::RuleElse_part);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(371);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(368);
      match(PascalSParser::T__47);
      setState(369);
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
  enterRule(_localctx, 70, PascalSParser::RuleCase_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(375);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::T__7:
      case PascalSParser::T__8:
      case PascalSParser::CONST_CHAR:
      case PascalSParser::ID:
      case PascalSParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(373);
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
  size_t startState = 72;
  enterRecursionRule(_localctx, 72, PascalSParser::RuleBranch_list, precedence);

    

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
    setState(378);
    branch();
    _ctx->stop = _input->LT(-1);
    setState(385);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Branch_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBranch_list);
        setState(380);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(381);
        match(PascalSParser::T__19);
        setState(382);
        branch(); 
      }
      setState(387);
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
  enterRule(_localctx, 74, PascalSParser::RuleBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    const_list(0);
    setState(389);
    match(PascalSParser::T__35);
    setState(390);
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
  size_t startState = 76;
  enterRecursionRule(_localctx, 76, PascalSParser::RuleConst_list, precedence);

    

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

    setState(393);
    const_variable();
    _ctx->stop = _input->LT(-1);
    setState(400);
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
        setState(395);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(396);
        match(PascalSParser::T__20);
        setState(397);
        const_variable(); 
      }
      setState(402);
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
  enterRule(_localctx, 78, PascalSParser::RuleUpdown);
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
    setState(403);
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
  enterRule(_localctx, 80, PascalSParser::RuleCall_procedure_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(421);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallWithNoParaContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(405);
      match(PascalSParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallWithParaContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(406);
      match(PascalSParser::ID);
      setState(407);
      match(PascalSParser::T__17);
      setState(408);
      expression_list(0);
      setState(409);
      match(PascalSParser::T__18);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallWritelnContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(411);
      match(PascalSParser::T__50);
      setState(412);
      match(PascalSParser::T__17);
      setState(413);
      expression_list(0);
      setState(414);
      match(PascalSParser::T__18);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Call_procedure_statementContext *>(_tracker.createInstance<PascalSParser::CallReadlnContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(416);
      match(PascalSParser::T__51);
      setState(417);
      match(PascalSParser::T__17);
      setState(418);
      variable();
      setState(419);
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
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, PascalSParser::RuleExpression_list, precedence);

    

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
    setState(424);
    expression();
    _ctx->stop = _input->LT(-1);
    setState(431);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expression_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression_list);
        setState(426);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(427);
        match(PascalSParser::T__20);
        setState(428);
        expression(); 
      }
      setState(433);
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
  enterRule(_localctx, 84, PascalSParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(439);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<PascalSParser::RelationOperationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(434);
      simple_expression(0);
      setState(435);
      relop();
      setState(436);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<PascalSParser::NoRalationOperationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(438);
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
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, PascalSParser::RuleSimple_expression, precedence);

    

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
    setState(447);
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

        setState(442);
        term(0);
        break;
      }

      case PascalSParser::T__7: {
        _localctx = _tracker.createInstance<PositiveTermContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(443);
        match(PascalSParser::T__7);
        setState(444);
        term(0);
        break;
      }

      case PascalSParser::T__8: {
        _localctx = _tracker.createInstance<NegativeTermContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(445);
        match(PascalSParser::T__8);
        setState(446);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(455);
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
        setState(449);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(450);
        addop();
        setState(451);
        term(0); 
      }
      setState(457);
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
  size_t startState = 88;
  enterRecursionRule(_localctx, 88, PascalSParser::RuleTerm, precedence);

    

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

    setState(459);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(467);
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
        setState(461);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(462);
        mulop();
        setState(463);
        factor(); 
      }
      setState(469);
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
  enterRule(_localctx, 90, PascalSParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(483);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::UnsignConstContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(470);
      unsign_const_variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::FactorVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(471);
      variable();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::FactorReturnContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(472);
      match(PascalSParser::ID);
      setState(473);
      match(PascalSParser::T__17);
      setState(474);
      expression_list(0);
      setState(475);
      match(PascalSParser::T__18);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::FactorPriorityContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(477);
      match(PascalSParser::T__17);
      setState(478);
      expression();
      setState(479);
      match(PascalSParser::T__18);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalSParser::ReverseFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(481);
      match(PascalSParser::T__52);
      setState(482);
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
  enterRule(_localctx, 92, PascalSParser::RuleUnsign_const_variable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(488);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::ID: {
        _localctx = dynamic_cast<Unsign_const_variableContext *>(_tracker.createInstance<PascalSParser::UnsignConstIdContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(485);
        match(PascalSParser::ID);
        break;
      }

      case PascalSParser::NUMBER: {
        _localctx = dynamic_cast<Unsign_const_variableContext *>(_tracker.createInstance<PascalSParser::UnsignConstNumberContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(486);
        match(PascalSParser::NUMBER);
        break;
      }

      case PascalSParser::CONST_CHAR: {
        _localctx = dynamic_cast<Unsign_const_variableContext *>(_tracker.createInstance<PascalSParser::UnsignConstCharContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(487);
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
    case 7: return identifier_listSempred(dynamic_cast<Identifier_listContext *>(context), predicateIndex);
    case 9: return const_declarationSempred(dynamic_cast<Const_declarationContext *>(context), predicateIndex);
    case 12: return type_declarationSempred(dynamic_cast<Type_declarationContext *>(context), predicateIndex);
    case 16: return periodsSempred(dynamic_cast<PeriodsContext *>(context), predicateIndex);
    case 19: return var_declarationSempred(dynamic_cast<Var_declarationContext *>(context), predicateIndex);
    case 20: return subprogram_declarationsSempred(dynamic_cast<Subprogram_declarationsContext *>(context), predicateIndex);
    case 24: return parameter_listsSempred(dynamic_cast<Parameter_listsContext *>(context), predicateIndex);
    case 29: return statement_listSempred(dynamic_cast<Statement_listContext *>(context), predicateIndex);
    case 32: return id_varpartsSempred(dynamic_cast<Id_varpartsContext *>(context), predicateIndex);
    case 36: return branch_listSempred(dynamic_cast<Branch_listContext *>(context), predicateIndex);
    case 38: return const_listSempred(dynamic_cast<Const_listContext *>(context), predicateIndex);
    case 41: return expression_listSempred(dynamic_cast<Expression_listContext *>(context), predicateIndex);
    case 43: return simple_expressionSempred(dynamic_cast<Simple_expressionContext *>(context), predicateIndex);
    case 44: return termSempred(dynamic_cast<TermContext *>(context), predicateIndex);

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
  "identifier_list", "const_declarations", "const_declaration", "const_variable", 
  "type_declarations", "type_declaration", "type", "standard_type", "record_body", 
  "periods", "period", "var_declarations", "var_declaration", "subprogram_declarations", 
  "subprogram_declaration", "subprogram_head", "formal_parameter", "parameter_lists", 
  "parameter_list", "var_parameter", "value_parameter", "compound_statement", 
  "statement_list", "statement", "variable", "id_varparts", "id_varpart", 
  "else_part", "case_body", "branch_list", "branch", "const_list", "updown", 
  "call_procedure_statement", "expression_list", "expression", "simple_expression", 
  "term", "factor", "unsign_const_variable"
};

std::vector<std::string> PascalSParser::_literalNames = {
  "", "':='", "'<'", "'>'", "'<='", "'>='", "'<>'", "'='", "'+'", "'-'", 
  "'or'", "'*'", "'/'", "'div'", "'mod'", "'and'", "'.'", "'program'", "'('", 
  "')'", "';'", "','", "'const'", "'type'", "'record'", "'end'", "'array'", 
  "'['", "']'", "'of'", "'integer'", "'real'", "'boolean'", "'char'", "'..'", 
  "'var'", "':'", "'function'", "'procedure'", "'begin'", "'if'", "'then'", 
  "'case'", "'while'", "'do'", "'repeat'", "'untile'", "'for'", "'else'", 
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
       0x3, 0x40, 0x1ed, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x7, 0x9, 0x80, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x83, 
       0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
       0xa, 0x8a, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x94, 0xa, 0xb, 0xc, 
       0xb, 0xe, 0xb, 0x97, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x5, 0xc, 0xa4, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xab, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 
       0xe, 0xb5, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xb8, 0xb, 0xe, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc6, 0xa, 
       0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xcc, 
       0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x7, 0x12, 0xd4, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xd7, 
       0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xe2, 0xa, 
       0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xec, 0xa, 0x15, 0xc, 0x15, 
       0xe, 0x15, 0xef, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x7, 0x16, 0xf6, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
       0xf9, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x10a, 
       0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x5, 0x19, 0x111, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x119, 0xa, 0x1a, 0xc, 0x1a, 
       0xe, 0x1a, 0x11c, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x120, 
       0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x7, 0x1f, 0x133, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x136, 0xb, 0x1f, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x15e, 0xa, 0x20, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x166, 
       0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x169, 0xb, 0x22, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x171, 
       0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x176, 0xa, 
       0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x17a, 0xa, 0x25, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 
       0x182, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x185, 0xb, 0x26, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x191, 0xa, 0x28, 0xc, 
       0x28, 0xe, 0x28, 0x194, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1a8, 0xa, 0x2a, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 
       0x2b, 0x1b0, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x1b3, 0xb, 0x2b, 0x3, 
       0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1ba, 
       0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x5, 0x2d, 0x1c2, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1c8, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
       0x1cb, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1d4, 0xa, 0x2e, 0xc, 0x2e, 
       0xe, 0x2e, 0x1d7, 0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1e6, 0xa, 0x2f, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1eb, 0xa, 0x30, 0x3, 
       0x30, 0x2, 0x10, 0x10, 0x14, 0x1a, 0x22, 0x28, 0x2a, 0x32, 0x3c, 
       0x42, 0x4a, 0x4e, 0x54, 0x58, 0x5a, 0x31, 0x2, 0x4, 0x6, 0x8, 0xa, 
       0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x2, 0x7, 0x3, 0x2, 
       0x4, 0x9, 0x3, 0x2, 0xa, 0xc, 0x3, 0x2, 0xd, 0x11, 0x3, 0x2, 0x20, 
       0x23, 0x3, 0x2, 0x33, 0x34, 0x2, 0x1f1, 0x2, 0x60, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0x62, 0x3, 0x2, 0x2, 0x2, 0x6, 0x64, 0x3, 0x2, 0x2, 0x2, 
       0x8, 0x66, 0x3, 0x2, 0x2, 0x2, 0xa, 0x68, 0x3, 0x2, 0x2, 0x2, 0xc, 
       0x6c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x73, 0x3, 0x2, 0x2, 0x2, 0x10, 0x79, 
       0x3, 0x2, 0x2, 0x2, 0x12, 0x89, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8b, 0x3, 
       0x2, 0x2, 0x2, 0x16, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x18, 0xaa, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0xac, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc5, 0x3, 0x2, 0x2, 
       0x2, 0x1e, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xcb, 0x3, 0x2, 0x2, 0x2, 
       0x22, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x24, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x26, 
       0xe1, 0x3, 0x2, 0x2, 0x2, 0x28, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf0, 
       0x3, 0x2, 0x2, 0x2, 0x2c, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x109, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x110, 0x3, 0x2, 0x2, 0x2, 0x32, 0x112, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x124, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x15d, 
       0x3, 0x2, 0x2, 0x2, 0x40, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x162, 
       0x3, 0x2, 0x2, 0x2, 0x44, 0x170, 0x3, 0x2, 0x2, 0x2, 0x46, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x48, 0x179, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x17b, 
       0x3, 0x2, 0x2, 0x2, 0x4c, 0x186, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x18a, 
       0x3, 0x2, 0x2, 0x2, 0x50, 0x195, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1a7, 
       0x3, 0x2, 0x2, 0x2, 0x54, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x58, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1cc, 
       0x3, 0x2, 0x2, 0x2, 0x5c, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1ea, 
       0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x3, 0x2, 0x2, 0x61, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x63, 0x9, 0x2, 0x2, 0x2, 0x63, 0x5, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x65, 0x9, 0x3, 0x2, 0x2, 0x65, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x66, 0x67, 0x9, 0x4, 0x2, 0x2, 0x67, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x68, 0x69, 0x5, 0xc, 0x7, 0x2, 0x69, 0x6a, 0x5, 0xe, 0x8, 0x2, 0x6a, 
       0x6b, 0x7, 0x12, 0x2, 0x2, 0x6b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 
       0x7, 0x13, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x39, 0x2, 0x2, 0x6e, 0x6f, 
       0x7, 0x14, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x10, 0x9, 0x2, 0x70, 0x71, 
       0x7, 0x15, 0x2, 0x2, 0x71, 0x72, 0x7, 0x16, 0x2, 0x2, 0x72, 0xd, 
       0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x5, 0x12, 0xa, 0x2, 0x74, 0x75, 
       0x5, 0x18, 0xd, 0x2, 0x75, 0x76, 0x5, 0x26, 0x14, 0x2, 0x76, 0x77, 
       0x5, 0x2a, 0x16, 0x2, 0x77, 0x78, 0x5, 0x3a, 0x1e, 0x2, 0x78, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x8, 0x9, 0x1, 0x2, 0x7a, 0x7b, 0x7, 
       0x39, 0x2, 0x2, 0x7b, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0xc, 
       0x4, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x17, 0x2, 0x2, 0x7e, 0x80, 0x7, 
       0x39, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 
       0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x11, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 
       0x2, 0x84, 0x85, 0x7, 0x18, 0x2, 0x2, 0x85, 0x86, 0x5, 0x14, 0xb, 
       0x2, 0x86, 0x87, 0x7, 0x16, 0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 
       0x2, 0x88, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x89, 0x84, 0x3, 0x2, 0x2, 0x2, 
       0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8b, 
       0x8c, 0x8, 0xb, 0x1, 0x2, 0x8c, 0x8d, 0x7, 0x39, 0x2, 0x2, 0x8d, 
       0x8e, 0x7, 0x9, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x16, 0xc, 0x2, 0x8f, 
       0x95, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0xc, 0x4, 0x2, 0x2, 0x91, 0x92, 
       0x7, 0x16, 0x2, 0x2, 0x92, 0x94, 0x5, 0x14, 0xb, 0x5, 0x93, 0x90, 
       0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 
       0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x15, 0x3, 0x2, 
       0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0xa, 0x2, 
       0x2, 0x99, 0xa4, 0x7, 0x39, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xb, 0x2, 
       0x2, 0x9b, 0xa4, 0x7, 0x39, 0x2, 0x2, 0x9c, 0xa4, 0x7, 0x39, 0x2, 
       0x2, 0x9d, 0x9e, 0x7, 0xa, 0x2, 0x2, 0x9e, 0xa4, 0x7, 0x3e, 0x2, 
       0x2, 0x9f, 0xa0, 0x7, 0xb, 0x2, 0x2, 0xa0, 0xa4, 0x7, 0x3e, 0x2, 
       0x2, 0xa1, 0xa4, 0x7, 0x3e, 0x2, 0x2, 0xa2, 0xa4, 0x7, 0x38, 0x2, 
       0x2, 0xa3, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x9a, 0x3, 0x2, 0x2, 0x2, 
       0xa3, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa3, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa2, 
       0x3, 0x2, 0x2, 0x2, 0xa4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 
       0x19, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x1a, 0xe, 0x2, 0xa7, 0xa8, 0x7, 
       0x16, 0x2, 0x2, 0xa8, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xab, 0x3, 
       0x2, 0x2, 0x2, 0xaa, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa9, 0x3, 0x2, 
       0x2, 0x2, 0xab, 0x19, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x8, 0xe, 0x1, 
       0x2, 0xad, 0xae, 0x7, 0x39, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x9, 0x2, 
       0x2, 0xaf, 0xb0, 0x5, 0x1c, 0xf, 0x2, 0xb0, 0xb6, 0x3, 0x2, 0x2, 
       0x2, 0xb1, 0xb2, 0xc, 0x4, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x16, 0x2, 
       0x2, 0xb3, 0xb5, 0x5, 0x1a, 0xe, 0x5, 0xb4, 0xb1, 0x3, 0x2, 0x2, 
       0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb8, 
       0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xc6, 0x5, 0x1e, 0x10, 0x2, 0xba, 
       0xbb, 0x7, 0x1a, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x20, 0x11, 0x2, 0xbc, 
       0xbd, 0x7, 0x1b, 0x2, 0x2, 0xbd, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xbe, 
       0xbf, 0x7, 0x1c, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x1d, 0x2, 0x2, 0xc0, 
       0xc1, 0x5, 0x22, 0x12, 0x2, 0xc1, 0xc2, 0x7, 0x1e, 0x2, 0x2, 0xc2, 
       0xc3, 0x7, 0x1f, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x1c, 0xf, 0x2, 0xc4, 
       0xc6, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xba, 
       0x3, 0x2, 0x2, 0x2, 0xc5, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x1d, 0x3, 
       0x2, 0x2, 0x2, 0xc7, 0xc8, 0x9, 0x5, 0x2, 0x2, 0xc8, 0x1f, 0x3, 0x2, 
       0x2, 0x2, 0xc9, 0xcc, 0x5, 0x28, 0x15, 0x2, 0xca, 0xcc, 0x3, 0x2, 
       0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 
       0x2, 0xcc, 0x21, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x8, 0x12, 0x1, 
       0x2, 0xce, 0xcf, 0x5, 0x24, 0x13, 0x2, 0xcf, 0xd5, 0x3, 0x2, 0x2, 
       0x2, 0xd0, 0xd1, 0xc, 0x4, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x17, 0x2, 
       0x2, 0xd2, 0xd4, 0x5, 0x24, 0x13, 0x2, 0xd3, 0xd0, 0x3, 0x2, 0x2, 
       0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 
       0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd7, 
       0xd5, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x16, 0xc, 0x2, 0xd9, 
       0xda, 0x7, 0x24, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x16, 0xc, 0x2, 0xdb, 
       0x25, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x25, 0x2, 0x2, 0xdd, 
       0xde, 0x5, 0x28, 0x15, 0x2, 0xde, 0xdf, 0x7, 0x16, 0x2, 0x2, 0xdf, 
       0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdc, 
       0x3, 0x2, 0x2, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x27, 0x3, 
       0x2, 0x2, 0x2, 0xe3, 0xe4, 0x8, 0x15, 0x1, 0x2, 0xe4, 0xe5, 0x5, 
       0x10, 0x9, 0x2, 0xe5, 0xe6, 0x7, 0x26, 0x2, 0x2, 0xe6, 0xe7, 0x5, 
       0x1c, 0xf, 0x2, 0xe7, 0xed, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0xc, 
       0x4, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x16, 0x2, 0x2, 0xea, 0xec, 0x5, 
       0x28, 0x15, 0x5, 0xeb, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xec, 0xef, 0x3, 
       0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 
       0x2, 0x2, 0xee, 0x29, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 
       0x2, 0xf0, 0xf7, 0x8, 0x16, 0x1, 0x2, 0xf1, 0xf2, 0xc, 0x4, 0x2, 
       0x2, 0xf2, 0xf3, 0x5, 0x2c, 0x17, 0x2, 0xf3, 0xf4, 0x7, 0x16, 0x2, 
       0x2, 0xf4, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf1, 0x3, 0x2, 0x2, 0x2, 
       0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 
       0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xf7, 
       0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x2e, 0x18, 0x2, 0xfb, 0xfc, 
       0x5, 0xe, 0x8, 0x2, 0xfc, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 
       0x27, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x39, 0x2, 0x2, 0xff, 0x100, 0x5, 
       0x30, 0x19, 0x2, 0x100, 0x101, 0x7, 0x26, 0x2, 0x2, 0x101, 0x102, 
       0x5, 0x1e, 0x10, 0x2, 0x102, 0x103, 0x7, 0x16, 0x2, 0x2, 0x103, 0x10a, 
       0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x7, 0x28, 0x2, 0x2, 0x105, 0x106, 
       0x7, 0x39, 0x2, 0x2, 0x106, 0x107, 0x5, 0x30, 0x19, 0x2, 0x107, 0x108, 
       0x7, 0x16, 0x2, 0x2, 0x108, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x109, 0xfd, 
       0x3, 0x2, 0x2, 0x2, 0x109, 0x104, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x14, 0x2, 0x2, 0x10c, 0x10d, 
       0x5, 0x32, 0x1a, 0x2, 0x10d, 0x10e, 0x7, 0x15, 0x2, 0x2, 0x10e, 0x111, 
       0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10b, 
       0x3, 0x2, 0x2, 0x2, 0x110, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x8, 0x1a, 0x1, 0x2, 0x113, 0x114, 
       0x5, 0x34, 0x1b, 0x2, 0x114, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 
       0xc, 0x4, 0x2, 0x2, 0x116, 0x117, 0x7, 0x16, 0x2, 0x2, 0x117, 0x119, 
       0x5, 0x34, 0x1b, 0x2, 0x118, 0x115, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11c, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x11b, 0x33, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x5, 0x36, 0x1c, 0x2, 0x11e, 0x120, 
       0x5, 0x38, 0x1d, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11e, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x35, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 
       0x7, 0x25, 0x2, 0x2, 0x122, 0x123, 0x5, 0x38, 0x1d, 0x2, 0x123, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x5, 0x10, 0x9, 0x2, 0x125, 0x126, 
       0x7, 0x26, 0x2, 0x2, 0x126, 0x127, 0x5, 0x1e, 0x10, 0x2, 0x127, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x7, 0x29, 0x2, 0x2, 0x129, 0x12a, 
       0x5, 0x3c, 0x1f, 0x2, 0x12a, 0x12b, 0x7, 0x1b, 0x2, 0x2, 0x12b, 0x3b, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x8, 0x1f, 0x1, 0x2, 0x12d, 0x12e, 
       0x5, 0x3e, 0x20, 0x2, 0x12e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 
       0xc, 0x4, 0x2, 0x2, 0x130, 0x131, 0x7, 0x16, 0x2, 0x2, 0x131, 0x133, 
       0x5, 0x3e, 0x20, 0x2, 0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x135, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 
       0x3, 0x2, 0x2, 0x2, 0x137, 0x15e, 0x5, 0x3a, 0x1e, 0x2, 0x138, 0x139, 
       0x5, 0x40, 0x21, 0x2, 0x139, 0x13a, 0x5, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
       0x5, 0x56, 0x2c, 0x2, 0x13b, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x15e, 
       0x5, 0x52, 0x2a, 0x2, 0x13d, 0x13e, 0x7, 0x2a, 0x2, 0x2, 0x13e, 0x13f, 
       0x5, 0x56, 0x2c, 0x2, 0x13f, 0x140, 0x7, 0x2b, 0x2, 0x2, 0x140, 0x141, 
       0x5, 0x3e, 0x20, 0x2, 0x141, 0x142, 0x5, 0x46, 0x24, 0x2, 0x142, 
       0x15e, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x2c, 0x2, 0x2, 0x144, 
       0x145, 0x5, 0x56, 0x2c, 0x2, 0x145, 0x146, 0x7, 0x1f, 0x2, 0x2, 0x146, 
       0x147, 0x5, 0x48, 0x25, 0x2, 0x147, 0x148, 0x7, 0x1b, 0x2, 0x2, 0x148, 
       0x15e, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x2d, 0x2, 0x2, 0x14a, 
       0x14b, 0x5, 0x56, 0x2c, 0x2, 0x14b, 0x14c, 0x7, 0x2e, 0x2, 0x2, 0x14c, 
       0x14d, 0x5, 0x3e, 0x20, 0x2, 0x14d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x14e, 
       0x14f, 0x7, 0x2f, 0x2, 0x2, 0x14f, 0x150, 0x5, 0x3c, 0x1f, 0x2, 0x150, 
       0x151, 0x7, 0x30, 0x2, 0x2, 0x151, 0x152, 0x5, 0x56, 0x2c, 0x2, 0x152, 
       0x15e, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x7, 0x31, 0x2, 0x2, 0x154, 
       0x155, 0x7, 0x39, 0x2, 0x2, 0x155, 0x156, 0x5, 0x2, 0x2, 0x2, 0x156, 
       0x157, 0x5, 0x56, 0x2c, 0x2, 0x157, 0x158, 0x5, 0x50, 0x29, 0x2, 
       0x158, 0x159, 0x5, 0x56, 0x2c, 0x2, 0x159, 0x15a, 0x7, 0x2e, 0x2, 
       0x2, 0x15a, 0x15b, 0x5, 0x3e, 0x20, 0x2, 0x15b, 0x15e, 0x3, 0x2, 
       0x2, 0x2, 0x15c, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x137, 0x3, 0x2, 
       0x2, 0x2, 0x15d, 0x138, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x13c, 0x3, 0x2, 
       0x2, 0x2, 0x15d, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x143, 0x3, 0x2, 
       0x2, 0x2, 0x15d, 0x149, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x14e, 0x3, 0x2, 
       0x2, 0x2, 0x15d, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15c, 0x3, 0x2, 
       0x2, 0x2, 0x15e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x39, 
       0x2, 0x2, 0x160, 0x161, 0x5, 0x42, 0x22, 0x2, 0x161, 0x41, 0x3, 0x2, 
       0x2, 0x2, 0x162, 0x167, 0x8, 0x22, 0x1, 0x2, 0x163, 0x164, 0xc, 0x4, 
       0x2, 0x2, 0x164, 0x166, 0x5, 0x44, 0x23, 0x2, 0x165, 0x163, 0x3, 
       0x2, 0x2, 0x2, 0x166, 0x169, 0x3, 0x2, 0x2, 0x2, 0x167, 0x165, 0x3, 
       0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 0x2, 0x168, 0x43, 0x3, 
       0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x7, 
       0x1d, 0x2, 0x2, 0x16b, 0x16c, 0x5, 0x54, 0x2b, 0x2, 0x16c, 0x16d, 
       0x7, 0x1e, 0x2, 0x2, 0x16d, 0x171, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 
       0x7, 0x12, 0x2, 0x2, 0x16f, 0x171, 0x7, 0x39, 0x2, 0x2, 0x170, 0x16a, 
       0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x7, 0x32, 0x2, 0x2, 0x173, 0x176, 
       0x5, 0x3e, 0x20, 0x2, 0x174, 0x176, 0x3, 0x2, 0x2, 0x2, 0x175, 0x172, 
       0x3, 0x2, 0x2, 0x2, 0x175, 0x174, 0x3, 0x2, 0x2, 0x2, 0x176, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x5, 0x4a, 0x26, 0x2, 0x178, 0x17a, 
       0x3, 0x2, 0x2, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 0x2, 0x179, 0x178, 
       0x3, 0x2, 0x2, 0x2, 0x17a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 
       0x8, 0x26, 0x1, 0x2, 0x17c, 0x17d, 0x5, 0x4c, 0x27, 0x2, 0x17d, 0x183, 
       0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0xc, 0x4, 0x2, 0x2, 0x17f, 0x180, 
       0x7, 0x16, 0x2, 0x2, 0x180, 0x182, 0x5, 0x4c, 0x27, 0x2, 0x181, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x182, 0x185, 0x3, 0x2, 0x2, 0x2, 0x183, 0x181, 
       0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 
       0x5, 0x4e, 0x28, 0x2, 0x187, 0x188, 0x7, 0x26, 0x2, 0x2, 0x188, 0x189, 
       0x5, 0x3e, 0x20, 0x2, 0x189, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 
       0x8, 0x28, 0x1, 0x2, 0x18b, 0x18c, 0x5, 0x16, 0xc, 0x2, 0x18c, 0x192, 
       0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0xc, 0x4, 0x2, 0x2, 0x18e, 0x18f, 
       0x7, 0x17, 0x2, 0x2, 0x18f, 0x191, 0x5, 0x16, 0xc, 0x2, 0x190, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 
       0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 
       0x9, 0x6, 0x2, 0x2, 0x196, 0x51, 0x3, 0x2, 0x2, 0x2, 0x197, 0x1a8, 
       0x7, 0x39, 0x2, 0x2, 0x198, 0x199, 0x7, 0x39, 0x2, 0x2, 0x199, 0x19a, 
       0x7, 0x14, 0x2, 0x2, 0x19a, 0x19b, 0x5, 0x54, 0x2b, 0x2, 0x19b, 0x19c, 
       0x7, 0x15, 0x2, 0x2, 0x19c, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 
       0x7, 0x35, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x14, 0x2, 0x2, 0x19f, 0x1a0, 
       0x5, 0x54, 0x2b, 0x2, 0x1a0, 0x1a1, 0x7, 0x15, 0x2, 0x2, 0x1a1, 0x1a8, 
       0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x36, 0x2, 0x2, 0x1a3, 0x1a4, 
       0x7, 0x14, 0x2, 0x2, 0x1a4, 0x1a5, 0x5, 0x40, 0x21, 0x2, 0x1a5, 0x1a6, 
       0x7, 0x15, 0x2, 0x2, 0x1a6, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x198, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x19d, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x8, 0x2b, 0x1, 0x2, 0x1aa, 0x1ab, 
       0x5, 0x56, 0x2c, 0x2, 0x1ab, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 
       0xc, 0x4, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x17, 0x2, 0x2, 0x1ae, 0x1b0, 
       0x5, 0x56, 0x2c, 0x2, 0x1af, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b3, 
       0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x1b2, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 
       0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x58, 0x2d, 0x2, 0x1b5, 0x1b6, 
       0x5, 0x4, 0x3, 0x2, 0x1b6, 0x1b7, 0x5, 0x58, 0x2d, 0x2, 0x1b7, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x58, 0x2d, 0x2, 0x1b9, 0x1b4, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x8, 0x2d, 0x1, 0x2, 0x1bc, 0x1c2, 
       0x5, 0x5a, 0x2e, 0x2, 0x1bd, 0x1be, 0x7, 0xa, 0x2, 0x2, 0x1be, 0x1c2, 
       0x5, 0x5a, 0x2e, 0x2, 0x1bf, 0x1c0, 0x7, 0xb, 0x2, 0x2, 0x1c0, 0x1c2, 
       0x5, 0x5a, 0x2e, 0x2, 0x1c1, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bd, 
       0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c9, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0xc, 0x3, 0x2, 0x2, 0x1c4, 0x1c5, 
       0x5, 0x6, 0x4, 0x2, 0x1c5, 0x1c6, 0x5, 0x5a, 0x2e, 0x2, 0x1c6, 0x1c8, 
       0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 
       0x3, 0x2, 0x2, 0x2, 0x1ca, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1c9, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x8, 0x2e, 0x1, 0x2, 0x1cd, 0x1ce, 
       0x5, 0x5c, 0x2f, 0x2, 0x1ce, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 
       0xc, 0x4, 0x2, 0x2, 0x1d0, 0x1d1, 0x5, 0x8, 0x5, 0x2, 0x1d1, 0x1d2, 
       0x5, 0x5c, 0x2f, 0x2, 0x1d2, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1cf, 
       0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 
       0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x5b, 
       0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1e6, 
       0x5, 0x5e, 0x30, 0x2, 0x1d9, 0x1e6, 0x5, 0x40, 0x21, 0x2, 0x1da, 
       0x1db, 0x7, 0x39, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x14, 0x2, 0x2, 0x1dc, 
       0x1dd, 0x5, 0x54, 0x2b, 0x2, 0x1dd, 0x1de, 0x7, 0x15, 0x2, 0x2, 0x1de, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x14, 0x2, 0x2, 0x1e0, 
       0x1e1, 0x5, 0x56, 0x2c, 0x2, 0x1e1, 0x1e2, 0x7, 0x15, 0x2, 0x2, 0x1e2, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x37, 0x2, 0x2, 0x1e4, 
       0x1e6, 0x5, 0x5c, 0x2f, 0x2, 0x1e5, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
       0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
       0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1eb, 0x7, 0x39, 0x2, 0x2, 0x1e8, 
       0x1eb, 0x7, 0x3e, 0x2, 0x2, 0x1e9, 0x1eb, 0x7, 0x38, 0x2, 0x2, 0x1ea, 
       0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 
       0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x22, 
       0x81, 0x89, 0x95, 0xa3, 0xaa, 0xb6, 0xc5, 0xcb, 0xd5, 0xe1, 0xed, 
       0xf7, 0x109, 0x110, 0x11a, 0x11f, 0x134, 0x15d, 0x167, 0x170, 0x175, 
       0x179, 0x183, 0x192, 0x1a7, 0x1b1, 0x1b9, 0x1c1, 0x1c9, 0x1d5, 0x1e5, 
       0x1ea, 
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
