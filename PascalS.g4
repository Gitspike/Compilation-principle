grammar PascalS;

begin: program;
// 大部分关键词前后需要加换行或空格，所以都做成词法分析
CONST: [ \n\r\t] 'const' [ \n\r\t];
TYPE: [ \n\r\t] 'type' [ \n\r\t];
RECORD: [ \n\r\t] 'record' [ \n\r\t];
ARRAY: [ \n\r\t] 'array' [ \n\r\t];
OF: [ \n\r\t] 'of' [ \n\r\t];
VAR: [ \n\r\t] 'var' [ \n\r\t];
FUNCTION: [ \n\r\t] 'function' [ \n\r\t];
PROCEDURE: [ \n\r\t] 'procedure' [ \n\r\t];
IF: [ \n\r\t] 'if' [ \n\r\t];
THEN: [ \n\r\t] 'then' [ \n\r\t];
ELSE: [ \n\r\t] 'else' [ \n\r\t];
CASE: [ \n\r\t] 'case' [ \n\r\t];
WHILE: [ \n\r\t] 'while' [ \n\r\t];
DO: [ \n\r\t] 'do' [ \n\r\t];
REPEAT: [ \n\r\t] 'repeat' [ \n\r\t];
UNTIL: [ \n\r\t] 'until' [ \n\r\t];
FOR: [ \n\r\t] 'for' [ \n\r\t];

CONST_CHAR: '\'' LETTER '\'';
ID: LETTER (LETTER | DIGIT)*; // 标识符
fragment LETTER: [a-zA-Z];

ASSIGNOP: ':=';
RELOP: '<' | '>' | '<=' | '>=' | '<>' | '=' | 'and' | 'or' | 'not';
ADDOP: '+' | '-';
MULOP: '*' | '/';
COMMENT: '(*' .*? '*)' -> skip;
MUL_COMMENT: '{' .*? '}' -> skip;
WS: [ \r\n\t] -> skip;


/* NUMBER:
 '-'? DIGITS '.' DIGITS EXP? // 匹配浮点数
 | '-'? DIGITS EXP // 匹配科学计数法
 | '-'? DIGITS; //
 匹配一般正负数
 fragment DIGITS: DIGIT+;
 fragment EXP: [Ee] [+\-]? DIGITS;
 */

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
identifier_list: identifier_list ',' ID | ID;

/* const 常量声明部分，该部分唯一出现一次 */
const_declarations: (CONST const_declaration ';')?; // 以 const 标识进入常量声明
const_declaration
	: const_declaration ';' const_declaration
	| ID '=' const_variable
	;
const_variable	// const_variable 定义了常量的具体数值
	: ADDOP? ID
	| ADDOP? NUMBER
	| CONST_CHAR
	; 

/* type 类型标识部分，该部分唯一出现一次 */
type_declarations: (TYPE type_declaration ';')?; // 以 type 标识进入类型标识
type_declaration
	: type_declaration ';' type_declaration
	| ID '=' type
	;
type
	: standard_type // 标准变量类型
	| RECORD record_body 'end' // 记录型变量
	| ARRAY '[' periods ']' OF type	// 数组型变量
	; 

standard_type: 'integer' | 'real' | 'boolean' | 'char';
record_body: var_declaration?;
periods: period ',' periods | period;
period: const_variable '..' const_variable;

/* var 变量声明部分，该部分唯一出现一次 */
var_declarations: (VAR var_declaration ';')?; // 以 var 标识进入变量声明部分
var_declaration
	: var_declaration ';' var_declaration
	| identifier_list ':' type
	;

/* 子程序部分，包括可能的多个函数和过程 */
subprogram_declarations: (subprogram_declaration ';' subprogram_declarations)?;
subprogram_declaration: subprogram_head program_body;
subprogram_head
	: FUNCTION ID formal_parameter ':' standard_type ';'	// 以 function 标识进入函数部分
	| PROCEDURE ID formal_parameter ';'	// 以 procedure 标识进入过程部分
	;	
formal_parameter: ('(' parameter_lists ')')?;
parameter_lists
	: parameter_lists ';' parameter_list
	| parameter_list
	;
parameter_list: var_parameter | value_parameter;	// 包括引用传递和传值传递
var_parameter: VAR value_parameter;	// 引用传递需要加 var 前缀
value_parameter: identifier_list ':' standard_type;

/* 主程序部分，由多个语句组成程序 */
compound_statement: 'begin' statement_list 'end';
statement_list
	: statement_list ';' statement
	| statement
	;
statement
	: (compound_statement)?											# Block
	| variable ASSIGNOP expression									# Assign
	| call_procedure_statement										# Call
	| IF expression THEN statement else_part					# If
	| CASE expression OF case_body 'end'						# Case
	| WHILE expression DO statement								# While
	| REPEAT statement_list UNTIL expression					# Repeat
	| FOR ID ASSIGNOP expression updown expression DO statement	# For
	;

/* 变量赋值 */
variable: ID id_varparts;
id_varparts: (id_varpart id_varparts)?;
id_varpart
	: '[' expression_list ']'	// 数组型变量的访问需要中括号
	| '.' ID					// 记录型变量的访问需要成员访问符(小数点)
	;

/* 条件判断 */
else_part: (ELSE statement)?;

/* 选择分支 */
case_body: (branch_list)?;
branch_list
	: branch_list ';' branch
	| branch
	;
branch: const_list ':' statement;
const_list
	: const_list ',' const_variable
	| const_variable
	;

/* 循环 */
updown: 'to' | 'downto';

/* 调用过程 */
call_procedure_statement: ID | ID '(' expression_list ')';

/* 表达式 */
expression_list
	: expression_list ',' expression
	| expression
	;


expression
	: simple_expression RELOP simple_expression
	| simple_expression
	;
simple_expression
	: ADDOP? term simple_expression_0
	;
simple_expression_0
	: ADDOP term simple_expression
	|
	;

term: factor MULOP term
	| factor
	;
factor
	: unsign_const_variable
	| variable
	| ID '(' expression_list ')'	// 利用子程序的返回值
	| '(' expression ')'
	| 'not' factor
	;
unsign_const_variable: NUMBER | CONST_CHAR;


/*
expression: CONST_CHAR |  factor (ADDOP factor)? | call_procedure_statement;
factor: variable | NUMBER; 
*/
