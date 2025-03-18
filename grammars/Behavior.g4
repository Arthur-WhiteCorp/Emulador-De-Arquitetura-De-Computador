grammar Behavior;

root : expr;

expr : expr (PLUS | SUB) expr 
     | NUM ;

NUM : [0-9]+;
PLUS : '+';
SUB : '-'; 
TEST : '*';
SUP : 'another one';
TL: 'asdsd';
WS : [ \n]+ -> skip;

