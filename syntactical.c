//<switchstmnt> ::= switch ( <expr> ) <stmnt>
void switchstmnt (void){
	if(nextToken != SWITCH_CODE)	
		error();
	else{
		lex();
		if(nextToken != LEFT_PAREN)
			error();
		else{
			lex();
			expr();
			if(nextToken != RIGHT_PAREN)
				error();
			else{
				lex();
				stmnt();
			}
		}
	}
}

//<whilestmt> ::= while ( <expr> ) <stmnt>
void whilestmt (void){
	if(nextToken != WHILE_CODE)	
		error();
	else{
		lex();
		if(nextToken != LEFT_PAREN)
			error();
		else{
			lex();
			expr();
			if(nextToken != RIGHT_PAREN)
				error();
			else{
				lex();
				stmnt();
			}
		}
	}
}

//<dowhilestmt> ::= do <stmnt> while ( <expr> ) 
void dowhilestmt (void){
	if(nextToken != DOWHILE_CODE)	
		error();
	else{
		lex();
		stmnt();
		if(nextToken != DOWHILE_CODE){
			error();
			if(nextToken != LEFT_PAREN){
				error();
			}else{
				lex();
				expr();
				if(nextToken != RIGHT_PAREN){
					error();
				}else{
					lex();
					stmnt();
				}
			}
		}
	}
}

//<ifstmt> ::= if ( <expr> ) <stmnt> [ else <stmnt> ]
void ifstmt (void){
	if(nextToken != IF_CODE)	
		error();
	else{
		lex();
		if(nextToken != LEFT_PAREN)
			error();
		else{
			lex();
			expr();
			if(nextToken != RIGHT_PAREN)
				error();
			else{
				lex();
				stmnt();
			}
		}
	}
}

//<block> '{' <statement>; '}'
void block ()
	if nextToken != '{'
		error();
	else
		while { nexttoken != '}{
			statement();
			if nextToken != ';'
				error();
			lex();
		}
	if nextToken != '}'
		error();
	lex();
	
//<returnstmnt> <statement>';'
void returnstmnt ()
	if nextToken != ';'
		error();
	else
		stmnt();
		lex();
		
//<assgnmnt> '=' <statement> 
void assgnmnt ()
	if nextToken != '='
		error();
	else
		stmnt();
		lex();

