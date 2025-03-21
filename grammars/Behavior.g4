grammar Behavior;

root : REGISTER_PREFIX NUM '=' or;

or :	xor | 
	or (OR) xor;

xor :   and | 
	xor (XOR) and;

and :   shift | 
	and (AND) expr;

shift : expr | 
	shift (SHIFT_LEFT|SHIFT_RIGHT) expr;

expr :  term |
	expr (PLUS|SUB) term;

term :  factor | 
	term (MULT|DIV) factor;

factor :primary | 
	primary (EXP) factor;

primary : (REGISTER_PREFIX NUM) | NUM;

NUM : [0-9]+;
REGISTER_PREFIX : 'R';
PLUS : '+';
SUB : '-'; 
MULT : '*';
DIV : '/';
EXP : '^';
SHIFT_LEFT : '<<';
SHIFT_RIGHT : '>>';
AND : 'and';
OR : 'or';
XOR : 'xor';

WS : [ \n]+ -> skip;

