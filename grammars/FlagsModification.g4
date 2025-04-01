grammar FlagsModification;

root  : '(' condition_equal ')' '?' (true_action) ':' (false_action);  

condition_equal : condition_or |
		  condition_equal (EQUAL) condition_or; 

condition_or : condition_and |
	       condition_or (OR) condition_and;

condition_and : comparison_expr |
                condition_and (AND) comparison_expr;

comparison_expr : not_expr |
                  comparison_expr (GREATER_EQUAL | GREATER | LESS_EQUAL | LESS) not_expr;

not_expr : primary | (NOT) primary;

primary : (REGISTER_PREFIX NUM) | NUM | parentheses | MAX | MIN;

parentheses : O_PAREN condition_equal C_PAREN;

true_action : FLAGS_REGISTER_POS ASSIGN   (TRUE | FALSE);

false_action : FLAGS_REGISTER_POS ASSIGN   (TRUE | FALSE);  


AND : '&&';
OR : '||';
NOT : '!';
EQUAL : '==';
NOT_EQUAL : '!=';
O_PAREN : '(';
C_PAREN : ')';
ASSIGN : '=';
FLAGS_REGISTER_POS : 'flags_register[' [0-9]+ ']';
TRUE : '1';
FALSE : '0';
NUM : [0-9]+;
REGISTER_PREFIX : 'R';
MAX : 'MAX' ;
MIN : 'MIN';
GREATER : '>';
LESS : '<';
GREATER_EQUAL : '>=';
LESS_EQUAL : '<=';


WS : [ \n]+ -> skip;
