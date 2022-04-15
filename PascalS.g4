grammar PascalS;
options {
	language = Cpp;
}

CONST_CHAR: '\'' LETTER '\'';
ID: LETTER (LETTER | DIGIT)*; // 标识符
LETTER: [a-zA-Z];

assignop: ':=';
relop: '<' | '>' | '<=' | '>=' | '<>' | '=';
addop: '+' | '-' | 'or';
mulop: '*' | '/' | 'div' | 'mod' | 'and';
COMMENT: '(*' .*? '*)' -> skip;
MUL_COMMENT: '{' .*? '}' -> skip;
WS: [ \r\n\t] -> skip;

NUMBER: DIGITS OPTIONAL_FRACTION? OPTIONAL_EXPONENT?; // 匹配无符号的数，若有符号，则在使用的地方前要加 “-”
DIGITS: DIGIT+;
DIGIT: [0-9];
fragment OPTIONAL_FRACTION: '.' DIGITS;
fragment OPTIONAL_EXPONENT: [Ee] [+\-]? DIGITS; // 匹配

program: program_head program_body '.';
program_head: 'program' ID '(' identifier_list ')' ';'; // 定义程序头，主要包括程序的名字
program_body:
	const_declarations
	type_declarations
	var_declarations
	subprogram_declarations
	compound_statement; // 定义程序体内容，按顺序分别是 const type var 子程序 主程序
identifier_list
	: identifier_list ',' ID	# MultiMainArg
	| ID						# MainArg
	;

/* const 常量声明部分，该部分唯一出现一次 */
const_declarations
	: 'const' const_declaration ';' // 以 const 标识进入常量声明
	|
	;
const_declaration
	: const_declaration ';' const_declaration	# MultiConstDeclaration
	| ID '=' const_variable						# SingleConstDeclaration
	;
const_variable	// const_variable 定义了常量的具体数值
	: '+' ID		# PositiveId
	| '-' ID		# NegativeId
	| ID			# PositiveId
	| '+' NUMBER	# PositiveNumber
	| '-' NUMBER	# NegativeNumber
	| NUMBER		# PositiveNumber
	| CONST_CHAR	# ConstChar
	; 

/* type 类型标识部分，该部分唯一出现一次 */
type_declarations
	: 'type' type_declaration ';'	// 以 type 标识进入类型标识
	|
	;
type_declaration
	: type_declaration ';' type_declaration	# MultiTypeDeclaration
	| ID '=' type							# SingleTypeDeclaration
	;
type
	: standard_type // 标准变量类型						# Standard
	| 'record' record_body 'end' // 记录型变量			# RecordType
	| 'array' '[' periods ']' 'of' type	// 数组型变量	# ArrayType
	; 

standard_type: 'integer' | 'real' | 'boolean' | 'char';
record_body
	: var_declaration
	|
	;
periods
	: periods ',' period	# MultiPeriod
	| period				# SinglePeriod
	;
period: const_variable '..' const_variable;

/* var 变量声明部分，该部分唯一出现一次 */
var_declarations
	: 'var' var_declaration ';' // 以 var 标识进入变量声明部分
	|
	;
var_declaration
	: var_declaration ';' var_declaration	# MultiVarDeclaration
	| identifier_list ':' type				# SingleVarDeclaration
	;

/* 子程序部分，包括可能的多个函数和过程 */
subprogram_declarations
	: subprogram_declarations subprogram_declaration ';'
	|
	;
subprogram_declaration: subprogram_head program_body;
subprogram_head
	: 'function' ID formal_parameter ':' standard_type ';'	# FunctionDeclaration	// 以 function 标识进入函数部分
	| 'procedure' ID formal_parameter ';'					# ProcedureDeclaration	// 以 procedure 标识进入过程部分
	;	
formal_parameter
	: '(' parameter_lists ')'
	|	// 当没有参数的时候，就不要写括号
	;
parameter_lists
	: parameter_lists ';' parameter_list	# MultiPara
	| parameter_list						# SinglePara
	;
parameter_list
	: var_parameter 	# VarPara	// 引用传递
	| value_parameter	# ValuePara	// 传值传递
	;	
var_parameter: 'var' value_parameter;	// 引用传递需要加 var 前缀
value_parameter: identifier_list ':' standard_type;

/* 主程序部分，由多个语句组成程序 */
compound_statement: 'begin' statement_list 'end';
statement_list
	: statement_list ';' statement		# MultiStatement
	| statement							# SingleStatement
	;
statement
	: compound_statement											# Block
	| variable assignop expression									# Assign
	| call_procedure_statement										# Call
	| 'if' expression 'then' statement else_part					# If
	| 'case' expression 'of' case_body 'end'						# Case
	| 'while' expression 'do' statement								# While
	| 'repeat' statement_list 'untile' expression					# Repeat
	| 'for' ID assignop expression updown expression 'do' statement	# For
	| 																# None
	;

/* 变量赋值 */
variable: ID id_varparts;
id_varparts
	: id_varparts id_varpart
	|
	;
id_varpart
	: '[' expression_list ']'	# ArrayAccess	// 数组型变量的访问需要中括号
	| '.' ID					# RecordAccess	// 记录型变量的访问需要成员访问符(小数点)
	;

/* 条件判断 */
else_part
	: 'else' statement
	|
	;

/* 选择分支 */
case_body
	: branch_list
	|
	;
branch_list
	: branch_list ';' branch
	| branch
	;
branch: const_list ':' statement;
const_list
	: const_list ',' const_variable		# MultiConstList
	| const_variable					# SingleConstList
	;

/* 循环 */
updown: 'to' | 'downto';

/* 调用过程 */
call_procedure_statement
	: ID								# CallWithNoPara 
	| ID '(' expression_list ')'		# CallWithPara
	| 'writeln' '(' expression_list ')'	# CallWriteln	// 将表达式的结果输出并换行
	| 'readln' '(' ID ')'				# CallReadln	// 将输入的内容保存在变量中，原版Pascal在这里不会做类型检查
	;

/* 表达式 */
expression_list
	: expression_list ',' expression
	| expression
	;
expression
	: simple_expression relop simple_expression		# RelationOperation
	| simple_expression								# NoRalationOperation
	;
simple_expression
	: term									# PositiveTerm
	| '+' term								# PositiveTerm
	| '-' term								# NegativeTerm
	| simple_expression addop term			# AddOperation
	;
term: term mulop factor				# MultiplyOperation
	| factor						# NoMultiplyOperation
	;
factor
	: unsign_const_variable			# UnsignConst
	| variable						# FactorVariable
	| ID '(' expression_list ')'	# FactorReturn		// 利用子程序的返回值
	| '(' expression ')'			# FactorPriority
	| 'not' factor					# ReverseFactor		// 取反
	;
unsign_const_variable
	: ID 			# UnsignConstId
	| NUMBER 		# UnsignConstNumber
	| CONST_CHAR	# UnsignConstChar
	;