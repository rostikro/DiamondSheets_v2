grammar DiamondSheets;

expression          : '(' expression ')'                                                            #parenthesisExpr
                    | <assoc=right>  expression '^' expression                                      #powerExpr
                    | expression (MULTIPLY|DIVIDE|MOD|INTDIV) expression                            #mulDivModExpr
                    | expression (PLUS|MINUS) expression                                            #addSubExpr
                    | expression (L_COMP|R_COMP|EQ_COMP|N_EQ_COMP|L_EQ_COMP|R_EQ_COMP) expression   #compExpr
                    | NUMBER                                                                        #numericAtomExpr
                    | CELLID                                                                        #cellIdAtomExpr
                    ;

// lexer rules
fragment LETTER : [a-zA-Z] ;
fragment DIGIT : [0-9] ;

MULTIPLY : '*' ;
DIVIDE : '/' ;
INTDIV: '//' ;
MOD : '%' ;
PLUS : '+' ;
MINUS : '-' ;

L_COMP: '<' ;
R_COMP: '>' ;
EQ_COMP: '=' ;
N_EQ_COMP: '!=';
L_EQ_COMP: '<=' ;
R_EQ_COMP: '>=' ;

CELLID : LETTER+ DIGIT+ ;

NAME : LETTER+ ;

NUMBER : DIGIT+ ('.' DIGIT+)? ;

WS : ' ' -> skip;