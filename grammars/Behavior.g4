grammar Behavior;

root : expr;

expr : expr (binary_op) expr 
     | NUM ;

binary_op : EXP    # EXPONENTIATION
	   | MULT   # MULTIPLICATION
	   | DIV    # DIVISION
           | PLUS   # ADDITION
           | SUB    # SUBTRACTION
           | SHIFT_LEFT  # SHL
           | SHIFT_RIGHT  # SHR
           | AND  # AND_BIT_WISE
           | XOR  # XOR_BIT_WISE
           | OR  # OR_BIT_WISE
	   ;
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

